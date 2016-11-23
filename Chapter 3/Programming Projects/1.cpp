/* A liter is 0.264179 gallons. Write a program that will read in the number of liters of gasoline
consumed by the user’s car and the number of miles traveled by the car and will then
output the number of miles per gallon the car delivered. Your program should allow the
user to repeat this calculation as often as the user wishes. Define a function to compute the
number of miles per gallon. Your program should use a globally defined constant for the
number of gallons per liter. */
#include <iostream>
using namespace std;
const double LITRE = 0.264179;
// A liter is 0.264179 gallons
double m_per_gallons(float, float);
int main(){
    char ans;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    do{
        float number_of_miles, liter_of_gas;
        cout << "Enter the number of miles you traveled: ";
        cin >> number_of_miles;
        cout << "\nEnter the number of liters of gasoline consumed: ";
        cin >> liter_of_gas;
        cout << endl << m_per_gallons(number_of_miles, liter_of_gas);
        cout << endl << "Want to calculate again? ";
        cin >> ans;
    }while(ans == 'Y' || ans == 'y');
    cout << "\nThank You!";
    return 0;
}
double m_per_gallons(float number_of_miles, float liter_of_gasoline){
    return number_of_miles/(liter_of_gasoline*LITRE);
}
