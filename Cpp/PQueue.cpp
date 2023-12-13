#include <iostream>
using namespace std;

const int MAX = 10;

class Queue {
private:
    int data[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (!isFull()) {
            data[++rear] = x;
            cout << "Job added successfully" << endl;
        } else {
            cout << "Queue is full" << endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int removedJob = data[++front];
            cout << "Job is removed: " << removedJob << endl;
            return removedJob;
        } else {
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    void display() {
        if (!isEmpty()) {
            cout << "Queue contains: ";
            for (int i = front +1; i <= rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }
};

int main() {
    Queue q;
    int ch, x;

    do {
        cout << "\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                if (!q.isFull()) {
                    cout << "Enter Data: ";
                    cin >> x;
                    q.enqueue(x);
                } else {
                    cout << "Queue is full" << endl;
                }
                break;
            case 2:
                q.dequeue();
                q.display();
                cout << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    } while (ch != 4);

    return 0;
}
