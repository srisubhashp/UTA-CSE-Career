//Sri Subhash Pathuri; UTA Id: 1001733778
//Coding Assignment 6

#include <thread>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <mutex>
#include <chrono>
#include <iostream>
#include "House.h"

#ifndef _CandyHouse_H_
#define _CandyHouse_H_

class CandyHouse : public House
{
    public:
        CandyHouse(std::string Name, std::map<int,std::string>CandyRanking);

        std::string ringDoorbell(std::ostringstream &path);

        //destructor
        ~CandyHouse()
        {
            std::cout<<"CANDYHOUSE \n";
        }
};

#endif
