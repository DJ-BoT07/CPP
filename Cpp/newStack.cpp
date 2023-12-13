#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Stack
{
private:
    char stack[MAX];
    int top;

public:
    Stack()
    {
        this->top = -1;
    }

    bool IsEmpty()
    {
        return top == -1;
    }

    void Push(char ch)
    {
        if (top == MAX - 1)
        {
            cout << "Stack is Full" << endl;
            return;
        }
        stack[++top] = ch;
    }

    int Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return stack[top--];
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};

int main()
{
    Stack stk;
    char ch;
    int count = 0; // Initialize count to 0
    cout << "Enter a string: ";
    
    // Read a whole string instead of a single character
    string input;
    cin >> input;
    
    for (char c : input) {
        stk.Push(c);
        count += 1; // Move count increment inside the loop
    }

    bool isP = true;
    for (int i = 0; i < count; i++)
    {
        char pos = stk.Pop(); // Use a separate variable to store the popped character
        if (input[i] != pos)
        {
            isP = false;
            break;
        }
    }

    if (isP)
    {
        cout << "The entered string is a palindrome." << endl;
    }
    else
    {
        cout << "The entered string is not a palindrome." << endl;
    }

    return 0;
}
