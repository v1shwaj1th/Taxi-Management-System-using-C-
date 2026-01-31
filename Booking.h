#ifndef BOOKING_H
#define BOOKING_H

class Booking
{
public:
    int bookingId;
    int customerId;
    char from, to;
    int pickupTime, dropTime;
    int amount;

    Booking(int bid, int cid, char f, char t, int p, int d, int amt);
};

#endif
