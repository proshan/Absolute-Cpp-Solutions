/*A simple rule to estimate your ideal body weight is to allow 110 pounds for the first 5
feet of height and 5 pounds for each additional inch. Write a program with a variable
for the height of a person in feet and another variable for the additional inches and
input values for these variables from the keyboard. Assume the person is at least 5 feet
tall. For example, a person that is 6 feet and 3 inches tall would be represented with
a variable that stores the number 6 and another variable that stores the number 3.
Based on these values calculate and output the ideal body weight.  */
#include <iostream>
using namespace std;
int main(){
    int height_in_feet;
    cout << "Enter your height in feet: ";
    cin >> height_in_feet;
    int additional_inches;
    cout << "\nEnter additional height: ";
    cin >> additional_inches;
    double weight;
    if(height_in_feet >= 5){
        weight = 110;
        weight = weight + additional_inches * 5;
    }
    else{
        cout << "\nAt least, the height has to be 5 feet.";
    }
    cout << "\nYour ideal weight is: " << weight;
    return 0;
}
