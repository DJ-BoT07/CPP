#include <iostream>
using namespace std;

int main() {
    int *a[10];
    int i, x, y, z;

    cout << "Enter three integers: " << endl;
    cin >> x >> y >> z;

    // Assign the addresses of x, y, and z to the array of pointers
    a[0] = &x;
    a[1] = &y;
    a[2] = &z;

    // Print the values of x, y, and z using the pointers
    for (i = 0; i < 3; i++) {
        cout << "Value at a[" << i << "]: " << *a[i] << endl;
    }

    return 0;
}
