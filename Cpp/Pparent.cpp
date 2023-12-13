#include <iostream>

using namespace std;

class Stack
{
public:
    bool isValid(string s)
    {
        const int MAX = 100;
        char stack[MAX];
        int top = -1;

        for (char ch : s)
        {
            if (isParenthesis(ch))
            {
                if (top == MAX - 1)
                {
                    cout << "Stack is full" << endl;
                    return false;
                }
                stack[++top] = ch;
            }
            else if (isClosingParenthesis(ch))
            {
                if (top == -1 || !isValidPair(stack[top], ch))
                {
                    return false;
                }
                top--;
            }
        }
        return top == -1;
    }

private:
    bool isParenthesis(char ch)
    {
        return (ch == '(' || ch == '[' || ch == '{');
    }
    bool isClosingParenthesis(char ch)
    {
        return (ch == ')' || ch == ']' || ch == '}');
    }

    bool isValidPair(char open, char close)
    {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};

int main()
{
    Stack stk;
    string input;
    cout << "Enter Parenthesis: ";
    cin >> input;

    if (stk.isValid(input))
    {
        cout << "The entered string has valid parentheses." << endl;
    }
    else
    {
        cout << "The entered string does not have valid parentheses." << endl;
    }

    return 0;
}
