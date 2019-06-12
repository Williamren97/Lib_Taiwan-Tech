a.out:y.tab.o lex.yy.o
	gcc -o a lex.yy.o y.tab.o -lfl
y.tab.o:parser.y
		bison -y -d parser.y
		gcc -c -g y.tab.c
lex.yy.o:scanner.l
		lex scanner.l
		gcc -c -g lex.yy.c
clean:
	rm -f *.o
