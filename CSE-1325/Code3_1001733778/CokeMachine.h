//Sri Subhash Pathuri; UTA Id-1001733778
//Coding Assignment 3- CSE1325-006
//Class Definition
#ifndef COKEMACHINE_H
#define COKEMACHINE_H

class CokeMachine{
    public: 
    CokeMachine(std::string name, int cost,int change, int inventory)
    {
        machineName=name;
        CokePrice=cost;
        changeLevel=change;
        inventoryLevel=inventory;
    }
    std::string GetMachineName()
    {
        return machineName;
    }
    bool buyACoke(int payment,std::string &change,int &action)
    {
         if(inventoryLevel==0)
        action=1;
        else if(changeLevel==0||((payment-CokePrice)>changeLevel&&(payment-CokePrice)>maxChangeCapacity))
            action=2;
        else
        {
            if(payment==CokePrice)
            {
                action=4;
                inventoryLevel--;
                changeLevel+=payment;
                return true;
            }
            else if(payment<CokePrice)
            {
                action=3;
            }
            else if(payment>CokePrice)
            {
                if((payment-CokePrice)<=changeLevel)
                {
                    action=0;
                    change=displayMoney(payment-CokePrice);
                    changeLevel+=CokePrice;
                    inventoryLevel--;
                    return true;
                }
                else
                {// ask Professor if the person pays 1 million and if it exceeds the maxchangeCapacity, what to do
                    action=3;
                }
            }
        }
        return false;
    }
    int getInventoryLevel()
    {
        return inventoryLevel;
    }
    int getMaxInventoryLevel()
    {
        return maxInventoryCapacity;
    }
    bool incrementInventory(int amountToAdd)
    {
        if((amountToAdd+inventoryLevel)>maxInventoryCapacity)
            return false;
        else
        {
            inventoryLevel+=amountToAdd;
        }
        return true;
    }
    std::string getChangeLevel()
    {
        return displayMoney(changeLevel);
    }
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
    std::string getMaxChangeCapacity()
    {
        return displayMoney(maxChangeCapacity);
    }
    std::string getCokePrice()
    {
        return displayMoney(CokePrice);
    }
    std::string displayMoney(int amount)
    {
        std::string dollar{std::to_string(amount/100)};
        std::string cents{std::to_string(abs(amount%100))};
        std::string Amt{"$"+dollar+"."+(cents.size()==1?"0":"")+cents};
        return Amt;
    }

    private:
        std::string machineName;
        int changeLevel;
        int maxChangeCapacity=5000;
        int CokePrice;
        int inventoryLevel;
        int maxInventoryCapacity=100;
};

#endif