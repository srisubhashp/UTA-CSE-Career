#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;

void get_command_line_params(int argc, char *argv[], std::string& totFile,std::string& houseFile,std::string& candyFile)
{
	int i;
	if(argc == 4)
    {
        totFile=argv[1];
        houseFile=argv[2];
        candyFile=argv[3];     
    }
	else
	{
		throw std::invalid_argument("\nRequired number of Command line parameters missing.\n");
	}
}
int main(int agrc,char *argv[])
{
    
	map<int,string> candyMap;
	string totFile,houseFile,candyFile;
	string line;//1 - for getting the string from file. 2- for getting the specific part.
	char *token;
	
	try
	{
		get_command_line_params(argc,argv,totFile,houseFile,candyFile);
	} //checking the exception.
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(0);
	}
	
	ifstream InputFile{candyFile};

	if(inputFile.is_open())
	{
		int i=0;
		while(getline(InputFile,line))
		{
			candyMap.insert(make_pair(i++,line));
		}
	}
	else
	{
		cout<<"\nUnable to open the Candy File";
	}

	cout<<"\n Contents of the Coding Assignment 5:\n";
	for(auto it: candyMap)
		cout<<"\n"<<candyMap.first<<" "<<candyMap.second<<endl;
	
	InputFile.close();
}