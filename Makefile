CFLAGS = -g -Wall -Wextra

lextest: main.o lex.yy.o errormsg.o util.o grammar.o
	gcc $(CFLAGS) -o lextest main.o lex.yy.o errormsg.o util.o grammar.o

main.o: main.c tokens.h errormsg.h util.h
	gcc $(CFLAGS) -c main.c

errormsg.o: errormsg.c errormsg.h util.h
	gcc $(CFLAGS) -c errormsg.c

lex.yy.o: lex.yy.c tokens.h errormsg.h util.h
	gcc $(CFLAGS) -c lex.yy.c

lex.yy.c: tiger.lex
	flex tiger.lex

util.o: util.c util.h
	gcc $(CFLAGS) -c util.c

grammar.o: grammar.c grammar.h
	gcc $(CFLAGS) -c grammar.c



clean: 
	rm -f a.out util.o main.o lex.yy.o lex.yy.c errormsg.o grammar.o