//Sri Subhash Pathuri - (CSE 1325-006)
//UTA Id: 1001733778

#include <iostream>
#include<string>
using namespace std;
#define pencilPrize 60

enum class statusMeaning
{
    PSoldChange,// Pencil Sold but change given.
    PSoldNoChange,  //Pencil sold but change not given.
    NoInventory,  // not enough pencils to buy.
    NoChange,  //not enough change to give to the user.
    NoSale,  // no sale happened because of insufficient amount. 
};

int menu()
{
    int response{0};
    do
    {
        if(response<0||response>3)
        {
            cout<<"\nInvalid menu choice. Please choose again";
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid menu choice. Please choose again. ";
        }
        cout<<"\n\nWelcome to my Pencil Machine"<<endl;
        cout<<"\nPlease choose from the following options"<<endl;
        cout<<"\n0. No pencils for me today";
        cout<<"\n1. Purchase pencils";
        cout<<"\n2. Check inventory level";
        cout<<"\n3. Check change level";
        cout<<"\n\nChoice : ";
        cin>>response;   
    }       
    while(cin.fail()||response<0||response>3);
    return response; 
}

string priceConversion(int amt)
{
    string dollar{to_string(amt/100)};
    string cents{to_string(abs(amt%100))};
    string Amt{"$"+dollar+"."+(cents.size()==1?"0":"")+cents};
    return Amt;
}

bool buyPencil(statusMeaning &status,int &inventory,int &change,int payAmt,int total,int pencilCount)
{
    if(inventory<pencilCount)
    {
        status=statusMeaning::NoInventory;
    }
    else
    {
        if(payAmt==total)
        {
            status=statusMeaning::PSoldNoChange;
            inventory-=pencilCount;
            return true;
        }
        else if(payAmt<total)
        {
            status=statusMeaning::NoSale; 
        }
        else if(payAmt>total)
        {
            if(change<(payAmt-total))
            {
                status=statusMeaning::NoChange;
            }
            else if(change>(payAmt-total))
            {
                change-=(payAmt-total);
                status=statusMeaning::PSoldChange;
                inventory-=pencilCount;
                return true;
            }
        }
    }
    return false;
}

int main() 
{
    int inventory{100};
    int change{500};
    int option{0};
    int pencilCount{0};
    int totalPrice{0};
    int paidAmt{0};
    int changePrevious{0};
    statusMeaning statusVar{};
    bool result{};

    do
    {
        option=menu();
        switch(option)
        {
            case 0:break;
            case 1:
            {
                if(inventory==0)
                {
                    cout<<"\nThe pencil Dispensor is out of inventory.";                    
                }
                else
                {
                    cout<<"\n\nA pencil costs "<<priceConversion(pencilPrize)<<endl;
                    cout<<"\nHow many pencils would you like to purchase? ";
                    cin>>pencilCount;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100,'\n');
                        cout<<"\nInput must be numeric. Please reenter ";
                        cin>>pencilCount;
                    }
                    if(pencilCount>inventory)
                    {
                        cout<<"\nThe machine does not have that many pencils - buy "<<inventory<<" or fewer";
                    }
                    else if(pencilCount<=0)
                    {
                        cout<<"\nYou must purchase at least one pencil.";
                    }
                    else
                    {
                        int totalPrice=pencilCount*pencilPrize;
                        cout<<"\nYour total is $"<<priceConversion(totalPrice)<<endl;
                        cout<<"\nEnter your payment (in cents) ";
                        cin>>paidAmt;
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(100,'\n');
                            cout<<"\nInput must be numeric. Please reenter  ";
                            cin>>paidAmt;
                        }
                        int total=pencilCount*pencilPrize;
                        changePrevious=change;
                        result=buyPencil(statusVar,inventory,change,paidAmt,total,pencilCount);
                        if(result)
                        {
                            switch(statusVar)
                            {
                                case statusMeaning::PSoldChange:
                                {
                                    cout<<"\nHere's your pencils and your change of "<<priceConversion(changePrevious-change)<<endl;
                                    break;
                                }
                                case statusMeaning::PSoldNoChange:
                                {
                                    cout<<"\nHere's your pencils. Thank you for exact payment.";
                                    break;
                                }
                            }
                        }
                        else
                        {
                            switch(statusVar)
                            {
                                case statusMeaning::NoChange:
                                {

                                    cout<<"\nThis Pencil Dispenser does not have enough change and cannot accept your payment.";
                                    break;
                                }
                                case statusMeaning::NoSale:
                                {
                                    cout<<"\nYou did not enter a sufficient payment. No pencils for you.";
                                    break;
                                }
                                case statusMeaning::NoInventory:
                                {
                                    if(!inventory)
                                        cout<<"\nThis pencil Dispenser is out of inventory.";
                                    else
                                        cout<<"\nThe machine does not have that many pencils - buy "<<inventory<<" or fewer."<<endl;
                                    break;
                                }
                                default:cout<<"\nSomething Unknown happened.";
                            }
                        }
                    }
                }
                break;
            }
            case 2:cout<<"\nThe current inventory level is "<<inventory;
                    break;
            case 3:cout<<"\nThe change level is "<<change;
                    break;
            default:cout<<"\n Please enter the correct input ";
        }
    }
    while(option!=0);
}
