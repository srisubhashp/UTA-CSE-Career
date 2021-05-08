//Sri Subhash Pathuri; UTA-Id:1001733778
//Coding Asssignment-5

// Trick or Treater Class Template

#include "TrickOrTreater.h"

int TrickOrTreater::ImDone = 0;

TrickOrTreater::TrickOrTreater(std::string Name, std::vector<House*>List)
	: name{Name}, ListOfHouses{List}
{
}

void TrickOrTreater::Walk(int speed) 
{
    for (int i = 0; i < 10; ++i) 
	{	
		path << '.';
		//* put this_thread to sleep for speed milliseconds 
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
	}
}
void TrickOrTreater::GoTrickOrTreating()
{
	int speed = 0;

	for(auto &it: ListOfHouses)/* range based for loop over ListOfHouses */
	{	
		speed = rand()%500 + 1;   // speed is between 1 and 500
		
		Walk(speed);/* call function Walk and pass it speed */
		Bucket[it->ringDoorbell(path)]++;
	}
	
	ImDone++;// Increment ImDone because this thread is done trick or treating
}

std::string TrickOrTreater::getName()
{
	return name;
}

void TrickOrTreater::startThread()
{
	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
	this->TOTThreadPtr->join();
	delete this->TOTThreadPtr;
}

std::string TrickOrTreater::getPath()
{
	return path.str();
	/* return the string version of ostringstream path */
}

std::ostream &operator<<(std::ostream& output,const TrickOrTreater &TOT)
{
	output <<"\n"<< TOT.name << "'s - ";

	/* create a range based for loop using TOT.Bucket    */
	/* use the insertion operator to write the map element to output */
	for(auto& it: TOT.Bucket)
	{
		output<<it.second<<" "<<it.first<<",";
	}

	return output;
}
