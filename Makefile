CC=gcc
CXX=g++
CFLAGS=-g -std=c99 -pedantic
CXXFLAGS=-g -std=c++11 -pedantic

BIN=lcg

BIN2=mt

.PHONY: all clean

all: $(BIN) $(BIN2)

$(BIN):	main.o lcg.o minstd.o distribution.o
	$(CC) -o $(BIN) main.o lcg.o minstd.o distribution.o
	
$(BIN2):	main2.o lcg.o minstd.o distribution.o
	$(CXX) -o $(BIN2) main2.o lcg.o minstd.o distribution.o



clean:
	rm -rf *.o *.exe $(BIN) $(BIN2)
	
format:
	clang-format -i -style=WebKit *.h *.c *.cpp


lcg.o: lcg.c lcg.h
minstd.o: minstd.c minstd.h lcg.h
main.o: main.c minstd.h lcg.h distribution.h
main2.o: main2.cpp mt19937_64.h
distribution.o: distribution.c distribution.h
