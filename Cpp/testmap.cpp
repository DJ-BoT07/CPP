#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> statePopulations;
    statePopulations["Maharashtra"] = 8000505;
    statePopulations["Punjab"] = 500000;
    // more random initialization
    statePopulations["Delhi"] = 8000;

    string search;
    while (true)
    {
        cout << "Enter the name of a state (or 'exit' to quit): ";
        cin >> search;

        if (search == "exit")
        {
            break;
        }

        map<string, int>::iterator itr = statePopulations.find(search);

        if (itr != statePopulations.end())
        {
            cout << "Population of " << search << ": " << itr->second << endl;
        }
        else
        {
            cout << "State not found." << endl;
        }
    }

    return 0;
}
