#include <iostream>
#include <string>

using namespace std;

class Student
{
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
    Student()
    {
        roll_no = 0;
        division = ' ';
        dob = "dd/mm/yyyy";
    }
    void getData()
    {
        cout << "\nEnter the Name : ";
        getline(cin, name);
        cout << "Enter Roll No. : ";
        cin >> roll_no;
        cout << "Enter Class : ";
        getline(cin, cls);
        cout << "Division (A/B/C/D) : ";
        cin >> division;
        cout << "Date of Birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "Blood Group : ";
        getline(cin, bloodgroup);
        cout << "Correspondence Address : ";
        getline(cin, caddress);
        cout << "Telephone Number : ";
        cin >> telno;
        cout << "DL Number : ";
        cin >> dlno;
    }

    void dispData()
    {
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
    static int count()
    {
        static int count = 0;
        return count;
    }
};

int main()
{
    Student *students[100];
    int n = 0;
    char ch;
    do {
        students[n] = new Student;
        students[n]->getData();
        n++;
        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for(int i = 0;i < n; i++){
        students[i]->dispData();
        delete students[i];
    }
    //total count
    cout<<"Total number of Students: "<<Student::count()<<endl;
    return 0;
}
