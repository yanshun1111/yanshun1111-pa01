#Makefile
CXXFLAGS = -std=c++11 -g -Wall -O0

all: main test

game: cards.cpp main.cpp
	g++ $(CXXFLAGS) cards.cpp main.cpp -o game
	./game

tests: cards.cpp test.cpp
	g++ $(CXXFLAGS) cards.cpp tests.cpp -o test
	./tests

clean:
	rm game tests
