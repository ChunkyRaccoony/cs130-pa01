  
CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field


prog1: prog1.cpp HashProgram.cpp BstTree.cpp
	${CXX} $^ -o $@

clean:
	rm prog1