#include <iostream>
#include <cstdlib>
using namespace std;

class Pizza {
private:
    static const int MAX_ORDERS = 5;
    int front, rear;
    int orders[MAX_ORDERS];

public:
    Pizza() : front(-1), rear(-1) {}

    bool isFull() {
        return (front == 0 && rear == MAX_ORDERS - 1) || front == rear + 1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    void addOrder() {
        if (!isFull()) {
            cout << "\nEnter the Pizza ID: ";
            int pizzaId;
            cin >> pizzaId;

            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % MAX_ORDERS;
            }

            orders[rear] = pizzaId;

            char c;
            cout << "Do you want to add another order? (y/n): ";
            cin >> c;

            if (c == 'y' || c == 'Y')
                addOrder();
        } else {
            cout << "\nOrders are full.\n";
        }
    }

    void serveOrder() {
        if (!isEmpty()) {
            cout << "\nOrder served is: " << orders[front];

            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX_ORDERS;
            }
        } else {
            cout << "\nOrders are empty.\n";
        }
    }

    void displayOrders() {
        if (!isEmpty()) {
            cout << "\nCurrent Orders: ";
            for (int i = front; i != rear; i = (i + 1) % MAX_ORDERS) {
                cout << orders[i] << " <- ";
            }
            cout << orders[rear] << "\n";
        } else {
            cout << "\nOrders are empty.\n";
        }
    }

    void processOrders() {
        int choice;
        cout << "\n\n* * * * PIZZA PARLOUR * * * *\n\n";
        cout << "1. Add a Pizza\n";
        cout << "2. Display the Orders\n";
        cout << "3. Serve a Pizza\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
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
            cout << "Invalid choice.\n";
        }

        char ch;
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
            processOrders();
    }
};

int main() {
    Pizza pizzaParlour;
    pizzaParlour.processOrders();
    return 0;
}
