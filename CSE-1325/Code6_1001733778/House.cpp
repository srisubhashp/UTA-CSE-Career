//Sri Subhash Pathuri UTA-Id: 1001733778
//Coding Assignment-6
// House Class Template

#include "House.h"

House::House(std::string Name, std::map<int,std::string>CandyRanking)
	:houseName{Name}, CandyRankingMap{CandyRanking}
{
	
}

House::~House()
{
	std::cout<<"HOUSE \n";
}