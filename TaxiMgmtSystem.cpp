#include <iostream>
#include <vector>
#include <climits>
#include <cctype>
#include <algorithm>

using namespace std;

/* -------------------- BOOKING CLASS -------------------- */
class Booking
{
public:
    int bookingId;
    int customerId;
    char from;
    char to;
    int pickupTime;
    int dropTime;
    int amount;

    Booking(int bid, int cid, char f, char t, int p, int d, int amt)
    {
        bookingId = bid;
        customerId = cid;
        from = f;
        to = t;
        pickupTime = p;
        dropTime = d;
        amount = amt;
    }
};

/* -------------------- TAXI CLASS -------------------- */
class Taxi
{
public:
    int id;
    char currentPoint;
    int totalEarnings;
    vector<Booking> bookings;

    Taxi(int id)
    {
        this->id = id;
        currentPoint = 'A';
        totalEarnings = 0;
    }

    bool isAvailable(int requestTime)
    {
        if (bookings.empty())
            return true;
        return bookings.back().dropTime <= requestTime;
    }

    int calculateEarning(char from, char to)
    {
        int distance = abs(to - from) * 15;
        if (distance <= 5)
            return 100;
        return 100 + (distance - 5) * 10;
    }

    void addBooking(Booking booking)
    {
        bookings.push_back(booking);
        totalEarnings += booking.amount;
        currentPoint = booking.to;
    }
};

/* -------------------- TAXI BOOKING SYSTEM -------------------- */
class TaxiBookingSystem
{
private:
    vector<Taxi> taxis;
    int customerCounter;

public:
    TaxiBookingSystem()
    {
        customerCounter = 1;
    }

    void initializeTaxis(int n)
    {
        for (int i = 1; i <= n; i++)
            taxis.push_back(Taxi(i));
    }

    void bookTaxi()
    {
        char pickup, drop;
        int pickupTime;

        cout << "Enter Pickup Point (A-F): ";
        cin >> pickup;
        pickup = toupper(pickup);

        cout << "Enter Drop Point (A-F): ";
        cin >> drop;
        drop = toupper(drop);

        cout << "Enter Pickup Time (in hours): ";
        cin >> pickupTime;

        Taxi *selectedTaxi = nullptr;
        int minDistance = INT_MAX;

        for (auto &taxi : taxis)
        {
            if (taxi.isAvailable(pickupTime))
            {
                int dist = abs(taxi.currentPoint - pickup);

                if (!selectedTaxi ||
                    dist < minDistance ||
                    (dist == minDistance &&
                     taxi.totalEarnings < selectedTaxi->totalEarnings))
                {

                    selectedTaxi = &taxi;
                    minDistance = dist;
                }
            }
        }

        if (!selectedTaxi)
        {
            cout << "Booking rejected. All taxis are busy at time "
                 << pickupTime << endl;
            return;
        }

        int dropTime = pickupTime + abs(drop - pickup);
        int amount = selectedTaxi->calculateEarning(pickup, drop);

        Booking booking(
            selectedTaxi->bookings.size() + 1,
            customerCounter++,
            pickup,
            drop,
            pickupTime,
            dropTime,
            amount);

        selectedTaxi->addBooking(booking);

        cout << "Taxi-" << selectedTaxi->id << " allocated successfully\n";
    }

    void displayTaxiDetails()
    {
        for (auto &taxi : taxis)
        {
            cout << "\nTaxi-" << taxi.id
                 << " Total Earnings: Rs." << taxi.totalEarnings << endl;

            if (taxi.bookings.empty())
                continue;

            cout << "BookingID CustomerID From To PickupTime DropTime Amount\n";

            for (auto &b : taxi.bookings)
            {
                cout << b.bookingId << "\t  "
                     << b.customerId << "\t   "
                     << b.from << "    "
                     << b.to << "     "
                     << b.pickupTime << "\t     "
                     << b.dropTime << "\t    "
                     << b.amount << endl;
            }
        }
    }
};

/* -------------------- MAIN -------------------- */
int main()
{
    TaxiBookingSystem system;
    int n, choice;

    cout << "Enter number of taxis: ";
    cin >> n;
    system.initializeTaxis(n);

    while (true)
    {
        cout << "\n1. Book Taxi\n2. Display Taxi Details\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            system.bookTaxi();
        else if (choice == 2)
            system.displayTaxiDetails();
        else if (choice == 3)
        {
            cout << "Exiting...\n";
            break;
        }
        else
            cout << "Invalid choice. Try again.\n";
    }

    return 0;
}
