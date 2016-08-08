CXX = g++
Flags = -Wall -Wextra -O3 -march=native -I. -std=c++11

%.o: %.cpp
	$(CXX) $(Flags) -c -o $@ $^

default: main.o
	$(CXX) $(Flags) $^ -o bitboards
