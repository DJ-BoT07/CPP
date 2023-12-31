#include <iostream>
#include <string>
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
    Seat* heads[10];  // Array of pointers to the head of each row

public:
    Cinemax() {
        createList();
    }

    void createList();
    void displaySeats();
    void bookSeat();
    void cancelBooking();
    void displayAvailableSeats();
};

void Cinemax::createList() {
    for (int i = 0; i < 10; ++i) {
        Seat* head = new Seat(1);
        Seat* tail = head;
        head->prev = tail;

        for (int j = 2; j <= 7; ++j) {
            Seat* newNode = new Seat(j);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        tail->next = head;
        heads[i] = head;
    }

    // Randomly book some seats for demonstration
    for (int i = 0; i < 10; ++i) {
        Seat* seatToBook = heads[i];
        for (int j = 0; j < 5; ++j) {
            seatToBook->booked = true;
            seatToBook->userId = "RandomBooking";
            seatToBook = seatToBook->next;
        }
    }
}

void Cinemax::displaySeats() {
    for (int i = 0; i < 10; ++i) {
        Seat* temp = heads[i];
        cout << "Row " << i + 1 << ": ";
        do {
            cout << (temp->booked ? "[B]" : "[ ]") << " ";
            temp = temp->next;
        } while (temp != heads[i]);
        cout << endl;
    }
}

void Cinemax::bookSeat() {
    int row, seat;
    cout << "Enter row number (1-10): ";
    cin >> row;

    if (row < 1 || row > 10) {
        cout << "Invalid row number.\n";
        return;
    }

    cout << "Enter seat number (1-7): ";
    cin >> seat;

    if (seat < 1 || seat > 7) {
        cout << "Invalid seat number.\n";
        return;
    }

    Seat* temp = heads[row - 1];
    do {
        if (temp->seatNumber == seat) {
            break;
        }
        temp = temp->next;
    } while (temp != heads[row - 1]);

    if (temp->booked) {
        cout << "Seat already booked!\n";
    } else {
        temp->booked = true;
        cout << "Enter your ID: ";
        cin >> temp->userId;
        cout << "Seat " << seat << " in Row " << row << " booked!\n";
    }
}

void Cinemax::cancelBooking() {
    int row, seat;
    cout << "Enter row number (1-10): ";
    cin >> row;

    if (row < 1 || row > 10) {
        cout << "Invalid row number.\n";
        return;
    }

    cout << "Enter seat number (1-7): ";
    cin >> seat;

    if (seat < 1 || seat > 7) {
        cout << "Invalid seat number.\n";
        return;
    }

    Seat* temp = heads[row - 1];
    do {
        if (temp->seatNumber == seat) {
            break;
        }
        temp = temp->next;
    } while (temp != heads[row - 1]);

    if (!temp->booked) {
        cout << "Seat not booked yet!\n";
    } else {
        temp->booked = false;
        temp->userId = "";
        cout << "Booking for seat " << seat << " in Row " << row << " cancelled!\n";
    }
}

void Cinemax::displayAvailableSeats() {
    for (int i = 0; i < 10; ++i) {
        Seat* temp = heads[i];
        cout << "Row " << i + 1 << " Available Seats: ";
        do {
            if (!temp->booked) {
                cout << temp->seatNumber << " ";
            }
            temp = temp->next;
        } while (temp != heads[i]);
        cout << endl;
    }
}

int main() {
    Cinemax cinemax;
    int choice;

    do {
        cout << "\nCINEMAX MOVIE THEATRE\n";
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
