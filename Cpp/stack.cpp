#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 100;

class Stack {
private:
  char stack_[MAX];
  int top_;

public:
  Stack() : top_(-1) {}

  bool IsEmpty() { 
    return top_ == -1; 
  }

  void Push(char ch) {
    if (top_ == MAX - 1) {
      cout << "Stack is full" << endl;
      return;
    }
    stack_[++top_] = ch;
  }

  char Pop() {
    if (IsEmpty()) {
      cout << "Stack is empty" << endl;
      return 0;
    }
    return stack_[top_--];
  }
};

int main() {
  Stack stk;
  char ch;
  int time;
  char pos;

  cout << "Enter the size of the string: ";
  cin >> time;

  for (int i = 0; i < time; i++) {
    cout << "Enter character " << i+1 << ": ";
    cin >> ch;
    stk.Push(ch);
  }

  // Check palindrome condition
  bool isPalindrome = true;
  for (int i = 0; i < time; i++) {
    pos = stk.Pop();
    if (ch != pos) {
      isPalindrome = false;
      break;
    }
  }

  if (isPalindrome) {
    cout << "The entered string is a palindrome." << endl;
  } else {
    cout << "The entered string is not a palindrome." << endl;
  }

  return 0;
}
