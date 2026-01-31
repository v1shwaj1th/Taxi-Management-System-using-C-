#include "Taxi.h"
#include <cmath>
#include <climits>
using namespace std;

Taxi::Taxi(int id)
{
    this->id = id;
    currentPoint = 'A';
    totalEarnings = 0;
}

bool Taxi::isAvailable(int requestTime)
{
    if (bookings.empty())
        return true;
    return bookings.back().dropTime <= requestTime;
}

int Taxi::calculateEarning(char from, char to)
{
    int dist = abs(to - from) * 15;
    return 100 + max(0, (dist - 5) * 10);
}

void Taxi::addBooking(Booking booking)
{
    bookings.push_back(booking);
    totalEarnings += booking.amount;
    currentPoint = booking.to;
}
