#include <iostream>
using namespace std;

class Toy {
private:
    int toyNumber;

public:
    // Constructor
    Toy(int number) {
        toyNumber = number;
    }

    // Copy Constructor
    Toy(const Toy& other) {
        toyNumber = other.toyNumber;
    }

    // Show the toy number
    void showToy() {
        cout << "Toy Number: " << toyNumber << endl;
    }
};

int main() {
    Toy toy1(123);
    Toy toy2 = toy1; // Copy constructor is used

    cout << "Toy 1: ";
    toy1.showToy();

    cout << "Toy 2: ";
    toy2.showToy();

    return 0;
}
