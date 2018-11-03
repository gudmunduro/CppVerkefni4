
#include "FlightBooking.h"
#include "Functions.cpp"

using namespace Functions;

void processCommand(string command, string value)
{
	if (command == "add")
	{

	}
	if (command == "cancel")
	{

	}
}

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
		getline(cin, command);
        string *cmdSplit = new string[2];
        SplitString(command, ' ', cmdSplit);
		processCommand(cmdSplit[0], cmdSplit[1]);
    }

    return 0;
}
