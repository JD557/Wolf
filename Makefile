main:wolf.cpp grammar.o
	g++ wolf.cpp grammar.cpp -o wolf

grammar.o:grammar.cpp
	g++ -c grammar.cpp -o grammar.o

