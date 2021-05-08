// Treat or Tricker class header file template
//Sri Subhash Pathuri; UTA Id-1001733778
//Coding Assignment 6
/* add the necessary includes */
#include<iostream>
#include<thread>
#include<string>
#include<cstring>
#include<sstream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<map>
#include"House.h"

/* add an include guard called _TOT_H */
#ifndef _TOT_H
#define _TOT_H

class TrickOrTreater
{
	/* create friend function prototype */
	friend std::ostream& operator<<(std::ostream& output,const TrickOrTreater &TOT);

	public :
		TrickOrTreater(std::string Name, std::vector<House*> List);
		/* create the prototype for the constructor based on TrickOrTreater.cpp */
		std::string getName();
		void startThread();
		void joinThread();
		void GoTrickOrTreating();
		void Walk(int); 
		std::string getPath();
		static int ImDone;
	private :
		std::string name;
		std::ostringstream path;
		std::thread *TOTThreadPtr = nullptr;
		std::map<std::string,int>Bucket;/* declare a map named Bucket of type string,int */
		std::vector<House*>ListOfHouses;/* declare a vector name ListOfHouses of type pointer to House */
};

#endif