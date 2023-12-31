#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<string, int> mapType;

void displayPopulation(const mapType& populationMap) {
    mapType::const_iterator iter; // Change iterator type to const_iterator
    cout << "\n========Population of states in India==========\n";
    cout << "\nSize of populationMap: " << populationMap.size() << "\n";
    string state_name;
    char ch;

    do {
        cout << "\nEnter name of the state: ";
        getline(cin, state_name);

        iter = populationMap.find(state_name);
        if (iter != populationMap.end())
            cout << state_name << "'s population is " << iter->second << endl;
        else
            cout << "Key is not in populationMap\n";

        cout << "Enter choice (y/n): ";
        cin >> ch;
        cin.ignore(); // Ignore the newline character left in the buffer
    } while (ch == 'y');
}

int main() {
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
