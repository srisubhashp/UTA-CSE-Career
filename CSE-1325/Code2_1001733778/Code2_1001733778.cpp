//Sri Subhash Pathuri, UTA Id - 1001733778; CSe 1325-006
//Coding Assignment 2= C++ Slam

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<cstdlib>

#define numDice 5
#define numFaces 6
#define numRolls 3
#define testRolls 23
using namespace std;

string TestRollDice(vector<int> &dice); //prototype

void RollDice(vector<int> &dice1)
{
    srand(time(NULL));
    for(int i=0;i<numFaces;i++)
    {
        dice1.push_back((rand()%numFaces)+1); // asigning random values to all elements of the dice1 vector.
    }
}

void PrintRoll(vector<int>dice)
{
    for(int item:dice)
    {
        cout<<item<<" "; // displaying the item with a blank space
    }
    cout<<"\n";
}

void FillHowMany(vector<int>&dice, vector<int>&howMany)
{
    for(int &j: howMany)
    {
        j=0;
    }

    for(int i:dice)
    {
        howMany[i-1]++; // initializing the values of the howMany vector with the count of each dice face. 
    }
}

void PickDice(vector<int>&dice)
{   
    char option2{};
    int ctr=0,i=0;
    cout<<"\n Pick which dice to reroll. Answer y at the prompt to keep that die.";
    i=0;
    while(ctr<numFaces)
    {
        cout<<"\nKeep "<<dice[i]<<" ? ";
        cin>>option2;

        if(option2=='y'||option2=='Y')
        {
            i++;
            ctr++;  // this is the main counter variable which is incremented irrespective of if we reach the end of the dice Array.
        }
        else if(option2=='n'||option2=='N')
        {
            dice.erase(dice.begin()+i);
            dice.push_back((rand()%numFaces)+1);  // first erasing and them passing the random value at last.  
            ctr++; 
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid choice. Please choose again. ";
        }
        else
        {
            cout<<"\nInvalid choice. Please choose again.\n";
        }
        

    }
}

int main(int argc,char* argv[]) 
{
    int counter{0};
    vector<int> dice{},howMany(numFaces,0);
    int ofAKind=0,FullHouse=0,TwoPair=0,CPPSlam=0,LargeStraight=0,SmallStraight=0;
    char option{'y'}; 

    if(argc==2&&strcmp(argv[1],"TEST")==0) // checking if the command line parameter has TEST in it. 
    {   int result1=0;
        string expectedType{},calcType{};
        while(counter<testRolls)  // cheking so that it does not cross the number of Test rolls 
        {

            ofAKind=0,FullHouse=0,TwoPair=0,CPPSlam=0,LargeStraight=0,SmallStraight=0;
            expectedType=TestRollDice(dice);  // receiving the expected result from the TestRollDice function in Test.cpp

            cout<<"\nYou rolled ";
            PrintRoll(dice);
            FillHowMany(dice, howMany);

            for(int i=0;i<numFaces;i++)
            {          // starting the analysis to figure out the best pattern present.
                if(howMany[i]==3)
                    FullHouse+=3;
                if(howMany[i]==2)
                {
                    FullHouse+=2;
                    TwoPair++;
                }
                if(howMany[i]==5)
                    CPPSlam++;
                if(howMany[i]==1)
                    LargeStraight++;
                else if(howMany[i]==0&&LargeStraight>0&&LargeStraight<5)
                    LargeStraight=0;
                
                if(howMany[i]>=1)
                    SmallStraight++;
                else if(howMany[i]==0&&SmallStraight>0&&SmallStraight<4)
                    SmallStraight=0;
                
                if(howMany[i]==4)
                    ofAKind=4;
                if(howMany[i]==3)
                    ofAKind=3;
            }

            if(LargeStraight==5)
                calcType="Large Straight";
            else if(SmallStraight>=4)
                calcType="Small Straight";
            else if(FullHouse==5)
                calcType="Full House";
            else if(CPPSlam==1)
                calcType="C++Slam!";
            else if(ofAKind==4)
                calcType="Four of a Kind";
            else if(ofAKind==3)
                calcType="Three of a Kind";
            else if(TwoPair==2)
                calcType="Two Pair";
            else
                calcType="You have nothing";

            cout<<"\n"<<calcType<<endl;

            if(calcType.compare(expectedType)==0) 
            {
                cout<<"\nTest Passed\n";
                result1++;
            }
            else
                cout<<"\nTest Failed\n";
            counter++;
        }

        cout<<"\nOut of "<<testRolls<<" tests, "<<result1<<" test passed and "<<testRolls-result1<<" tests failed."<<endl;
    }
    else
    { // if TEST is not present, going through the standard way. 
    
        RollDice(dice);
        while(counter<=numRolls&&option=='y')
        {   
            ofAKind=0,FullHouse=0,TwoPair=0,CPPSlam=0,LargeStraight=0,SmallStraight=0;
            
            for(int i=0;i<numFaces;i++)
            {
                howMany[i]=0;
            }
            cout<<"You rolled ";
            PrintRoll(dice);
            FillHowMany(dice, howMany);

            for(int i=0;i<numFaces;i++)
            {
                if(howMany[i]==3)
                    FullHouse+=3;
                if(howMany[i]==2)
                {
                    FullHouse+=2;
                    TwoPair++;
                }
                if(howMany[i]==5)
                {
                    CPPSlam++;
                }

                if(howMany[i]==1)
                    LargeStraight++;
                else if(howMany[i]==0&&LargeStraight>0&&LargeStraight<5)
                    LargeStraight=0;
                
                if(howMany[i]>=1)
                    SmallStraight++;
                else if(howMany[i]==0&&SmallStraight>0&&SmallStraight<4)
                    SmallStraight=0;
                
                if(howMany[i]==4)
                    ofAKind=4;
                if(howMany[i]==3)
                    ofAKind=3;
            }

            if(LargeStraight==5)
                cout<<"\nLarge Straight";
            else if(SmallStraight>=4)
                cout<<"\nSmall Straight";
            else if(FullHouse==5)
                cout<<"\nFull House";
            else if(CPPSlam==1)
                cout<<"\nC++Slam!";
            else if(ofAKind==4)
                cout<<"\nFour of a Kind";
            else if(ofAKind==3)
                cout<<"\nThree of a Kind";
            else if(TwoPair==2)
                cout<<"\nTwo Pair";
            else
                cout<<"\n You have nothing";

            if(counter<numRolls)
            {
                cout<<"\n\n\n Do you want to reroll? ";
                cin>>option;

                if(option=='y')
                {  
                    PickDice(dice); // showing the user with the options if he wants to reroll each dice. 
                }
            }
            counter++;
        }
    }
}