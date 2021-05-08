#FirstName LastName 1001234567
#makefile for Coding Assignment 2: C++ SLAM
SRC1 = Code2_1001733778.cpp
SRC2 = Test.cpp
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
EXE = $(SRC1:.cpp=.e)

CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) -o $(EXE)

$(OBJ1) : $(SRC1)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)
	
$(OBJ2) : $(SRC2)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)
	

