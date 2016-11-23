/*Buoyancy is the ability of an object to float. Archimedes’ Principle states that the
buoyant force is equal to the weight of the fluid that is displaced by the submerged
object. The buoyant force can be computed by
 Fb = V * g
 where Fb
 is the buoyant force, V is the volume of the submerged object, and g is
the specific weight of the fluid. If Fb
 is greater than or equal to the weight of the
object, then it will float, otherwise it will sink.
 Write a program that inputs the weight (in pounds) and radius (in feet) of a sphere
and outputs whether the sphere will sink or float in water. Use g = 62.4 lb/ft 3 as
the specific weight of water. The volume of a sphere is computed by (4/3)pr3 . */
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double const PI = 3.1416;
    double const specific_weight_of_liquid = 62.4;
    double weight;
    double radius;
    cout << "Enter the weight of sphere in pounds: ";
    cin >> weight;
    cout << "\nEnter the radius of sphere in feet: ";
    cin >> radius;
    double volume;
    volume = (4/3)*PI*pow(radius, 3);
    double buoyant_force;
    buoyant_force = volume * specific_weight_of_liquid;
    if(buoyant_force >= weight){
        cout << "\nThe sphere will float in the liquid.";
    }
    else{
        cout << "\nThe sphere will sink in the liquid.";
    }
    cout << endl;
    return 0;
}
