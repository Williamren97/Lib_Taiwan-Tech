/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COMMA = 258,
     COLON = 259,
     SEMICOLON = 260,
     LEFTPARENTHESES = 261,
     RIGHTPARENTHESES = 262,
     LEFTSQUAREBRACKETS = 263,
     RIGHTSQUAREBRACKETS = 264,
     BRACKETS = 265,
     PLUS = 266,
     MINUS = 267,
     MULTIPLY = 268,
     DIVIDE = 269,
     REMAINDER = 270,
     LESS = 271,
     LESSEQUAL = 272,
     GREATEREQUAL = 273,
     GREATER = 274,
     EQUAL = 275,
     NOTEQUAL = 276,
     AND = 277,
     OR = 278,
     XOR = 279,
     ASSIGNMENT = 280,
     ARRAY = 281,
     BOOLEAN = 282,
     BEGIN_ = 283,
     BREAK = 284,
     CHAR = 285,
     CASE = 286,
     CONST = 287,
     CONTINUE = 288,
     DO = 289,
     ELSE = 290,
     END = 291,
     EXIT = 292,
     FOR = 293,
     FN = 294,
     IF = 295,
     IN = 296,
     INTEGER = 297,
     LOOP = 298,
     MODULE = 299,
     PRINT = 300,
     PRINTLN = 301,
     PROCEDURE = 302,
     REPEAT = 303,
     RETURN = 304,
     REAL = 305,
     STRING = 306,
     RECORD = 307,
     THEN = 308,
     TYPE = 309,
     USE = 310,
     UTIL = 311,
     VAR = 312,
     WHILE = 313,
     INTEGERCONSTANTS = 314,
     BOOLEANCONSTANTS = 315,
     REALCONSTANTS = 316,
     STRINGCONSTANTS = 317,
     IDENTIFIER = 318,
     PERIOD = 319,
     READ = 320,
     OF = 321,
     UMINUS = 322
   };
#endif
/* Tokens.  */
#define COMMA 258
#define COLON 259
#define SEMICOLON 260
#define LEFTPARENTHESES 261
#define RIGHTPARENTHESES 262
#define LEFTSQUAREBRACKETS 263
#define RIGHTSQUAREBRACKETS 264
#define BRACKETS 265
#define PLUS 266
#define MINUS 267
#define MULTIPLY 268
#define DIVIDE 269
#define REMAINDER 270
#define LESS 271
#define LESSEQUAL 272
#define GREATEREQUAL 273
#define GREATER 274
#define EQUAL 275
#define NOTEQUAL 276
#define AND 277
#define OR 278
#define XOR 279
#define ASSIGNMENT 280
#define ARRAY 281
#define BOOLEAN 282
#define BEGIN_ 283
#define BREAK 284
#define CHAR 285
#define CASE 286
#define CONST 287
#define CONTINUE 288
#define DO 289
#define ELSE 290
#define END 291
#define EXIT 292
#define FOR 293
#define FN 294
#define IF 295
#define IN 296
#define INTEGER 297
#define LOOP 298
#define MODULE 299
#define PRINT 300
#define PRINTLN 301
#define PROCEDURE 302
#define REPEAT 303
#define RETURN 304
#define REAL 305
#define STRING 306
#define RECORD 307
#define THEN 308
#define TYPE 309
#define USE 310
#define UTIL 311
#define VAR 312
#define WHILE 313
#define INTEGERCONSTANTS 314
#define BOOLEANCONSTANTS 315
#define REALCONSTANTS 316
#define STRINGCONSTANTS 317
#define IDENTIFIER 318
#define PERIOD 319
#define READ 320
#define OF 321
#define UMINUS 322




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <string.h>	

	extern int lineCount;
	
	//File
	FILE *file;
	
	//SymbolTable
	enum varconstEnum
	{
		variable,constant
	};
	struct SymbolTableStruct
	{
		char name[100];
		char type[10];
		enum varconstEnum varconst;
		int intValue;
		char strValue[100];
	};
	struct SymbolTableStruct globalSymbolTable[100];
	struct SymbolTableStruct localSymbolTable[100];
	int globalSymbolCount=0;
	int localSymbolCount=0;
	int lookup(struct SymbolTableStruct symbolTable[],char compareString[],int symbolCount)
	{
		for(int i=0;i<symbolCount;i++)
		{
			if(!strcmp(symbolTable[i].name,compareString))
				return i;
		}
		return -1;
	}
	void dump(struct SymbolTableStruct symbolTable[],int symbolCount)	
	{
		for(int i=0;i<symbolCount;i++)
			printf("%d:%s:%s\n",lookup(symbolTable,symbolTable[i].name,symbolCount),symbolTable[i].name,symbolTable[i].type);
		printf("\n");
	}
	char* getSymbolType(char name[])
	{
		int index=lookup(localSymbolTable,name,localSymbolCount);
		if(index!=-1)
			return localSymbolTable[index].type;
		index=lookup(globalSymbolTable,name,globalSymbolCount);
		if(index!=-1)
			return globalSymbolTable[index].type;
		return strdup("null");
	}
	
	//ProcedureTable
	struct ProcedureTableStruct
	{
		char name[100];
		char type[10];
		char formalType[100][10];
		int formalTypeCount;
	};
	struct ProcedureTableStruct procedureTable[100];
	int procedureCount=0;
	int lookupProcedure(struct ProcedureTableStruct procedureTable[],char compareString[],int procedureCount)
	{
		for(int i=0;i<procedureCount;i++)
		{
			if(!strcmp(procedureTable[i].name,compareString))
				return i;
		}
		return -1;
	}
	void dumpProcedure( )	
	{
		for(int i=0;i<procedureCount;i++)
		{
			printf("%d:%s:%s\n",lookupProcedure(procedureTable,procedureTable[i].name,procedureCount),procedureTable[i].name,procedureTable[i].type);
			for(int j=0;j<procedureTable[i].formalTypeCount;j++)
				printf("%s ",procedureTable[i].formalType[j]);
			printf("\n");
		}
		printf("\n");
	}
	void addProcedure(char name[])
	{
		if(lookupProcedure(procedureTable,name,procedureCount)==-1)
		{
			procedureTable[procedureCount].name[0]='\0';
			strcat(procedureTable[procedureCount].name,name);
			procedureCount++;
		}
	}
	void checkProcedure(char name[])
	{
		if(lookupProcedure(procedureTable,name,procedureCount)==-1)
			printf("\"%s\" No Function Declaration:line%d\n",name,lineCount+1);
	}
	
	//Scope
	enum scopeEnum
	{
		global,local
	};
	enum scopeEnum scope=global;
	void checkScope(char name[])
	{
		if(lookup(localSymbolTable,name,localSymbolCount)==-1 && lookup(globalSymbolTable,name,globalSymbolCount)==-1)
			printf("\"%s\" No Declaration:line%d\n",name,lineCount+1);
	}
	void checkall(char name[])
	{
		if(lookup(localSymbolTable,name,localSymbolCount)==-1 && lookup(globalSymbolTable,name,globalSymbolCount)==-1 && lookupProcedure(procedureTable,name,procedureCount)==-1)
			printf("\"%s\" No Declaration:line%d\n",name,lineCount+1);
	}
	
	//DataType
	int typeCount=0;
	
	//Parameter Match
	int parameterCount=0;
	char callProcedureName[100];

	void addType(char type[],enum varconstEnum varconst)
	{
		if(scope==global)
		{
			for(int i=globalSymbolCount-typeCount;i<globalSymbolCount;i++)
			{
				sscanf(type,"%s",globalSymbolTable[i].type);
				globalSymbolTable[i].varconst=varconst;
				//Generate Code
				if(varconst==variable)
					fprintf(file,"field static int %s\n",globalSymbolTable[i].name);
			}
		}
		else
		{
			for(int i=localSymbolCount-typeCount;i<localSymbolCount;i++)
			{
				sscanf(type,"%s",localSymbolTable[i].type);
				localSymbolTable[i].varconst=varconst;
			}
		}
		typeCount=0;
	}
	void addSymbol(char name[])	
	{
		if(!strcmp("",name))return;
		if(scope==global)
		{
			if(lookup(globalSymbolTable,name,globalSymbolCount)==-1)
			{
				sscanf(name,"%s",globalSymbolTable[globalSymbolCount].name);
				globalSymbolCount++;
			}
		}
		else
		{
			if(lookup(localSymbolTable,name,localSymbolCount)==-1)
			{
				sscanf(name,"%s",localSymbolTable[localSymbolCount].name);
				localSymbolCount++;
			}
		}	
	}
	//Constant Value
	int constInt;
	char constString[100];
	void addValue(int intValue,char strValue[])
	{
		if(scope==global)
		{
			globalSymbolTable[globalSymbolCount-1].intValue=intValue;
			strcpy(globalSymbolTable[globalSymbolCount-1].strValue,strValue);
		}
		else
		{
			localSymbolTable[localSymbolCount-1].intValue=intValue;
			strcpy(localSymbolTable[localSymbolCount-1].strValue,strValue);
		}	
	}
	
	//Label
	int ifLabelCount=0;
	int whileLabelCount=0;
	int booleanLabelCount=0;
	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 193 "parser.y"
{
	int integerVal;
	char stringVal[100];
}
/* Line 193 of yacc.c.  */
#line 423 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 436 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,     7,    21,    24,    25,
      28,    31,    33,    36,    39,    41,    46,    49,    52,    54,
      59,    62,    64,    76,    80,    82,    83,    84,    85,   100,
     101,   102,   110,   111,   112,   119,   120,   123,   124,   126,
     129,   130,   136,   137,   146,   147,   152,   153,   158,   159,
     164,   167,   171,   172,   183,   184,   185,   186,   198,   199,
     203,   204,   211,   212,   216,   217,   220,   224,   228,   232,
     236,   240,   244,   246,   248,   249,   255,   256,   262,   266,
     270,   274,   278,   282,   286,   290,   294,   298,   300,   301,
     306,   308,   310,   312,   314,   316,   318,   320,   322,   324
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    -1,    -1,    -1,    -1,    44,    63,    70,
      74,    71,    83,    28,    72,   114,    36,    63,    73,    64,
      -1,    75,    74,    -1,    -1,    32,    76,    -1,    57,    78,
      -1,    80,    -1,    77,    76,    -1,    77,    80,    -1,    77,
      -1,    63,    20,   112,     5,    -1,    79,    78,    -1,    79,
      80,    -1,    79,    -1,    82,     4,   113,     5,    -1,    81,
      80,    -1,    81,    -1,    82,     4,    26,     8,    59,     3,
      59,     9,    66,   113,     5,    -1,    63,     3,    82,    -1,
      63,    -1,    -1,    -1,    -1,    47,    63,    84,    87,    91,
      85,    74,    28,    92,    36,    63,    86,     5,    83,    -1,
      -1,    -1,     6,    63,     4,   113,    88,    89,     7,    -1,
      -1,    -1,     3,    63,     4,   113,    90,    89,    -1,    -1,
       4,   113,    -1,    -1,    93,    -1,    93,    92,    -1,    -1,
      63,    94,    25,   107,     5,    -1,    -1,    63,    95,     8,
     107,     9,    25,   107,     5,    -1,    -1,    45,    96,   107,
       5,    -1,    -1,    46,    97,   107,     5,    -1,    -1,    65,
      63,    98,     5,    -1,    49,     5,    -1,    49,   107,     5,
      -1,    -1,    40,     6,   107,     7,    53,    99,   114,   105,
      36,     5,    -1,    -1,    -1,    -1,    58,   100,     6,   107,
     101,     7,    34,   114,   102,    36,     5,    -1,    -1,    63,
     103,     5,    -1,    -1,    63,   104,     6,   110,     7,     5,
      -1,    -1,    35,   106,   114,    -1,    -1,    12,   107,    -1,
     107,    13,   107,    -1,   107,    14,   107,    -1,   107,    11,
     107,    -1,   107,    12,   107,    -1,   107,    15,   107,    -1,
       6,   107,     7,    -1,   112,    -1,    63,    -1,    -1,    63,
     108,     6,   110,     7,    -1,    -1,    63,   109,     8,   107,
       9,    -1,   107,    16,   107,    -1,   107,    17,   107,    -1,
     107,    20,   107,    -1,   107,    18,   107,    -1,   107,    19,
     107,    -1,   107,    21,   107,    -1,   107,    24,   107,    -1,
     107,    22,   107,    -1,   107,    23,   107,    -1,   107,    -1,
      -1,   107,   111,     3,   110,    -1,    62,    -1,    59,    -1,
      60,    -1,    61,    -1,    51,    -1,    42,    -1,    50,    -1,
      27,    -1,    92,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   223,   223,   228,   233,   239,   221,   249,   250,   252,
     253,   254,   257,   258,   259,   261,   264,   265,   266,   268,
     271,   272,   274,   277,   278,   284,   291,   298,   282,   309,
     312,   311,   322,   325,   324,   335,   337,   338,   342,   343,
     346,   346,   360,   360,   368,   367,   384,   383,   399,   399,
     400,   401,   404,   402,   415,   421,   427,   414,   437,   437,
     450,   449,   466,   465,   475,   482,   488,   496,   504,   512,
     520,   528,   529,   538,   594,   593,   609,   609,   616,   625,
     634,   643,   652,   661,   670,   678,   686,   695,   705,   704,
     714,   715,   716,   717,   720,   721,   722,   723,   726,   727
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "COLON", "SEMICOLON",
  "LEFTPARENTHESES", "RIGHTPARENTHESES", "LEFTSQUAREBRACKETS",
  "RIGHTSQUAREBRACKETS", "BRACKETS", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "REMAINDER", "LESS", "LESSEQUAL", "GREATEREQUAL", "GREATER", "EQUAL",
  "NOTEQUAL", "AND", "OR", "XOR", "ASSIGNMENT", "ARRAY", "BOOLEAN",
  "BEGIN_", "BREAK", "CHAR", "CASE", "CONST", "CONTINUE", "DO", "ELSE",
  "END", "EXIT", "FOR", "FN", "IF", "IN", "INTEGER", "LOOP", "MODULE",
  "PRINT", "PRINTLN", "PROCEDURE", "REPEAT", "RETURN", "REAL", "STRING",
  "RECORD", "THEN", "TYPE", "USE", "UTIL", "VAR", "WHILE",
  "INTEGERCONSTANTS", "BOOLEANCONSTANTS", "REALCONSTANTS",
  "STRINGCONSTANTS", "IDENTIFIER", "PERIOD", "READ", "OF", "UMINUS",
  "$accept", "program", "@1", "@2", "@3", "@4", "variableconstant_decs",
  "variableconstant_dec", "constant_decs", "constant_dec", "variable_decs",
  "variable_dec", "array_decs", "array_dec", "identifiers",
  "function_decs", "@5", "@6", "@7", "arguments", "@8", "argument", "@9",
  "proceduretype", "statements", "statement", "@10", "@11", "@12", "@13",
  "@14", "@15", "@16", "@17", "@18", "@19", "@20", "else_statements",
  "@21", "expression", "@22", "@23", "commaseparated_expressions", "@24",
  "constant", "datatype", "zero_statements", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    70,    71,    72,    73,    69,    74,    74,    75,
      75,    75,    76,    76,    76,    77,    78,    78,    78,    79,
      80,    80,    81,    82,    82,    84,    85,    86,    83,    83,
      88,    87,    87,    90,    89,    89,    91,    91,    92,    92,
      94,    93,    95,    93,    96,    93,    97,    93,    98,    93,
      93,    93,    99,    93,   100,   101,   102,    93,   103,    93,
     104,    93,   106,   105,   105,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   107,   109,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   110,   111,   110,
     112,   112,   112,   112,   113,   113,   113,   113,   114,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    13,     2,     0,     2,
       2,     1,     2,     2,     1,     4,     2,     2,     1,     4,
       2,     1,    11,     3,     1,     0,     0,     0,    14,     0,
       0,     7,     0,     0,     6,     0,     2,     0,     1,     2,
       0,     5,     0,     8,     0,     4,     0,     4,     0,     4,
       2,     3,     0,    10,     0,     0,     0,    11,     0,     3,
       0,     6,     0,     3,     0,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     0,     5,     0,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     8,     0,     0,    24,     3,
       8,    11,    21,     0,     0,     9,    14,    10,    18,     0,
       0,    29,     7,    20,     0,     0,    24,    12,    13,    16,
      17,     0,     0,    23,     0,     0,     0,    91,    92,    93,
      90,     0,     0,    97,    95,    96,    94,     0,    25,     4,
       0,    15,    19,    32,    99,     0,     0,    37,     0,    44,
      46,     0,    54,    40,     0,    98,    38,     0,     0,     0,
       0,    26,     0,     0,     0,    50,     0,     0,    73,     0,
      72,     0,     0,     0,     0,     0,    48,    39,     0,     0,
       0,    36,     8,     0,     0,     0,     0,    65,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     5,     0,    30,     0,     0,    45,    47,    71,     0,
       0,    68,    69,    66,    67,    70,    78,    79,    81,    82,
      80,    83,    85,    86,    84,    55,     0,     0,    87,     0,
      49,     0,     0,    35,     0,    52,     0,     0,     0,    41,
       0,     0,     0,     6,     0,     0,     0,     0,    99,    75,
      77,     0,     0,     0,    61,    22,     0,    31,     0,    64,
      99,     0,    89,     0,    27,    62,     0,    56,    43,    33,
       0,    99,     0,     0,    35,    29,    63,    53,     0,    34,
      28,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    21,    54,   151,     9,    10,    15,    16,
      17,    18,    11,    12,    13,    35,    53,    92,   190,    57,
     153,   166,   194,    71,    65,    66,    82,    83,    73,    74,
     120,   168,    81,   158,   193,    84,    85,   186,   191,   148,
      98,    99,   149,   161,    80,    47,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int16 yypact[] =
{
     -37,   -55,    32,  -111,  -111,   -26,   -42,   -28,    33,  -111,
     -26,  -111,   -28,    60,    46,  -111,     4,  -111,   -28,    65,
     -28,    29,  -111,  -111,    54,    48,    20,  -111,  -111,  -111,
    -111,    82,   -12,  -111,    26,    71,    94,  -111,  -111,  -111,
    -111,    99,   -17,  -111,  -111,  -111,  -111,   100,  -111,  -111,
      52,  -111,  -111,   126,    38,   130,    86,   146,   145,  -111,
    -111,    -1,  -111,    92,    89,  -111,    38,   117,   110,   166,
     -12,  -111,    12,    12,    12,  -111,    12,    12,    21,   123,
    -111,   165,   147,   181,   168,   184,  -111,  -111,   128,   200,
     -12,  -111,   -26,   221,   143,   163,   239,   177,   187,   202,
    -111,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,  -111,    12,
     206,  -111,   164,  -111,   185,   159,  -111,  -111,  -111,    12,
      12,   116,   116,   177,   177,   285,    80,    80,    80,    80,
      80,    80,   313,   299,   327,   285,   183,   255,   103,   222,
    -111,   167,   -12,   244,    38,  -111,   241,   271,   242,  -111,
     240,   278,   317,  -111,   330,   273,   342,   314,    38,  -111,
    -111,   318,    12,    12,  -111,  -111,   347,  -111,   290,   319,
      38,   203,  -111,   -12,  -111,  -111,   320,  -111,  -111,  -111,
     350,    38,   352,   322,   244,    29,  -111,  -111,   354,  -111,
    -111,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,  -111,  -111,    -7,  -111,   344,  -111,
     343,  -111,    10,  -111,    61,   169,  -111,  -111,  -111,  -111,
    -111,   171,  -111,  -111,   -64,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   -60,
    -111,  -111,  -110,  -111,   337,   -70,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -89
static const yytype_int16 yytable[] =
{
      91,    79,    87,    22,    75,    76,     6,     1,     3,    36,
      43,    77,    93,    94,    95,    43,    96,    97,    76,   156,
     123,    14,    23,    20,    77,    44,    28,   -74,    30,   -76,
      44,     7,     4,    45,    46,     8,    20,     8,    45,    46,
      25,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    37,    38,
      39,    40,    78,   182,    24,   179,    25,    26,    19,    32,
     157,    37,    38,    39,    40,    78,    34,   187,    58,    31,
      36,    33,   164,    59,    60,   124,    42,    61,   196,    48,
     167,   101,   102,   103,   104,   105,    62,   -58,   -60,    49,
     -42,    63,    50,    64,    51,    52,   -88,    37,    38,    39,
      40,    55,   181,   189,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   100,   103,
     104,   105,    56,    68,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   126,    69,
      70,    72,    86,    88,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   127,    89,
      90,   115,   116,   118,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   159,   117,
     119,   121,   105,   129,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   188,   122,
     130,   150,   155,   154,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   125,   162,
     152,   163,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   128,   165,   169,   171,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   160,   172,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     170,   173,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   174,   114,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   175,   176,   114,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   177,
     178,   183,   180,   184,   185,   195,   192,   197,   198,   201,
      27,    29,    41,     0,   200,   199
};

static const yytype_int16 yycheck[] =
{
      70,    61,    66,    10,     5,     6,    32,    44,    63,    26,
      27,    12,    72,    73,    74,    27,    76,    77,     6,   129,
      90,    63,    12,     3,    12,    42,    16,     6,    18,     8,
      42,    57,     0,    50,    51,    63,     3,    63,    50,    51,
      20,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    59,    60,
      61,    62,    63,   173,     4,   168,    20,    63,     7,     4,
     130,    59,    60,    61,    62,    63,    47,   180,    40,    18,
      26,    20,   152,    45,    46,    92,     4,    49,   191,    63,
     154,    11,    12,    13,    14,    15,    58,     5,     6,    28,
       8,    63,     8,    65,     5,     5,     3,    59,    60,    61,
      62,    59,   172,   183,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,    13,
      14,    15,     6,     3,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,    63,
       4,     6,    63,    36,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,    59,
       4,     6,    25,     5,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,     8,
       6,    63,    15,     6,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,     9,
       8,     5,    53,    28,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     7,     7,
      66,    64,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     7,     3,     7,     7,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     9,    25,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       9,     3,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     5,    24,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     5,    63,    24,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     7,
      36,     4,    34,    63,    35,     5,    36,     5,    36,     5,
      16,    18,    25,    -1,   195,   194
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    69,    63,     0,    70,    32,    57,    63,    74,
      75,    80,    81,    82,    63,    76,    77,    78,    79,    82,
       3,    71,    74,    80,     4,    20,    63,    76,    80,    78,
      80,    82,     4,    82,    47,    83,    26,    59,    60,    61,
      62,   112,     4,    27,    42,    50,    51,   113,    63,    28,
       8,     5,     5,    84,    72,    59,     6,    87,    40,    45,
      46,    49,    58,    63,    65,    92,    93,   114,     3,    63,
       4,    91,     6,    96,    97,     5,     6,    12,    63,   107,
     112,   100,    94,    95,   103,   104,    63,    92,    36,    59,
       4,   113,    85,   107,   107,   107,   107,   107,   108,   109,
       5,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     6,    25,     8,     5,     6,
      98,    63,     9,   113,    74,     7,     5,     5,     7,     6,
       8,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   110,
       5,    73,    66,    88,    28,    53,   110,   107,   101,     5,
       9,   111,     7,    64,   113,     3,    89,    92,    99,     7,
       9,     7,    25,     3,     5,     5,    63,     7,    36,   114,
      34,   107,   110,     4,    63,    35,   105,   114,     5,   113,
      86,   106,    36,   102,    90,     5,   114,     5,    36,    89,
      83,     5
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 223 "parser.y"
    {
	//Generate Code
	fprintf(file,"class a\n{\n");
}
    break;

  case 3:
#line 228 "parser.y"
    {
	scope=local;
}
    break;

  case 4:
#line 233 "parser.y"
    {
	//Generate Code
	fprintf(file,"method public static void main(java.lang.String[])\nmax_stack 15\nmax_locals 15\n{\n");
}
    break;

  case 5:
#line 239 "parser.y"
    {
	if(strcmp((yyvsp[(2) - (11)].stringVal),(yyvsp[(11) - (11)].stringVal)))
		printf("Wrong Program Name:line%d\n",lineCount+1);
	//Generate Code
	fprintf(file,"return\n}\n}");
}
    break;

  case 15:
#line 261 "parser.y"
    {addSymbol((yyvsp[(1) - (4)].stringVal));typeCount++;addType((yyvsp[(3) - (4)].stringVal),constant);addValue(constInt,constString);}
    break;

  case 19:
#line 268 "parser.y"
    {addType((yyvsp[(3) - (4)].stringVal),variable);}
    break;

  case 22:
#line 274 "parser.y"
    {addType((yyvsp[(10) - (11)].stringVal),variable);}
    break;

  case 23:
#line 277 "parser.y"
    {addSymbol((yyvsp[(1) - (3)].stringVal));typeCount++;}
    break;

  case 24:
#line 278 "parser.y"
    {addSymbol((yyvsp[(1) - (1)].stringVal));typeCount++;}
    break;

  case 25:
#line 284 "parser.y"
    {
	addProcedure((yyvsp[(2) - (2)].stringVal));
	//Generate Code
	fprintf(file,"method public static int %s(",(yyvsp[(2) - (2)].stringVal));
}
    break;

  case 26:
#line 291 "parser.y"
    {
	sscanf((yyvsp[(5) - (5)].stringVal),"%s",procedureTable[procedureCount-1].type);
	//Generate Code
	fprintf(file,")\nmax_stack 15\nmax_locals 15\n{\n");
}
    break;

  case 27:
#line 298 "parser.y"
    {
	if(strcmp((yyvsp[(2) - (11)].stringVal),(yyvsp[(11) - (11)].stringVal)))
		printf("Wrong Procedure Name:line%d\n",lineCount+1);
	localSymbolCount=0;
	//Generate Code
	if(strcmp("void",(yyvsp[(5) - (11)].stringVal)))
		fprintf(file,"ireturn\n}\n");
	else
		fprintf(file,"return\n}\n");
}
    break;

  case 30:
#line 312 "parser.y"
    {
	addSymbol((yyvsp[(2) - (4)].stringVal));
	typeCount++;
	addType((yyvsp[(4) - (4)].stringVal),variable);
	sscanf((yyvsp[(4) - (4)].stringVal),"%s",procedureTable[procedureCount-1].formalType[procedureTable[procedureCount-1].formalTypeCount]);
	procedureTable[procedureCount-1].formalTypeCount++;
	//Generate Code
	fprintf(file,"int");
}
    break;

  case 33:
#line 325 "parser.y"
    {
	addSymbol((yyvsp[(2) - (4)].stringVal));
	typeCount++;
	addType((yyvsp[(4) - (4)].stringVal),variable);
	sscanf((yyvsp[(4) - (4)].stringVal),"%s",procedureTable[procedureCount-1].formalType[procedureTable[procedureCount-1].formalTypeCount]);
	procedureTable[procedureCount-1].formalTypeCount++;
	//Generate Code
	fprintf(file,",int");
}
    break;

  case 36:
#line 337 "parser.y"
    {sscanf((yyvsp[(2) - (2)].stringVal),"%s",(yyval.stringVal));}
    break;

  case 37:
#line 338 "parser.y"
    {sscanf("void","%s",(yyval.stringVal));}
    break;

  case 40:
#line 346 "parser.y"
    {checkScope((yyvsp[(1) - (1)].stringVal));}
    break;

  case 41:
#line 347 "parser.y"
    {
	if(strcmp(getSymbolType((yyvsp[(1) - (5)].stringVal)),(yyvsp[(4) - (5)].stringVal)))
			printf("Assignment Not Consistent:line%d\n",lineCount+1);
	//Generate Code
	int index=lookup(globalSymbolTable,(yyvsp[(1) - (5)].stringVal),globalSymbolCount);
	if(index!=-1)
		fprintf(file,"putstatic int a.%s\n",(yyvsp[(1) - (5)].stringVal));
	else
	{
		index=lookup(localSymbolTable,(yyvsp[(1) - (5)].stringVal),localSymbolCount);
		fprintf(file,"istore %d\n",index);
	}
}
    break;

  case 42:
#line 360 "parser.y"
    {checkScope((yyvsp[(1) - (1)].stringVal));}
    break;

  case 43:
#line 361 "parser.y"
    {
	if(strcmp(getSymbolType((yyvsp[(1) - (8)].stringVal)),(yyvsp[(7) - (8)].stringVal)))
		printf("Assignment Not Consistent:line%d\n",lineCount+1);
	if(strcmp((yyvsp[(4) - (8)].stringVal),"integer"))
		printf("Only Integer:line%d\n",lineCount+1);
}
    break;

  case 44:
#line 368 "parser.y"
    {
	//Generate Code
	fprintf(file,"getstatic java.io.PrintStream java.lang.System.out\n");
}
    break;

  case 45:
#line 374 "parser.y"
    {
	//Generate Code
	if(!strcmp("string",(yyvsp[(3) - (4)].stringVal)))
		fprintf(file,"invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
	else if(!strcmp("boolean",(yyvsp[(3) - (4)].stringVal)))
		fprintf(file,"invokevirtual void java.io.PrintStream.print(boolean)\n");
	else
		fprintf(file,"invokevirtual void java.io.PrintStream.print(int)\n");
}
    break;

  case 46:
#line 384 "parser.y"
    {
	//Generate Code
	fprintf(file,"getstatic java.io.PrintStream java.lang.System.out\n");
}
    break;

  case 47:
#line 390 "parser.y"
    {
	//Generate Code
	if(!strcmp("string",(yyvsp[(3) - (4)].stringVal)))
		fprintf(file,"invokevirtual void java.io.PrintStream.println(java.lang.String)\n");
	else if(!strcmp("boolean",(yyvsp[(3) - (4)].stringVal)))
		fprintf(file,"invokevirtual void java.io.PrintStream.println(boolean)\n");
	else
		fprintf(file,"invokevirtual void java.io.PrintStream.println(int)\n");
}
    break;

  case 48:
#line 399 "parser.y"
    {checkScope((yyvsp[(2) - (2)].stringVal));}
    break;

  case 52:
#line 404 "parser.y"
    {
	//Generate Code
	fprintf(file,"ifeq Lif%d\n",ifLabelCount);
}
    break;

  case 53:
#line 410 "parser.y"
    {
	if(strcmp((yyvsp[(3) - (10)].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
}
    break;

  case 54:
#line 415 "parser.y"
    {
	//Generate Code
	fprintf(file,"Lwhile%d:\n",whileLabelCount);
}
    break;

  case 55:
#line 421 "parser.y"
    {
	//Generate Code
	fprintf(file,"ifeq Lwhile%d\n",whileLabelCount+1);
}
    break;

  case 56:
#line 427 "parser.y"
    {
	//Generate Code
	fprintf(file,"goto Lwhile%d\nLwhile%d:\n",whileLabelCount,whileLabelCount+1);
	whileLabelCount+=2;
}
    break;

  case 57:
#line 433 "parser.y"
    {
	if(strcmp((yyvsp[(4) - (11)].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
}
    break;

  case 58:
#line 437 "parser.y"
    {checkProcedure((yyvsp[(1) - (1)].stringVal));}
    break;

  case 59:
#line 438 "parser.y"
    {
	int index=lookupProcedure(procedureTable,(yyvsp[(1) - (3)].stringVal),procedureCount);
	if(procedureTable[index].formalTypeCount!=0)
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	//Generate Code
	if(strcmp("void",procedureTable[index].type))
		fprintf(file,"invokestatic int a.%s()\n",(yyvsp[(1) - (3)].stringVal));
	else
		fprintf(file,"invokestatic void a.%s()\n",(yyvsp[(1) - (3)].stringVal));
	
}
    break;

  case 60:
#line 450 "parser.y"
    {
	checkProcedure((yyvsp[(1) - (1)].stringVal));
	sscanf((yyvsp[(1) - (1)].stringVal),"%s",callProcedureName);
}
    break;

  case 61:
#line 455 "parser.y"
    {
	//Generate Code
	int index=lookupProcedure(procedureTable,(yyvsp[(1) - (6)].stringVal),procedureCount);
	fprintf(file,"invokestatic int a.%s(int",(yyvsp[(1) - (6)].stringVal));
	for(int i=0;i<procedureTable[index].formalTypeCount-1;i++)
		fprintf(file,",int");
	fprintf(file,")\n");
}
    break;

  case 62:
#line 466 "parser.y"
    {
	fprintf(file,"goto Lif%d\nLif%d:\n",ifLabelCount+1,ifLabelCount);
}
    break;

  case 63:
#line 470 "parser.y"
    {
	fprintf(file,"Lif%d:\n",ifLabelCount+1);
	ifLabelCount+=2;
}
    break;

  case 64:
#line 475 "parser.y"
    {
	fprintf(file,"Lif%d:\n",ifLabelCount);
	ifLabelCount++;
}
    break;

  case 65:
#line 483 "parser.y"
    {
	sscanf((yyvsp[(2) - (2)].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"ineg\n");
}
    break;

  case 66:
#line 489 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[(1) - (3)].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"imul\n");
}
    break;

  case 67:
#line 497 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[(1) - (3)].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"idiv\n");
}
    break;

  case 68:
#line 505 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[(1) - (3)].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"iadd\n");
}
    break;

  case 69:
#line 513 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[(1) - (3)].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"isub\n");
}
    break;

  case 70:
#line 521 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[(1) - (3)].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"irem\n");
}
    break;

  case 71:
#line 528 "parser.y"
    {sscanf((yyvsp[(2) - (3)].stringVal),"%s",(yyval.stringVal));}
    break;

  case 72:
#line 530 "parser.y"
    {
	sscanf((yyvsp[(1) - (1)].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	if(strcmp((yyvsp[(1) - (1)].stringVal),"string"))
		fprintf(file,"sipush %d\n",constInt);
	else
		fprintf(file,"ldc \"%s\"\n",constString);
}
    break;

  case 73:
#line 539 "parser.y"
    {
	checkall((yyvsp[(1) - (1)].stringVal));
	char* type=getSymbolType((yyvsp[(1) - (1)].stringVal));
	if(strcmp(type,"null"))
	{
		sscanf(type,"%s",(yyval.stringVal));
		//Generate Code
		int index=lookup(globalSymbolTable,(yyvsp[(1) - (1)].stringVal),globalSymbolCount);
		//Global
		if(index!=-1)
		{
			//Variable
			if(globalSymbolTable[index].varconst==variable)
				fprintf(file,"getstatic int a.%s\n",(yyvsp[(1) - (1)].stringVal));
			//Constant
			else
			{
				if(strcmp(type,"string"))
					fprintf(file,"sipush %d\n",globalSymbolTable[index].intValue);
				else
					fprintf(file,"ldc \"%s\"\n",globalSymbolTable[index].strValue);
			}			
		}
		//Local
		else
		{
			index=lookup(localSymbolTable,(yyvsp[(1) - (1)].stringVal),localSymbolCount);
			if(localSymbolTable[index].varconst==variable)
				fprintf(file,"iload %d\n",index);
			else
			{
				if(strcmp(type,"string"))
					fprintf(file,"sipush %d\n",localSymbolTable[index].intValue);
				else
					fprintf(file,"ldc \"%s\"\n",localSymbolTable[index].strValue);
			}
		}
	}
	else
	{
		int index=lookupProcedure(procedureTable,(yyvsp[(1) - (1)].stringVal),procedureCount);
		if(index!=-1)
		{
			if(procedureTable[index].formalTypeCount!=0)
				printf("Parameter Type Not Match:line%d\n",lineCount+1);
			sscanf(procedureTable[index].type,"%s",(yyval.stringVal));
			//Generate Code
			if(strcmp("void",procedureTable[index].type))
				fprintf(file,"invokestatic int a.%s()\n",(yyvsp[(1) - (1)].stringVal));
			else
				fprintf(file,"invokestatic void a.%s()\n",(yyvsp[(1) - (1)].stringVal));
		}
	}	
}
    break;

  case 74:
#line 594 "parser.y"
    {
	checkProcedure((yyvsp[(1) - (1)].stringVal));
	sscanf((yyvsp[(1) - (1)].stringVal),"%s",callProcedureName);
}
    break;

  case 75:
#line 600 "parser.y"
    {
	sscanf(procedureTable[lookupProcedure(procedureTable,(yyvsp[(1) - (5)].stringVal),procedureCount)].type,"%s",(yyval.stringVal));
	//Generate Code
	int index=lookupProcedure(procedureTable,(yyvsp[(1) - (5)].stringVal),procedureCount);
	fprintf(file,"invokestatic int a.%s(int",(yyvsp[(1) - (5)].stringVal));
	for(int i=0;i<procedureTable[index].formalTypeCount-1;i++)
		fprintf(file,",int");
	fprintf(file,")\n");
}
    break;

  case 76:
#line 609 "parser.y"
    {checkScope((yyvsp[(1) - (1)].stringVal));}
    break;

  case 77:
#line 610 "parser.y"
    {
	if(strcmp((yyvsp[(4) - (5)].stringVal),"integer"))
		printf("Only Integer:line%d\n",lineCount+1);
	sscanf(getSymbolType((yyvsp[(1) - (5)].stringVal)),"%s",(yyval.stringVal));
}
    break;

  case 78:
#line 617 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"isub\niflt Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
    break;

  case 79:
#line 626 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"isub\nifle Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
    break;

  case 80:
#line 635 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"isub\nifeq Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
    break;

  case 81:
#line 644 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"isub\nifge Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
    break;

  case 82:
#line 653 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"isub\nifgt Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
    break;

  case 83:
#line 662 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),(yyvsp[(3) - (3)].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"isub\nifne Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
    break;

  case 84:
#line 671 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),"boolean")||strcmp((yyvsp[(3) - (3)].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"ixor\n");
}
    break;

  case 85:
#line 679 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),"boolean")||strcmp((yyvsp[(3) - (3)].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"iand\n");
}
    break;

  case 86:
#line 687 "parser.y"
    {
	if(strcmp((yyvsp[(1) - (3)].stringVal),"boolean")||strcmp((yyvsp[(3) - (3)].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	fprintf(file,"ior\n");
}
    break;

  case 87:
#line 696 "parser.y"
    {
	int index=lookupProcedure(procedureTable,callProcedureName,procedureCount);
	if(strcmp((yyvsp[(1) - (1)].stringVal),procedureTable[index].formalType[parameterCount]))
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	else if(parameterCount+1!=procedureTable[index].formalTypeCount)
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	parameterCount=0;
}
    break;

  case 88:
#line 705 "parser.y"
    {
	int index=lookupProcedure(procedureTable,callProcedureName,procedureCount);
	if(strcmp((yyvsp[(1) - (1)].stringVal),procedureTable[index].formalType[parameterCount]))
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	parameterCount++;
}
    break;

  case 90:
#line 714 "parser.y"
    {sscanf("string","%s",(yyval.stringVal));strcpy(constString,(yyvsp[(1) - (1)].stringVal));}
    break;

  case 91:
#line 715 "parser.y"
    {sscanf("integer","%s",(yyval.stringVal));constInt=(yyvsp[(1) - (1)].integerVal);}
    break;

  case 92:
#line 716 "parser.y"
    {sscanf("boolean","%s",(yyval.stringVal));constInt=(yyvsp[(1) - (1)].integerVal);}
    break;

  case 93:
#line 717 "parser.y"
    {sscanf("real","%s",(yyval.stringVal));}
    break;

  case 94:
#line 720 "parser.y"
    {sscanf((yyvsp[(1) - (1)].stringVal),"%s",(yyval.stringVal));}
    break;

  case 95:
#line 721 "parser.y"
    {sscanf((yyvsp[(1) - (1)].stringVal),"%s",(yyval.stringVal));}
    break;

  case 96:
#line 722 "parser.y"
    {sscanf((yyvsp[(1) - (1)].stringVal),"%s",(yyval.stringVal));}
    break;

  case 97:
#line 723 "parser.y"
    {sscanf((yyvsp[(1) - (1)].stringVal),"%s",(yyval.stringVal));}
    break;


/* Line 1267 of yacc.c.  */
#line 2516 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 729 "parser.y"

int yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
	return 0;
}
int main(void)
{
	file=fopen("a.jasm","w+");
	yyparse();
	fclose(file);
	return 0;
}

