#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Item {
public:
    string name;
    int quantity;
    int cost;
    int code;

    // Overloaded operators for sorting and searching
    bool operator==(const Item& other) const {
        return code == other.code;
    }

    bool operator<(const Item& other) const {
        return code < other.code;
    }
};

vector<Item> items;

void print(const Item& item) {
    cout << "\nItem Name: " << item.name;
    cout << "\nItem Quantity: " << item.quantity;
    cout << "\nItem Cost: " << item.cost;
    cout << "\nItem Code: " << item.code;
    cout << "\n\n";
}

void display() {
    for_each(items.begin(), items.end(), print);
}

void insert() {
    Item newItem;
    cout << "\nEnter Item Name: ";
    cin >> newItem.name;
    cout << "\nEnter Item Quantity: ";
    cin >> newItem.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> newItem.cost;
    cout << "\nEnter Item Code: ";
    cin >> newItem.code;
    items.push_back(newItem);
}

void search() {
    Item searchItem;
    cout << "\nEnter Item Code to search: ";
    cin >> searchItem.code;
    auto iter = find(items.begin(), items.end(), searchItem);
    if (iter == items.end()) {
        cout << "\nNot found!!!";
    } else {
        cout << "\nFound!!!";
    }
}

void dlt() {
    Item deleteItem;
    cout << "\nEnter Item Code to delete: ";
    cin >> deleteItem.code;
    auto iter = find(items.begin(), items.end(), deleteItem);
    if (iter == items.end()) {
        cout << "\nNot found!!!";
    } else {
        items.erase(iter);
        cout << "\nDeleted!!!";
    }
}

int main() {
    int choice;
    do {
        cout << "\n* * * * * Menu * * * * *";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(items.begin(), items.end());
                cout << "\n\n Sorted on Code : ";
                display();
                break;
            case 5:
                dlt();
                break;
            case 6:
                exit(0);
        }

    } while (choice != 6);

    return 0;
}
