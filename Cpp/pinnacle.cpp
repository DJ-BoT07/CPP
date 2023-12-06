#include <iostream>
#include <string>
using namespace std;

class MemberNode {
public:
    int prn;
    string name;
    MemberNode* next;

    MemberNode(int prn, string name) : prn(prn), name(name), next(NULL) {}
};

class ClubList {
private:
    MemberNode* president;
    MemberNode* secretary;
    int totalMembers;

public:
    ClubList() {
        president = NULL;
        secretary = NULL;
        totalMembers = 0;
    }

    void addMember(int prn, string name);
    void removePresident();
    void removeSecretary();
    void removeMember(int prn);
    int getTotalMembers();
    void displayMembers();
    void displayMenu();
};

void ClubList::addMember(int prn, string name) {
    MemberNode* newMember = new MemberNode(prn, name);

    if (president == NULL) {
        president = newMember;
        secretary = newMember;
    } else {
        secretary->next = newMember;
        secretary = newMember;
    }

    totalMembers++;
}

void ClubList::removePresident() {
    if (president == NULL) {
        cout << "Club is empty." << endl;
        return;
    }

    MemberNode* temp = president;
    president = president->next;
    delete temp;

    if (president == NULL) {
        secretary = NULL;
    }

    totalMembers--;
}

void ClubList::removeSecretary() {
    if (secretary == NULL) {
        cout << "Club is empty." << endl;
        return;
    }

    if (president == secretary) {
        delete secretary;
        president = NULL;
        secretary = NULL;
    } else {
        MemberNode* temp = president;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        secretary = temp;
    }

    totalMembers--;
}

void ClubList::removeMember(int prn) {
    if (president == NULL) {
        cout << "Club is empty." << endl;
        return;
    }

    if (president->prn == prn) {
        removePresident();
        return;
    }

    MemberNode* current = president;
    MemberNode* prev = NULL;

    while (current != NULL && current->prn != prn) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Member not found." << endl;
        return;
    }

    prev->next = current->next;
    delete current;

    if (current == secretary) {
        secretary = prev;
    }

    totalMembers--;
}

int ClubList::getTotalMembers() {
    return totalMembers;
}

void ClubList::displayMembers() {
    MemberNode* current = president;

    while (current != NULL) {
        cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
        current = current->next;
    }
}

void ClubList::displayMenu() {
    int choice;
    int prn;
    string name;

    do {
        cout << "\n1. Add Member\n";
        cout << "2. Remove President\n";
        cout << "3. Remove Secretary\n";
        cout << "4. Remove Member\n";
        cout << "5. Display Members\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin >> name;
                addMember(prn, name);
                break;
            case 2:
                removePresident();
                break;
            case 3:
                removeSecretary();
                break;
            case 4:
                cout << "Enter PRN of the member to remove: ";
                cin >> prn;
                removeMember(prn);
                break;
            case 5:
                cout << "Total members: " << getTotalMembers() << endl;
                cout << "Members:" << endl;
                displayMembers();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
}

int main() {
    ClubList pinnacleClub;

    pinnacleClub.displayMenu();

    return 0;
}
