#include <iostream>
using namespace std;

class Seat {
public:
    int seatNumber;
    bool booked;
    string userId;
    Seat* next;
    Seat* prev;

    Seat(int number) : seatNumber(number), booked(false), userId(""), next(nullptr), prev(nullptr) {}
};

class Cinemax {
private:
    Seat* head;
    Seat* tail;
    Seat* rowHeads[10]; 

public:
    Cinemax() : head(nullptr), tail(nullptr) {
        createList();
        initializeRowHeads();
        for (int i = 0; i < 10; ++i) {
            Seat* seatToBook = rowHeads[i];
            for (int j = 0; j < 5; ++j) {
                seatToBook->booked = true;
                seatToBook->userId = "RandomBooking";
                seatToBook = seatToBook->next;
            }
        }
    }

    void createList();
    void initializeRowHeads();
    void displaySeats();
    void bookSeat();
    void cancelBooking();
    void displayAvailableSeats();
};

void Cinemax::createList() {
    head = new Seat(1);
    tail = head;

    for (int i = 2; i <= 70; ++i) {
        Seat* newNode = new Seat(i);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
    }
}

void Cinemax::initializeRowHeads() {
    for (int i = 0; i < 10; ++i) {
        rowHeads[i] = head;
        head = head->next;
    }
}

void Cinemax::displaySeats() {
    Seat* temp = head;

    cout << "-------------------------\n";
    do {
        cout << (temp->booked ? "[B]" : "[ ]") << " ";
        temp = temp->next;

        if (temp == head) {
            break;
        }

        if (temp->seatNumber % 7 == 1) {
            cout << "\n";
        }
    } while (true);
    cout << "-------------------------\n";
}

void Cinemax::bookSeat() {
    int seatNumber;
    cout << "Enter seat number to be booked: ";
    cin >> seatNumber;

    if (seatNumber < 1 || seatNumber > 70) {
        cout << "Invalid seat number!\n";
        return;
    }

    Seat* temp = head;
    do {
        if (temp->seatNumber == seatNumber) {
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (temp->booked) {
        cout << "Seat already booked!\n";
    } else {
        temp->booked = true;
        cout << "Enter your ID: ";
        cin >> temp->userId;
        cout << "Seat " << seatNumber << " booked!\n";
    }
}

void Cinemax::cancelBooking() {
    int seatNumber;
    cout << "Enter seat number to cancel booking: ";
    cin >> seatNumber;

    if (seatNumber < 1 || seatNumber > 70) {
        cout << "Invalid seat number!\n";
        return;
    }

    Seat* temp = head;
    do {
        if (temp->seatNumber == seatNumber) {
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!temp->booked) {
        cout << "Seat not booked yet!\n";
    } else {
        temp->booked = false;
        temp->userId = "";
        cout << "Booking for seat " << seatNumber << " cancelled!\n";
    }
}

void Cinemax::displayAvailableSeats() {
    cout << "Available Seats:\n";
    Seat* temp = head;
    do {
        if (!temp->booked) {
            cout << temp->seatNumber << " ";
        }
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}

int main() {
    Cinemax cinemax;
    int choice;

    do {
        cout << "1. Display Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Display Available Seats\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cinemax.displaySeats();
                break;
            case 2:
                cinemax.bookSeat();
                break;
            case 3:
                cinemax.cancelBooking();
                break;
            case 4:
                cinemax.displayAvailableSeats();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
