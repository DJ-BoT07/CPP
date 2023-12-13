#include <iostream>
using namespace std;

template<class T>
void selectionSort(T A[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[min])
            min = j;

        }
        swap(A[i],A[min]);
        
    }
    
}

int main() {
    const int size = 10;
    int intArray[size];
    float floatArray[size];
    int choice,n;

    do {
        cout << "\n* * * * * SELECTION SORT SYSTEM * * * * *";
        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Integer Values";
        cout << "\n2. Float Values";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter total number of int elements:";
                cin >> n;
                cout << "\nEnter int elements:";
                for (int i = 0; i < n; ++i)
                    cin >> intArray[i];
                selectionSort(intArray, n);
                break;

            case 2:
                cout << "\nEnter total number of float elements:";
                cin >> n;
                cout << "\nEnter float elements:";
                for (int i = 0; i < n; ++i)
                    cin >> floatArray[i];
                selectionSort(floatArray, n);
                break;

            case 3:
                exit(0);
        }
    } while (choice != 3);

    return 0;
}