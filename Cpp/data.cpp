#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int roll_no;
    string cls;
    char division;
    string dob;
    string bloodgroup;
    string caddress;
    long telno;
    long dlno;

public:
    // Default Constructor
    Student() : roll_no(0), division(' '), dob("dd/mm/yyyy") {}

    // Destructor not needed

    void getData() {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> roll_no;
        cout << "Enter Class: ";
        cin >> cls;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Date of Birth: ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodgroup;

        // Get additional data
        cout << "Enter Contact Address: ";
        cin.ignore(); // Ignore newline character in buffer
        getline(cin, caddress);
        cout << "Enter Telephone Number: ";
        cin >> telno;
        cout << "Enter Driving License Number: ";
        cin >> dlno;
    }

    void dispData() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
        cout << "Class: " << cls << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodgroup << endl;

        // Display additional data
        cout << "Contact Address: " << caddress << endl;
        cout << "Telephone Number: " << telno << endl;
        cout << "Driving License Number: " << dlno << endl;
    }

    static int getCount() {
        // Assuming count is the number of created student objects
        static int count = 0;
        return count;
    }
};

int main() {
    Student* students[100];
    int n = 0;
    char ch;

    do {
        students[n] = new Student;
        students[n]->getData();
        n++;
        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << "---------------------------------------------------------------\n";
        students[i]->dispData();
        delete students[i]; // Release memory
    }

    cout << "---------------------------------------------------------------\n";
    cout << "Total Students: " << Student::getCount() << endl;
    cout << "---------------------------------------------------------------\n";

    return 0;
}
