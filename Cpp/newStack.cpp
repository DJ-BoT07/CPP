#include <iostream>
using namespace std;

class Queue
{
private:
    const static int maxSize = 100;
    int arr[maxSize];
    int front;
    int rear;
    int element;

public:
    Queue() : front(-1), rear(-1) {}

    void push_front()
    {
        cout << "Enter element : ";
        cin >> element;
        if (isFull())
            cout << "Queue is full" << endl;
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = element;
        }
        else if (front == 0)
        {
            front = maxSize - 1;
            arr[front] = element;
        }
        else
        {
            front--;
            arr[front] = element;
        }
    }

    void push_rear()
    {
        cout << "Enter element : ";
        cin >> element;
        if (isFull())
            cout << "Queue is full" << endl;
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = element;
        }
        else if (rear == maxSize - 1)
        {
            rear = 0;
            arr[rear] = element;
        }
        else
        {
            rear++;
            arr[rear] = element;
        }
    }

    void pop_front()
    {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else if (front == rear)
            front = rear = -1;
        else if (front == maxSize - 1)
            front = 0;
        else
            front++;
    }

    void pop_rear()
    {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = maxSize - 1;
        else
            rear--;
    }

    bool isFull() const
    {
        return (front == 0 && rear == maxSize - 1) || (rear + 1 == front);
    }

    bool isEmpty() const
    {
        return front == -1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize && i != front);

        cout << endl;
    }
};

int main()
{
    Queue q;
    q.push_rear();
    q.push_rear();
    q.push_front();
    q.pop_front();
    q.pop_rear();
    q.display();

    return 0;
}
