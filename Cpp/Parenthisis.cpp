#include<iostream>
#include<string.h>
using namespace std;

#define MAX 100

class Stack {
private:
    char stack[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char);
    char pop();
    bool isEmpty();
};

void Stack::push(char element) {
    if (top == MAX - 1) {
        cout << "\n Stack Overflow!!!\n";
        return;
    }
    stack[++top] = element;
}

char Stack::pop() {
    if (top == -1) {
        cout << "\n Stack Underflow!!!\n";
        return '\0'; // Indicate an error with '\0'
    }
    return stack[top--];
}

bool Stack::isEmpty() {
    return (top == -1);
}

class ParenthesesChecker {
private:
    char code[MAX];

public:
    void getInput();
    void checkParentheses();
};

void ParenthesesChecker::getInput() {
    cout << "\n Enter a code snippet: ";
    cin.getline(code, MAX);
}

void ParenthesesChecker::checkParentheses() {
    Stack stack;
    int length = strlen(code);
    
    for (int i = 0; i < length; i++) {
        char currentChar = code[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            stack.push(currentChar);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            if (stack.isEmpty() || stack.pop() != currentChar) {
                cout << "\n Entered code is not correctly parenthesized.\n";
                return;
            }
        }
    }

    if (stack.isEmpty()) {
        cout << "\n Entered code is correctly parenthesized.\n";
    } else {
        cout << "\n Entered code is not correctly parenthesized.\n";
    }
}

int main() {
    ParenthesesChecker parenthesesChecker;
    parenthesesChecker.getInput();
    parenthesesChecker.checkParentheses();
    return 0;
}
