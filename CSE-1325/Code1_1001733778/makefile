#Sri Subhash Pathuri;UTA Id: 1001733778
#CSE 1325-006
#makefile for C++ program of Coding Assignment 1

SRC = Code1_1001733778.cpp
OBJ = $(SRC:.cpp=.o)
EXE = $(SRC:.cpp=.e)

CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ) 
	g++ $(CFLAGS) $(OBJ) -o $(EXE) 

$(OBJ) : $(SRC)
	g++ -c $(CFLAGS) $(SRC) -o $(OBJ) 

