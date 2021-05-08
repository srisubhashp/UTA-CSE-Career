#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<cstdlib>
#include"Test-CA2.cpp"

#define numDice 5
#define numFaces 6
#define numRolls 3
#define testRolls 23
using namespace std;

void RollDice(vector<int> &dice1)
{
    srand(time(NULL));
    for(int i=0;i<numFaces;i++)
    {
        dice1.push_back((rand()%numFaces)+1);
    }
}

void PrintRoll(vector<int>dice)
{
    for(int item:dice)
    {
        cout<<item<<" ";
    }
    cout<<"\n";
}

void HowMany(vector<int>&dice, vector<int>&faceCount)
{
    for(int i:dice)
    {
        faceCount[i-1]++;
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
        cout<<"\nKeep "<<dice[i]<<"?";
        cin>>option2;

        if(option2=='y'||option2=='Y')
        {
            i++;
            ctr++;
        }
        else if(option2=='n'||option2=='N')
        {
            dice.erase(dice.begin()+i);
            dice.push_back((rand()%6)+1);
            ctr++; 
        }

    }
}

int main(int argc,char* argv[]) {

    int counter{0};
    vector<int> dice{},howMany(6,0);
    int ofAKind=0,FullHouse=0,TwoPair=0,CPPSlam=0,LargeStraight=0,SmallStraight=0;
    char option{'y'};

    if(argc==2&&strcmp(argv[1],"TEST")==0)
    {   int result1=0;string expectedType{},calcType{};
        while(counter<testRolls)
        {
            ofAKind=0,FullHouse=0,TwoPair=0,CPPSlam=0,LargeStraight=0,SmallStraight=0;
            expectedType=TestRollDice(dice);

            cout<<"You rolled ";
            PrintRoll(dice);
            HowMany(dice, howMany);

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
                calcType="Large Straight";
            else if(SmallStraight>=4)
                calcType="Small Straight";
            else if(FullHouse==5)
                calcType="FullHouse";
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

        cout<<"\nOut of "<<testRolls<<" tests, "<<result1<<" test passed and "<<testRolls-result1<<" tests failed.";

    }
    else
    {
    
        RollDice(dice);

        while(counter<=numRolls&&option=='y')
        {   
            ofAKind=0,FullHouse=0,TwoPair=0,CPPSlam=0,LargeStraight=0,SmallStraight=0;

            cout<<"You rolled ";
            PrintRoll(dice);
            HowMany(dice, howMany);

            for(int i=0;i<6;i++)
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
                cout<<"\nFullHouse";
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

        if(counter<numRolls){

            cout<<"\n\n\n Do you want to reroll? ";
            cin>>option;

            if(option=='y')
            
            {  
                PickDice(dice);
                /*for(int i=0;i<dice.size();i++)
                {
                    cout<<"\nKeep "<<dice[i]<<"?";
                    cin>>option2;

                    if(option2=='n')
                    {
                        dice.erase(dice.begin()+i);
                        dice.push_back((rand()%6)+1);
                    }
                }*/
            }
            

        }
        counter++;
        }
    
    }
}