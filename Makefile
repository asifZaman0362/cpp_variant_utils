CC = g++
FLAGS = -Wall
STD = c++20

all: demo

demo: headers test.cc
	$(CC) $(FLAGS) --std=$(STD) test.cc

headers: src/errors.hpp src/result_t.hpp src/result.hpp

clean:
	rm -rf *.o *.out
