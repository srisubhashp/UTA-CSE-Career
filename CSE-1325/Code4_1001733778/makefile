#Sri Subhash Pathuri 1001733778
#makefile for Coding Assignment 4

SRC1=Code4_1001733778.cpp
SRC2=CokeMachine.cpp
SRC3=CokeLib.cpp
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
CBJ3 = $(SRC3:.cpp=.o)
EXE = $(SRC:.cpp=.e)

HFILES = CokeMachine.h CokeLib.h

CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) -o $(EXE)

$(OBJ1) : $(SRC1)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2) : $(SRC2)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3) : $(SRC3)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3)