#include <iostream>

const int MAX = 10;

using namespace std;

class Queue {
private:
    int data[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() const {
        return (front == -1 && rear == -1);
    }

    bool isFull() const {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (!isFull()) {
            data[++rear] = x;
            cout << "Job added successfully.\n";
        } else {
            cout << "Queue is full (overflow).\n";
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int removedJob = data[++front];
            cout << "Deleted Element = " << removedJob << "\n";
            return removedJob;
        } else {
            cout << "Queue is empty (underflow).\n";
            return -1; // Return a sentinel value to indicate failure.
        }
    }

    void display() const {
        if (!isEmpty()) {
            cout << "Queue contains: ";
            for (int i = front + 1; i <= rear; ++i) {
                cout << data[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "Queue is empty.\n";
        }
    }
};

int main() {
    Queue obj;
    int ch, x;

    do {
        cout << "\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                if (!obj.isFull()) {
                    cout << "Enter data: ";
                    cin >> x;
                    obj.enqueue(x);
                } else {
                    cout << "Queue is full (overflow).\n";
                }
                break;

            case 2:
                obj.dequeue();
                obj.display();
                break;

            case 3:
                obj.display();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (ch != 4);

    return 0;
}
