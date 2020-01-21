# Compiler
Java-like language compiler for Compiler design course at Amirkabir University of Technology (polytechnic)

## Technologies
- Lex (Lexical analyser)
- Yacc
- GCC
- C++17
- Premake build system

---

## How to build
just run this bat file.
```
win-make-vs2019.bat
```

---

## Example code
output code is in __C__, and has to compile with __GCC__.
you can find more examples [here.](https://github.com/AminAliari/Compiler/tree/master/Compiler/inputs)

__input__:
```java
class Program
{
	static void _main()
	{
		int num = 0;

		num = 5523;
		num = getPalindrome(num);
	
		print("{num}");
	}
	
	static int getPalindrome(int num)
	{
		int pal = 0;
		pal = 0;
		
		while(num >= 1)
		{
			int units;
			units = getUnit(num);
			pal = pal * 10 + units;
			num = (num - units) / 10;
		}
		
		return pal;
	}

	static int getUnit(int num)
	{
		int q = 0;
		int r = 0;
		
		q = 0;
		r = 0;
		
		while(q * 10 < num)
			q = q + 1;
		
		if(num == q * 10)
			return 0;
		
		q = q - 1;
		
		return num - q * 10;
	}
}
```
---
__output__:
```c
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 1000

#define PUSH(T0) --stack_top;\
*stack_top = T0
#define POP() *stack_top;\
++stack_top;

#define PUSH_LABEL(L0) --labels_top;\
*labels_top = &&L0
#define POP_LABEL() *labels_top;\
++labels_top;

int main()
{
	void * ret_address;
	double * stack_top = (double*) malloc(STACK_MAX * sizeof(double));
	stack_top += STACK_MAX;

	void** labels_top = (void **) malloc(STACK_MAX * sizeof(void *));
	labels_top += STACK_MAX;


	// ------------ declerations ------------  //
	int num = 0;
	double T0 = 0.0;
	int pal = 0;
	int units = 0;
	double T1 = 0.0;
	int T2 = 0;
	int T3 = 0;
	int T4 = 0;
	int T5 = 0;
	int q = 0;
	int r = 0;
	int T6 = 0;
	int T7 = 0;
	int T8 = 0;
	int T9 = 0;
	int T10 = 0;
	int T11 = 0;
	// ----------- end of declerations ----------- 

	_main:
	num = 5523;
	PUSH_LABEL( L0 );
	
	// store program state
	PUSH( num );
	
	// push args
	PUSH( num );
	
	// return label
	goto getPalindrome;
	
	// return value
	L0: T0 = POP();
	
	// restore program state
	num = POP();
	num = ( int )T0;
	printf("%d\n", num);
	goto end;
	
	getPalindrome: 
	num = POP();
	pal = 0;
	L4: 
	if ( num >= 1 ) goto L1;
	goto L2;
	
	L1: PUSH_LABEL( L3 );
	
	// store program state
	PUSH( units );
	PUSH( pal );
	PUSH( T0 );
	PUSH( num );
	
	
	// push args
	PUSH( num );
	
	// return label
	goto getUnit;
	
	// return value
	L3: T1 = POP();
	
	// restore program state
	num = POP();
	T0 = POP();
	pal = POP();
	units = POP();
	units = ( int )T1;
	T2 = pal * 10;
	T3 = T2 + units;
	pal = T3;
	T4 = num - units;
	T5 = T4 / 10;
	num = T5;
	goto L4;
	L2: ret_address = POP_LABEL();
	PUSH( pal );
	goto *ret_address;
	
	getUnit: 
	num = POP();
	q = 0;
	r = 0;
	L7: T6 = q * 10;
	
	if ( T6 < num ) goto L5;
	goto L6;
	
	L5: T7 = q + 1;
	q = T7;
	goto L7;
	L6: T8 = q * 10;
	
	if ( num == T8 ) goto L8;
	goto L9;
	
	L8: ret_address = POP_LABEL();
	PUSH( 0 );
	goto *ret_address;
	goto L10;
	L9: L10: T9 = q - 1;
	q = T9;
	T10 = q * 10;
	T11 = num - T10;
	ret_address = POP_LABEL();
	PUSH( T11 );
	goto *ret_address;
	
	end: return 0;
}
```

---

## Grammer

```
program : macros classes

macros : macros macro 
       | /* lambda */

macro : reference 

reference : REFERENCE STRING
classes : classes class
        | /* lambda */

class : CLASS ID LCB symbol_decs RCB

symbol_decs : symbol_decs symbol_dec
	    | /* lambda */

symbol_dec : var_dec
	   | func_dec

var_dec : var_type var_list SEMICOLON

var_type : return_type
	 | STATIC return_type

return_type : INT_TYPE
	     | REAL_TYPE
	     | BOOL_TYPE
	     | STRING_TYPE
	     | ID

var_list : var_list COMMA var_list_item
	 | var_list_item

var_list_item : ID 
	      | ID ASSIGNMENT exp 

func_dec : var_type func_body
	 | VOID func_body
	 | STATIC VOID func_body

func_body : ID LP formal_arguments RP block

formal_arguments : formal_arguments_list
		 | /* lambda */

formal_arguments_list : formal_arguments_list COMMA formal_argument
			| formal_argument

formal_argument : return_type ID 

block : LCB statements_list RCB
		| statement

statements_list : statements_list statement
		| /* lambda */

statement : SEMICOLON
			| exp SEMICOLON
			| assignment
			| print
			| statement_var_dec
			| if
			| for
			| while
			| return
			| break
			| continue

assignment : lvalue ASSIGNMENT exp SEMICOLON

lvalue : ID
		| ID DOT ID

print : PRINT LP STRING RP SEMICOLON

statement_var_dec : return_type var_list SEMICOLON

if : IF LP exp RP block elseif_blocks else_block

elseif_blocks : elseifs
				| /* lambda */

elseifs : elseifs elseif
		| elseif
elseif : ELSEIF LP exp RP block

else_block : ELSE block
			| /* lambda */

for : FOR LP ID IN exp TO exp STEPS exp RP block 

while : WHILE LP exp RP block

return : RETURN exp SEMICOLON

break : BREAK SEMICOLON

continue : CONTINUE SEMICOLON

exp : INT
	| REAL
	| TRUE
	| FALSE
	| STRING
	| lvalue
	| binary_operation
	| logical_operation
	| comparison_operation
	| bitwise_operation
	| unary_operation
	| LP exp RP
	| function_call

binary_operation :  exp PLUS exp
					| exp MINUS exp { print("binary_operation : exp - exp");
					| exp MUL exp
					| exp DIV exp
					| exp MOD exp
					| exp POW exp
					| exp SHIFT_LEFT exp
					| exp SHIFT_RIGHT exp

logical_operation : exp AND exp
					| exp OR exp

comparison_operation : exp LT exp
					 | exp LE exp
					 | exp GT exp
					 | exp GE exp
					 | exp EQ exp
					 | exp NE exp

bitwise_operation : exp BITWISE_AND exp
					| exp BITWISE_OR exp

unary_operation : MINUS exp
				| NOT exp
				| BITWISE_NOT exp

function_call : ID function_call_body 
				| ID DOT ID function_call_body

function_call_body: LP actual_arguments RP

actual_arguments : actual_arguments_list
				 | /* lambda */

actual_arguments_list : actual_arguments_list COMMA exp
					  | exp
```

---

## Tokens

```
program
ID
INT
REAL
STRING
CLASS
REFERENCE
STATIC
INT_TYPE
REAL_TYPE
BOOL_TYPE
STRING_TYPE
VOID
TRUE
FALSE
PRINT
RETURN
BREAK
CONTINUE
IF
ELSE
ELSEIF
WHILE
FOR
TO
IN
STEPS
ASSIGNMENT
OR
AND
BITWISE_OR
BITWISE_AND
EQ
NE
GT
GE
LT
LE
SHIFT_RIGHT
SHIFT_LEFT
MINUS
PLUS
DIV
MUL
MOD
POW
BITWISE_NOT
NOT
LCB
RCB
LP
RP
DOT
SEMICOLON
COMMA
```
