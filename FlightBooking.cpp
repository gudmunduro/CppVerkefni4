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
    if (reserved < 0) reserved = 0;
    this->reserved = reserved;
}
void FlightBooking::printStatus()
{
    const float seatsReserved = ((float)reserved) / ((float)capacity) * 100.0f;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << seatsReserved << "%) seats reserved" << endl;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
    if (isAllowedReservation(number_ob_seats + reserved))
    {
        if (number_ob_seats < 0) number_ob_seats = 0;
        reserved += number_ob_seats;
        return true;
    }
    return false;
}
bool FlightBooking::canceReservations(int number_ob_seats)
{
    if (number_ob_seats < 0) number_ob_seats = 0;
    reserved -= number_ob_seats;
    return true;
}
bool FlightBooking::isAllowedReservation(int reservation)
{
    return ((float)reservation) / ((float)capacity) < 1.05;
}