//Sri Subhash Pathuri; UTA Id-1001733778
//Coding Assignment 4- CSE1325-006
//Main .cpp file for the assignment

#include"CokeMachine.h"
#include"Cokelib.h"
using namespace std;

enum class ACTION 
{ //the status of the transaction from the previous coding assignment
    OK,
    NOINVENTORY,
    NOCHANGE,
    INSUFFICIENTFUNDS,
    EXACTCHANGE
};

void CokeMachineMenu(int &option) //menu for each indiviual CokeMachine
{
    
    cout << "\n0. Walk Away" << endl;
    cout << "1. Buy a Coke" << endl;
    cout << "2. Restock Machine" << endl;
    cout << "3. Add change" << endl;
    cout << "4. Display Machine Info" << endl;
    cout << "5. Set Machine Name" << endl; 
    cout << "6. Set Coke Price\n" << endl; 

    cout << "Choice: ";
    
    cin >> option; 

    //checking if input is a letter, and if it is, ask user to reenter
    while (cin.fail())
    {   //checking if the input stram fails
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\ninput must be numeric, please reenter ";
        cin >>option;
    }
}

int printMainClasses(vector<CokeMachine>& tempCokeSet,CokeMachine& MyCokeMachine)
{
    int option2=0,i=0;
    cout<<"\nPick a Coke Machine";
    cout<<"\n\n0. Exit";
    for(i=0;i<tempCokeSet.size();i++)
    {          //Printing different Coke machines 
        cout<<"\n"<<(i+1)<<" "<<tempCokeSet[i].GetMachineName();
    }
    cout<<"\n"<<i+1<<" Add a new Machine\n";

    cout<<"\nEnter choice ";

    cin>>option2;

    while(cin.fail()||option2<0||option2>(tempCokeSet.size()+1))
    {
        cin.clear();
        cin.ignore(100,'\n'); // checking if cin fails 
        cout<<"\nInvalid menu choice. Please choose again. ";
        cin>>option2;
    //At the end, 
    }
    
    if(option2>0&&option2<=(tempCokeSet.size()))
    {
        cout<<"\nYou choose "<<tempCokeSet[option2-1].GetMachineName();   
            // if we were able to find a machine, then we are notifying the user. 
    }

    return option2;
}



int main(int argc,char *argv[])
{

    vector<CokeMachine> SetOfCokeMachines;

    int option{0},option1{0},option2{0};
    int payment{};
    int action{},addChange{},addCoke{},newCokePrice{};
    string INPUTFILENAME{},OUTPUTFILENAME{},CokeMachineLine{};
    vector<string> ConstructorValues(4);

    string change{},newMachineName;
    CokeMachine MyCokeMachine{};

    try
    { // checking if the file is readable.  
        get_command_line_params(argc,argv, INPUTFILENAME, OUTPUTFILENAME);
    }
    catch(invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    ifstream CokeInputFile{INPUTFILENAME};
    
    
    if(CokeInputFile.is_open())
    {
        while(getline(CokeInputFile,CokeMachineLine))
        { 
            if(ParseCokeLine(CokeMachineLine,ConstructorValues))
            {   // reading each line of the file so that we can initialize each line as an object file. 
                CokeMachine tempMachine {ConstructorValues[0],stoi(ConstructorValues[1]),stoi(ConstructorValues[2]),stoi(ConstructorValues[3])};
                SetOfCokeMachines.push_back(tempMachine);
            }
        }
    }
    else
    {
        cout<<"\n Unable to open file";
        exit(0);
    }

        do
        {   // printing the menu and accepting the valid option from the user. 
            option2=printMainClasses(SetOfCokeMachines,MyCokeMachine);

            if(option2!=0&&option2==(SetOfCokeMachines.size()+1))
            {
                CokeMachine tempMachine;

                SetOfCokeMachines.push_back(tempMachine);
                cout<<"\n\nNew machine added";

            }
            else if(option2!=0)
            {
                //MyCokeMachine=SetOfCokeMachines.at(option2-1);
                do
                {   // This part copied from the Coding assignment 3
                    option=0;
                    change="";
                    cout<<"\n\n\n"<<SetOfCokeMachines.at(option2-1).GetMachineName();

                    CokeMachineMenu(option);

                    switch(option)
                    {
                        case 0:
                        {
                            cout<<"\nAre you sure you aren't really THIRSTY and need a Coke?\n";
                            
                            break;
                        }
                        case 1:
                        {
                            if(SetOfCokeMachines.at(option2-1).getInventoryLevel()==0)
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

                                SetOfCokeMachines.at(option2-1).buyACoke(payment, change, action);
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
                            if(SetOfCokeMachines.at(option2-1).incrementInventory(addCoke))
                            {
                                cout<<"\nYour machine has been restocked";
                                cout<<"\n\nYour inventory level is now "<<SetOfCokeMachines.at(option2-1).getInventoryLevel();
                            }
                            else
                            {
                                cout<<"\nYou have exceeded your machine's max capacity";   
                                cout<<"\n\nYour inventory level is now "<<SetOfCokeMachines.at(option2-1).getInventoryLevel();
                            }
                            break;
                        }
                        case 3:
                        {
                            cout<<"\nHow much change are you adding to the machine ";
                            cin>>addChange;

                            if(SetOfCokeMachines.at(option2-1).incrementChangeLevel(addChange))
                            {
                                cout<<"\n\nYour change has been updated";
                                cout<<"\nYour change level is now "<<SetOfCokeMachines.at(option2-1).getChangeLevel();
                            }
                            else
                            {
                                cout<<"\n\nYou have exceeded your machine's max change capacity";
                                cout<<"\n\nYour change level is now "<<SetOfCokeMachines.at(option2-1).getChangeLevel();
                            }
                            break;
                        }
                        case 4:
                        {
                            
                            cout<<SetOfCokeMachines.at(option2-1);
                            break;
                        }
                        case 5:
                        {
                            cout<<"\nEnter a new Machine name: ";
                            cin.ignore();
                            getline(cin,newMachineName);

                            SetOfCokeMachines.at(option2-1).setMachineName(newMachineName);

                            cout<<"\nMachine name has been updated.";

                            break;
                        }
                        case 6:
                        {
                            cout<<"\nUpdate the Coke price selected \n"<<endl;

                            cout<<"\nEnter a new Coke price"<<endl;
                            cin>>newCokePrice;

                            SetOfCokeMachines.at(option2-1).setCokePrice(newCokePrice);
                            break;
                        }
                        default:  
                            cout<<"\nInvalid input. Please choose the correct option..!";
                    } 
                }
                while(option!=0);  
            } 
        }
        while(option2!=0); // checking if the user wanted to exit out of the main menu by checking for 0

        ofstream CokeOutputFile{OUTPUTFILENAME,ios::out};
        // Once the user exits we are writing the contents to the specific output file. 
        if(option2==0)
        {
            if(CokeOutputFile.is_open())
            {
                for(int a=0;a<SetOfCokeMachines.size();a++)
                {
                    CreateCokeOutputLine(SetOfCokeMachines.at(a),CokeOutputFile);
                }
            }
            else
            {
                cout<<"\nThe Outfile did not open.";
            }
            
        }
    CokeInputFile.close();
    CokeOutputFile.close();
    return 0;  
} 

    