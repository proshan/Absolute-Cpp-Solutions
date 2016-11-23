/* Write a program that asks for the user’s height, weight, and age, and then computes clothing
sizes according to the following formulas.
■ Hat size = weight in pounds divided by height in inches and all that multiplied by 2.9.
■ Jacket size (chest in inches) = height times weight divided by 288 and then adjusted by adding
one-eighth of an inch for each 10 years over age 30. (Note that the adjustment only
takes place after a full 10 years. So, there is no adjustment for ages 30 through 39, but one eighth
of an inch is added for age 40.)
■ Waist in inches = weight divided by 5.7 and then adjusted by adding one-tenth of an inch
for each 2 years over age 28. (Note that the adjustment only takes place after a full 2 years.
So, there is no adjustment for age 29, but one-tenth of an inch is added for age 30.)
Use functions for each calculation. Your program should allow the user to repeat this calculation
as often as the user wishes. */
#include <iostream>
using namespace std;
float hat_size(float weight, float height);
float jacket_size(float height, float weight, int age);
int main(){
    float height, weight;
    int age;
    cout << "\nEnter your height: ";
    cin >> height;
    cout << "\nEnter your weight: ";
    cin >> weight;
    cout << "\nEnter your age: ";
    cin >> age;
    cout << "\nYour hat size is: " << hat_size(weight, height);
    cout << endl;
    cout << "\nYour jacket size is: " << jacket_size(height, weight, age);
    cout << endl;
    return 0;
}
float hat_size(float weight, float height){
    return (weight/height *2.9);
}
float jacket_size(float height, float weight, int age){
    float result = (height*weight)/static_cast<double>(288);
    int to_adjust_age = age - 30;
    int to_be_multiplied = (to_adjust_age/10);
    int additional = 0;
    if(age >= 30){
        for(int i = 1; i<=to_be_multiplied; i++){
            additional += ((1/8)*to_be_multiplied);
        }
    }
    return result+additional;
}


