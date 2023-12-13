#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef map<string, int> mapType;

void displayPopulation(mapType &populationMap)
{
    mapType::const_iterator it;
    cout << "\n========Population of states in India==========\n";
    cout << "SIze of PopulationMap : " << populationMap.size() << endl;
    string name;
    char ch;

    do
    {
        cout << "Enter the name of State: ";
        cin >> name;

        it = populationMap.find(name);
        if (it != populationMap.end())
            cout << name << " s population is " << it->second << endl;
        else
            cout << "Key not found" << endl;

        cout << "ENter the choice :";
        cin >> ch;

    } while (ch == 'y');
}

int main()
{
    mapType populationMap;
    populationMap.insert(pair<string, int>("Maharashtra", 7026357));
    populationMap.insert(pair<string, int>("Rajasthan", 6578936));
    populationMap.insert(pair<string, int>("Karnataka", 6678993));
    populationMap.insert(pair<string, int>("Punjab", 5789032));
    populationMap.insert(pair<string, int>("West Bengal", 6676291));

    displayPopulation(populationMap);

    populationMap.clear();

    return 0;
}