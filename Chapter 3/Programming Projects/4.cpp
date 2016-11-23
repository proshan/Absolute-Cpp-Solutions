/*  The gravitational attractive force between two bodies with masses m1 and m2 separated by
a distance d is given by the following formula:
where G is the universal gravitational constant:
G = 6.673 × 10-8 cm3
/(g • sec2
)
Write a function definition that takes arguments for the masses of two bodies and the distance
between them and returns the gravitational force between them. Since you will use
the above formula, the gravitational force will be in dynes. One dyne equals a
g • cm/sec2
You should use a globally defined constant for the universal gravitational constant. Embed
your function definition in a complete program that computes the gravitational force
between two objects given suitable inputs. Your program should allow the user to repeat
this calculation as often as the user wishes. */
#include <iostream>
#include <cmath>
using namespace std;
float force(float mass1, float mass2, float distance);
const double G = 6.673 * pow(10, -8);
int main(){
    float mass1, mass2, distance;
    char ans;
    do{
        cout << "\nEnter the mass of first object: ";
        cin >> mass1;
        cout << "\nEnter the mass of second object: ";
        cin >> mass2;
        cout << "\nEnter the distance between those two objects: ";
        cin >> distance;
        cout << "\nThe Gravitational force is: " << force(mass1, mass2, distance);
        cout << endl << "\nWant to calculate again? ";
        cin >> ans;
    }while(ans == 'Y' || ans == 'y');
    cout << "\nThank You!" << endl;
}
float force(float mass1, float mass2, float distance){
    return (G*mass1*mass2)/(pow(distance, 2));
}
