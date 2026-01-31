#ifndef TAXI_BOOKING_SYSTEM_H
#define TAXI_BOOKING_SYSTEM_H

#include <vector>
#include "Taxi.h"

class TaxiBookingSystem
{
private:
    std::vector<Taxi> taxis;
    int customerCounter;

public:
    TaxiBookingSystem();
    void initializeTaxis(int n);
    void bookTaxi();
    void displayTaxiDetails();
};

#endif
