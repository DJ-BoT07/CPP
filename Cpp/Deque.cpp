#include <iostream>

using namespace std;

class Deque {
private:
    static const int maxSize = 5;  // Maximum size of the deque
    int arr[maxSize];
    int front, rear;

public:
    Deque() : front(-1), rear(-1) {}

    // Function to insert element at the front of the deque
    void insertFront(int value) {
        if ((front == 0 && rear == maxSize - 1) || (rear + 1 == front)) {
            cout << "Deque is full. Cannot insert at the front." << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
            } else if (front == 0) {
                front = maxSize - 1;
            } else {
                front--;
            }
            arr[front] = value;
            cout << value << " inserted at the front of the deque." << endl;
        }
    }

    // Function to insert element at the rear of the deque
    void insertRear(int value) {
        if ((front == 0 && rear == maxSize - 1) || (rear + 1 == front)) {
            cout << "Deque is full. Cannot insert at the rear." << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
            } else if (rear == maxSize - 1) {
                rear = 0;
            } else {
                rear++;
            }
            arr[rear] = value;
            cout << value << " inserted at the rear of the deque." << endl;
        }
    }

    // Function to delete element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front." << endl;
        } else {
            cout << arr[front] << " deleted from the front of the deque." << endl;
            if (front == rear) {
                front = rear = -1;  // The deque is now empty
            } else if (front == maxSize - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }

    // Function to delete element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear." << endl;
        } else {
            cout << arr[rear] << " deleted from the rear of the deque." << endl;
            if (front == rear) {
                front = rear = -1;  // The deque is now empty
            } else if (rear == 0) {
                rear = maxSize - 1;
            } else {
                rear--;
            }
        }
    }

    // Function to check if the deque is empty
    bool isEmpty() const {
        return front == -1;
    }

    // Function to check if the deque is full
    bool isFull() const {
        return (front == 0 && rear == maxSize - 1) || (rear + 1 == front);
    }

    // Function to display the elements of the deque
    void display() const {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
        } else {
            cout << "Deque elements: ";
            int i = front;
            do {
                cout << arr[i] << " ";
                i = (i + 1) % maxSize;
            } while (i != (rear + 1) % maxSize);
            cout << endl;
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

    return 0;
}
