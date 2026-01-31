#include <iostream>
#include "TaxiBookingSystem.h"

using namespace std;

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
        else
            break;
    }
    return 0;
}
