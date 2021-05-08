//Sri Subhash Pathuri; UTA Id-1001733778
//Coding Assignment 3- CSE1325-006

#include<iostream>
#include<vector>
#include<string>
#include"CokeMachine.h"
using namespace std;

enum class ACTION 
{
    OK,
    NOINVENTORY,
    NOCHANGE,
    INSUFFICIENTFUNDS,
    EXACTCHANGE
};


int main(void)
{
    int option{0};
    int payment{};
    int action{},addChange{},addCoke{};

    string change{};
    CokeMachine MyCokeMachine{"CSE 1325 Coke Machine", 50, 500, 100};
        
    do
    {
        option=0;
        change="";
        cout<<"\n\n\n"<<MyCokeMachine.GetMachineName();
        cout<<"\n\n\n0. Walk Away.";
        cout<<"\n\n1. Buy a Coke";
        cout<<"\n\n2. Restock Machine";
        cout<<"\n\n3. Add change";
        cout<<"\n\n4. Display machine Info\n\n";
        cin>>option;

        switch(option)
        {
            case 0:
            {
                cout<<"\nAre you sure you aren't really THIRSTY and need a Coke?\n";
                break;
            }
            case 1:
            {
                if(MyCokeMachine.getInventoryLevel()==0)
                {
                    cout<<"\nThe Coke dispenser is out of inventory.\n";
                }
                else
                {
                    cout<<"\n\nInsert payment ";
                    cin>>payment;

                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100,'\n');
                        cout<<"\nInput must be numeric. Please re-enter = ";
                        cin>>option;
                    }

                    MyCokeMachine.buyACoke(payment, change, action);
                    switch(action)
                    {
                        case 0: 
                        {
                            cout<<"\nHere's your Coke and your change of "<<change;
                            break;    
                        }
                        case 1:
                        {
                            cout<<"\n\nNo Coke is available...returning your payment";
                            break;
                        }
                        case 2:
                        {
                            cout<<"\n\nUnable to give change at this time...returning your payment";
                            break;
                        }
                        case 3:
                        {
                            cout<<"\n\nInsufficent payment...returning your payment";
                            break;
                        }
                        case 4:
                        {
                            cout<<"\nThank you for exact change";
                            cout<<"\nHere's your Coke";
                            break;
                        }
                    }
                }
                break;
            }
            case 2: 
            {
                cout<<"\nHow much product are you adding to the machine? ";
                cin>>addCoke;
                if(MyCokeMachine.incrementInventory(addCoke))
                {
                    cout<<"\nYour machine has been restocked";
                    cout<<"\n\nYour inventory level is now "<<MyCokeMachine.getInventoryLevel();
                }
                else
                {
                    cout<<"\nYou have exceeded your machine's max capacity";   
                    cout<<"\n\nYour inventory level is now "<<MyCokeMachine.getInventoryLevel();
                }
                break;
            }
            case 3:
            {
                cout<<"\nHow much change are you adding to the machine ";
                cin>>addChange;

                if(MyCokeMachine.incrementChangeLevel(addChange))
                {
                    cout<<"\n\nYour change has been updated";
                    cout<<"\nYour change level is now "<<MyCokeMachine.getChangeLevel();
                }
                else
                {
                    cout<<"\n\nYou have exceeded your machine's max change capacity";
                    cout<<"\n\nYour change level is now "<<MyCokeMachine.getChangeLevel();
                }
                break;
            }
            case 4:
            {
                cout<<"\nCurrent Inventory Level "<<MyCokeMachine.getInventoryLevel();
                cout<<"\nMax Inventory Capacity "<<MyCokeMachine.getMaxInventoryLevel();
                cout<<"\n\nCurrent Change Level "<<MyCokeMachine.getChangeLevel();
                cout<<"\nMax Change Capacity "<<MyCokeMachine.getMaxChangeCapacity();
                cout<<"\n\nCurrent Coke Price is "<<MyCokeMachine.getCokePrice();
                break;
            }
            default:  
                cout<<"\nInvalid input. Please choose the correct option..!";
        } 
    }
    while(option!=0);  
}