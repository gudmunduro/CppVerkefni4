//
// Created by gudmundur on 25.10.2018.
//

#include "FlightBooking.h"

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;
    if (!isAllowedReservation(reserved))
    {
        throw invalid_argument("Reserved value above capacity");
    }
    if (reserved < 0) reserved = 0; // Ef það er í mínus breytist það í núll
    this->reserved = reserved;
}
void FlightBooking::printStatus()
{
    const float seatsReserved = ((float)reserved) / ((float)capacity) * 100.0f;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << seatsReserved << "%) seats reserved" << endl;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
    if (isAllowedReservation(number_ob_seats + reserved) && number_ob_seats >= 0) // Ef niðurstaðan eftir breytingar er leyfileg og talan sem var sett inn er ekki í mínus
    {
        reserved += number_ob_seats;
        return true;
    }
    return false;
}
bool FlightBooking::canceReservations(int number_ob_seats)
{
	if (reserved - number_ob_seats >= 0 && number_ob_seats >= 0) // Ef niðurstaðan eftir breytingu verður hærri en núll og talan sem var sett inn er ekki í mínus
	{
		reserved -= number_ob_seats;
		return true;
	}
	return false;
}
bool FlightBooking::isAllowedReservation(int reservation)
{
    return ((float)reservation) / ((float)capacity) < 1.05; // Skilar true eða false eftir því hvort það sé yfir leyfilega magninu sem er 105%
}