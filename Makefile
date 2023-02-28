#Makefile
CXXFLAGS = -std=c++11 -g

all: main test

game: cards.o main.o
	g++ $(CXXFLAGS) cards.o main.o -o game

tests: cards.o test.o
	g++ $(CXXFLAGS) cards.o tests.o -o test
	./tests

main.o: main.cpp
	g++ $(CXXFLAGS) main.cpp -c

tests.o: tests.cpp
	g++ $(CXXFLAGS) tests.cpp -c

cards.o: cards.cpp cards.h
	g++ $(CXXFLAGS) cards.cpp -c

clean:
	rm game tests *.o
