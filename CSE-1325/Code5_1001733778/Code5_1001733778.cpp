// Coding Assignment 5 Template
//Sri Subhash Pathuri 10001733778

/* Add the needed includes */

#include "TrickOrTreater.h"
#include "House.h"

using namespace std;
void get_command_line_params(int argc, char *argv[], string& TOTfile, string& Housefile, string& Candyfile)
{
	/* if argc is 4, then put argv[1] in TOTfile, argv[2] in Housefile and argv[3] in Candyfile
	/* else throw an invalid_argument with the message shown in the output */
	int i;
	std::string cla;

	int checkCandy=0,checkHouse=0,checkTot=0;

	for(i=1;i<argc;i++)
	{
		cla=argv[i];
		if(cla.substr(0,cla.find("=")) == "TOTINPUT")
		{
			TOTfile=cla.substr(cla.find("=")+1,cla.length());
			checkTot = 1;
		}
		else if(cla.substr(0,cla.find("="))=="HOUSEINPUT")
		{
			Housefile=cla.substr(cla.find("=")+1,cla.length());
			checkHouse = 1;
		}
		else if(cla.substr(0,cla.find("="))=="CANDYINPUT")
		{
			Candyfile=cla.substr(cla.find("=")+1,cla.length());
			checkCandy = 1;
		}
	}
	if(!(checkCandy && checkHouse && checkTot))
	{
		throw invalid_argument("\nMissing command line parameters - Usage : TOTINPUT = HOUSEINPUT= CANDYINPUT= \n");
	}
}

int main(int argc, char *argv[])
{
	string TOTFilename, HouseFilename, CandyFilename;

	/*- create a map named CandyRankingMap of type int,string */
	map<int,string> CandyRankingMap;
	
	string CandyLine;
	char CandyLineA[50] = {};
	string CandyName;
	int CandyRanking;
	char *CandyPtr = NULL;

	/*- create a vector named Houses of type pointers to House */
	vector<House*> Houses;
	string HouseLine;

	/* create a vector named TOTs of type TrickOrTreater */
	vector<TrickOrTreater> TOTs;
	string TotLine;
	
	/* declare an ostringstream named HouseHeading */
	ostringstream HouseHeading;

	srand(time(NULL));
	
	/* create a try-catch block for function get_command_line_params */
	try
	{
		get_command_line_params(argc, argv, TOTFilename, HouseFilename, CandyFilename);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		exit(0);
	}

	/*- open all three files from command line for reading - use TOTFH, HouseFH and CandyFH */	
	ifstream CandyFH{CandyFilename};
	ifstream HouseFH{HouseFilename};
	ifstream TOTFH{TOTFilename};

	if(CandyFH.is_open()) 
	{
		while (getline(CandyFH,CandyLine))
		{/*- make getline read from CandyFH into CandyLine */
			strcpy(CandyLineA, CandyLine.c_str());
			CandyPtr = strtok(CandyLineA, "|");
			CandyName = CandyPtr;
			CandyPtr = strtok(NULL, "|");
			CandyRanking = atoi(CandyPtr);
			/*- call insert() and make_pair() with CandyRanking and CandyName */
			CandyRankingMap.insert(make_pair(CandyRanking, CandyName));
		}
	}
	else
	{
		cout<<"\n Unable to open file \""<<CandyFilename<<"\"...\n"<<endl;
	}
	
	/*- Close the Candy file - CandyFH */
	CandyFH.close();

	HouseHeading << "          ";
	
	if(HouseFH.is_open())
	{
		while(getline(HouseFH,HouseLine))
		{
			/*- in one line - use new to allocate a House object that is constructed by    */
			/*- passing HouseLine and CandyRankingMap and push_back the object into Houses */
			Houses.push_back(new House(HouseLine,CandyRankingMap));

			HouseHeading << HouseLine;
			for (int i = 0; i < 11 - HouseLine.length(); i++)
				HouseHeading << " ";
		}
	}
	else
	{
		cout<<"\nUnable to open file \""<<HouseFilename<<"\"...\n"<<endl;	
	}
	
		
	HouseHeading << endl << endl;
	/*- Close the House file - HouseFH */
	HouseFH.close();

	/*- Create all of the Trick or Treaters - NotVerified*/

	if(TOTFH.is_open())
	{
		while (getline(TOTFH,TotLine/*- make getline read from TOTFH into TotLine */))
		{
			TOTs.push_back(TrickOrTreater(TotLine, Houses));
		}
	}
	else
	{
		cout<<"\nUnable to open the file\""<<TOTFilename<<"\"...\n"<<endl;
	}
	
	/*- Close the TOT file - TOTFH */
	TOTFH.close();
	
	/*- Start all of the trick or treaters using a range based for loop over vector TOT */
	/*- call function startThread() for each iterator for each pass through the loop */
	for(auto& it: TOTs)
		it.startThread();
	

	while (TrickOrTreater::ImDone != TOTs.size() ) 
	{
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << HouseHeading.str();

        for (auto &it: TOTs/* range based for loop over TOTs */) 
		{
			cout <<it.getPath()<<it.getName()<</* call getName() for iterator */endl;
        }
		
		/* put this_thread to sleep for 5 milliseconds */
		this_thread::sleep_for(chrono::milliseconds(5));
    }	
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << HouseHeading.str();

	for (auto &it: TOTs) 
	{/*- range based for loop over TOTs */
		cout <<it.getPath()<<it.getName()<< endl;/*- call getName() for iterator */
	}
	
	for (auto &it: TOTs)
	{/*- range based for loop over TOTs */
		cout << it;
	}

	for (auto &it: TOTs)
	{
		it.joinThread();/*- Call function joinThread() for iterator */
	}

	for (auto &it: Houses)
	{
		delete it;/* use delete for iterator to return dynamically allocated memory */
	}
	
	return 0;
}