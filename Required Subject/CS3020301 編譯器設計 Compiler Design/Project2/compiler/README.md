# 2019-Compiler-project2

## Building

Run `Makefile`

```
make
```

## Usage

Set example modula file as stdin

```
./parser < example.modula
```

## Change

### scanner.l

- add return token to yacc

- add a series token to yacc

- Remove the part that uses SymbolTable

- Set the return value of the token

- In the token part of id, bool, int, str, set the value to be passed to parser

- Remove the main function
