#include <iostream>
using namespace std;

#define MAX 5

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is Full" << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
            } else if (front == 0) {
                front = MAX - 1;
            } else {
                front--;
            }
            arr[front] = value;
            cout << value << " Inserted at First" << endl;
        }
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is Full" << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
            } else if (rear == MAX - 1) {
                rear = 0;
            } else {
                rear++;
            }
            arr[rear] = value;
            cout << value << " Inserted successfully" << endl;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty" << endl;
        } else {
            cout << arr[front] << " deleted from queue" << endl;
            if (front == rear) {
                front = rear = -1;
            } else if (front == MAX - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty" << endl;
        } else {
            cout << arr[rear] << " deleted from the rear of the deque." << endl;
            if (front == rear) {
                front = rear = -1;
            } else if (rear == 0) {
                rear = MAX - 1;
            } else {
                rear--;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
        } else {
            cout << "Deque elements: ";
            for (int i = front; i != rear; i = (i + 1) % MAX) {
                cout << arr[i] << " <- ";
            }
            cout << arr[rear];
        }
    }
};

int main() {
    Deque deque;

    deque.insertRear(10);
    deque.insertRear(20);
    deque.insertFront(5);

    deque.display();

    deque.deleteFront();
    deque.deleteRear();

    deque.display();
    deque.insertFront(50);
    deque.display(); 

    return 0;
}
