BINARY=brot
SOURCES=brainrot-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c

all:
	gcc $(SOURCES) -o $(BINARY)

install:
	cp $(BINARY) /usr/local/bin/
