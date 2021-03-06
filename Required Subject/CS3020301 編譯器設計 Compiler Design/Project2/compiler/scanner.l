%{


char tempStrBuf[1024];

#include "y.tab.h"
#include <stdio.h>

%}
%x STRING
%%


"(*"([^\*]|(\*)*[^\*/])*(\*)*"*)" {}
"//"[^\n]* {}

"," {return (',');}

":" {return (':');}
";" {return (';');}
"(" {return ('(');}
")" {return (')');}
"[" {return ('[');}
"]" {return (']');}
"{" {return ('{');}
"}" {return ('}');}
"+" {return ('+');}
"-" {return ('-');}
"*" {return ('*');}
"/" {return ('/');}
"^" {return (',');}
"%" {return ('%');}
"&" {return ('&');}
"!" {return ('!');}
"=" {return ('=');}
"<" {return ('<');}
">" {return ('>');}
"." {return ('.');}

"<=" {strcpy(yylval.val, yytext);return (LE_OP);}
">=" {strcpy(yylval.val, yytext);return (GE_OP);}
"==" {strcpy(yylval.val, yytext);return (EQ_OP);}
"!=" {strcpy(yylval.val, yytext);return (NE_OP);}
"+=" {strcpy(yylval.val, yytext);return (ADD_ASSIGN);}
"-=" {strcpy(yylval.val, yytext);return (SUB_ASSIGN);}
"*=" {strcpy(yylval.val, yytext);return (MUL_ASSIGN);}
"/=" {strcpy(yylval.val, yytext);return (DIV_ASSIGN);}


"const" {strcpy(yylval.val, yytext);return (CONST);}
"else" {strcpy(yylval.val, yytext);return (ELSE);}
"then" {strcpy(yylval.val, yytext);return (THEN);}
"if" {strcpy(yylval.val, yytext);return (IF);}
"bool" {strcpy(yylval.val, yytext);return (BOOL);}
"integer" {strcpy(yylval.val, yytext);return (INT);}
"print" {strcpy(yylval.val, yytext);return (PRINT);}
"println" {strcpy(yylval.val, yytext);return (PRINTLN);}
"real" {strcpy(yylval.val, yytext);return (REAL);}
"return" {strcpy(yylval.val, yytext);return (RETURN);}
"string" {strcpy(yylval.val, yytext);return (STRINGKEYWORD);}
"var" {strcpy(yylval.val, yytext);return (VAR);}
"while" {strcpy(yylval.val, yytext);return (WHILE);}
"read" {strcpy(yylval.val, yytext);return (READ);}
"module" {strcpy(yylval.val, yytext);return (MODULE);}
"begin" {strcpy(yylval.val, yytext);return (BEG);}
"end" {strcpy(yylval.val, yytext);return (END);}
"procedure" {strcpy(yylval.val, yytext);return (PROCEDURE);}
"do" {strcpy(yylval.val, yytext);return (DO);}



true {strcpy(yylval.val, yytext);return (TRUE);}
false {strcpy(yylval.val, yytext);return (FALSE);}


([a-zA-Z]+[a-zA-Z0-9]*) {strcpy(yylval.val, yytext);return (IDENTIFIER);}
[0-9]+ {yylval.int_type = atoi(yytext);return (INTEGER);}

-?(([0-9]+)([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {sscanf(yytext, "%lf", &yylval.double_type);return (REALCONSTANTS);}

\"{1} {BEGIN(STRING);}
<STRING>([^"]*)+ {strcat(tempStrBuf, yytext);}
<STRING>"\"\"" {strcat(tempStrBuf, "\"\"");}
<STRING>\"{1} {strcpy(yylval.val, tempStrBuf);tempStrBuf[0] = '\0';BEGIN(INITIAL);
return (STR);}

(" ")* ;
^[ \t]*\n ;

[ \t]+$ ;

[\t\n]+   ;

%%
