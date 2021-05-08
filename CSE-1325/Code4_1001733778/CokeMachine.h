#include<iostream>
#include<string>

#ifndef COKEMACHINE_H
#define COKEMACHINE_H


class CokeMachine{
    public: 
        CokeMachine(std::string name="New Machine", int cost=50,int change=500, int inventory=100);
        ~CokeMachine();
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

        std::string getChangeLevel();
        std::string getMaxChangeCapacity();
        std::string getCokePrice();
        std::string displayMoney(int amount);
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