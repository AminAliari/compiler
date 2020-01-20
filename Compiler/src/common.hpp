#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <stack>
#include <vector>
#include <string>

#define MT_EMPTY_ARG ""
#define MT_TRUE_VALUE "true"
#define MT_FALSE_VALUE "false"
#define MT_INVALID "INVALID"

#define CURRENT_TABLE_COUNT int(g.quad_table.size())

enum class TypeEnum
{
	BOOL,
	INT,
	REAL,
	STRING,
	ID,
	ID_EXP_TUPLE,
	FUNCTION,
	QUAD_ENTRY,
};

enum class QuadEntryTypeEnum
{
	ARIMETHIC_EXP,
	BOOL_EXP,
	IF_EXP,
	ELSEIF_EXP,
	ELSE_EXP,
	WHILE_EXP,
	FOR_EXP,
	ASSIGN_EXP,
	RETURN_EXP,
	FUNC_CALL,
	PRINT_EXP,
};

enum class OpEnum
{
	NONE,
	PLUS,
	MINUS,
	MUL,
	DIV,
	MOD, // int
	POW,
	SHIFT_LEFT, // int
	SHIFT_RIGHT, // int
	LOGICAL_AND,
	LOGICAL_OR,
	LT,
	LE,
	GT,
	GE,
	EQ,
	NE,
	BITWISE_AND, // int
	BITWISE_OR, // int
	UMINUS,
	LOGICAL_NOT,
	BITWISE_NOT, // int
};

struct QuadEntry
{
	int id = -1;
	QuadEntryTypeEnum type;
	std::string c0 = MT_EMPTY_ARG;
	std::string c1 = MT_EMPTY_ARG;
	std::string res = MT_EMPTY_ARG;
	std::string code = MT_EMPTY_ARG;
	std::vector<QuadEntry *> deps;
};

struct StackEntry
{
	TypeEnum type;
	std::string value;
	QuadEntry * quad_entry;
	int quad_index;
};

struct DeclEntry
{
	std::string id;
	TypeEnum type;
	std::string value;
};

struct TableEntry
{
	int id;
	std::string name;
};

struct SymbolTable
{
	int id = -1;
	std::vector<TableEntry *> entries;

	SymbolTable * parent = nullptr;
	SymbolTable * child = nullptr;
};

struct Global
{
	int rel_counter = 0;
	int temp_counter = 0;
	int label_counter = 0;
	int symbol_table_counter = 0;

	int last_func = 0;
	int var_list_item_counter = 0;
	int formal_argument_counter = 0;
	int actual_arguments_counter = 0;

	std::string st_log;
	SymbolTable * global_st;
	SymbolTable * current_st;

	std::stack<StackEntry *> stack;
	std::vector<DeclEntry *> decls;
	std::vector<QuadEntry *> quad_table;
};

// ------- Utils ------ //
void Util_CopyClipboard(std::string text);

std::string Util_GetNewTemp();
std::string Util_GetNewLabel();
int Util_GetNewSymbolTableId();
int Util_GetNewRelationId();

void Util_FixBooleanValue(std::string & value);

std::string Util_GetTypeString(TypeEnum type);
std::string Util_GetTypePrintToken(TypeEnum type);
std::string Util_GetOpString(OpEnum op);
bool Util_IsIntegerOnlyOp(OpEnum op);
std::string Util_GetTypeDefaultValue(TypeEnum type);
int Util_GetQuadEntryIndex(QuadEntry * entry);

// ------- Program ------ //
void Program_Initialize();
Global & Program_GetGlobal();
void Program_PrintCode();

// ------- Quad Table ------ //
QuadEntry * QuadTable_AddEntry(QuadEntry * entry);

// ------- Stack ------ //
void Stack_Push(StackEntry * entry);
StackEntry * Stack_Pop();
StackEntry * Stack_Peek();

// ------- Symbol Table ------ //
TableEntry * SymbolTable_AddEntry(std::string name);

SymbolTable * SymbolTable_Create();
void SymbolTable_SetCurrent(SymbolTable * st);
void SymbolTable_PopCurrent();
TableEntry * SymbolTable_Lookup(std::string name, SymbolTable * st);
void SymbolTable_Log(SymbolTable * st);
void SymbolTable_Print();

// ---------- Decleration list ---------- //
DeclEntry * DeclList_Add(std::string id, TypeEnum type, bool can_change = false);
DeclEntry * DeclList_Add(std::string id, TypeEnum type, std::string value, bool can_change = false);
DeclEntry * DeclList_Lookup(std::string id);

// ------- Code ------ //
TypeEnum Code_DecayType(TypeEnum t0, TypeEnum t1);

void Code_DeclareVarList();

void Code_ArithmeticUnary(OpEnum op);
void Code_ArithmeticBinary(OpEnum op);

void Code_BoolComparison(OpEnum op);
void Code_LogicalNot();
void Code_LogicalOR();
void Code_LogicalAnd();

void Code_Assignment();

void Code_Else();
void Code_ElseIF();
void Code_IF();

QuadEntry * Code_FindDependancy(QuadEntry * entry);
void Code_While();

void Code_For();

void Code_FuncDecl(bool has_ret);
void Code_FuncCall();
void Code_Return();

void Code_AddPrint(std::string text);
void Code_Print(QuadEntry * entry);
