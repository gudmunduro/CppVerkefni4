#include "FlightBooking.h"
#include "Functions.cpp"

using namespace Functions;

map<int, FlightBooking*> flightBookings;

bool isValidId(int id)
{
	return flightBookings.find(id) != flightBookings.end(); // Skilar true e�a false eftir �v� hvort �a� s� til flug me� �essu id
}

void createArgumentsArray(string *cmdSplit, string *arguments)
{
	for (int i = 0; i < 10; i++)
	{
		arguments[i] = cmdSplit[i + 1];  // Taka �r einu s�ti fyrir ofan � cmdSplit �v� commandi� sj�lft er fyrst � �v�
	}
}

void printError(int code = 0)
{
	switch (code)
	{
	case 0: break;
	case 1: cout << "Error: Flight does not exist(Invalid ID)" << endl; break;
	case 2: cout << "Error: Flight already exists" << endl; break;
	case 3: cout << "Error: Invalid command" << endl; break;
	case 4: cout << "Error: Seats cannot be at more than 105% capacity" << endl; break;
	case 5: cout << "Error: Seats cannot be at below 0% capacity" << endl; break;
	}
	cout << "Cannot perform this operation" << endl;
}

void processCommand(string command, string *arguments)
{
	if (command == "quit") return;

	int id = stoi(arguments[0]);

	if (command == "create")
	{
		if (!isValidId(id))
			flightBookings[id] = new FlightBooking(id, stoi(arguments[1]), 0);
		else printError(2);
	}
	if (command == "delete")
	{
		if (isValidId(id))
			flightBookings.erase(id);
		else printError(1);
	}
	if (command == "add")
	{
		if (isValidId(id))
		{
			if (!flightBookings[id]->reserveSeats(stoi(arguments[1])))
				printError(4); // Prentar �t error ef �a� t�kst ekki
		}
		else printError(1);
	}
	if (command == "cancel")
	{
		if (isValidId(id))
		{
			if (!flightBookings[id]->canceReservations(stoi(arguments[1])))
				printError(5); // Prentar �t error ef �a� t�kst ekki
		}
		else printError(1);
	}
}

int main() {
    string command = "";

    while (command != "quit")
    {
        cout << "What would you like to do?: ";
		getline(cin, command);

		if (command == "")
		{
			/* H�tta vi� ef ekkert er skirfa� */
			printError(3);
			continue;
		}

        string *cmdSplit = new string[11];
		string *arguments = new string[10];
        SplitString(command, ' ', cmdSplit);
		createArgumentsArray(cmdSplit, arguments); // Taka �ll arguments og setja � s�r array

		if (arguments[0] == "")
		{
			/* H�tta vi� ef command hefur engin arguments */
			printError(3);
			continue;
		}

		processCommand(cmdSplit[0], arguments);

		if (isValidId(stoi(arguments[0])))
			flightBookings[stoi(arguments[0])]->printStatus(); // Ef flugi� me� �etta id er til prentar �a� status
    }

    return 0;
}
