%{
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
	
%}


%token COMMA COLON SEMICOLON LEFTPARENTHESES RIGHTPARENTHESES LEFTSQUAREBRACKETS RIGHTSQUAREBRACKETS BRACKETS PLUS MINUS MULTIPLY DIVIDE REMAINDER LESS LESSEQUAL GREATEREQUAL GREATER EQUAL NOTEQUAL AND OR XOR ASSIGNMENT ARRAY BOOLEAN BEGIN_ BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT FOR FN IF IN INTEGER LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT RETURN REAL STRING RECORD THEN TYPE USE UTIL VAR WHILE INTEGERCONSTANTS BOOLEANCONSTANTS REALCONSTANTS STRINGCONSTANTS IDENTIFIER PERIOD READ OF

%union
{
	int integerVal;
	char stringVal[100];
}
%type <stringVal> IDENTIFIER
%type <stringVal> datatype
%type <stringVal> STRING
%type <stringVal> INTEGER
%type <stringVal> REAL
%type <stringVal> BOOLEAN
%type <stringVal> proceduretype
%type <stringVal> constant
%type <integerVal> INTEGERCONSTANTS
%type <integerVal> BOOLEANCONSTANTS
%type <stringVal> STRINGCONSTANTS
%type <stringVal> expression

%left OR
%left AND
%left XOR
%left LESS LESSEQUAL EQUAL GREATEREQUAL GREATER NOTEQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE
%nonassoc UMINUS

%%

//Program
program:MODULE 
IDENTIFIER
{
	//Generate Code
	fprintf(file,"class a\n{\n");
}
variableconstant_decs
{
	scope=local;
} 
function_decs 
BEGIN_ 
{
	//Generate Code
	fprintf(file,"method public static void main(java.lang.String[])\nmax_stack 15\nmax_locals 15\n{\n");
}
zero_statements END 
IDENTIFIER
{
	if(strcmp($2,$11))
		printf("Wrong Program Name:line%d\n",lineCount+1);
	//Generate Code
	fprintf(file,"return\n}\n}");
} 
PERIOD
;

//Declarations
variableconstant_decs:variableconstant_dec variableconstant_decs
|
;
variableconstant_dec:CONST constant_decs
|VAR variable_decs	
|array_decs	
;
//Constants
constant_decs:constant_dec constant_decs
|constant_dec array_decs	
|constant_dec	
;
constant_dec:IDENTIFIER EQUAL constant SEMICOLON	{addSymbol($1);typeCount++;addType($3,constant);addValue(constInt,constString);}	
;
//Variables
variable_decs:variable_dec variable_decs
|variable_dec array_decs	
|variable_dec	
;
variable_dec:identifiers COLON datatype SEMICOLON	{addType($3,variable);}	
;
//Array
array_decs:array_dec array_decs	
|array_dec	
;
array_dec:identifiers COLON ARRAY LEFTSQUAREBRACKETS INTEGERCONSTANTS COMMA INTEGERCONSTANTS RIGHTSQUAREBRACKETS OF datatype SEMICOLON	{addType($10,variable);}	
;
//Identifiers
identifiers:IDENTIFIER COMMA identifiers	{addSymbol($1);typeCount++;}
|IDENTIFIER	{addSymbol($1);typeCount++;}
;

//FunctionDeclarations
function_decs:PROCEDURE 
IDENTIFIER
{
	addProcedure($2);
	//Generate Code
	fprintf(file,"method public static int %s(",$2);
} 
arguments 
proceduretype
{
	sscanf($5,"%s",procedureTable[procedureCount-1].type);
	//Generate Code
	fprintf(file,")\nmax_stack 15\nmax_locals 15\n{\n");
} 
variableconstant_decs BEGIN_ statements END 
IDENTIFIER
{
	if(strcmp($2,$11))
		printf("Wrong Procedure Name:line%d\n",lineCount+1);
	localSymbolCount=0;
	//Generate Code
	if(strcmp("void",$5))
		fprintf(file,"ireturn\n}\n");
	else
		fprintf(file,"return\n}\n");
} 
SEMICOLON function_decs	
|
;
arguments:LEFTPARENTHESES IDENTIFIER COLON datatype
{
	addSymbol($2);
	typeCount++;
	addType($4,variable);
	sscanf($4,"%s",procedureTable[procedureCount-1].formalType[procedureTable[procedureCount-1].formalTypeCount]);
	procedureTable[procedureCount-1].formalTypeCount++;
	//Generate Code
	fprintf(file,"int");
} 
argument RIGHTPARENTHESES	
|
;
argument:COMMA IDENTIFIER COLON datatype
{
	addSymbol($2);
	typeCount++;
	addType($4,variable);
	sscanf($4,"%s",procedureTable[procedureCount-1].formalType[procedureTable[procedureCount-1].formalTypeCount]);
	procedureTable[procedureCount-1].formalTypeCount++;
	//Generate Code
	fprintf(file,",int");
}
argument	
|
;
proceduretype:COLON datatype	{sscanf($2,"%s",$$);}
|	{sscanf("void","%s",$$);}
;

//Statements
statements:statement	
|statement statements	
;
statement:
IDENTIFIER{checkScope($1);} ASSIGNMENT expression SEMICOLON	
{
	if(strcmp(getSymbolType($1),$4))
			printf("Assignment Not Consistent:line%d\n",lineCount+1);
	//Generate Code
	int index=lookup(globalSymbolTable,$1,globalSymbolCount);
	if(index!=-1)
		fprintf(file,"putstatic int a.%s\n",$1);
	else
	{
		index=lookup(localSymbolTable,$1,localSymbolCount);
		fprintf(file,"istore %d\n",index);
	}
}
|IDENTIFIER{checkScope($1);} LEFTSQUAREBRACKETS expression RIGHTSQUAREBRACKETS ASSIGNMENT expression SEMICOLON
{
	if(strcmp(getSymbolType($1),$7))
		printf("Assignment Not Consistent:line%d\n",lineCount+1);
	if(strcmp($4,"integer"))
		printf("Only Integer:line%d\n",lineCount+1);
}
|PRINT
{
	//Generate Code
	fprintf(file,"getstatic java.io.PrintStream java.lang.System.out\n");
} 
expression 
SEMICOLON
{
	//Generate Code
	if(!strcmp("string",$3))
		fprintf(file,"invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
	else if(!strcmp("boolean",$3))
		fprintf(file,"invokevirtual void java.io.PrintStream.print(boolean)\n");
	else
		fprintf(file,"invokevirtual void java.io.PrintStream.print(int)\n");
}	
|PRINTLN
{
	//Generate Code
	fprintf(file,"getstatic java.io.PrintStream java.lang.System.out\n");
}
expression 
SEMICOLON
{
	//Generate Code
	if(!strcmp("string",$3))
		fprintf(file,"invokevirtual void java.io.PrintStream.println(java.lang.String)\n");
	else if(!strcmp("boolean",$3))
		fprintf(file,"invokevirtual void java.io.PrintStream.println(boolean)\n");
	else
		fprintf(file,"invokevirtual void java.io.PrintStream.println(int)\n");
}	
|READ IDENTIFIER{checkScope($2);} SEMICOLON
|RETURN SEMICOLON	
|RETURN expression SEMICOLON
|IF LEFTPARENTHESES expression RIGHTPARENTHESES 
THEN 
{
	//Generate Code
	fprintf(file,"ifeq Lif%d\n",ifLabelCount);
} 
zero_statements else_statements END 
SEMICOLON
{
	if(strcmp($3,"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
}
|WHILE
{
	//Generate Code
	fprintf(file,"Lwhile%d:\n",whileLabelCount);
} 
LEFTPARENTHESES 
expression
{
	//Generate Code
	fprintf(file,"ifeq Lwhile%d\n",whileLabelCount+1);
} 
RIGHTPARENTHESES DO 
zero_statements
{
	//Generate Code
	fprintf(file,"goto Lwhile%d\nLwhile%d:\n",whileLabelCount,whileLabelCount+1);
	whileLabelCount+=2;
} 
END SEMICOLON	
{
	if(strcmp($4,"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
}
|IDENTIFIER{checkProcedure($1);} SEMICOLON 
{
	int index=lookupProcedure(procedureTable,$1,procedureCount);
	if(procedureTable[index].formalTypeCount!=0)
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	//Generate Code
	if(strcmp("void",procedureTable[index].type))
		fprintf(file,"invokestatic int a.%s()\n",$1);
	else
		fprintf(file,"invokestatic void a.%s()\n",$1);
	
}
|IDENTIFIER
{
	checkProcedure($1);
	sscanf($1,"%s",callProcedureName);
} 
LEFTPARENTHESES commaseparated_expressions RIGHTPARENTHESES SEMICOLON
{
	//Generate Code
	int index=lookupProcedure(procedureTable,$1,procedureCount);
	fprintf(file,"invokestatic int a.%s(int",$1);
	for(int i=0;i<procedureTable[index].formalTypeCount-1;i++)
		fprintf(file,",int");
	fprintf(file,")\n");
}
;
//Else Statements
else_statements:ELSE
{
	fprintf(file,"goto Lif%d\nLif%d:\n",ifLabelCount+1,ifLabelCount);
} 
zero_statements
{
	fprintf(file,"Lif%d:\n",ifLabelCount+1);
	ifLabelCount+=2;
}
|
{
	fprintf(file,"Lif%d:\n",ifLabelCount);
	ifLabelCount++;
}
;

//Expression
expression:MINUS expression %prec UMINUS	
{
	sscanf($2,"%s",$$);
	//Generate Code
	fprintf(file,"ineg\n");
}
|expression MULTIPLY expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf($1,"%s",$$);
	//Generate Code
	fprintf(file,"imul\n");
}
|expression DIVIDE expression
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf($1,"%s",$$);
	//Generate Code
	fprintf(file,"idiv\n");
}	
|expression PLUS expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf($1,"%s",$$);
	//Generate Code
	fprintf(file,"iadd\n");
}
|expression MINUS expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf($1,"%s",$$);
	//Generate Code
	fprintf(file,"isub\n");
}
|expression REMAINDER expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf($1,"%s",$$);
	//Generate Code
	fprintf(file,"irem\n");
}
|LEFTPARENTHESES expression RIGHTPARENTHESES	{sscanf($2,"%s",$$);}
|constant	
{
	sscanf($1,"%s",$$);
	//Generate Code
	if(strcmp($1,"string"))
		fprintf(file,"sipush %d\n",constInt);
	else
		fprintf(file,"ldc \"%s\"\n",constString);
}
|IDENTIFIER //Variable or Function
{
	checkall($1);
	char* type=getSymbolType($1);
	if(strcmp(type,"null"))
	{
		sscanf(type,"%s",$$);
		//Generate Code
		int index=lookup(globalSymbolTable,$1,globalSymbolCount);
		//Global
		if(index!=-1)
		{
			//Variable
			if(globalSymbolTable[index].varconst==variable)
				fprintf(file,"getstatic int a.%s\n",$1);
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
			index=lookup(localSymbolTable,$1,localSymbolCount);
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
		int index=lookupProcedure(procedureTable,$1,procedureCount);
		if(index!=-1)
		{
			if(procedureTable[index].formalTypeCount!=0)
				printf("Parameter Type Not Match:line%d\n",lineCount+1);
			sscanf(procedureTable[index].type,"%s",$$);
			//Generate Code
			if(strcmp("void",procedureTable[index].type))
				fprintf(file,"invokestatic int a.%s()\n",$1);
			else
				fprintf(file,"invokestatic void a.%s()\n",$1);
		}
	}	
} 
|IDENTIFIER
{
	checkProcedure($1);
	sscanf($1,"%s",callProcedureName);
} 
LEFTPARENTHESES commaseparated_expressions 
RIGHTPARENTHESES	
{
	sscanf(procedureTable[lookupProcedure(procedureTable,$1,procedureCount)].type,"%s",$$);
	//Generate Code
	int index=lookupProcedure(procedureTable,$1,procedureCount);
	fprintf(file,"invokestatic int a.%s(int",$1);
	for(int i=0;i<procedureTable[index].formalTypeCount-1;i++)
		fprintf(file,",int");
	fprintf(file,")\n");
}
|IDENTIFIER{checkScope($1);} LEFTSQUAREBRACKETS expression RIGHTSQUAREBRACKETS	
{
	if(strcmp($4,"integer"))
		printf("Only Integer:line%d\n",lineCount+1);
	sscanf(getSymbolType($1),"%s",$$);
}
//BooleanExpression
|expression LESS expression
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"isub\niflt Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
|expression LESSEQUAL expression
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"isub\nifle Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}	
|expression EQUAL expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"isub\nifeq Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
|expression GREATEREQUAL expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"isub\nifge Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
|expression GREATER expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"isub\nifgt Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
|expression NOTEQUAL expression	
{
	if(strcmp($1,$3))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"isub\nifne Lboolean%d\niconst_0\ngoto Lboolean%d\nLboolean%d:iconst_1\nLboolean%d:\n",booleanLabelCount,booleanLabelCount+1,booleanLabelCount,booleanLabelCount+1);
	booleanLabelCount+=2;
}
|expression XOR expression
{
	if(strcmp($1,"boolean")||strcmp($3,"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"ixor\n");
}
|expression AND expression
{
	if(strcmp($1,"boolean")||strcmp($3,"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"iand\n");
}	
|expression OR expression
{
	if(strcmp($1,"boolean")||strcmp($3,"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",$$);
	//Generate Code
	fprintf(file,"ior\n");
}	
;
commaseparated_expressions:expression
{
	int index=lookupProcedure(procedureTable,callProcedureName,procedureCount);
	if(strcmp($1,procedureTable[index].formalType[parameterCount]))
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	else if(parameterCount+1!=procedureTable[index].formalTypeCount)
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	parameterCount=0;
}
|expression
{
	int index=lookupProcedure(procedureTable,callProcedureName,procedureCount);
	if(strcmp($1,procedureTable[index].formalType[parameterCount]))
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	parameterCount++;
} 
COMMA commaseparated_expressions
;
//constant
constant:STRINGCONSTANTS	{sscanf("string","%s",$$);strcpy(constString,$1);}
|INTEGERCONSTANTS	{sscanf("integer","%s",$$);constInt=$1;}
|BOOLEANCONSTANTS	{sscanf("boolean","%s",$$);constInt=$1;}
|REALCONSTANTS	{sscanf("real","%s",$$);}
;
//DataType
datatype:STRING	{sscanf($1,"%s",$$);}
|INTEGER	{sscanf($1,"%s",$$);}
|REAL	{sscanf($1,"%s",$$);}
|BOOLEAN	{sscanf($1,"%s",$$);}
;
//ZeroStatements
zero_statements:statements	
|
;
%%
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
