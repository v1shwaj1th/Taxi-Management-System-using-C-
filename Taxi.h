#ifndef TAXI_H
#define TAXI_H

#include <vector>
#include "Booking.h"

class Taxi
{
public:
    int id;
    char currentPoint;
    int totalEarnings;
    std::vector<Booking> bookings;

    Taxi(int id);

    bool isAvailable(int requestTime);
    int calculateEarning(char from, char to);
    void addBooking(Booking booking);
};

#endif
