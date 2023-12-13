#include<iostream>
#include<fstream>
using namespace std;

class Test{
    public:
        void writeData();
        void readData();
};

void Test::writeData(){
    ostream file('it.txt',ios::app);
    if(!file) throw "Error opening the file";
    char ch;
    cout << "Enter a character to be written in the file : ";
    cin.get(ch);

    while(ch != '.'){
        file.get(ch);
        cin>>ch;
    }

    file.close();
}

void readData(){
    istream file("it.txt");
    if(!file) throw "File not found!";
    char ch;
    while(file.get(ch)){
        cout<<ch;
    }
    file.close();
}