#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<string> populateVector(vector<string> civList){
    //Tier 1
    civList.push_back("Babylon");
    civList.push_back("Egypt");
    civList.push_back("England");
    civList.push_back("Ethiopia");
    civList.push_back("Inca");
    civList.push_back("Korea");
    civList.push_back("Persia");
    civList.push_back("Poland");

    //Tier 2
    civList.push_back("Arabia");
    civList.push_back("Aztec");
    civList.push_back("China");
    civList.push_back("Greece");
    civList.push_back("Huns");
    civList.push_back("Maya");
    civList.push_back("Russia");
    civList.push_back("Shoshone");
    civList.push_back("Spain");

    //Tier 3
    civList.push_back("Brazil");
    civList.push_back("Byzantium");
    civList.push_back("Celts");
    civList.push_back("Germany");
    civList.push_back("India");
    civList.push_back("Indonesia");
    civList.push_back("Mongolia");
    civList.push_back("Morocco");
    civList.push_back("Ottomans");
    civList.push_back("Portugal");
    civList.push_back("Rome");
    civList.push_back("Siam");
    civList.push_back("Songhai");
    civList.push_back("Sweden");
    civList.push_back("Zulu");

    //Tier 4
    civList.push_back("America");
    civList.push_back("Assyria");
    civList.push_back("Austria");
    civList.push_back("Carthage");
    civList.push_back("Denmark");
    civList.push_back("Netherlands");

    //Tier 5
    civList.push_back("France");
    civList.push_back("Japan");
    civList.push_back("Polynesia");

    //Tier 6
    civList.push_back("Venice");
    civList.push_back("Iroquois");

    return civList;
}

vector<string>  banCiv(string civToBan, vector<string> civList, int show){ //set show to 1 if you want to print erase
    for(int i = 0; i<civList.size(); i++){
        if(civList[i] == civToBan){
            if(show == 1){
                cout<<civList[i]<<" was erased.\n"<<endl;
            }
            civList.erase(civList.begin() + i);
            return civList;
        }
    }
    return civList;
}

vector<string>  getCivs(int numCivs, vector<string> civList, float weight){

    //if more civs are requested than are available
    if(numCivs > civList.size()){
        cout<<"ALERT: There are not enough civs remaining.\n"<<endl;
        return civList;
    }

    //if the number of civs requested are exactly the same as the number left
    if(numCivs == civList.size()){
        for(int i = 0; i<civList.size(); i++){
            cout<<civList[i]<<endl;
        }
        cout<<"\n"<<endl;
        civList.clear();
        return civList;
    }

    //else get the selected number of civs randomly
    int randVal;
    cout<<"Your random civs are:\n"<<endl;
    for(int j=0; j<numCivs; j++){
        int numberOfCivsSubOne = civList.size() - 1; //used for random calculation

        randVal = rand() % numberOfCivsSubOne + 0;
        randVal = int(randVal/weight);

        if(randVal > numberOfCivsSubOne){ //so it can't go out of bounds
            randVal = numberOfCivsSubOne;
        }

        cout<<civList[randVal]<<endl;
        civList.erase(civList.begin() + randVal);
    }
    cout<<"\n"<<endl;
    return civList;
}

vector<string>  banBaseCivs(vector<string> civList){
    civList = banCiv("Venice", civList, 0);
    civList = banCiv("Polynesia", civList, 0);
    civList = banCiv("Songhai", civList, 0);
    civList = banCiv("Germany", civList, 0);
    return civList;
}

int main()
{
    srand (time(NULL));

    vector<string> civList;
    civList = populateVector(civList);
    civList = banBaseCivs(civList);

    int choice;
    string civChoice;
    int numCivChoice;

    float civWeight = 1.1; //make this value higher for consistently better civs, 1 is normal, less than 1 is worse

    int loopVar = 1;

    while(loopVar == 1){
        cout<<"----MAIN MENU----"<<endl;
        cout<<"1. Ban a civ"<<endl;
        cout<<"2. Get some civs"<<endl;
        cout<<"3. List remaining civs"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter a choice: ";
        cin >> choice;
        cout<<endl;

        switch(choice){
            case 1:
                cout<<"Civ to ban: ";
                cin>>civChoice;
                cout<<endl;

                civList = banCiv(civChoice, civList, 1);
                break;

            case 2:
                cout<<"Number of civs to pick: ";
                cin>>numCivChoice;
                cout<<endl;

                civList = getCivs(numCivChoice, civList, civWeight);
                break;

            case 3:
                cout<<"There are "<<civList.size()<<" civs remaining."<<endl;
                for(int i = 0; i<civList.size(); i++){
                    cout<<civList[i]<<endl;
                }
                cout<<"\n"<<endl;
                break;

            case 4:
                loopVar = 0;
                break;


        }
    }

    return 0;
}
