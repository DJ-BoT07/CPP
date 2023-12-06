#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node* next;

  Node(int value) {
    this->value = value;
    this->next = NULL;
  }
};

class LinkedList {
private:
  Node* head;
  Node* tail;
  int size;

public:
  LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  void insertFirst(int value) {
    Node* node = new Node(value);
    node->next = head;
    head = node;
    if (tail == NULL) {
      tail = node;
    }
    size++;
  }

  void insertLast(int value) {
    Node* node = new Node(value);
    tail->next = node;
    tail = node;
    size++;
  }

  int get(int index) {
    if (head == NULL) {
      return -1;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
      if (current->next == NULL) {
        return -1;
      }
      current = current->next;
    }
    return current->value;
  }

  int deleteFirst() {
    int val = head->value;
    head = head->next;
    if (head == NULL) {
      tail = NULL;
    }
    size--;
    return val;
  }

  int deleteLast() {
    if (head == NULL) {
      return -1;
    }

    Node* current = head;
    while (current->next->next != NULL) {
      current = current->next;
    }

    int val = current->next->value;
    delete current->next;
    current->next = NULL;
    tail = current;
    size--;
    return val;
  }

  void display() {
    Node* current = head;
    while (current != NULL) {
      cout << current->value << " -> ";
      current = current->next;
    }
    cout << "END"<<endl;
  }

  int getSize() {
    return size;
  }
};

int main() {
  LinkedList linkedList;

  linkedList.insertFirst(10);
  linkedList.insertFirst(20);
  linkedList.insertFirst(30);
  linkedList.insertLast(100);

  linkedList.display();

  cout << "Size of linked list: " << linkedList.getSize() << endl;

  linkedList.deleteFirst();

  linkedList.display();


  cout << "Size of linked list: " << linkedList.getSize() << endl;
  cout<<linkedList.get(1)<<endl;
  return 0;
}