#include "CandyHouse.h"

CandyHouse::CandyHouse(std::string Name, std::map<int,std::string>CandyRanking): House(Name,CandyRanking)
{
    
}

std::string CandyHouse::ringDoorbell(std::ostringstream &path)
{
    door.lock();/* lock the door mutex */
    path << "+";
    /* put this_thread to sleep for 3 seconds */
    std::this_thread::sleep_for(std::chrono::seconds(3));

    //Pick a candy from the CandyRankingMap
    int candy = rand() % (CandyRankingMap.size()) + 1;

    door.unlock();/* unlock the door mutex */
    return CandyRankingMap[candy];
}

