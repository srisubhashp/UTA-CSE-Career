//Sri Subhash Pathuri; UTA Id - 1001733778

#include "ToothbrushHouse.h"

ToothbrushHouse::ToothbrushHouse(std::string Name, std::map<int, std::string> CandyRanking) : House(Name, CandyRanking)
{

}

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &path)
{
    //lock the door mutex
    door.lock();
    path << "-";
    //put this_thread to sleep for 3 seconds
    std::this_thread::sleep_for(std::chrono::seconds(3));
    //Pick a candy from the CandyRankingMap

    //unlock the door mutex
    door.unlock();
    return "TOOTHBRUSH";
}
