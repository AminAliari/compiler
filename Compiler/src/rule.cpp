/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

void Push_ID(bool enforce_decl = false)
{
	auto id = ids.top();
	ids.pop();
	auto entry = DeclList_Lookup(id);
	if (enforce_decl && nullptr == entry)
	{
		yyerror("undeclared identifier");
		exit(EXIT_FAILURE);
	}
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

#line 115 "rule.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "rule.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_CLASS = 7,                      /* CLASS  */
  YYSYMBOL_REFERENCE = 8,                  /* REFERENCE  */
  YYSYMBOL_STATIC = 9,                     /* STATIC  */
  YYSYMBOL_INT_TYPE = 10,                  /* INT_TYPE  */
  YYSYMBOL_REAL_TYPE = 11,                 /* REAL_TYPE  */
  YYSYMBOL_BOOL_TYPE = 12,                 /* BOOL_TYPE  */
  YYSYMBOL_STRING_TYPE = 13,               /* STRING_TYPE  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 23,                    /* ELSEIF  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_TO = 26,                        /* TO  */
  YYSYMBOL_IN = 27,                        /* IN  */
  YYSYMBOL_STEPS = 28,                     /* STEPS  */
  YYSYMBOL_ASSIGNMENT = 29,                /* ASSIGNMENT  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_BITWISE_OR = 32,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_AND = 33,               /* BITWISE_AND  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NE = 35,                        /* NE  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_GE = 37,                        /* GE  */
  YYSYMBOL_LT = 38,                        /* LT  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_SHIFT_RIGHT = 40,               /* SHIFT_RIGHT  */
  YYSYMBOL_SHIFT_LEFT = 41,                /* SHIFT_LEFT  */
  YYSYMBOL_MINUS = 42,                     /* MINUS  */
  YYSYMBOL_PLUS = 43,                      /* PLUS  */
  YYSYMBOL_DIV = 44,                       /* DIV  */
  YYSYMBOL_MUL = 45,                       /* MUL  */
  YYSYMBOL_MOD = 46,                       /* MOD  */
  YYSYMBOL_POW = 47,                       /* POW  */
  YYSYMBOL_BITWISE_NOT = 48,               /* BITWISE_NOT  */
  YYSYMBOL_NOT = 49,                       /* NOT  */
  YYSYMBOL_LCB = 50,                       /* LCB  */
  YYSYMBOL_RCB = 51,                       /* RCB  */
  YYSYMBOL_LP = 52,                        /* LP  */
  YYSYMBOL_RP = 53,                        /* RP  */
  YYSYMBOL_DOT = 54,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 55,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 56,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_macros = 59,                    /* macros  */
  YYSYMBOL_macro = 60,                     /* macro  */
  YYSYMBOL_reference = 61,                 /* reference  */
  YYSYMBOL_classes = 62,                   /* classes  */
  YYSYMBOL_class = 63,                     /* class  */
  YYSYMBOL_symbol_decs = 64,               /* symbol_decs  */
  YYSYMBOL_symbol_dec = 65,                /* symbol_dec  */
  YYSYMBOL_var_dec = 66,                   /* var_dec  */
  YYSYMBOL_var_type = 67,                  /* var_type  */
  YYSYMBOL_return_type = 68,               /* return_type  */
  YYSYMBOL_var_list = 69,                  /* var_list  */
  YYSYMBOL_var_list_item = 70,             /* var_list_item  */
  YYSYMBOL_func_dec = 71,                  /* func_dec  */
  YYSYMBOL_func_body = 72,                 /* func_body  */
  YYSYMBOL_formal_arguments = 73,          /* formal_arguments  */
  YYSYMBOL_formal_arguments_list = 74,     /* formal_arguments_list  */
  YYSYMBOL_formal_argument = 75,           /* formal_argument  */
  YYSYMBOL_block = 76,                     /* block  */
  YYSYMBOL_statements_list = 77,           /* statements_list  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_assignment = 79,                /* assignment  */
  YYSYMBOL_lvalue = 80,                    /* lvalue  */
  YYSYMBOL_print = 81,                     /* print  */
  YYSYMBOL_statement_var_dec = 82,         /* statement_var_dec  */
  YYSYMBOL_if = 83,                        /* if  */
  YYSYMBOL_elseif_blocks = 84,             /* elseif_blocks  */
  YYSYMBOL_elseifs = 85,                   /* elseifs  */
  YYSYMBOL_elseif = 86,                    /* elseif  */
  YYSYMBOL_else_block = 87,                /* else_block  */
  YYSYMBOL_for = 88,                       /* for  */
  YYSYMBOL_while = 89,                     /* while  */
  YYSYMBOL_return = 90,                    /* return  */
  YYSYMBOL_break = 91,                     /* break  */
  YYSYMBOL_continue = 92,                  /* continue  */
  YYSYMBOL_exp = 93,                       /* exp  */
  YYSYMBOL_binary_operation = 94,          /* binary_operation  */
  YYSYMBOL_logical_operation = 95,         /* logical_operation  */
  YYSYMBOL_comparison_operation = 96,      /* comparison_operation  */
  YYSYMBOL_bitwise_operation = 97,         /* bitwise_operation  */
  YYSYMBOL_unary_operation = 98,           /* unary_operation  */
  YYSYMBOL_function_call = 99,             /* function_call  */
  YYSYMBOL_function_call_body = 100,       /* function_call_body  */
  YYSYMBOL_actual_arguments = 101,         /* actual_arguments  */
  YYSYMBOL_actual_arguments_list = 102     /* actual_arguments_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   100,   101,   103,   105,   107,   108,   110,
     112,   113,   115,   116,   118,   120,   121,   123,   124,   125,
     126,   127,   129,   130,   132,   139,   146,   147,   148,   150,
     156,   162,   167,   168,   170,   177,   178,   180,   181,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     195,   197,   198,   200,   202,   204,   206,   207,   209,   210,
     211,   213,   214,   216,   223,   225,   227,   229,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   245,   246,   247,   248,   249,   250,   251,   252,   254,
     255,   257,   258,   259,   260,   261,   262,   264,   265,   267,
     268,   269,   271,   278,   280,   282,   283,   285,   286
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT", "REAL",
  "STRING", "CLASS", "REFERENCE", "STATIC", "INT_TYPE", "REAL_TYPE",
  "BOOL_TYPE", "STRING_TYPE", "VOID", "TRUE", "FALSE", "PRINT", "RETURN",
  "BREAK", "CONTINUE", "IF", "ELSE", "ELSEIF", "WHILE", "FOR", "TO", "IN",
  "STEPS", "ASSIGNMENT", "OR", "AND", "BITWISE_OR", "BITWISE_AND", "EQ",
  "NE", "GT", "GE", "LT", "LE", "SHIFT_RIGHT", "SHIFT_LEFT", "MINUS",
  "PLUS", "DIV", "MUL", "MOD", "POW", "BITWISE_NOT", "NOT", "LCB", "RCB",
  "LP", "RP", "DOT", "SEMICOLON", "COMMA", "$accept", "program", "macros",
  "macro", "reference", "classes", "class", "symbol_decs", "symbol_dec",
  "var_dec", "var_type", "return_type", "var_list", "var_list_item",
  "func_dec", "func_body", "formal_arguments", "formal_arguments_list",
  "formal_argument", "block", "statements_list", "statement", "assignment",
  "lvalue", "print", "statement_var_dec", "if", "elseif_blocks", "elseifs",
  "elseif", "else_block", "for", "while", "return", "break", "continue",
  "exp", "binary_operation", "logical_operation", "comparison_operation",
  "bitwise_operation", "unary_operation", "function_call",
  "function_call_body", "actual_arguments", "actual_arguments_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -64,    10,     4,   -64,    21,   -64,   -64,    16,   -64,    28,
     -64,     5,   -64,     8,   -64,    22,   -64,   -64,   -64,   -64,
      68,   -64,   -64,   -64,    73,   -64,   -64,    68,   -64,    44,
     -64,   -28,   -27,   -64,   -64,   -64,    82,    85,   -64,    94,
      95,    46,    49,   -64,   -46,   -64,   -64,   -64,   -64,   -64,
      85,    85,    85,    85,   -64,   401,   -64,   -64,   -64,   -64,
     -64,   -64,    77,   -64,   -64,   139,    82,    85,   106,   -64,
      17,   -64,   -64,   243,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,     6,    66,    85,    64,    65,    69,    70,    72,
     -64,   -64,    94,   -64,   -64,   -64,    96,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   165,   -64,   401,    75,    76,
      79,   -64,   418,   434,   449,   463,   476,   488,   125,   125,
     125,   125,   172,   197,    17,    17,    88,    88,    88,   -64,
     123,   191,   -64,   -64,    85,    85,   133,    62,    14,    85,
     -64,   -64,    85,   -64,    86,   -64,   267,   291,   111,   -64,
     -64,   -64,   217,   401,    91,   139,   139,    85,   -64,   -64,
     124,   -64,   363,   101,   151,   124,   -64,    85,    85,   139,
     -64,   -64,   383,   315,   -64,    85,   139,   339,   -64,   139,
     -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     8,     1,     0,     3,     5,     2,     6,     0,
       7,     0,    11,     0,    21,     0,    17,    18,    19,    20,
       0,     9,    10,    12,     0,    15,    13,     0,    16,     0,
      27,    24,     0,    23,    26,    28,    31,     0,    14,     0,
       0,     0,    30,    33,    51,    68,    69,    72,    70,    71,
       0,     0,     0,     0,    73,    25,    74,    75,    76,    77,
      78,    80,    24,    22,    34,     0,     0,   106,     0,   102,
      99,   101,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
      38,    39,     0,    29,    36,    41,    73,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    32,   108,     0,   105,
      52,    79,    90,    89,    98,    97,    95,    96,    93,    94,
      91,    92,    88,    87,    82,    81,    84,    83,    85,    86,
       0,     0,    66,    67,     0,     0,     0,     0,     0,     0,
      40,   104,     0,   103,     0,    65,     0,     0,     0,    35,
      37,    54,     0,   107,     0,     0,     0,     0,    50,    53,
      57,    64,     0,     0,    62,    56,    59,     0,     0,     0,
      55,    58,     0,     0,    61,     0,     0,     0,    60,     0,
      63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -10,    74,   135,   -64,   -20,   -64,   -64,   112,    -4,
     -64,    30,   -64,   -63,   -64,   -64,   -64,   -64,   -64,     9,
     -64,   -64,   -64,   -64,   -64,   -64,   -37,   -64,   -64,   -64,
     -64,   -64,   -64,    59,   -64,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,     7,    10,    13,    22,    23,
      24,   102,    32,    33,    26,    30,    41,    42,    43,   103,
     147,   104,   105,    54,   107,   108,   109,   174,   175,   176,
     180,   110,   111,   112,   113,   114,   115,    56,    57,    58,
      59,    60,    61,    69,   118,   119
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    37,   106,    25,    34,    28,    67,    35,    68,   -21,
       3,    14,     4,    70,    71,    72,    73,    15,    16,    17,
      18,    19,    20,     9,    36,    14,    40,     8,    38,    39,
     117,    11,    16,    17,    18,    19,    27,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    12,    40,   141,    67,    21,
      68,    88,    89,    90,    91,    92,    45,    46,    47,   161,
      39,    29,    16,    17,    18,    19,    31,    48,    49,    93,
      94,    95,    96,    97,   106,    14,    98,    99,    44,    45,
      46,    47,    16,    17,    18,    19,    36,    62,    64,    65,
      48,    49,   106,   106,    50,    66,    37,   156,   157,   120,
      51,    52,   162,   159,    53,   163,   106,   101,   140,   142,
     143,   144,   145,   106,   146,   149,   106,    50,   151,   154,
     172,    67,   152,    51,    52,    91,   158,    53,   167,   164,
     182,   183,    92,    45,    46,    47,   169,   173,   187,    16,
      17,    18,    19,   178,    48,    49,    93,    94,    95,    96,
      97,   170,   171,    98,    99,    84,    85,    86,    87,    88,
      89,    90,    91,   179,    63,   184,   148,   160,   116,   153,
       0,    50,   188,     0,   181,   190,     0,    51,    52,   100,
       0,    53,     0,     0,   101,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    85,    86,    87,    88,    89,    90,    91,
     150,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    86,
      87,    88,    89,    90,    91,     0,   155,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,   168,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,   121,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
     165,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,     0,   166,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,   186,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,   177,
       0,     0,   189,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   185,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      37,    29,    65,    13,    24,    15,    52,    27,    54,     3,
       0,     3,     8,    50,    51,    52,    53,     9,    10,    11,
      12,    13,    14,     7,    52,     3,    36,     6,    55,    56,
      67,     3,    10,    11,    12,    13,    14,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    50,    66,    94,    52,    51,
      54,    44,    45,    46,    47,     3,     4,     5,     6,    55,
      56,     3,    10,    11,    12,    13,     3,    15,    16,    17,
      18,    19,    20,    21,   147,     3,    24,    25,     3,     4,
       5,     6,    10,    11,    12,    13,    52,     3,     3,    53,
      15,    16,   165,   166,    42,    56,    29,   144,   145,     3,
      48,    49,   149,    51,    52,   152,   179,    55,    52,    55,
      55,    52,    52,   186,    52,    29,   189,    42,    53,     6,
     167,    52,    56,    48,    49,    47,     3,    52,    27,    53,
     177,   178,     3,     4,     5,     6,    55,    23,   185,    10,
      11,    12,    13,    52,    15,    16,    17,    18,    19,    20,
      21,   165,   166,    24,    25,    40,    41,    42,    43,    44,
      45,    46,    47,    22,    39,   179,   102,   147,    66,   120,
      -1,    42,   186,    -1,   175,   189,    -1,    48,    49,    50,
      -1,    52,    -1,    -1,    55,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    41,    42,    43,    44,    45,    46,    47,
      55,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    42,
      43,    44,    45,    46,    47,    -1,    55,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      53,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    53,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    26,
      -1,    -1,    53,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    58,    59,     0,     8,    60,    61,    62,     6,     7,
      63,     3,    50,    64,     3,     9,    10,    11,    12,    13,
      14,    51,    65,    66,    67,    68,    71,    14,    68,     3,
      72,     3,    69,    70,    72,    72,    52,    29,    55,    56,
      68,    73,    74,    75,     3,     4,     5,     6,    15,    16,
      42,    48,    49,    52,    80,    93,    94,    95,    96,    97,
      98,    99,     3,    70,     3,    53,    56,    52,    54,   100,
      93,    93,    93,    93,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    17,    18,    19,    20,    21,    24,    25,
      50,    55,    68,    76,    78,    79,    80,    81,    82,    83,
      88,    89,    90,    91,    92,    93,    75,    93,   101,   102,
       3,    53,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      52,    93,    55,    55,    52,    52,    52,    77,    69,    29,
      55,    53,    56,   100,     6,    55,    93,    93,     3,    51,
      78,    55,    93,    93,    53,    53,    53,    27,    55,    55,
      76,    76,    93,    23,    84,    85,    86,    26,    52,    22,
      87,    86,    93,    93,    76,    28,    53,    93,    76,    53,
      76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    61,    62,    62,    63,
      64,    64,    65,    65,    66,    67,    67,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    72,
      73,    73,    74,    74,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    80,    81,    82,    83,    84,    84,    85,    85,
      86,    87,    87,    88,    89,    90,    91,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    98,    99,    99,   100,   101,   101,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     2,     2,     0,     5,
       2,     0,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     1,     3,     2,     2,     3,     5,
       1,     0,     3,     1,     2,     3,     1,     2,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     5,     3,     7,     1,     0,     2,     1,
       5,     2,     0,    11,     5,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     4,     3,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: macros classes  */
#line 98 "parser.y"
                         { print("program : macros classes"); }
#line 1412 "rule.cpp"
    break;

  case 3: /* macros: macros macro  */
#line 100 "parser.y"
                      { print("macros : macros macro"); }
#line 1418 "rule.cpp"
    break;

  case 4: /* macros: %empty  */
#line 101 "parser.y"
                               { print("macros : lambda"); }
#line 1424 "rule.cpp"
    break;

  case 5: /* macro: reference  */
#line 103 "parser.y"
                  { print("macro : reference"); }
#line 1430 "rule.cpp"
    break;

  case 6: /* reference: REFERENCE STRING  */
#line 105 "parser.y"
                             { print("reference : REFERENCE STRING"); }
#line 1436 "rule.cpp"
    break;

  case 7: /* classes: classes class  */
#line 107 "parser.y"
                        { print("classes : classes class"); }
#line 1442 "rule.cpp"
    break;

  case 8: /* classes: %empty  */
#line 108 "parser.y"
                               { print("classes : lambda"); }
#line 1448 "rule.cpp"
    break;

  case 9: /* class: CLASS ID LCB symbol_decs RCB  */
#line 110 "parser.y"
                                     { print("class : CLASS ID {symbol_decs}"); }
#line 1454 "rule.cpp"
    break;

  case 10: /* symbol_decs: symbol_decs symbol_dec  */
#line 112 "parser.y"
                                     { print("symbol_decs : symbol_decs symbol_dec"); }
#line 1460 "rule.cpp"
    break;

  case 11: /* symbol_decs: %empty  */
#line 113 "parser.y"
                                       { print("symbol_decs : lambda"); }
#line 1466 "rule.cpp"
    break;

  case 12: /* symbol_dec: var_dec  */
#line 115 "parser.y"
                     { print("symbol_dec : var_dec"); }
#line 1472 "rule.cpp"
    break;

  case 13: /* symbol_dec: func_dec  */
#line 116 "parser.y"
                                   { print("symbol_dec : func_dec"); }
#line 1478 "rule.cpp"
    break;

  case 14: /* var_dec: var_type var_list SEMICOLON  */
#line 118 "parser.y"
                                      { print("var_dec : var_type var_list;"); Code_DeclareVarList(); }
#line 1484 "rule.cpp"
    break;

  case 15: /* var_type: return_type  */
#line 120 "parser.y"
                       { print("var_type : return_type"); }
#line 1490 "rule.cpp"
    break;

  case 16: /* var_type: STATIC return_type  */
#line 121 "parser.y"
                                             { print("var_type : STATIC return_type"); }
#line 1496 "rule.cpp"
    break;

  case 17: /* return_type: INT_TYPE  */
#line 123 "parser.y"
                       { print("return_type : INT_TYPE"); Stack_Push(new StackEntry{TypeEnum::INT, Util_GetTypeString(TypeEnum::INT)}); }
#line 1502 "rule.cpp"
    break;

  case 18: /* return_type: REAL_TYPE  */
#line 124 "parser.y"
                                    { print("return_type : REAL_TYPE"); Stack_Push(new StackEntry{TypeEnum::REAL, Util_GetTypeString(TypeEnum::REAL)});}
#line 1508 "rule.cpp"
    break;

  case 19: /* return_type: BOOL_TYPE  */
#line 125 "parser.y"
                                    { print("return_type : BOOL_TYPE"); Stack_Push(new StackEntry{TypeEnum::BOOL, Util_GetTypeString(TypeEnum::BOOL)});}
#line 1514 "rule.cpp"
    break;

  case 20: /* return_type: STRING_TYPE  */
#line 126 "parser.y"
                                      { print("return_type : STRING_TYPE"); Stack_Push(new StackEntry{TypeEnum::STRING, Util_GetTypeString(TypeEnum::STRING)}); }
#line 1520 "rule.cpp"
    break;

  case 21: /* return_type: ID  */
#line 127 "parser.y"
                             { print("return_type : ID"); Push_ID(false); }
#line 1526 "rule.cpp"
    break;

  case 22: /* var_list: var_list COMMA var_list_item  */
#line 129 "parser.y"
                                        { print("var_list : var_list, var_list_item"); }
#line 1532 "rule.cpp"
    break;

  case 23: /* var_list: var_list_item  */
#line 130 "parser.y"
                                        { print("var_list : var_list_item"); }
#line 1538 "rule.cpp"
    break;

  case 24: /* var_list_item: ID  */
#line 133 "parser.y"
                                {
					print("var_list_item : ID"); 
					Push_VarListItem(false); 
					++g.var_list_item_counter;
				}
#line 1548 "rule.cpp"
    break;

  case 25: /* var_list_item: ID ASSIGNMENT exp  */
#line 140 "parser.y"
                                {
					print("var_list_item : ID = exp"); 
					Push_VarListItem(true);
					++g.var_list_item_counter;
				}
#line 1558 "rule.cpp"
    break;

  case 26: /* func_dec: var_type func_body  */
#line 146 "parser.y"
                              { print("func_dec : func_body"); Code_FuncDecl(true); }
#line 1564 "rule.cpp"
    break;

  case 27: /* func_dec: VOID func_body  */
#line 147 "parser.y"
                                         { print("func_dec : VOID func_body"); Code_FuncDecl(false); }
#line 1570 "rule.cpp"
    break;

  case 28: /* func_dec: STATIC VOID func_body  */
#line 148 "parser.y"
                                                { print("func_dec : STATIC VOID func_body"); Code_FuncDecl(false); }
#line 1576 "rule.cpp"
    break;

  case 29: /* func_body: ID LP formal_arguments RP block  */
#line 151 "parser.y"
                        {
				print("func_body : ID ( formal_arguments ) block");
				Push_ID(false); 
			}
#line 1585 "rule.cpp"
    break;

  case 30: /* formal_arguments: formal_arguments_list  */
#line 157 "parser.y"
                                 {
					print("formal_arguments : formal_arguments_list"); 
					g.last_func = CURRENT_TABLE_COUNT; 
				 }
#line 1594 "rule.cpp"
    break;

  case 31: /* formal_arguments: %empty  */
#line 162 "parser.y"
                                 {
					print("formal_arguments : lambda");
					g.last_func = CURRENT_TABLE_COUNT; 
				 }
#line 1603 "rule.cpp"
    break;

  case 32: /* formal_arguments_list: formal_arguments_list COMMA formal_argument  */
#line 167 "parser.y"
                                                                    { print("formal_arguments_list : formal_arguments_list, formal_argument");  }
#line 1609 "rule.cpp"
    break;

  case 33: /* formal_arguments_list: formal_argument  */
#line 168 "parser.y"
                                                                  { print("formal_arguments_list : formal_argument"); }
#line 1615 "rule.cpp"
    break;

  case 34: /* formal_argument: return_type ID  */
#line 171 "parser.y"
                                { 
					print("formal_argument : statements_list ID"); 
					Push_ID(false); 
					++g.formal_argument_counter;
				}
#line 1625 "rule.cpp"
    break;

  case 35: /* block: LCB statements_list RCB  */
#line 177 "parser.y"
                                { print("block : { statments_list }"); }
#line 1631 "rule.cpp"
    break;

  case 36: /* block: statement  */
#line 178 "parser.y"
                            { print("block : statement"); }
#line 1637 "rule.cpp"
    break;

  case 37: /* statements_list: statements_list statement  */
#line 180 "parser.y"
                                             { print("statements_list : statements_list statement"); }
#line 1643 "rule.cpp"
    break;

  case 38: /* statements_list: %empty  */
#line 181 "parser.y"
                                               { print("statements_list : lambda"); }
#line 1649 "rule.cpp"
    break;

  case 39: /* statement: SEMICOLON  */
#line 183 "parser.y"
                      { print("statement : SEMICOLON"); }
#line 1655 "rule.cpp"
    break;

  case 40: /* statement: exp SEMICOLON  */
#line 184 "parser.y"
                                        { print("statement : exp;"); }
#line 1661 "rule.cpp"
    break;

  case 41: /* statement: assignment  */
#line 185 "parser.y"
                                     { print("statement : assignment"); }
#line 1667 "rule.cpp"
    break;

  case 42: /* statement: print  */
#line 186 "parser.y"
                                { print("statement : print"); }
#line 1673 "rule.cpp"
    break;

  case 43: /* statement: statement_var_dec  */
#line 187 "parser.y"
                                            { print("statement : statement_var_dec"); }
#line 1679 "rule.cpp"
    break;

  case 44: /* statement: if  */
#line 188 "parser.y"
                             { print("statement : if"); }
#line 1685 "rule.cpp"
    break;

  case 45: /* statement: for  */
#line 189 "parser.y"
                              { print("statement : for"); }
#line 1691 "rule.cpp"
    break;

  case 46: /* statement: while  */
#line 190 "parser.y"
                                { print("statement : while"); }
#line 1697 "rule.cpp"
    break;

  case 47: /* statement: return  */
#line 191 "parser.y"
                                 { print("statement : return"); }
#line 1703 "rule.cpp"
    break;

  case 48: /* statement: break  */
#line 192 "parser.y"
                                { print("statement : break"); }
#line 1709 "rule.cpp"
    break;

  case 49: /* statement: continue  */
#line 193 "parser.y"
                                   { print("statement : continue"); }
#line 1715 "rule.cpp"
    break;

  case 50: /* assignment: lvalue ASSIGNMENT exp SEMICOLON  */
#line 195 "parser.y"
                                             { print("assignment : lvalue = exp;"); Code_Assignment(); }
#line 1721 "rule.cpp"
    break;

  case 51: /* lvalue: ID  */
#line 197 "parser.y"
            { print("lvalue : ID"); Push_ID(true); }
#line 1727 "rule.cpp"
    break;

  case 52: /* lvalue: ID DOT ID  */
#line 198 "parser.y"
                            { print("lvalue : ID.ID"); yyerror("member access assignment is not supported"); YYABORT; }
#line 1733 "rule.cpp"
    break;

  case 53: /* print: PRINT LP STRING RP SEMICOLON  */
#line 200 "parser.y"
                                     { print("print : PRINT ( STRING );"); Code_AddPrint(str_data); }
#line 1739 "rule.cpp"
    break;

  case 54: /* statement_var_dec: return_type var_list SEMICOLON  */
#line 202 "parser.y"
                                                   { print("statement_var_dec : return_type var_list;"); Code_DeclareVarList(); }
#line 1745 "rule.cpp"
    break;

  case 55: /* if: IF LP exp RP block elseif_blocks else_block  */
#line 204 "parser.y"
                                                 { print("if : IF ( exp ) block elseif_blocks else_block"); Code_IF(); }
#line 1751 "rule.cpp"
    break;

  case 56: /* elseif_blocks: elseifs  */
#line 206 "parser.y"
                        { print("elseif_blocks : elseifs"); }
#line 1757 "rule.cpp"
    break;

  case 57: /* elseif_blocks: %empty  */
#line 207 "parser.y"
                                               { print("elseif_blocks : lambda"); }
#line 1763 "rule.cpp"
    break;

  case 58: /* elseifs: elseifs elseif  */
#line 209 "parser.y"
                         { print("elseifs : elseifs elseif "); }
#line 1769 "rule.cpp"
    break;

  case 59: /* elseifs: elseif  */
#line 210 "parser.y"
                         { print("elseifs : elseif "); }
#line 1775 "rule.cpp"
    break;

  case 60: /* elseif: ELSEIF LP exp RP block  */
#line 211 "parser.y"
                                { print("elseif : ELSEIF ( exp ) block "); Code_ElseIF(); }
#line 1781 "rule.cpp"
    break;

  case 61: /* else_block: ELSE block  */
#line 213 "parser.y"
                        { print("else_block : ELSE block "); Code_Else(); }
#line 1787 "rule.cpp"
    break;

  case 62: /* else_block: %empty  */
#line 214 "parser.y"
                                       { print("else_block : lambda"); }
#line 1793 "rule.cpp"
    break;

  case 63: /* for: FOR LP ID IN exp TO exp STEPS exp RP block  */
#line 217 "parser.y"
        { 
		print("for : FOR ( ID IN exp TO exp STEPS exp ) block");
		Push_ID();
		Code_For();
	}
#line 1803 "rule.cpp"
    break;

  case 64: /* while: WHILE LP exp RP block  */
#line 223 "parser.y"
                              { print("while : WHILE ( exp ) block"); Code_While(); }
#line 1809 "rule.cpp"
    break;

  case 65: /* return: RETURN exp SEMICOLON  */
#line 225 "parser.y"
                              { print("return : RETURN exp;"); Code_Return(); }
#line 1815 "rule.cpp"
    break;

  case 66: /* break: BREAK SEMICOLON  */
#line 227 "parser.y"
                        { print("break : BREAK;"); Code_Break(); }
#line 1821 "rule.cpp"
    break;

  case 67: /* continue: CONTINUE SEMICOLON  */
#line 229 "parser.y"
                              { print("continue : CONTINUE;"); Code_Continue(); }
#line 1827 "rule.cpp"
    break;

  case 68: /* exp: INT  */
#line 231 "parser.y"
          { print("exp : INT"); Stack_Push(new StackEntry{TypeEnum::INT, data});}
#line 1833 "rule.cpp"
    break;

  case 69: /* exp: REAL  */
#line 232 "parser.y"
               { print("exp : REAL"); Stack_Push(new StackEntry{TypeEnum::REAL, data}); }
#line 1839 "rule.cpp"
    break;

  case 70: /* exp: TRUE  */
#line 233 "parser.y"
               { print("exp : TRUE"); Stack_Push(new StackEntry{TypeEnum::BOOL, "true"}); }
#line 1845 "rule.cpp"
    break;

  case 71: /* exp: FALSE  */
#line 234 "parser.y"
                { print("exp : FALSE"); Stack_Push(new StackEntry{TypeEnum::BOOL, "false"}); }
#line 1851 "rule.cpp"
    break;

  case 72: /* exp: STRING  */
#line 235 "parser.y"
                 { print("exp : STRING"); last_string = str_data; Stack_Push(new StackEntry{TypeEnum::STRING, str_data}); }
#line 1857 "rule.cpp"
    break;

  case 73: /* exp: lvalue  */
#line 236 "parser.y"
                 { print("exp : lvalue"); }
#line 1863 "rule.cpp"
    break;

  case 74: /* exp: binary_operation  */
#line 237 "parser.y"
                           { print("exp : binary_operation"); }
#line 1869 "rule.cpp"
    break;

  case 75: /* exp: logical_operation  */
#line 238 "parser.y"
                            { print("exp : logical_operation"); }
#line 1875 "rule.cpp"
    break;

  case 76: /* exp: comparison_operation  */
#line 239 "parser.y"
                               { print("exp : comparison_operation"); }
#line 1881 "rule.cpp"
    break;

  case 77: /* exp: bitwise_operation  */
#line 240 "parser.y"
                            { print("exp : bitwise_operation"); }
#line 1887 "rule.cpp"
    break;

  case 78: /* exp: unary_operation  */
#line 241 "parser.y"
                          { print("exp : unary_operation"); }
#line 1893 "rule.cpp"
    break;

  case 79: /* exp: LP exp RP  */
#line 242 "parser.y"
                    { print("exp : ( exp )"); }
#line 1899 "rule.cpp"
    break;

  case 80: /* exp: function_call  */
#line 243 "parser.y"
                        { print("exp : function_call"); }
#line 1905 "rule.cpp"
    break;

  case 81: /* binary_operation: exp PLUS exp  */
#line 245 "parser.y"
                                 { print("binary_operation : exp + exp"); Code_ArithmeticBinary(OpEnum::PLUS); }
#line 1911 "rule.cpp"
    break;

  case 82: /* binary_operation: exp MINUS exp  */
#line 246 "parser.y"
                                                        { print("binary_operation : exp - exp"); Code_ArithmeticBinary(OpEnum::MINUS); }
#line 1917 "rule.cpp"
    break;

  case 83: /* binary_operation: exp MUL exp  */
#line 247 "parser.y"
                                                      { print("binary_operation : exp * exp"); Code_ArithmeticBinary(OpEnum::MUL); }
#line 1923 "rule.cpp"
    break;

  case 84: /* binary_operation: exp DIV exp  */
#line 248 "parser.y"
                                                      { print("binary_operation : exp / exp"); Code_ArithmeticBinary(OpEnum::DIV); }
#line 1929 "rule.cpp"
    break;

  case 85: /* binary_operation: exp MOD exp  */
#line 249 "parser.y"
                                                      { print("binary_operation : exp % exp"); Code_ArithmeticBinary(OpEnum::MOD); }
#line 1935 "rule.cpp"
    break;

  case 86: /* binary_operation: exp POW exp  */
#line 250 "parser.y"
                                                      { print("binary_operation : exp ^ exp"); Code_ArithmeticBinary(OpEnum::POW); }
#line 1941 "rule.cpp"
    break;

  case 87: /* binary_operation: exp SHIFT_LEFT exp  */
#line 251 "parser.y"
                                                             { print("binary_operation : exp << exp"); Code_ArithmeticBinary(OpEnum::SHIFT_LEFT); }
#line 1947 "rule.cpp"
    break;

  case 88: /* binary_operation: exp SHIFT_RIGHT exp  */
#line 252 "parser.y"
                                                              { print("binary_operation : exp >> exp"); Code_ArithmeticBinary(OpEnum::SHIFT_RIGHT); }
#line 1953 "rule.cpp"
    break;

  case 89: /* logical_operation: exp AND exp  */
#line 254 "parser.y"
                                { print("logical_operation : exp && exp"); Code_LogicalAnd(); }
#line 1959 "rule.cpp"
    break;

  case 90: /* logical_operation: exp OR exp  */
#line 255 "parser.y"
                                                     { print("logical_operation : exp || exp"); Code_LogicalOR(); }
#line 1965 "rule.cpp"
    break;

  case 91: /* comparison_operation: exp LT exp  */
#line 257 "parser.y"
                                  { print("comparison_operation : exp < exp"); Code_BoolComparison(OpEnum::LT); }
#line 1971 "rule.cpp"
    break;

  case 92: /* comparison_operation: exp LE exp  */
#line 258 "parser.y"
                                                             { print("comparison_operation : exp <= exp"); Code_BoolComparison(OpEnum::LE); }
#line 1977 "rule.cpp"
    break;

  case 93: /* comparison_operation: exp GT exp  */
#line 259 "parser.y"
                                                             { print("comparison_operation : exp > exp"); Code_BoolComparison(OpEnum::GT); }
#line 1983 "rule.cpp"
    break;

  case 94: /* comparison_operation: exp GE exp  */
#line 260 "parser.y"
                                                             { print("comparison_operation : exp >= exp"); Code_BoolComparison(OpEnum::GE); }
#line 1989 "rule.cpp"
    break;

  case 95: /* comparison_operation: exp EQ exp  */
#line 261 "parser.y"
                                                             { print("comparison_operation : exp == exp"); Code_BoolComparison(OpEnum::EQ); }
#line 1995 "rule.cpp"
    break;

  case 96: /* comparison_operation: exp NE exp  */
#line 262 "parser.y"
                                                             { print("comparison_operation : exp != exp"); Code_BoolComparison(OpEnum::NE); }
#line 2001 "rule.cpp"
    break;

  case 97: /* bitwise_operation: exp BITWISE_AND exp  */
#line 264 "parser.y"
                                        { print("bitwise_operation : exp & exp"); Code_ArithmeticBinary(OpEnum::BITWISE_AND); }
#line 2007 "rule.cpp"
    break;

  case 98: /* bitwise_operation: exp BITWISE_OR exp  */
#line 265 "parser.y"
                                                             { print("bitwise_operation : exp | exp"); Code_ArithmeticBinary(OpEnum::BITWISE_OR); }
#line 2013 "rule.cpp"
    break;

  case 99: /* unary_operation: MINUS exp  */
#line 267 "parser.y"
                            { print("unary_operation : -exp"); Code_ArithmeticUnary(OpEnum::UMINUS);}
#line 2019 "rule.cpp"
    break;

  case 100: /* unary_operation: NOT exp  */
#line 268 "parser.y"
                                          { print("unary_operation : !exp"); Code_LogicalNot(); }
#line 2025 "rule.cpp"
    break;

  case 101: /* unary_operation: BITWISE_NOT exp  */
#line 269 "parser.y"
                                                  { print("unary_operation : ~exp"); Code_ArithmeticUnary(OpEnum::BITWISE_NOT);}
#line 2031 "rule.cpp"
    break;

  case 102: /* function_call: ID function_call_body  */
#line 272 "parser.y"
                                { 
					print("function_call : ID function_call_body");
					Push_ID(false);
					Code_FuncCall(); 
				}
#line 2041 "rule.cpp"
    break;

  case 103: /* function_call: ID DOT ID function_call_body  */
#line 278 "parser.y"
                                                              { print("function_call : ID.ID function_call_body"); yyerror("member function calls are not supported"); YYABORT; }
#line 2047 "rule.cpp"
    break;

  case 104: /* function_call_body: LP actual_arguments RP  */
#line 280 "parser.y"
                                           { print("function_call_body : ( actual_arguments )"); }
#line 2053 "rule.cpp"
    break;

  case 105: /* actual_arguments: actual_arguments_list  */
#line 282 "parser.y"
                                         { print("actual_arguments : actual_arguments_list"); }
#line 2059 "rule.cpp"
    break;

  case 106: /* actual_arguments: %empty  */
#line 283 "parser.y"
                                                       { print("actual_arguments : lambda"); }
#line 2065 "rule.cpp"
    break;

  case 107: /* actual_arguments_list: actual_arguments_list COMMA exp  */
#line 285 "parser.y"
                                                        { print("actual_arguments_list : actual_arguments_list, exp"); ++g.actual_arguments_counter; }
#line 2071 "rule.cpp"
    break;

  case 108: /* actual_arguments_list: exp  */
#line 286 "parser.y"
                                                      { print("actual_arguments_list : exp"); ++g.actual_arguments_counter; }
#line 2077 "rule.cpp"
    break;


#line 2081 "rule.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 288 "parser.y"


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

	Program_Shutdown();
	return 0;
}
