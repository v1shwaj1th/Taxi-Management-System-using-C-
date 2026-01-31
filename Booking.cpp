#include "Booking.h"

Booking::Booking(int bid, int cid, char f, char t, int p, int d, int amt)
{
    bookingId = bid;
    customerId = cid;
    from = f;
    to = t;
    pickupTime = p;
    dropTime = d;
    amount = amt;
}
