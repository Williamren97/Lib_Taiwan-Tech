%{

#define MAX_LINE_LENG 256
#define LIST strcat(buf, yytext)
#define token(t) { LIST; printf("<%s>\n", #t); }
#define tokenChar(t) { LIST; printf("<'%c'>\n", t); }
#define tokenInteger(t,i) { LIST; printf("<%s: %d>\n", #t, i); }
#define tokenString(t,s) { LIST; printf("<%s: %s>\n", #t, s); }

#include <string>
#include <map>
#include <vector>


using std::string;
using std::map;
using std::vector;



int linenum = 1;
char buf[MAX_LINE_LENG];

class SymbolTable {
  private:
    vector<string> symbols;
    map<string, int> table_map;
    int index;
  public:
    SymbolTable();
    int lookup(string s);
    int insert(string s);
    int dump();
};

SymbolTable *table;

%}

ARITHMETIC              ([-+*/%])
DELIMITER               ([,:;.()[\]{}])
IDENTIFIER              ([A-Za-z_][0-9A-Za-z_]*)
DIGIT                   ([0-9]+)
INTEGER                 ({DIGIT})
RELATIONAL              ([<>!=])
REAL                    ([-+]?{DIGIT}\.{DIGIT}?([Ee](-+)?{DIGIT})?)
STRING                  (\"(\"\"|[^"\n])*\")
SINGLE_COMMENT          (\/\/[^\n]*)
BEGIN_COMMENT           (\/\*)
END_COMMENT             (\*\/)

%x COMMENT

%%

 /* single character token */
{DELIMITER}  |
{ARITHMETIC} |
{RELATIONAL}            { tokenChar(yytext[0]); }

 /* Double-character token */
"++"                    { token('++'); }
"--"                    { token('--'); }
"<="                    { token('<='); }
">="                    { token('>='); }
"=="                    { token('=='); }
"!="                    { token('!='); }
"&&"                    { token('&&'); }
"||"                    { token('||'); }
"+="                    { token('+='); }
"-="                    { token('-='); }
"*="                    { token('*='); }
"/="                    { token('/='); }

 /* keyword */
"int"                   { token(INT); }
"let"                   { token(LET); }
"loop"                  { token(LOOP); }
"bool"                  { token(BOOL); }
"break"                 { token(BREAK); }
"char"                  { token(CHAR); }
"continue"              { token(CONTINUE); }
"do"                    { token(DO); }
"else"                  { token(ELSE); }
"enum"                  { token(ENUM); }
"extern"                { token(EXTERN); }
"false"                 { token(FALSE); }
"float"                 { token(FLOAT); }
"match"                 { token(MATCH); }
"for"                   { token(FOR); }
"fn"                    { token(FN); }
"if"                    { token(IF); }
"in"                    { token(IN); }
"print"                 { token(PRINT); }
"println"               { token(PRINTLN); }
"return"                { token(RETURN); }
"self"                  { token(SELF); }
"struct"                { token(STRUCT); }
"true"                  { token(TRUE); }
"use"                   { token(USE); }
"where"                 { token(WHERE); }
"while"                 { token(WHILE); }
"begin"                 { token(begin); }
"end"                   { token(end); }
"module"                { token(module); }
"static"                { token(STATIC); }
"str"                   { token(STR); }
 /* example.modula token */
"procedure"             { token(procedure); }
"var"                   { token(var); }
"integer"               { token(integer); }
"const"                 { token(const); }
 /* sigma.modula token */
"sum"                 { token(sum); }
"index"               { token(index); }

{INTEGER}               {
                          tokenInteger(INTEGER, atoi(yytext));
                        }

{IDENTIFIER}            {
                          tokenString(id, yytext);
                          //push to symbol table
                          table->insert(yytext);
                        }

{REAL}                  {
                          tokenString(REAL, yytext);
                        }

{STRING}                {
                          char s[MAX_LINE_LENG] = {0};
                          int idx = 0;
                          for (int i = 1; i < yyleng - 1; ++i) {
                            if (yytext[i] == '"') ++i;
                            s[idx++] = yytext[i];
                          }
                          tokenString(STRING, s);
                        }

  /* comment */
{SINGLE_COMMENT}        { LIST; }

{BEGIN_COMMENT}         {
                          LIST;
                          BEGIN COMMENT;
                        }

<COMMENT>[^\n]          {
                          LIST;
                        }

<COMMENT>\n             {
                          LIST;
                          printf("%d: %s", linenum, buf);
                          linenum++;
                          buf[0] = '\0';
                        }

<COMMENT>{END_COMMENT}  {
                          LIST;
                          BEGIN INITIAL;
                        }

\n                      {
                          LIST;
                          printf("%d: %s", linenum, buf);
                          linenum++;
                          buf[0] = '\0';
                        }

[ \t]*                  { LIST; }

.                       {
                          LIST;
                          printf("%d:%s\n", linenum, buf);
                          printf("bad character:'%s'\n",yytext);
                          exit(-1);
                        }

%%

SymbolTable::SymbolTable()
{
  index = 0;
}

int SymbolTable::lookup(string s)
{
  if (table_map.find(s) != table_map.end()) {
    return table_map[s];
  }
  else {
    return -1;
  }
}

int SymbolTable::insert(string s)
{
  if (table_map.find(s) != table_map.end()) {
    return -1;
  }
  else {
    symbols.push_back(s);
    table_map[s] = index;
    return index++;
  }
}

void create()
{
  table = new SymbolTable();
}

int SymbolTable::dump()
{
  for (int i = 0; i < index; ++i) {
    printf("%d:\t%s\n", i, symbols[i].c_str());
  }
  return index;
}



int main()
{
  create();
  yylex();
  printf("\n%s\n", "Symbol Table:");
  table->dump();
}
