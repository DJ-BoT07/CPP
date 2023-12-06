#include <iostream>
using namespace std;

#define SIZE 10

template <class T>
void selectionSort(T A[], int size) {
    int i, j, minIndex;
    T temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main() {
    int choice;
    int intArray[SIZE];
    float floatArray[SIZE];
    int n, i;

    cout << "-----------------------";
    do {
        cout << "\n 1. Integer : ";
        cout << "\n 2. Float : ";
        cout << "\n 3. Exit : " << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Total Number Of Integer Elements:";
                cin >> n;
                cout << "\nEnter Integer Elements:";
                for (i = 0; i < n; i++) {
                    cin >> intArray[i];
                }
                selectionSort(intArray, n);
                cout << "\nSorted array: ";
                for (i = 0; i < n; i++) {
                    cout << " " << intArray[i];
                }
                break;
            case 2:
                cout << "\nEnter Total Number Of Float Elements:";
                cin >> n;
                cout << "\nEnter Float Elememts:";
                for (i = 0; i < n; i++) {
                    cin >> floatArray[i];
                }
                selectionSort(floatArray, n);
                cout << "\nSorted array: ";
                for (i = 0; i < n; i++) {
                    cout << " " << floatArray[i];
                }
                break;
            case 3:
                cout << "**********Program Exited Successfully**********" << endl;
                return 0;
            default:
                cout << "\n Invalid";
        }
    } while (choice != 4);

    return 0;
}
