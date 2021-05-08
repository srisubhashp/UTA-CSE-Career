//Sri Subhash Pathuri UTA-Id: 1001733778
//Coding Assignment-5
// House Class Template

#include "House.h"

House::House(std::string Name, std::map<int,std::string>CandyRanking)
	:houseName{Name}, CandyRankingMap{CandyRanking}
{
}

std::string House::ringDoorbell(std::ostringstream &path)
{
	door.lock();/* lock the door mutex */
	path << "*";
	/* put this_thread to sleep for 3 seconds */
	std::this_thread::sleep_for(std::chrono::seconds(3));

	//Pick a candy from the CandyRankingMap
	int candy = rand() % (CandyRankingMap.size()) + 1;

	door.unlock();/* unlock the door mutex */
	return CandyRankingMap[candy];
}