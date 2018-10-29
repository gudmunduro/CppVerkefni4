
#include "FlightBooking.h"
#include "Functions.cpp"


int main() {
    int reserved = 0,
            capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    string command = "";
    while (command != "quit")
    {
        booking.printStatus();
        cout << "What would you like to do?: ";
        cin.getline(command);

    }

    return 0;
}
