#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int actual_km, next_km;
    double current_fuel_consumption;
    double current_maximum;
    double maximum;
    int number_of_leaks;
    string event;

    while (cin >> actual_km >> event >> event >> current_fuel_consumption, current_fuel_consumption) {

        maximum = 0;
        current_maximum = 0;
        number_of_leaks = 0;


        while (cin >> next_km >> event, event != "Goal") {

            current_maximum += ((next_km - actual_km) / 100.00 * current_fuel_consumption);
            current_maximum += ((next_km - actual_km) * number_of_leaks); 
            actual_km = next_km;

            if (event == "Leak") {
                number_of_leaks++;
            } else if (event == "Fuel") {
                cin >> event;
                cin >> current_fuel_consumption;
            } else if (event == "Mechanic") {
                number_of_leaks = 0;
            } else if (event == "Gas") {
                cin >> event;
                maximum = max(maximum, current_maximum);
                current_maximum = 0;
            }
        }

        current_maximum += ((next_km - actual_km) / 100.00 * current_fuel_consumption);
        current_maximum += ((next_km - actual_km) * number_of_leaks); 
        maximum = max(maximum, current_maximum);

        printf("%.3f\n", maximum);
    }
}