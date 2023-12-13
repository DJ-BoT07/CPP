#include <iostream>
using namespace std;

class Node
{
public:
    int prn;
    string name;
    Node *next;

    Node(int prn, string name)
    {
        this->prn = prn;
        this->name = name;
        this->next = NULL;
    }

    Node(int prn, string name, Node* next)
    {
        this->prn = prn;
        this->name = name;
        this->next = next;
    }
};

class ACES
{
private:
    Node *president;
    Node *sec;
    int size;

public:
    ACES()
    {
        president = NULL;
        sec = NULL;
        size = 0;
    }

    void insertFirst(int prn, string name)
    {
        Node *node = new Node(prn, name);
        node->next = president;
        president = node;
        if (sec == NULL)
        {
            sec = node;
        }
        size++;
    }

    void insertLast(int prn, string name)
    {
        Node *node = new Node(prn, name);
        sec->next = node;
        sec = node;
        size++;
    }

    int get(int index)
    {
        if (president == NULL)
        {
            return -1;
        }
        Node *temp = president;
        for (int i = 0; i < index; i++)
        {
            if (temp->next == NULL)
            {
                return -1;
            }
            temp = temp->next;
        }
        return temp->prn;
    }

    int deleteFirst()
    {
        int prn = president->prn;
        president = president->next;
        if (president == NULL)
        {
            sec = NULL;
        }
        size--;
        return prn;
    }

    int deleteLast()
    {
        if (president == NULL)
        {
            return -1;
        }
        Node* temp = president;
        while(temp->next != sec){
            temp = temp->next;
        }
        int prn = sec->prn;
        sec = temp;
        delete temp->next;
        sec->next = NULL;
        size--;
        return prn;

    }

    void display()
    {
        Node *temp = president;
        while (temp != NULL)
        {
            cout << temp->prn << " : " << temp->name << " -> ";
            temp = temp->next;
        }
        cout << " END " << endl;
    }

    int getSize()
    {
        return size;
    }

    void Sec(){
        cout<<"Secretary : "<<sec->name<<endl;
    }

    void Pr(){
        cout<<"President: " <<president->name<<endl;
    }

     void concatenate(ACES &list2)
    {
        if (list2.president == NULL)
        {
            return; // List2 is empty, nothing to concatenate
        }

        if (president == NULL)
        {
            // If the first list is empty, set its head to the head of the second list
            president = list2.president;
            sec = list2.sec;
        }
        else
        {
            // Otherwise, find the last node of the first list and link it to the head of the second list
            sec->next = list2.president;
            sec = list2.sec;
        }

        size += list2.size; // Update the size of the first list
        list2.president = NULL; // Clear the second list
        list2.sec = NULL;
        list2.size = 0;
    }

};

int main(){
    ACES list;
    ACES list2;
    list.insertFirst(1, "Alice");
    list.insertFirst(2, "Bob");
    list.insertFirst(3, "Charlie");
    list.insertLast(4,"DJ");
    //
    list.insertLast(5,"Eve");
    list.insertLast(6,"Fred");//now delete
    list.insertLast(7,"Grace");
    list.display();
    list.Sec();
    list.Pr();
    cout<<list.getSize()<<endl;

    list.deleteFirst();
    list.deleteLast();
    list.display();
    list.Sec();
    list.Pr();


    // list2.insertFirst(1, "Alice");
    // list2.insertFirst(2, "Bob");
    // list2.insertFirst(3, "Charlie");
    // list2.insertLast(4,"DJ");
    // //
    // list2.insertLast(5,"Eve");
    // list2.insertLast(6,"Fred");//now delete
    // list2.insertLast(7,"Grace");

    // list.concatenate(list2);
    // list.display();



}