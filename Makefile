CXX = g++
Flags = -Wno-missing-braces -O3 -march=native -I. -std=c++11

%.o: %.cpp
	$(CXX) $(Flags) -c -o $@ $^

default: main.o bitboard.o MoveGeneration.o game.o
	$(CXX) $(Flags) $^ -o bitboards
