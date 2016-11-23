/*One way to measure the amount of energy that is expended during exercise is to
use metabolic equivalents (MET). Here are some METS for various activities:
 Running 6 MPH: 10 METS
 Basketball: 8 METS
 Sleeping: 1 MET
 The number of calories burned per minute may be estimated using the formula
 Calories/Minute = 0.0175 × 1 MET × (Weight in kilograms)
 Write a program that inputs a subject’s weight in pounds, the number of METS
for an activity, and the number of minutes spent on that activity, and then outputs
an estimate for the total number of calories burned. One kilogram is equal
to 2.2 pounds. */
#include <iostream>
using namespace std;
int main(){
    double weight;
    cout << "Enter your weight in pounds: ";
    cin >> weight;
    weight = weight/2.2;
    double running_met, basketball_met, sleeping_met;
    double running_min, basketball_min, sleeping_min;
    cout << "\nEnter the number of MET in Running 6mph: ";
    cin >> running_met;
    cout << "\nEnter the number of minutes in Running 6mph: ";
    cin >> running_min;
    cout << "\nEnter the number of MET in Basketball: ";
    cin >> basketball_met;
    cout << "\nEnter the number of minutes in Basketball: ";
    cin >> basketball_min;
    cout << "\nEnter the number of MET in sleeping: ";
    cin >> sleeping_met;
    cout << "\nEnter the number of minutes in sleeping: ";
    cin >> sleeping_min;
    double calories;
    double calories_from_running = 0.0175 * running_met *running_min * weight;
    double calories_from_basketball = 0.0175 * basketball_met * basketball_min * weight;
    double calories_from_sleeping = 0.0175 * sleeping_met * sleeping_min * weight;
    calories = calories_from_running + calories_from_basketball + calories_from_sleeping;
    cout << "\nEstimated calorie is: " << calories;
    return 0;

}
