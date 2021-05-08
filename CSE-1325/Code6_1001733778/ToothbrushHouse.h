//Sri Subhash Pathuri
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


#ifndef _ToothbrushHouse_H_
#define _ToothbrushHouse_H_

class ToothbrushHouse : public House 
{
    public:
        ToothbrushHouse(std::string Name, std::map<int,std::string>CandyRanking);
        std::string ringDoorbell(std::ostringstream &path);

        ~ToothbrushHouse()
        {
            std::cout<<"TOOTHBRUSHHOUSE "<<std::endl;
        }

};


#endif
