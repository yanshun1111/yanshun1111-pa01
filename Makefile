#Makefile
CXXFLAGS = -std=c++11 -g -Wall -O0

all: main test

main: cards.cpp main.cpp
	g++ $(CXXFLAGS) cards.cpp main.cpp -o main
	./main a1.txt b1.txt

tests: cards.cpp test.cpp
	g++ $(CXXFLAGS) cards.cpp tests.cpp -o test
	./tests

clean:
	rm main
	rm tests
