#include "common.hpp"

#include <Windows.h>

// ------- Globals ------ //
Global * global = new Global{};
Global & g = *global;

// ------- Utils ------ //
void Util_CopyClipboard(std::string text)
{
	auto output = text.c_str();
	size_t const len = strlen(output) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}
std::string Util_GetNewTemp()
{
	std::string ret = "T";
	auto temp = std::to_string(g.temp_counter);
	++g.temp_counter;
	return ret.append(temp);
}
std::string Util_GetNewLabel()
{
	std::string ret = "L";
	auto temp = std::to_string(g.label_counter);
	++g.label_counter;
	return ret.append(temp);
}
int Util_GetNewSymbolTableId()
{
	auto ret = g.symbol_table_counter;
	++g.symbol_table_counter;
	return ret;
}
int Util_GetNewRelationId()
{
	auto ret = g.rel_counter;
	++g.rel_counter;
	return ret;
}
void Util_FixBooleanValue(std::string & value)
{
	if (MT_TRUE_VALUE == value)
		value = "1";
	else if (MT_FALSE_VALUE == value)
		value = "0";
}
std::string Util_GetTypeString(TypeEnum type)
{
	switch (type)
	{
		case TypeEnum::BOOL:
			return "int";

		case TypeEnum::INT:
			return "int";

		case TypeEnum::REAL:
			return "double";

		case TypeEnum::STRING:
			return "string";

		case TypeEnum::ID:
			return "id";

		case TypeEnum::FUNCTION:
			return "function";

		default:
			return MT_INVALID;
	}
}
std::string Util_GetTypePrintToken(TypeEnum type)
{
	switch (type)
	{
		case TypeEnum::BOOL:
			return "%d";

		case TypeEnum::INT:
			return "%d";

		case TypeEnum::REAL:
			return "%lf";

		case TypeEnum::STRING:
			return "%s";

		default:
			return MT_INVALID;
	}
}
std::string Util_GetOpString(OpEnum op)
{
	switch (op)
	{
		case OpEnum::PLUS:
			return "+";
		case OpEnum::MINUS:
			return "-";
		case OpEnum::MUL:
			return "*";
		case OpEnum::DIV:
			return "/";
		case OpEnum::MOD:
			return "%";
		case OpEnum::POW:
			return "^";
		case OpEnum::SHIFT_LEFT:
			return "<<";
		case OpEnum::SHIFT_RIGHT:
			return ">>";
		case OpEnum::LOGICAL_AND:
			return "&&";
		case OpEnum::LOGICAL_OR:
			return "||";
		case OpEnum::LT:
			return "<";
		case OpEnum::LE:
			return "<=";
		case OpEnum::GT:
			return ">";
		case OpEnum::GE:
			return ">=";
		case OpEnum::EQ:
			return "==";
		case OpEnum::NE:
			return "!=";
		case OpEnum::BITWISE_AND:
			return "&";
		case OpEnum::BITWISE_OR:
			return "|";
		case OpEnum::UMINUS:
			return "-";
		case OpEnum::LOGICAL_NOT:
			return "!";
		case OpEnum::BITWISE_NOT:
			return "~";
		default:
		case OpEnum::NONE:
			return "NONE";
	}
}
bool Util_IsIntegerOnlyOp(OpEnum op)
{
	switch (op)
	{
		case OpEnum::MOD:
		case OpEnum::SHIFT_LEFT:
		case OpEnum::SHIFT_RIGHT:
		case OpEnum::BITWISE_AND:
		case OpEnum::BITWISE_OR:
		case OpEnum::BITWISE_NOT:
			return true;
		default:
			return false;
	}
}
std::string Util_GetTypeDefaultValue(TypeEnum type)
{
	if (TypeEnum::BOOL == type)
		return "0";
	else if (TypeEnum::INT == type)
		return "0";
	else if (TypeEnum::REAL == type)
		return "0.0";

	return MT_INVALID;
}
int Util_GetQuadEntryIndex(QuadEntry * entry)
{
	for (int i = 0; i < g.quad_table.size(); ++i)
	{
		if (g.quad_table[i]->id == entry->id)
			return i;
	}
	return -1;
}

// ------- Program ------ //
void Program_Initialize()
{
	g.global_st = SymbolTable_Create();
	SymbolTable_SetCurrent(g.global_st);
}
Global & Program_GetGlobal()
{
	return g;
}
void Program_PrintCode()
{
	std::string header;
	header.append("#include <stdio.h>\n#include <stdlib.h>\n"); // includes and defines
	header.append("\n#define STACK_MAX 1000\n\n");

	header.append("#define PUSH(T0) --stack_top;\\\n" // push/pop macro
		"*stack_top = T0\n"
		"#define POP() *stack_top;\\\n"
		"++stack_top;\n\n");

	header.append("#define PUSH_LABEL(L0) --labels_top;\\\n" // push/pop macro
		"*labels_top = &&L0\n"
		"#define POP_LABEL() *labels_top;\\\n"
		"++labels_top;\n\n");

	header.append("int main()\n{\n\t"); // main

	header.append("void * ret_address;\n\t");

	header.append("double * stack_top = (double*) malloc(STACK_MAX * sizeof(double));\n\t"); // stack
	header.append("stack_top += STACK_MAX;\n\n\t"); // reset top

	header.append("void** labels_top = (void **) malloc(STACK_MAX * sizeof(void *));\n\t"); // label stack
	header.append("labels_top += STACK_MAX;\n\n\t"); // reset top

	std::string decls = "\t";
	for (auto entry : g.decls)
	{
		if (TypeEnum::BOOL == entry->type)
		{
			entry->type = TypeEnum::INT;
			Util_FixBooleanValue(entry->value);
		}
		decls.append(Util_GetTypeString(entry->type) + " " + entry->id + " = " + entry->value + ";\n\t");
	}
	std::string code = "\t";
	for (auto entry : g.quad_table)
		code.append(entry->code);

	std::string footer;
	footer.append("\n\tend: return 0;\n"); // main return code
	footer.append("}\n"); // end of main

	std::string baked = header
		+ "\n\t// ------------ declerations ------------  //\n"
		+ decls
		+ "// ----------- end of declerations ----------- \n\n"
		+ code
		+ footer;
	Util_CopyClipboard(baked);
	printf("\n\n-------------------Output Code-------------------\n%s------------------------------------------------ - \n\n", baked.c_str());
}

// ------- Quad Table ------ //
QuadEntry * QuadTable_AddEntry(QuadEntry * entry)
{
	g.quad_table.push_back(entry);
	return entry;
}

// ------- Stack ------ //
void Stack_Push(StackEntry * entry)
{
	entry->quad_index = CURRENT_TABLE_COUNT;
	g.stack.push(entry);
}
StackEntry * Stack_Pop()
{
	StackEntry * ret = nullptr;

	if (g.stack.size() > 0)
	{
		ret = g.stack.top();
		g.stack.pop();
	}

	return ret;
}
StackEntry * Stack_Peek()
{
	StackEntry * ret = nullptr;

	if (g.stack.size() > 0)
		ret = g.stack.top();

	return ret;
}

// ------- Symbol Table ------ //
TableEntry * SymbolTable_AddEntry(std::string name)
{
	TableEntry * ret = nullptr;

	auto st = g.current_st;
	ret = SymbolTable_Lookup(name, st);

	if (nullptr == ret)
	{
		int id = int(st->entries.size());
		ret = new TableEntry{ id, name };
		st->entries.push_back(ret);
	}

	return ret;
}

SymbolTable * SymbolTable_Create()
{
	return new SymbolTable{ Util_GetNewSymbolTableId() };
}
void SymbolTable_SetCurrent(SymbolTable * st)
{
	if (nullptr != g.current_st)
	{
		g.current_st->child = st;
		st->parent = g.current_st;
	}
	g.current_st = st;
}
void SymbolTable_PopCurrent()
{
	if (nullptr != g.current_st)
	{
		auto parent = g.current_st->parent;

		// free current
		SymbolTable_Log(g.current_st);
		delete g.current_st;
		g.current_st = nullptr;

		if (nullptr != parent)
		{
			g.current_st = parent;
			g.current_st->child = nullptr;
		}
	}
}
TableEntry * SymbolTable_Lookup(std::string name, SymbolTable * st)
{
	TableEntry * ret = nullptr;

	// search current st
	for (auto entry : st->entries)
	{
		if (name == entry->name)
		{
			ret = entry;
			break;
		}
	}

	// if not a func -> search parent
	if (nullptr == ret)
	{
		if (nullptr != st->parent)
			ret = SymbolTable_Lookup(name, st->parent);
	}

	return ret;
}
void SymbolTable_Log(SymbolTable * st)
{
	char * buff = new char[5000];
	sprintf(buff, "\n\n-------------------Symbol Table#%d-------------------\n", st->id);
	sprintf(buff + strlen(buff), "%-12s%s\n", "name", "id");
	for (auto entry : st->entries)
		sprintf(buff + strlen(buff), "%-13s%d\n", entry->name.c_str(), entry->id);
	sprintf(buff + strlen(buff), "----------------------------------------------------\n\n");
	g.st_log.append(buff);
	delete[] buff;
}
void SymbolTable_Print()
{
	SymbolTable_Log(g.global_st);
	printf("%s", g.st_log.c_str());
}

// ---------- Decleration list ---------- //
DeclEntry * DeclList_Add(std::string id, TypeEnum type, bool can_change)
{
	return DeclList_Add(id, type, Util_GetTypeDefaultValue(type), can_change);
}
DeclEntry * DeclList_Add(std::string id, TypeEnum type, std::string value, bool can_change)
{
	auto ret = DeclList_Lookup(id);

	if (nullptr == ret)
	{
		if (type == TypeEnum::ID && can_change) // happens to for loops
		{
			type = TypeEnum::REAL;
			value = Util_GetTypeDefaultValue(type);
		}

		ret = new DeclEntry{ id, type, value };
		g.decls.push_back(ret);
	}
	return ret;
}
DeclEntry * DeclList_Lookup(std::string id)
{
	DeclEntry * ret = nullptr;
	for (auto itr = g.decls.begin(); itr != g.decls.end(); ++itr)
	{
		auto entry = *itr;
		if (entry->id == id)
		{
			ret = entry;
			break;
		}
	}
	return ret;
}

// ------- Code ------ //
TypeEnum Code_DecayType(TypeEnum t0, TypeEnum t1)
{
	if (TypeEnum::REAL == t0 || TypeEnum::REAL == t1)
		return TypeEnum::REAL;
	return t0;
}
void Code_DeclareVarList()
{
	for (int i = 0; i < g.var_list_item_counter; ++i)
	{
		auto id_entry = Stack_Pop();
		auto id = id_entry->value;
		std::string value = MT_EMPTY_ARG;
		if (TypeEnum::ID_EXP_TUPLE == id_entry->type) // means id = exp (value, function call, etc.)
			value = Stack_Pop()->value;
		DeclList_Add(id, TypeEnum::ID, value);
	}
	auto type = Stack_Pop()->type;

	auto itr = g.decls.end();
	for (int i = 0; i < g.var_list_item_counter; ++i)
	{
		--itr;
		auto entry = *itr;
		if (MT_EMPTY_ARG == entry->value) // default values
			entry->value = Util_GetTypeDefaultValue(type);
		entry->type = type;
	}
	g.var_list_item_counter = 0;
}
void Code_ArithmeticUnary(OpEnum op)
{
	auto arg0 = Stack_Pop();
	if (TypeEnum::ID == arg0->type)
	{
		DeclList_Add(arg0->value, TypeEnum::REAL);
		arg0->type = TypeEnum::REAL;
	}

	auto type = arg0->type;
	if (Util_IsIntegerOnlyOp(op))
		type = TypeEnum::INT;

	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::ARIMETHIC_EXP;
	entry->c0 = arg0->value;
	entry->c1 = MT_EMPTY_ARG;
	entry->res = Util_GetNewTemp();
	DeclList_Add(entry->res, type, true);

	entry->code = entry->res + " = "
		+ Util_GetOpString(op)
		+ (arg0->type != type ? "( " + Util_GetTypeString(type) + " )" : "") + entry->c0 + ";\n\t";

	if (nullptr != arg0->quad_entry)
	{
		entry->deps.insert(entry->deps.end(), arg0->quad_entry->deps.begin(), arg0->quad_entry->deps.end());
		entry->deps.emplace_back(arg0->quad_entry);
	}

	Stack_Push(new StackEntry{ arg0->type, entry->res, entry });
	QuadTable_AddEntry(entry);
}
void Code_ArithmeticBinary(OpEnum op)
{
	auto arg1 = Stack_Pop();
	auto arg0 = Stack_Pop();

	if (TypeEnum::ID == arg0->type)
	{
		DeclList_Add(arg0->value, TypeEnum::REAL);
		arg0->type = TypeEnum::REAL;
	}
	if (TypeEnum::ID == arg1->type)
	{
		DeclList_Add(arg1->value, TypeEnum::REAL);
		arg1->type = TypeEnum::REAL;
	}

	auto type = arg0->type;
	if (Util_IsIntegerOnlyOp(op))
		type = TypeEnum::INT;
	else
		type = Code_DecayType(arg0->type, arg1->type);

	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::ARIMETHIC_EXP;
	entry->c0 = arg0->value;
	entry->c1 = arg1->value;
	entry->res = Util_GetNewTemp();
	DeclList_Add(entry->res, type, true);

	entry->code = entry->res + " = "
		+ (arg0->type != type ? "( " + Util_GetTypeString(type) + " )" : "") + entry->c0 + " "
		+ Util_GetOpString(op) + " "
		+ (arg1->type != type ? "( " + Util_GetTypeString(type) + " )" : "") + entry->c1 + ";\n\t";


	if (nullptr != arg0->quad_entry)
	{
		entry->deps.insert(entry->deps.end(), arg0->quad_entry->deps.begin(), arg0->quad_entry->deps.end());
		entry->deps.emplace_back(arg0->quad_entry);
	}
	if (nullptr != arg1->quad_entry)
	{
		entry->deps.insert(entry->deps.end(), arg1->quad_entry->deps.begin(), arg1->quad_entry->deps.end());
		entry->deps.emplace_back(arg1->quad_entry);
	}

	Stack_Push(new StackEntry{ type, entry->res, entry });
	QuadTable_AddEntry(entry);
}
void Code_BoolComparison(OpEnum op)
{
	auto arg1 = Stack_Pop();
	auto arg0 = Stack_Pop();

	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::BOOL_EXP;
	entry->c0 = Util_GetNewLabel();
	entry->c1 = Util_GetNewLabel();
	entry->res = arg0->value // condition
		+ " " + Util_GetOpString(op) + " "
		+ arg1->value;

	if (nullptr != arg0->quad_entry)
	{
		entry->deps.insert(entry->deps.end(), arg0->quad_entry->deps.begin(), arg0->quad_entry->deps.end());
		entry->deps.emplace_back(arg0->quad_entry);
	}
	if (nullptr != arg1->quad_entry)
	{
		entry->deps.insert(entry->deps.end(), arg1->quad_entry->deps.begin(), arg1->quad_entry->deps.end());
		entry->deps.emplace_back(arg1->quad_entry);
	}

	QuadTable_AddEntry(entry);
	Stack_Push(new StackEntry{ TypeEnum::QUAD_ENTRY, "", entry });
}
void Code_LogicalNot()
{
	auto arg0 = Stack_Pop();

	if (TypeEnum::QUAD_ENTRY != arg0->type)
	{
		Util_FixBooleanValue(arg0->value);

		auto entry = new QuadEntry{};
		entry->id = CURRENT_TABLE_COUNT;
		entry->type = QuadEntryTypeEnum::BOOL_EXP;
		entry->c0 = Util_GetNewLabel();
		entry->c1 = Util_GetNewLabel();
		entry->res = arg0->value;
		arg0->quad_entry = entry;
		arg0->type = TypeEnum::QUAD_ENTRY;
		QuadTable_AddEntry(entry);
	}

	auto fall_label = Util_GetNewLabel();
	auto temp = Util_GetNewTemp();
	DeclList_Add(temp, TypeEnum::BOOL);

	auto l0 = Util_GetNewLabel();
	auto l1 = Util_GetNewLabel();

	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::BOOL_EXP;
	entry->c0 = Util_GetNewLabel();
	entry->c1 = Util_GetNewLabel();
	entry->res = temp;
	auto other = arg0->quad_entry;
	entry->code = "if ( " + other->res + " ) goto " + l0 + ";\n\t"
		+ "goto " + l1 + ";\n\t"
		+ l0 + ": " + temp + " = 0;\n\t"
		+ "goto " + fall_label + ";\n\t"
		+ l1 + ": " + temp + " = 1\n\t"
		+ fall_label + ": ";

	entry->deps.insert(entry->deps.end(), other->deps.begin(), other->deps.end());
	entry->deps.emplace_back(other);

	QuadTable_AddEntry(entry);
	Stack_Push(new StackEntry{ TypeEnum::QUAD_ENTRY, "", entry });
}
void Code_LogicalOR()
{
	auto arg1 = Stack_Pop();
	auto arg0 = Stack_Pop();

	if (TypeEnum::QUAD_ENTRY != arg0->type)
	{
		Util_FixBooleanValue(arg0->value);

		auto entry = new QuadEntry{};
		entry->id = CURRENT_TABLE_COUNT;
		entry->type = QuadEntryTypeEnum::BOOL_EXP;
		entry->c0 = Util_GetNewLabel();
		entry->c1 = Util_GetNewLabel();
		entry->res = arg0->value;
		arg0->quad_entry = entry;
		arg0->type = TypeEnum::QUAD_ENTRY;
		QuadTable_AddEntry(entry);
	}
	if (TypeEnum::QUAD_ENTRY != arg1->type)
	{
		Util_FixBooleanValue(arg1->value);

		auto entry = new QuadEntry{};
		entry->id = CURRENT_TABLE_COUNT;
		entry->type = QuadEntryTypeEnum::BOOL_EXP;
		entry->c0 = Util_GetNewLabel();
		entry->c1 = Util_GetNewLabel();
		entry->res = arg1->value;
		arg1->quad_entry = entry;
		arg1->type = TypeEnum::QUAD_ENTRY;
		QuadTable_AddEntry(entry);
	}

	auto fall_label = Util_GetNewLabel();
	arg0->quad_entry->code.append("if ( " + arg0->quad_entry->res + " ) goto " + arg0->quad_entry->c0 + ";\n\t"
		+ "goto " + arg0->quad_entry->c1 + ";\n\t"
		+ arg0->quad_entry->c0 + ": goto " + arg1->quad_entry->c0 + ";\n\t"
		+ arg0->quad_entry->c1 + ": goto " + fall_label + ";\n\t"
		+ fall_label + ": ");

	arg1->quad_entry->deps.insert(arg1->quad_entry->deps.end(), arg0->quad_entry->deps.begin(), arg0->quad_entry->deps.end());
	arg1->quad_entry->deps.emplace_back(arg0->quad_entry);

	Stack_Push(arg1);
}
void Code_LogicalAnd()
{
	auto arg1 = Stack_Pop();
	auto arg0 = Stack_Pop();

	if (TypeEnum::QUAD_ENTRY != arg0->type)
	{
		Util_FixBooleanValue(arg0->value);

		auto entry = new QuadEntry{};
		entry->id = CURRENT_TABLE_COUNT;
		entry->type = QuadEntryTypeEnum::BOOL_EXP;
		entry->c0 = Util_GetNewLabel();
		entry->c1 = Util_GetNewLabel();
		entry->res = arg0->value;
		arg0->quad_entry = entry;
		arg0->type = TypeEnum::QUAD_ENTRY;
		QuadTable_AddEntry(entry);
	}
	if (TypeEnum::QUAD_ENTRY != arg1->type)
	{
		Util_FixBooleanValue(arg1->value);

		auto entry = new QuadEntry{};
		entry->id = CURRENT_TABLE_COUNT;
		entry->type = QuadEntryTypeEnum::BOOL_EXP;
		entry->c0 = Util_GetNewLabel();
		entry->c1 = Util_GetNewLabel();
		entry->res = arg1->value;
		arg1->quad_entry = entry;
		arg1->type = TypeEnum::QUAD_ENTRY;
		QuadTable_AddEntry(entry);
	}

	auto fall_label = Util_GetNewLabel();
	arg0->quad_entry->code.append("if ( " + arg0->quad_entry->res + " ) goto " + arg0->quad_entry->c0 + ";\n\t"
		+ "goto " + arg0->quad_entry->c1 + ";\n\t"
		+ arg0->quad_entry->c0 + ": goto " + fall_label + ";\n\t"
		+ arg0->quad_entry->c1 + ": goto " + arg1->quad_entry->c1 + ";\n\t"
		+ fall_label + ": ");

	arg1->quad_entry->deps.insert(arg1->quad_entry->deps.end(), arg0->quad_entry->deps.begin(), arg0->quad_entry->deps.end());
	arg1->quad_entry->deps.emplace_back(arg0->quad_entry);

	Stack_Push(arg1);
}
void Code_Assignment()
{
	auto arg1 = Stack_Pop();
	auto arg0 = Stack_Pop();

	auto type = arg0->type;
	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::ASSIGN_EXP;

	if (TypeEnum::QUAD_ENTRY == arg1->type)
	{
		auto new_label = Util_GetNewLabel();
		auto other = arg1->quad_entry;
		entry->code = "\n\tif ( "
			+ other->res
			+ " ) goto " + other->c0 + ";\n\t"
			+ "goto " + other->c1 + ";\n\t"
			+ "\n\t" + other->c0 + ": "
			+ arg0->value + " = 1;\n\t"
			+ "goto " + new_label + ";\n\t"
			+ "\n\t" + other->c1 + ": "
			+ arg0->value + " = 0;\n\t"
			+ new_label + ": ";
	}
	else
	{
		Util_FixBooleanValue(arg1->value);
		entry->code = arg0->value + " = "
			+ (arg1->type != type ? "( " + Util_GetTypeString(type) + " )" : "") + arg1->value + ";\n\t";
	}

	QuadTable_AddEntry(entry);
}
void Code_Else()
{
	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::ELSE_EXP;
	auto stack_entry = new StackEntry{ TypeEnum::QUAD_ENTRY, "", entry };
	auto top_index = Util_GetQuadEntryIndex(Stack_Peek()->quad_entry);
	Stack_Push(stack_entry);
	stack_entry->quad_index = top_index;
}
void Code_ElseIF()
{
	auto top = Stack_Peek();
	if (TypeEnum::QUAD_ENTRY != top->type)
	{
		Util_FixBooleanValue(top->value);

		auto entry = new QuadEntry{};
		entry->id = CURRENT_TABLE_COUNT;
		entry->c0 = Util_GetNewLabel();
		entry->c1 = Util_GetNewLabel();
		entry->res = top->value;
		top->type = TypeEnum::QUAD_ENTRY;
		top->quad_entry = QuadTable_AddEntry(entry);
	}
	top->quad_index = Util_GetQuadEntryIndex(top->quad_entry);
	top->quad_entry->type = QuadEntryTypeEnum::ELSEIF_EXP;
}
void Code_IF()
{
	auto label = Util_GetNewLabel();

	auto if_entry = new QuadEntry{};
	if_entry->id = CURRENT_TABLE_COUNT;
	if_entry->type = QuadEntryTypeEnum::IF_EXP;
	if_entry->code = label + ": ";

	int begin_index = -1;
	while (true)
	{
		auto top = Stack_Pop();
		if (TypeEnum::QUAD_ENTRY != top->type)
		{
			Util_FixBooleanValue(top->value);

			auto entry = g.quad_table[top->quad_index];
			auto l0 = Util_GetNewLabel();
			auto l1 = Util_GetNewLabel();
			entry->code = "\n\tif ( "
				+ top->value + " ) goto "
				+ l0 + ";\n\t" + "goto "
				+ l1 + ";\n\t"
				+ "\n\t" + l0 + ": " + entry->code;

			QuadEntry * last_entry;
			if (-1 != begin_index)
				last_entry = g.quad_table[begin_index];
			else
				last_entry = g.quad_table[CURRENT_TABLE_COUNT - 1];

			last_entry->code.append("goto " + label + ";\n\t");
			last_entry->code.append(l1 + ": ");
			break;
		}
		else if (QuadEntryTypeEnum::BOOL_EXP == top->quad_entry->type)
		{
			auto entry = top->quad_entry;
			entry->code = "\n\tif ( "
				+ entry->res + " ) goto "
				+ entry->c0 + ";\n\t" + "goto "
				+ entry->c1 + ";\n\t"
				+ "\n\t" + entry->c0 + ": ";

			QuadEntry * last_entry;
			if (-1 != begin_index)
				last_entry = g.quad_table[begin_index];
			else
				last_entry = g.quad_table[g.quad_table.size() - 1];

			last_entry->code.append("goto " + label + ";\n\t");
			last_entry->code.append(entry->c1 + ": ");
			break;
		}
		else if (QuadEntryTypeEnum::ELSEIF_EXP == top->quad_entry->type)
		{
			begin_index = top->quad_index;

			auto entry = top->quad_entry;
			entry->code = "\n\tif ( "
				+ entry->res + " ) goto "
				+ entry->c0 + ";\n\t" + "goto "
				+ entry->c1 + ";\n\t"
				+ "\n\t" + entry->c0 + ": ";

			auto begin_entry = g.quad_table[top->quad_index];
			begin_entry->code.append("goto " + label + ";\n\t");
			begin_entry->code.append(entry->c1 + ": ");
		}
		else if (QuadEntryTypeEnum::ELSE_EXP == top->quad_entry->type)
		{
			begin_index = top->quad_index;

			auto entry = top->quad_entry;
			entry->code.append("goto " + label + ";\n\t");
		}
	}

	QuadTable_AddEntry(if_entry);
}
QuadEntry * Code_FindDependancy(QuadEntry * entry)
{
	if (0 == entry->deps.size())
		return entry;

	for (auto itr = g.quad_table.begin(); itr != g.quad_table.end(); ++itr)
	{
		auto first = *itr;
		for (auto itr1 = entry->deps.begin(); itr1 != entry->deps.end(); ++itr1)
		{
			auto second = *itr1;
			if (second == first)
				return second;
		}
	}

	return entry;
}
void Code_While()
{
	auto while_entry = new QuadEntry{};
	while_entry->id = CURRENT_TABLE_COUNT;
	while_entry->type = QuadEntryTypeEnum::WHILE_EXP;

	auto top = Stack_Pop();

	QuadEntry * entry = nullptr;
	std::string l0, l1;
	std::string name;

	if (TypeEnum::QUAD_ENTRY != top->type)
	{
		Util_FixBooleanValue(top->value);

		entry = g.quad_table[top->quad_index];
		name = top->value;
		l0 = Util_GetNewLabel();
		l1 = Util_GetNewLabel();
	}
	else if (QuadEntryTypeEnum::BOOL_EXP == top->quad_entry->type)
	{
		entry = top->quad_entry;
		name = entry->res;
		l0 = entry->c0;
		l1 = entry->c1;
	}

	entry->code = "\n\tif ( "
		+ name + " ) goto "
		+ l0 + ";\n\t" + "goto "
		+ l1 + ";\n\t"
		+ "\n\t" + l0 + ": ";

	auto new_label = Util_GetNewLabel();
	while_entry->code = "goto " + new_label + ";\n\t"
		+ l1 + ": ";

	// real begin
	int search_index = Util_GetQuadEntryIndex(entry);
	auto begin_entry = Code_FindDependancy(g.quad_table[search_index]);
	begin_entry->code = new_label + ": " + begin_entry->code;

	QuadTable_AddEntry(while_entry);
}
void Code_For()
{
	auto for_entry = new QuadEntry{};
	for_entry->id = CURRENT_TABLE_COUNT;
	for_entry->type = QuadEntryTypeEnum::FOR_EXP;
	auto check_label = Util_GetNewLabel();
	auto start_label = Util_GetNewLabel();
	auto end_label = Util_GetNewLabel();

	// info about for loop
	std::string counter_var = Stack_Pop()->value;
	auto ending_entry = Stack_Pop();
	std::string steps = ending_entry->value;
	std::string end_range = Stack_Pop()->value;

	auto initial_entry = Stack_Pop();
	std::string begin_range = initial_entry->value;

	DeclList_Add(counter_var, TypeEnum::REAL);

	for_entry->code = counter_var + " = " + counter_var + " + " + steps + ";\n\t"
		+ "goto " + check_label + ";\n\t"
		+ end_label + ": ";

	// end
	auto end_entry = g.quad_table[ending_entry->quad_index];
	end_entry->code =
		check_label + ": "
		+ "if ( " + counter_var + " < " + end_range + " ) goto " + start_label + ";\n\t"
		+ "goto " + end_label + ";\n\t"
		+ start_label + ": "
		+ end_entry->code;

	// real begin
	auto begin_entry = Code_FindDependancy(g.quad_table[initial_entry->quad_index]);
	if (initial_entry->quad_entry)
	{
		begin_entry->code.append(
			counter_var + " = " + begin_range + ";\n\t"
		);
	}
	else
	{
		begin_entry->code =
			counter_var + " = " + begin_range + ";\n\t"
			+ begin_entry->code;
	}

	QuadTable_AddEntry(for_entry);
}
void Code_FuncDecl(bool has_ret)
{
	auto func_name_ptr = Stack_Pop();
	int func_begin_index = g.last_func;
	int func_end_index = func_name_ptr->quad_index - 1;

	std::string footer = "";
	auto func_name = func_name_ptr->value;

	// pop params
	std::string args = "";
	while (g.formal_argument_counter > 0)
	{
		auto id = Stack_Pop()->value;
		auto type = Stack_Pop()->type;

		DeclList_Add(id, type);

		args += id + " = " + "POP();\n\t";
		--g.formal_argument_counter;
	}
	args += "\n\t";

	std::string code = "";
	code += args + "\n\n\t";

	if (has_ret)
		Stack_Pop(); // func ret type

	for (int i = func_begin_index; i < func_name_ptr->quad_index; ++i)
	{
		auto entry = g.quad_table[i];
		if (QuadEntryTypeEnum::PRINT_EXP == entry->type && MT_EMPTY_ARG == entry->c0)
			Code_Print(entry);
	}

	// header
	auto func_begin = g.quad_table[func_begin_index];
	code = func_name + ": \n\t" + code;
	func_begin->code = code + func_begin->code;

	// footer
	if ("main" == func_name || "_main" == func_name)
		footer += "goto end;\n\t";
	auto func_end_ptr = g.quad_table[func_end_index];
	func_end_ptr->code += footer;
}
void Code_FuncCall()
{
	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::FUNC_CALL;

	auto ret_label = Util_GetNewLabel();
	std::string code = "PUSH_LABEL( " + ret_label + " );\n\t";
	auto func_name = Stack_Pop()->value;

	// store program state
	std::string decls = "";
	std::vector<std::string> decls_id;
	code += "\n\t// store program state\n\t";
	for (auto itr = g.decls.rbegin(); itr != g.decls.rend(); ++itr)
	{
		auto id = (*itr)->id;
		decls += "PUSH( " + id + " );\n\t";
		decls_id.push_back(id);
	}
	code += decls + "\n\t";

	// push args
	code += "\n\t// push args\n\t";
	std::string args = "";
	while (g.actual_arguments_counter > 0)
	{
		auto id = Stack_Pop()->value;
		args = "PUSH( " + id + " );\n\t" + args;
		--g.actual_arguments_counter;
	}
	code += args;

	// return label
	code += "\n\t// return label\n\t";
	code += "goto " + func_name + ";\n\t";
	auto ret_temp = Util_GetNewTemp();
	DeclList_Add(ret_temp, TypeEnum::REAL);

	// return value
	code += "\n\t// return value\n\t";
	code += ret_label + ": " + ret_temp + " = POP();\n\t";

	// restore program state
	code += "\n\t// restore program state\n\t";
	for (auto itr = decls_id.rbegin(); itr != decls_id.rend(); ++itr)
	{
		auto id = *itr;
		code += id + " = " + "POP();\n\t";
	}

	Stack_Push(new StackEntry{ TypeEnum::REAL, ret_temp });

	entry->code = code;
	QuadTable_AddEntry(entry);
}
void Code_Return()
{
	auto entry = new QuadEntry{};
	entry->id = CURRENT_TABLE_COUNT;
	entry->type = QuadEntryTypeEnum::RETURN_EXP;

	auto ret_value = Stack_Pop();

	std::string code = "ret_address = POP_LABEL();\n\t";
	code += "PUSH( " + ret_value->value + " );\n\t";
	code += "goto *ret_address;\n\t";

	entry->code = code;
	QuadTable_AddEntry(entry);
}
void Code_AddPrint(std::string text)
{
	size_t first_brace = text.find_first_of('{');
	size_t last_brace = text.find_last_of('}');

	if (std::string::npos != first_brace && std::string::npos != last_brace)
	{
		auto entry = new QuadEntry{};
		entry->id = CURRENT_TABLE_COUNT;
		entry->type = QuadEntryTypeEnum::PRINT_EXP;
		entry->res = text.substr(first_brace + 1, last_brace - first_brace - 1); // token
		QuadTable_AddEntry(entry);
	}
}
void Code_Print(QuadEntry * entry)
{
	entry->c0 = "processed";

	auto token = entry->res;
	std::string print_code = "";

	auto var_entry = DeclList_Lookup(token);
	if (nullptr != var_entry)
		print_code = "printf(\"" + Util_GetTypePrintToken(var_entry->type) + "\\n\", " + token + ");\n\t";
	else // literal
		print_code = "printf(\"" + token + "\\n\");\n\t";

	entry->code.assign(print_code);
}
