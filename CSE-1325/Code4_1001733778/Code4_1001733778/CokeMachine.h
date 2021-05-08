//Sri Subhash Pathuri; UTA Id - 1001733778
//Coding Assignment- 4
//CSE 1325-006


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>


#ifndef COKEMACHINE_H
#define COKEMACHINE_H

class CokeMachine
{

    friend std::ostream& operator<<(std::ostream& output, const CokeMachine& MyCokeMachine);
    friend void CreateCokeOutputLine(const CokeMachine& tempCokeSet,std::ostream& outputStream);
    public: 
        CokeMachine(std::string name="New Machine", int cost=50,int change=500, int inventory=100);
        ~CokeMachine();//destructor
        bool buyACoke(int payment,std::string &change,int &action);
        
        int getInventoryLevel();
        std::string GetMachineName();

        int getMaxInventoryLevel();
        bool incrementInventory(int amountToAdd);
        
        bool incrementChangeLevel(int amountToAdd)
        {
            if((amountToAdd+changeLevel)>maxChangeCapacity)
                return false;
            else
            {
                changeLevel+=amountToAdd;
            }
            return true;
        }

        std::string getChangeLevel() const;
        std::string getMaxChangeCapacity() const;
        std::string getCokePrice() const;
        std::string displayMoney(int amount) const;
        void setMachineName(std::string newMachineName);
        void setCokePrice(int newPrice);

    private:
        std::string machineName;
        int changeLevel;
        int maxChangeCapacity=5000;
        int CokePrice;
        int inventoryLevel;
        int maxInventoryCapacity=100;
};

#endif