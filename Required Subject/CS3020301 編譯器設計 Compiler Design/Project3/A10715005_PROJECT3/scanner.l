%{
	#include "y.tab.h"

	enum symbolType
	{
		string,integer,boolean,real
	};
	struct SymbolTableStruct
	{
		char name[100];
		char type[10];
	};
	struct SymbolTableStruct allSymbolTable[100];
	int allSymbolCount=0;
	char content[256];
	void addContent()	{strcat(content,yytext);}
	int lineCount=0;

%}
letter	[A-Za-z]
digit	[0-9]
digits	{digit}+
%x COMMENT
%%
,	{addContent();/*printf("<'%s'>\n",yytext);*/return COMMA;}
:	{addContent();/*printf("<'%s'>\n",yytext);*/return COLON;}
;	{addContent();/*printf("<'%s'>\n",yytext);*/return SEMICOLON;}
"("	{addContent();/*printf("<'%s'>\n",yytext);*/return LEFTPARENTHESES;}
")"	{addContent();/*printf("<'%s'>\n",yytext);*/return RIGHTPARENTHESES;}
"["	{addContent();/*printf("<'%s'>\n",yytext);*/return LEFTSQUAREBRACKETS;}
"]"	{addContent();/*printf("<'%s'>\n",yytext);*/return RIGHTSQUAREBRACKETS;}
"{"	{addContent();/*printf("<'%s'>\n",yytext);*/return BRACKETS;}
"}"	{addContent();/*printf("<'%s'>\n",yytext);*/return BRACKETS;}

"+"	{addContent();/*printf("<'%s'>\n",yytext);*/return PLUS;}
"-"	{addContent();/*printf("<'%s'>\n",yytext);*/return MINUS;}
"*"	{addContent();/*printf("<'%s'>\n",yytext);*/return MULTIPLY;}
"/"	{addContent();/*printf("<'%s'>\n",yytext);*/return DIVIDE;}
"%"	{addContent();/*printf("<'%s'>\n",yytext);*/return REMAINDER;}

"<"	{addContent();/*printf("<'%s'>\n",yytext);*/return LESS;}
"<="	{addContent();/*printf("<'%s'>\n",yytext);*/return LESSEQUAL;}
">="	{addContent();/*printf("<'%s'>\n",yytext);*/return GREATEREQUAL;}
">"	{addContent();/*printf("<'%s'>\n",yytext);*/return GREATER;}
=	{addContent();/*printf("<'%s'>\n",yytext);*/return EQUAL;}
"<>"	{addContent();/*printf("<'%s'>\n",yytext);*/return NOTEQUAL;}
&&	{addContent();/*printf("<'%s'>\n",yytext);*/return AND;}
"||"	{addContent();/*printf("<'%s'>\n",yytext);*/return OR;}
~	{addContent();/*printf("<'%s'>\n",yytext);*/return XOR;}

:=	{addContent();/*printf("<'%s'>\n",yytext);*/return ASSIGNMENT;}

array	{addContent();/*printf("<%s>\n",yytext);*/return ARRAY;}
boolean	{addContent();/*printf("<%s>\n",yytext);*/sscanf("boolean","%s",&yylval);return BOOLEAN;}
begin	{addContent();/*printf("<%s>\n",yytext);*/return BEGIN_;}
break	{addContent();/*printf("<%s>\n",yytext);*/return BREAK;}
char	{addContent();/*printf("<%s>\n",yytext);*/return CHAR;}
case	{addContent();/*printf("<%s>\n",yytext);*/return CASE;}
const	{addContent();/*printf("<%s>\n",yytext);*/return CONST;}
continue	{addContent();/*printf("<%s>\n",yytext);*/return CONTINUE;}
do	{addContent();/*printf("<%s>\n",yytext);*/return DO;}
else	{addContent();/*printf("<%s>\n",yytext);*/return ELSE;}
end	{addContent();/*printf("<%s>\n",yytext);*/return END;}
exit	{addContent();/*printf("<%s>\n",yytext);*/return EXIT;}
for	{addContent();/*printf("<%s>\n",yytext);*/return FOR;}
fn	{addContent();/*printf("<%s>\n",yytext);*/return FN;}
if	{addContent();/*printf("<%s>\n",yytext);*/return IF;}
in	{addContent();/*printf("<%s>\n",yytext);*/return IN;}
integer	{addContent();/*printf("<%s>\n",yytext);*/sscanf("integer","%s",&yylval);return INTEGER;}
loop	{addContent();/*printf("<%s>\n",yytext);*/return LOOP;}
module	{addContent();/*printf("<%s>\n",yytext);*/return MODULE;}
print	{addContent();/*printf("<%s>\n",yytext);*/return PRINT;}
println	{addContent();/*printf("<%s>\n",yytext);*/return PRINTLN;}
procedure	{addContent();/*printf("<%s>\n",yytext);*/return PROCEDURE;}
repeat	{addContent();/*printf("<%s>\n",yytext);*/return REPEAT;}
return	{addContent();/*printf("<%s>\n",yytext);*/return RETURN;}
real	{addContent();/*printf("<%s>\n",yytext);*/sscanf("real","%s",&yylval);return REAL;}
string	{addContent();/*printf("<%s>\n",yytext);*/sscanf("string","%s",&yylval);return STRING;}
record	{addContent();/*printf("<%s>\n",yytext);*/return RECORD;}
then	{addContent();/*printf("<%s>\n",yytext);*/return THEN;}
type	{addContent();/*printf("<%s>\n",yytext);*/return TYPE;}
use	{addContent();/*printf("<%s>\n",yytext);*/return USE;}
util	{addContent();/*printf("<%s>\n",yytext);*/return UTIL;}
var	{addContent();/*printf("<%s>\n",yytext);*/return VAR;}
while	{addContent();/*printf("<%s>\n",yytext);*/return WHILE;}
read	{addContent();/*printf("<%s>\n",yytext);*/return READ;}
of	{addContent();/*printf("<%s>\n",yytext);*/return OF;}

{digits}	{addContent();/*printf("<integer:%s>\n",yytext);*/sscanf(yytext,"%d",&yylval);return INTEGERCONSTANTS;}
true	{addContent();/*printf("<boolean:%s>\n",yytext);*/sscanf("1","%d",&yylval);return BOOLEANCONSTANTS;}
false	{addContent();/*printf("<boolean:%s>\n",yytext);*/sscanf("0","%d",&yylval);return BOOLEANCONSTANTS;}
{digits}"."{digits}([Ee][+-]?{digits})?	{addContent();/*printf("<real:%s>\n",yytext);*/return REALCONSTANTS;}
\"[^\"]*\"	{
				char c=input();	
				if(c=='\"')
					yymore();	
				else
				{		
					addContent();
					for(int i=0;i<yyleng-1;i++)
						yytext[i]=yytext[i+1];
					yytext[yyleng-2]='\0';
					for(int i=0;i<yyleng-1;i++)
					{
						if(yytext[i]=='\"' && yytext[i+1]=='\"')
						{
							for(int j=i;j<yyleng-1;j++)
								yytext[j]=yytext[j+1];
						}
					}	
					unput(c);	
					//printf("<string:%s>\n",yytext);
					strcpy(yylval.stringVal,yytext);
					return STRINGCONSTANTS;
				}	
				unput(c);
			}

{letter}({letter}|{digit})*	{
								if(lookup(allSymbolTable,yytext,allSymbolCount)==-1)
								{
									addSymbol(allSymbolTable,yytext,allSymbolCount);
									allSymbolCount++;
								}	
								addContent();
								//printf("<id: %s>\n",yytext);
								sscanf(yytext,"%s",&yylval);
								return IDENTIFIER;
							}

[ \t]	{addContent();}
"//".*	{addContent();}

"(*"	{addContent();BEGIN(COMMENT);}
<COMMENT>.	{addContent();}
<COMMENT>\n	{
				lineCount++;
				//printf("%d: %s\n",lineCount,content);
				content[0]='\0';
			}
<COMMENT>"*)"	{addContent();BEGIN(INITIAL);}

\n	{
		lineCount++;
		//printf("%d: %s\n",lineCount,content);
		content[0]='\0';
	}

"."	{
			addContent();
			//printf("<'.'>\n");
			lineCount++;
			//printf("%d: %s\n",lineCount,content);
			content[0]='\0';
			//dump(allSymbolTable,allSymbolCount);
			return PERIOD;
		}
%%
