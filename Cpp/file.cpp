#include<iostream>
#include<fstream>
using namespace std;

class Test {
public:
    void writeData();
    void readData();
};

void Test::writeData() {
    ofstream file("it.txt",ios::app);
    char ch;
    
    cout << "Enter data (enter '.' to stop): ";
    cin.get(ch);

    while (ch != '.') {
        file.put(ch);
        cin.get(ch);
    }

    file.close();
}

void Test::readData() {
    ifstream file("it.txt");
    char ch;

    cout << "\nData from file:\n";

    while (file.get(ch)) {
        cout << ch;
    }

    file.close();
}

int main() {
    Test obj;
    int choice;

    do {
        cout << "\n1. Write\n2. Read\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.writeData();
                break;
            case 2:
                obj.readData();
                break;
        }
    } while (choice != 3);

    return 0;
}
