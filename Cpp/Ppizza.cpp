#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int front, rear, orders[5];

public:
    PizzaParlor() : front(-1), rear(-1) {}

    bool isFull() {
        return (front == 0 && rear == 4) || (front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void addOrder() {
        if (!isFull()) {
            cout << "\nEnter the Pizza ID: ";
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % 5;
            }
            cin >> orders[rear];
            char choice;
            cout << "Do you want to add another order? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                addOrder();
            }
        } else {
            cout << "\nOrders are full.";
        }
    }

    void serveOrder() {
        if (!isEmpty()) {
            cout << "\nOrder served is: " << orders[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % 5;
            }
        } else {
            cout << "\nOrders are empty.";
        }
    }

    void displayOrders() {
        if (!isEmpty()) {
            cout << "\nOrders: ";
            for (int i = front; i != rear; i = (i + 1) % 5) {
                cout << orders[i] << " <- ";
            }
            cout << orders[rear];
        } else {
            cout << "\nOrders are empty.";
        }
    }

    void run() {
        while (true) {
            cout << "\n\n* * * * PIZZA PARLOUR * * * *\n";
            cout << "\n1. Add a Pizza\n2. Display the Orders\n3. Serve a Pizza\n4. Exit\nEnter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    addOrder();
                    break;
                case 2:
                    displayOrders();
                    break;
                case 3:
                    serveOrder();
                    break;
                case 4:
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

            char continueChoice;
            cout << "\nDo you want to continue? (y/n): ";
            cin >> continueChoice;
            if (continueChoice != 'y' && continueChoice != 'Y') {
                break;
            }
        }
    }
};

int main() {
    PizzaParlor pizzaParlor;
    pizzaParlor.run();
    return 0;
}
