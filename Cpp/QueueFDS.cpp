#include <iostream>
#define MAX 10
using namespace std;

class Queue {
private:
    int data[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (!isFull()) {
            data[++rear] = x;
            cout << "Job enqueued successfully.\n";
        } else {
            cout << "Queue is full. Cannot enqueue more jobs.\n";
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            return data[++front];
        } else {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // Assuming -1 as an indicator of an empty queue
        }
    }

    void display() {
        if (!isEmpty()) {
            cout << "Jobs in the queue: ";
            for (int i = front + 1; i <= rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Queue is empty.\n";
        }
    }
};

int main() {
    Queue jobQueue;
    int choice, job;

    do {
        cout << "\n1. Enqueue Job\n2. Dequeue Job\n3. Display Jobs\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the job data: ";
                cin >> job;
                jobQueue.enqueue(job);
                break;
            case 2:
                job = jobQueue.dequeue();
                if (job != -1) {
                    cout << "Dequeued Job: " << job << endl;
                }
                break;
            case 3:
                jobQueue.display();
                break;
            case 4:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
