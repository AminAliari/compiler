/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_RULE_HPP_INCLUDED
# define YY_YY_RULE_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INT = 259,                     /* INT  */
    REAL = 260,                    /* REAL  */
    STRING = 261,                  /* STRING  */
    CLASS = 262,                   /* CLASS  */
    REFERENCE = 263,               /* REFERENCE  */
    STATIC = 264,                  /* STATIC  */
    INT_TYPE = 265,                /* INT_TYPE  */
    REAL_TYPE = 266,               /* REAL_TYPE  */
    BOOL_TYPE = 267,               /* BOOL_TYPE  */
    STRING_TYPE = 268,             /* STRING_TYPE  */
    VOID = 269,                    /* VOID  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    PRINT = 272,                   /* PRINT  */
    RETURN = 273,                  /* RETURN  */
    BREAK = 274,                   /* BREAK  */
    CONTINUE = 275,                /* CONTINUE  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    ELSEIF = 278,                  /* ELSEIF  */
    WHILE = 279,                   /* WHILE  */
    FOR = 280,                     /* FOR  */
    TO = 281,                      /* TO  */
    IN = 282,                      /* IN  */
    STEPS = 283,                   /* STEPS  */
    ASSIGNMENT = 284,              /* ASSIGNMENT  */
    OR = 285,                      /* OR  */
    AND = 286,                     /* AND  */
    BITWISE_OR = 287,              /* BITWISE_OR  */
    BITWISE_AND = 288,             /* BITWISE_AND  */
    EQ = 289,                      /* EQ  */
    NE = 290,                      /* NE  */
    GT = 291,                      /* GT  */
    GE = 292,                      /* GE  */
    LT = 293,                      /* LT  */
    LE = 294,                      /* LE  */
    SHIFT_RIGHT = 295,             /* SHIFT_RIGHT  */
    SHIFT_LEFT = 296,              /* SHIFT_LEFT  */
    MINUS = 297,                   /* MINUS  */
    PLUS = 298,                    /* PLUS  */
    DIV = 299,                     /* DIV  */
    MUL = 300,                     /* MUL  */
    MOD = 301,                     /* MOD  */
    POW = 302,                     /* POW  */
    BITWISE_NOT = 303,             /* BITWISE_NOT  */
    NOT = 304,                     /* NOT  */
    LCB = 305,                     /* LCB  */
    RCB = 306,                     /* RCB  */
    LP = 307,                      /* LP  */
    RP = 308,                      /* RP  */
    DOT = 309,                     /* DOT  */
    SEMICOLON = 310,               /* SEMICOLON  */
    COMMA = 311                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_RULE_HPP_INCLUDED  */
