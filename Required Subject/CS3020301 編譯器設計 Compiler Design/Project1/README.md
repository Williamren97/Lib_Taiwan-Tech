# 2019-Compiler-project1

## How to Building

Run `Makefile`

```
make
```

Otherwise, compile via  commonly

```
lex scanner.l
mv lex.yy.c lex.yy.cc
g++ -o scanner -O lex.yy.cc -ll
```

## How to execute Modula file

Set example modula file as stdin

```
./scanner < HelloWorld.modula
