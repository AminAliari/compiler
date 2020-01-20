%{
#include "common.hpp"

#define g Program_GetGlobal()

// ------- from scanner ------ //
extern FILE * yyin;
extern char * yytext;

extern std::string data;
extern std::string str_data;
extern std::stack<std::string> ids;
// --------------------------- //

std::string last_string = MT_INVALID;

int yylex(void);

void yyerror(char const * input);
void print(char const * input);

void Push_ID()
{
	auto id = ids.top();
	ids.pop();
	auto entry = DeclList_Lookup(id);
	auto type = nullptr == entry ? TypeEnum::ID : entry->type;
	Stack_Push(new StackEntry{type, id});
}

void Push_VarListItem(bool has_value)
{
	auto id = ids.top();
	ids.pop();
	auto type = has_value ? TypeEnum::ID_EXP_TUPLE : TypeEnum::ID;
	Stack_Push(new StackEntry{type, id});
}
%}

// ------- tokens ------- //
%start program
%token ID
%token INT
%token REAL
%token STRING
%token CLASS
%token REFERENCE
%token STATIC
%token INT_TYPE
%token REAL_TYPE
%token BOOL_TYPE
%token STRING_TYPE
%token VOID
%token TRUE
%token FALSE
%token PRINT
%token RETURN
%token BREAK
%token CONTINUE
%token IF
%token ELSE
%token ELSEIF
%token WHILE
%token FOR
%token TO
%token IN
%token STEPS
%right ASSIGNMENT
%left OR
%left AND
%left BITWISE_OR
%left BITWISE_AND
%left EQ
%left NE
%left GT
%left GE
%left LT
%left LE
%left SHIFT_RIGHT
%left SHIFT_LEFT
%left MINUS
%left PLUS
%left DIV
%left MUL
%left MOD
%left POW
%left BITWISE_NOT
%left NOT
%token LCB
%token RCB
%token LP
%token RP
%token DOT
%token SEMICOLON
%token COMMA

%%

// grammar rules
program : macros classes { print("program : macros classes"); }

macros : macros macro { print("macros : macros macro"); }
		| /* lambda */ { print("macros : lambda"); }

macro : reference { print("macro : reference"); }

reference : REFERENCE STRING { print("reference : REFERENCE STRING"); }

classes : classes class { print("classes : classes class"); }
		| /* lambda */ { print("classes : lambda"); }

class : CLASS ID LCB symbol_decs RCB { print("class : CLASS ID {symbol_decs}"); }

symbol_decs : symbol_decs symbol_dec { print("symbol_decs : symbol_decs symbol_dec"); }
			| /* lambda */ { print("symbol_decs : lambda"); }

symbol_dec : var_dec { print("symbol_dec : var_dec"); }
			| func_dec { print("symbol_dec : func_dec"); }

var_dec : var_type var_list SEMICOLON { print("var_dec : var_type var_list;"); Code_DeclareVarList(); }

var_type : return_type { print("var_type : return_type"); }
			| STATIC return_type { print("var_type : STATIC return_type"); }

return_type : INT_TYPE { print("return_type : INT_TYPE"); Stack_Push(new StackEntry{TypeEnum::INT, Util_GetTypeString(TypeEnum::INT)}); }
			| REAL_TYPE { print("return_type : REAL_TYPE"); Stack_Push(new StackEntry{TypeEnum::REAL, Util_GetTypeString(TypeEnum::REAL)});}
			| BOOL_TYPE { print("return_type : BOOL_TYPE"); Stack_Push(new StackEntry{TypeEnum::BOOL, Util_GetTypeString(TypeEnum::BOOL)});}
			| STRING_TYPE { print("return_type : STRING_TYPE"); }
			| ID { print("return_type : ID"); Push_ID(); }

var_list : var_list COMMA var_list_item { print("var_list : var_list, var_list_item"); }
			| var_list_item { print("var_list : var_list_item"); }

var_list_item : ID 
				{
					print("var_list_item : ID"); 
					Push_VarListItem(false); 
					++g.var_list_item_counter;
				}
				| 
				ID ASSIGNMENT exp 
				{
					print("var_list_item : ID = exp"); 
					Push_VarListItem(true);
					++g.var_list_item_counter;
				}

func_dec : var_type func_body { print("func_dec : func_body"); Code_FuncDecl(true); }
			| VOID func_body { print("func_dec : VOID func_body"); Code_FuncDecl(false); }
			| STATIC VOID func_body { print("func_dec : STATIC VOID func_body"); Code_FuncDecl(false); }

func_body : ID LP formal_arguments RP block
			{
				print("func_body : ID ( formal_arguments ) block");
				Push_ID(); 
			}

formal_arguments : formal_arguments_list
				 {
					print("formal_arguments : formal_arguments_list"); 
					g.last_func = CURRENT_TABLE_COUNT; 
				 }
				 | /* lambda */
				 {
					print("formal_arguments : lambda");
					g.last_func = CURRENT_TABLE_COUNT; 
				 }

formal_arguments_list : formal_arguments_list COMMA formal_argument { print("formal_arguments_list : formal_arguments_list, formal_argument");  }
						| formal_argument { print("formal_arguments_list : formal_argument"); }

formal_argument : return_type ID 
				{ 
					print("formal_argument : statements_list ID"); 
					Push_ID(); 
					++g.formal_argument_counter;
				}

block : LCB statements_list RCB { print("block : { statments_list }"); }
		| statement { print("block : statement"); }

statements_list : statements_list statement  { print("statements_list : statements_list statement"); }
				| /* lambda */ { print("statements_list : lambda"); }

statement : SEMICOLON { print("statement : SEMICOLON"); } 
			| exp SEMICOLON { print("statement : exp;"); }
			| assignment { print("statement : assignment"); }
			| print { print("statement : print"); }
			| statement_var_dec { print("statement : statement_var_dec"); }
			| if { print("statement : if"); }
			| for { print("statement : for"); }
			| while { print("statement : while"); }
			| return { print("statement : return"); }
			| break { print("statement : break"); }
			| continue { print("statement : continue"); }

assignment : lvalue ASSIGNMENT exp SEMICOLON { print("assignment : lvalue = exp;"); Code_Assignment(); }

lvalue : ID { print("lvalue : ID"); Push_ID(); }
		| ID DOT ID { print("lvalue : ID.ID"); /* not supported */ }

print : PRINT LP STRING RP SEMICOLON { print("print : PRINT ( STRING );"); Code_AddPrint(str_data); }

statement_var_dec : return_type var_list SEMICOLON { print("statement_var_dec : return_type var_list;"); Code_DeclareVarList(); }

if : IF LP exp RP block elseif_blocks else_block { print("if : IF ( exp ) block elseif_blocks else_block"); Code_IF(); }

elseif_blocks : elseifs { print("elseif_blocks : elseifs"); }
				| /* lambda */ { print("elseif_blocks : lambda"); }

elseifs : elseifs elseif { print("elseifs : elseifs elseif "); }
		| elseif { print("elseifs : elseif "); }
elseif : ELSEIF LP exp RP block { print("elseif : ELSEIF ( exp ) block "); Code_ElseIF(); }

else_block : ELSE block { print("else_block : ELSE block "); Code_Else(); }
			| /* lambda */ { print("else_block : lambda"); }

for : FOR LP ID IN exp TO exp STEPS exp RP block 
	{ 
		print("for : FOR ( ID IN exp TO exp STEPS exp ) block");
		Push_ID();
		Code_For();
	}

while : WHILE LP exp RP block { print("while : WHILE ( exp ) block"); Code_While(); }

return : RETURN exp SEMICOLON { print("return : RETURN exp;"); Code_Return(); }

break : BREAK SEMICOLON { print("break : BREAK;"); }

continue : CONTINUE SEMICOLON { print("continue : CONTINUE;"); }

exp : INT { print("exp : INT"); Stack_Push(new StackEntry{TypeEnum::INT, data});}
	| REAL { print("exp : REAL"); Stack_Push(new StackEntry{TypeEnum::REAL, data}); }
	| TRUE { print("exp : TRUE"); Stack_Push(new StackEntry{TypeEnum::BOOL, "true"}); }
	| FALSE { print("exp : FALSE"); Stack_Push(new StackEntry{TypeEnum::BOOL, "false"}); }
	| STRING { print("exp : STRING"); last_string = str_data; }
	| lvalue { print("exp : lvalue"); }
	| binary_operation { print("exp : binary_operation"); }
	| logical_operation { print("exp : logical_operation"); }
	| comparison_operation { print("exp : comparison_operation"); }
	| bitwise_operation { print("exp : bitwise_operation"); }
	| unary_operation { print("exp : unary_operation"); }
	| LP exp RP { print("exp : ( exp )"); }
	| function_call { print("exp : function_call"); }

binary_operation :  exp PLUS exp { print("binary_operation : exp + exp"); Code_ArithmeticBinary(OpEnum::PLUS); }
					| exp MINUS exp { print("binary_operation : exp - exp"); Code_ArithmeticBinary(OpEnum::MINUS); }
					| exp MUL exp { print("binary_operation : exp * exp"); Code_ArithmeticBinary(OpEnum::MUL); }
					| exp DIV exp { print("binary_operation : exp / exp"); Code_ArithmeticBinary(OpEnum::DIV); }
					| exp MOD exp { print("binary_operation : exp % exp"); Code_ArithmeticBinary(OpEnum::MOD); }
					| exp POW exp { print("binary_operation : exp ^ exp"); Code_ArithmeticBinary(OpEnum::POW); }
					| exp SHIFT_LEFT exp { print("binary_operation : exp << exp"); Code_ArithmeticBinary(OpEnum::SHIFT_LEFT); }
					| exp SHIFT_RIGHT exp { print("binary_operation : exp >> exp"); Code_ArithmeticBinary(OpEnum::SHIFT_RIGHT); }

logical_operation : exp AND exp { print("logical_operation : exp && exp"); Code_LogicalAnd(); }
					| exp OR exp { print("logical_operation : exp || exp"); Code_LogicalOR(); }

comparison_operation : exp LT exp { print("comparison_operation : exp < exp"); Code_BoolComparison(OpEnum::LT); }
						| exp LE exp { print("comparison_operation : exp <= exp"); Code_BoolComparison(OpEnum::LE); }
						| exp GT exp { print("comparison_operation : exp > exp"); Code_BoolComparison(OpEnum::GT); }
						| exp GE exp { print("comparison_operation : exp >= exp"); Code_BoolComparison(OpEnum::GE); }
						| exp EQ exp { print("comparison_operation : exp == exp"); Code_BoolComparison(OpEnum::EQ); }
						| exp NE exp { print("comparison_operation : exp != exp"); Code_BoolComparison(OpEnum::NE); }

bitwise_operation : exp BITWISE_AND exp { print("bitwise_operation : exp & exp"); Code_ArithmeticBinary(OpEnum::BITWISE_AND); }
					| exp BITWISE_OR exp { print("bitwise_operation : exp | exp"); Code_ArithmeticBinary(OpEnum::BITWISE_OR); }

unary_operation : MINUS exp { print("unary_operation : -exp"); Code_ArithmeticUnary(OpEnum::UMINUS);}
				| NOT exp { print("unary_operation : !exp"); Code_LogicalNot(); }
				| BITWISE_NOT exp { print("unary_operation : ~exp"); Code_ArithmeticUnary(OpEnum::BITWISE_NOT);}

function_call : ID function_call_body 
				{ 
					print("function_call : ID function_call_body");
					Push_ID();
					Code_FuncCall(); 
				}
				
				| ID DOT ID function_call_body{ print("function_call : ID.ID function_call_body"); /* not supported */ }

function_call_body: LP actual_arguments RP { print("function_call_body : ( actual_arguments )"); }

actual_arguments : actual_arguments_list { print("actual_arguments : actual_arguments_list"); }
					| /* lambda */ { print("actual_arguments : lambda"); }

actual_arguments_list : actual_arguments_list COMMA exp { print("actual_arguments_list : actual_arguments_list, exp"); ++g.actual_arguments_counter; }
						| exp { print("actual_arguments_list : exp"); ++g.actual_arguments_counter; }

%%

void print(char const * input)
{
	printf("[matched grammer]: %s\n", input);
}

void yyerror(char const * input)
{
	printf("[parser error]: %s, lexeme=%s\n", input, yytext);
}

int main()
{
	Program_Initialize();
	yyin = fopen("inputs/input.txt", "r");
	if (yyin)
	{
		printf("[parser] file opened.\n");
		yyparse();
		fclose(yyin);
		SymbolTable_Print();
		Program_PrintCode();
	}
	else
		printf("[error] could not read the file=input.txt\n");

	getchar();
	return 0;
}