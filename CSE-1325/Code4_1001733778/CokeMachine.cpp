#include"CokeMachine.h"


CokeMachine::CokeMachine(std::string name="New Machine", int cost=50,int change=500, int inventory=100)
{
    machineName=name;
    CokePrice=cost;
    changeLevel=change;
    inventoryLevel=inventory;
}

std::string CokeMachine::GetMachineName()
{
    return machineName;
}

bool CokeMachine::buyACoke(int payment,std::string &change,int &action)
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

int CokeMachine::getInventoryLevel()
{
    return inventoryLevel;
}
int CokeMachine::getMaxInventoryLevel()
{
    return maxInventoryCapacity;
}

bool CokeMachine::incrementInventory(int amountToAdd)
{
    if((amountToAdd+inventoryLevel)>maxInventoryCapacity)
        return false;
    else
    {
        inventoryLevel+=amountToAdd;
    }
    return true;
}

std::string CokeMachine::getChangeLevel()
{
    return displayMoney(changeLevel);
}

std::string CokeMachine::getMaxChangeCapacity()
{
    return displayMoney(maxChangeCapacity);
}

std::string CokeMachine::getCokePrice()
{
    return displayMoney(CokePrice);
}

std::string CokeMachine::displayMoney(int amount)
{
    std::string dollar{std::to_string(amount/100)};
    std::string cents{std::to_string(abs(amount%100))};
    std::string Amt{"$"+dollar+"."+(cents.size()==1?"0":"")+cents};
    return Amt;
}

void CokeMachine::setMachineName(std::string newMachineName)
{
    machineName=newMachineName;
}

void CokeMachine::setCokePrice(int newPrice)
{
    CokePrice=newPrice;
}

CokeMachine::~CokeMachine()
{
    std::cout<<"\nCokeMachine Machine "<<machineName<<" has been destryed.";
}