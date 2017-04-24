CXX = g++
Flags = -Wno-missing-braces -O0 -march=native -I. -std=c++11 -g

%.o: %.cpp
	$(CXX) $(Flags) -c -o $@ $^

default: main.o bitboard.o MoveGeneration.o game.o
	$(MAKE) test
	$(CXX) $(Flags) $^ -o bitboards
	./bitboards

test: test.o bitboard.o MoveGeneration.o game.o
	$(CXX) $(Flags) $^ -o tests


clean:
	rm *.o
