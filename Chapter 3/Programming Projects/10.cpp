/* One way to estimate the height of a child is to use the following formula, which
uses the height of the parents:
 Hmale_child = (( Hmother 13/12) + Hfather )/2
 Hfemale_child = (( Hfather 12/13) + Hmother )/2
 All heights are in inches. Write a function that takes as input parameters the gender
of the child, height of the mother in inches, and height of the father in inches,
and outputs the estimated height of the child in inches. Embed your function in a
program that allows you to test the function over and over again until telling the
program to exit. The user should be able to input the heights in feet and inches,
and the program should output the estimated height of the child in feet and inches.
Use the integer data type to store the heights.*/
#include <iostream>
#include <cstdlib>
using namespace std;
int height(int feet, int inch);
int estimated_height(char gender, int mothers_height, int fathers_height);
int main(){
    int feet, inch;
    char gender;
    cout << "Enter the gender of the child (m or f): ";
    cin >> gender;
    cout << endl;
    cout << "Enter the height of mother in feet and inches separated by a space: ";
    cin >> feet >> inch;
    int mothers_height = height(feet, inch);
    cout << "\nEnter the height of father in feet and inches separated by a space: ";
    cin >> feet >> inch;
    int fathers_height = height(feet, inch);
    int height = estimated_height(gender, mothers_height, fathers_height);
    int child_feet = height/12;
    int child_inch = height % 12;
    cout << "\nThe child is " << child_feet << " feet and " << child_inch << ((child_inch > 1) ? " inches" : " inch");
    cout << endl;
    return 0;

}
int height(int feet, int inch){
    return (feet*12)+inch;
}
int estimated_height(char gender, int mothers_height, int fathers_height){
    int estimated_height;
    if(gender == 'm' || gender == 'M'){
        estimated_height = ((mothers_height * 13/12) + fathers_height)/2;
    }
    else if(gender == 'f' || gender == 'F'){
        estimated_height = ((fathers_height * 12/13) + mothers_height)/2;
    }
    else{
        cout << "Input error!";
        exit(1);
    }
    return estimated_height;
}

