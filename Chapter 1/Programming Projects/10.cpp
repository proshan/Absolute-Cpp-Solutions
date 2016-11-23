/*Write a program that allows the user to enter a time in seconds and then outputs
how far an object would drop if it is in freefall for that length of time. Assume no
friction or resistance from air and a constant acceleration of 32 feet per second due
to gravity. Use the equation
 Distance = 1/2 * acceleration * time2 */
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double time;
    cout << "Enter the time: ";
    cin >> time;
    const double ACCELERATION = 32;
    double distance = (static_cast<float>(1)/2) * ACCELERATION * pow(time, 2);
    cout << "\nThe distance it will reach is: " << distance;
    return 0;
}
