// Coding Assignment 5 Template

/* Add the needed includes */

using namespace std;

void get_command_line_params(int argc, char *argv[], string& TOTfile, string& Housefile, string& Candyfile)
{
	/* if argc is 4, then put argv[1] in TOTfile, argv[2] in Housefile and argv[3] in Candyfile
	/* else throw an invalid_argument with the message shown in the output */
}

int main(int argc, char *argv[])
{
	string TOTFilename, HouseFilename, CandyFilename;

	/* create a map named CandyRankingMap of type int,string */
	string CandyLine;
	char CandyLineA[50] = {};
	string CandyName;
	int CandyRanking;
	char *CandyPtr = NULL;

	/* create a vector named Houses of type pointers to House */
	string HouseLine;

	/* create a vector named TOTs of type TrickOrTreater */
	string TotLine;
	
	/* declare an ostringstream named HouseHeading */
	
	srand(time(NULL));
	
	/* create a try-catch block for function get_command_line_params */

	/* open all three files from command line for reading - use TOTFH, HouseFH and CandyFH */	

	while (getline(/* make getline read from CandyFH into CandyLine */))
	{
		strcpy(CandyLineA, CandyLine.c_str());
		CandyPtr = strtok(CandyLineA, "|");
		CandyName = CandyPtr;
		CandyPtr = strtok(NULL, "|");
		CandyRanking = atoi(CandyPtr);
		/* call insert() and make_pair() with CandyRanking and CandyName */
	}
	/* Close the Candy file - CandyFH */
	
	HouseHeading << "          ";
	
	while (getline(/* make getline read from HouseFH into HouseLine */))
	{
		/* in one line - use new to allocate a House object that is constructed by    */
		/* passing HouseLine and CandyRankingMap and push_back the object into Houses */
		HouseHeading << HouseLine;
		for (int i = 0; i < 11 - HouseLine.length(); i++)
			HouseHeading << " ";
	}
	HouseHeading << endl << endl;
	/* Close the House file - HouseFH */

	/* Create all of the Trick or Treaters */
	while (getline(/* make getline read from TOTFH into TotLine */))
	{
		TOTs.push_back(TrickOrTreater{TotLine, Houses});
	}
	/* Close the TOT file - TOTFH */
	
	/* Start all of the trick or treaters using a range based for loop over vector TOT */	
	/* call function startThread() for each iterator for each pass through the loop */
	
	while (TrickOrTreater::ImDone != TOTs.size() ) 
	{
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << HouseHeading.str();


        for (/* range based for loop over TOTs */) 
		{
			cout << /* call getPath() for iterator */ << /* call getName() for iterator */ << endl;
        }
		/* put this_thread to sleep for 5 milliseconds */
    }	
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << HouseHeading.str();

	for (/* range based for loop over TOTs */) 
	{
		cout << /* call getPath() for iterator */ << /* call getName() for iterator */ << endl;
	}
	
	for (/* range based for loop over TOTs */)
	{
		cout << it;
	}

	for (/* range based for loop over TOTs */)
	{
		/* Call function joinThread() for iterator */
	}

	for (/* range based for loop over Houses */)
	{
		/* use delete for iterator to return dynamically allocated memory */
	}
	
	return 0;
}