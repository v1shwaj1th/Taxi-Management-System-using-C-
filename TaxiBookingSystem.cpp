#include "TaxiBookingSystem.h"
#include <iostream>
#include <climits>
#include <cctype>

using namespace std;

TaxiBookingSystem::TaxiBookingSystem()
{
    customerCounter = 1;
}

void TaxiBookingSystem::initializeTaxis(int n)
{
    for (int i = 1; i <= n; i++)
        taxis.push_back(Taxi(i));
}

void TaxiBookingSystem::bookTaxi()
{
    char pickup, drop;
    int pickupTime;

    cout << "Enter Pickup Point (A-F): ";
    cin >> pickup;
    pickup = toupper(pickup);

    cout << "Enter Drop Point (A-F): ";
    cin >> drop;
    drop = toupper(drop);

    cout << "Enter Pickup Time: ";
    cin >> pickupTime;

    Taxi *selectedTaxi = nullptr;
    int minDist = INT_MAX;

    for (auto &taxi : taxis)
    {
        if (taxi.isAvailable(pickupTime))
        {
            int dist = abs(taxi.currentPoint - pickup);
            if (!selectedTaxi || dist < minDist ||
                (dist == minDist && taxi.totalEarnings < selectedTaxi->totalEarnings))
            {
                selectedTaxi = &taxi;
                minDist = dist;
            }
        }
    }

    if (!selectedTaxi)
    {
        cout << "Booking rejected. No taxis available.\n";
        return;
    }

    int dropTime = pickupTime + abs(drop - pickup);
    int amount = selectedTaxi->calculateEarning(pickup, drop);

    Booking booking(
        selectedTaxi->bookings.size() + 1,
        customerCounter++,
        pickup, drop,
        pickupTime, dropTime,
        amount);

    selectedTaxi->addBooking(booking);

    cout << "Taxi-" << selectedTaxi->id << " allocated\n";
}

void TaxiBookingSystem::displayTaxiDetails()
{
    for (auto &taxi : taxis)
    {
        cout << "\nTaxi-" << taxi.id
             << " Total Earnings: Rs." << taxi.totalEarnings << endl;

        for (auto &b : taxi.bookings)
        {
            cout << "BookingID "
                 << " CustomerID "
                 << " From "
                 << " To "
                 << " Pickup_Time "
                 << " Drop_Time "
                 << " Amount \n"
                 << " " << b.bookingId << "        "
                 << " " << b.customerId << "        "
                 << "   " << b.from << "    "
                 << " " << b.to << "    "
                 << "  " << b.pickupTime << "        "
                 << "  " << b.dropTime << "    "
                 << "    " << b.amount << endl;
        }
    }
}
