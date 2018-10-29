//
// Created by gudmundur on 25.10.2018.
//

#include "Functions.cpp"

#ifndef SKILAVERKEFNI4_FLIGHTBOOKING_H
#define SKILAVERKEFNI4_FLIGHTBOOKING_H


class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_ob_seats);
    bool canceReservations(int number_ob_seats);
private:
    bool isAllowedReservation(int reservation);
    int id;
    int capacity;
    int reserved;
};


#endif //SKILAVERKEFNI4_FLIGHTBOOKING_H
