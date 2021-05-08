//Sri Subhash Pathuri; UTA Id - 1001733778
//Coding Assignment- 4
//CSE 1325-006

#include"CokeMachine.h"

CokeMachine::CokeMachine(std::string name, int cost,int change, int inventory)
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

void CreateCokeOutputLine(const CokeMachine& tempCoke,std::ostream& CokeOutputFile)
{

    CokeOutputFile<<tempCoke.machineName<<"|"<<tempCoke.CokePrice<<"|"<<tempCoke.changeLevel<<"|"<<tempCoke.inventoryLevel<<"\n";

}

std::ostream& operator<<(std::ostream& output, const CokeMachine& MyCokeMachine)
{
    output<<"\nMachine Name : "<<MyCokeMachine.machineName;// printing out the machine name
    output<<"\nCurrent Inventory Level "<<MyCokeMachine.inventoryLevel;
    output<<"\nMax Inventory Capacity "<<MyCokeMachine.maxInventoryCapacity;
    output<<"\n\nCurrent Change Level "<<MyCokeMachine.getChangeLevel();
    output<<"\nMax Change Capacity "<<MyCokeMachine.getMaxChangeCapacity();
    output<<"\n\nCurrent Coke Price is "<<MyCokeMachine.getCokePrice();
    return output;
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

std::string CokeMachine::getChangeLevel() const
{
    return displayMoney(changeLevel);
}

std::string CokeMachine::getMaxChangeCapacity() const
{
    return displayMoney(maxChangeCapacity);
}
std::string CokeMachine::getCokePrice() const
{
    return displayMoney(CokePrice);
}

std::string CokeMachine::displayMoney(int amount) const
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

CokeMachine::~CokeMachine() //Destructor
{
    std::cout<<"\nCokeMachine Machine "<<machineName<<" has been destroyed.";
}