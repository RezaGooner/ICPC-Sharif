//
// Created by Reza on 26/11/2024.
//


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int cars, street;
    cin >> cars >> street;

    vector<int> carsSpeed(cars), carsLocation(cars);

    for (int i = 0; i < cars; i++)  cin >> carsLocation[i] >> carsSpeed[i];


    int firstCar = -1;
    double minTime = numeric_limits<double>::max();

    for (int i = 0; i < cars; i++) {
        double time = static_cast<double>(street - carsLocation[i]) / carsSpeed[i];
        if (time < minTime) {
            minTime = time;
            firstCar = i;
        }
    }

    cout << firstCar + 1 << endl;

    return 0;
}
