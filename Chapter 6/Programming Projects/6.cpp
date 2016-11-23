/*Define a class called Odometer that will track fuel and mileage for an automotive
vehicle. The class should have member variables to track the miles driven and the
fuel efficiency of the vehicle in miles per gallon. Include a mutator function to reset
the odometer to zero miles, a mutator function to set the fuel efficiency, a mutator
function that accepts miles driven for a trip and adds it to the odometer’s total, and
an accessor function that returns the number of gallons of gasoline that the vehicle
has consumed since the odometer was last reset.
 Use your class with a test program that creates several trips with different fuel
 efficiencies. You should decide which variables should be public, if any. */
#include <iostream>
using namespace std;
class Odometer{
private:
    double milesDriven;
    double fuelEfficiency;
    double totalMilesDriven;
    double numberOfGallons;
public:
    Odometer();
    void resetFuelEfficiency();
    void setFuelEfficiency();
    void getMiles();
    void getNumberOfGallons();
    void printResult();
};
Odometer::Odometer(){
    totalMilesDriven = 0;
}
void Odometer::resetFuelEfficiency(){
    fuelEfficiency = 0;
}
void Odometer::setFuelEfficiency(){
    cout << "Enter the fuel efficiency: ";
    cin >> fuelEfficiency;
}
void Odometer::getMiles(){
    cout << "Enter the miles driven for a trip: ";
    cin >> milesDriven;
    totalMilesDriven += milesDriven;
}
void Odometer::getNumberOfGallons(){
    numberOfGallons = totalMilesDriven/3.6;
}
void Odometer::printResult(){
    cout << "The number of gallons is: " << numberOfGallons;
}
int main(){
    Odometer o;
    o.setFuelEfficiency();
    o.getMiles();
    o.getNumberOfGallons();
    o.printResult();
    cout << endl;
    return 0;
}

