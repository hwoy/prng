CC=gcc
CFLAGS=-g -std=c99 -pedantic

BIN=a

.PHONY: all clean

all: $(BIN)

$(BIN):	main.o lcg.o minstd.o distribution.o
	$(CC) -o $(BIN) main.o lcg.o minstd.o distribution.o



clean:
	rm -rf *.o *.exe $(BIN)
	
format:
	clang-format -i -style=WebKit *.h *.c *.cpp


lcg.o: lcg.c lcg.h
minstd.o: minstd.c minstd.h lcg.h
main.o: main.c minstd.h lcg.h distribution.h
distribution.o: distribution.c distribution.h
