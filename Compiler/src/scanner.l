%{

#include "common.hpp"

#define g Program_GetGlobal()

#define YY_NO_UNISTD_H
#include <io.h>
#define isatty(X) _isatty(X)
#include "rule.hpp"
extern "C" int yywrap ( void ) { return 1; }

std::string data;
std::string str_data;
std::stack<std::string> ids;

%}

digit [0-9]
letter [a-zA-Z_]
letter_digit [a-zA-Z0-9]
string \"([^"\n]|\\["\n])*\"
ws [ \t]+

%%

{ws} {}

0b([1-9][0-9]*|0) {
	data = std::to_string((int)strtol(yytext + 2, NULL, 2));
	return INT;
}

0x([1-9][0-9]*|0) {
	data = std::to_string((int)strtol(yytext + 2, NULL, 16));
	return INT;
}

[0-9]+"."[0-9]+ {
	data = yytext;
	return REAL;
}

[0-9]+ {
	data = yytext;
	return INT;
}

"//".* ;

"/*"([^*/]|[^*]"/"|"*"[^/]|"*")*"*/" ;

class {
	return CLASS;
}

reference {
	return REFERENCE;
}

static {
	return STATIC;
}

int {
	return INT_TYPE;
}

real {
	return REAL_TYPE;
}

bool {
	return BOOL_TYPE;
}

string {
	return STRING_TYPE;
}

void {
	return VOID;
}

true {
	return TRUE;
}

false  {
	return FALSE;
}

print {
	return PRINT;
}

return {
	return RETURN;
}

break {
	return BREAK;
}

continue {
	return CONTINUE;
}

if {
	return IF;
}

else {
	return ELSE;
}

elseif {
	return ELSEIF;
}

while {
	return WHILE;
}

for {
	return FOR;
}

to {
	return TO;
}

in {
	return IN;
}

steps {
	return STEPS;
}

\& {
	return BITWISE_AND;
}

\&& {
	return AND;
}

\| {
	return BITWISE_OR;
}

\|\| {
	return OR;
}

\! {
	return NOT;
}

\~ {
	return BITWISE_NOT;
}

\>> {
	return SHIFT_RIGHT;
}

\<< {
	return SHIFT_LEFT;
}

\= {
	return ASSIGNMENT;
}

\+ {
	return PLUS;
}

\- {
	return MINUS;
}

\* {
	return MUL;
}

\/ {
	return DIV;
}

\% {
	return MOD;
}

\^ {
	return POW;
}

\> {
	return GT;
}

\>= {
	return GE;
}

\< {
	return LT;
}

\<= {
	return LE;
}

\== {
	return EQ;
}

\!= {
	return NE;
}

\{ {
	SymbolTable_SetCurrent(SymbolTable_Create());
	return LCB;
}

\} {
	SymbolTable_PopCurrent();
	return RCB;
}

\( {
	return LP;
}

\) {
	return RP;
}

\. {
	return DOT;
}

\; {
	return SEMICOLON;
}

, {
	return COMMA;
}

{letter}({letter}|{digit})* {
	SymbolTable_AddEntry(yytext);
	ids.push(yytext);
	return ID;
}

{string} {
	str_data = yytext;
	return STRING;
}

[^ \>\>=\<\<=\==\!=\&\&&\|\||\!\~\+\-\*\>>\<<\=\/\%\^\t\n\{\}\(\)\.\;\,\"]+ {
	printf("[scanner]: error, token={%s}\n", yytext);
}

%%