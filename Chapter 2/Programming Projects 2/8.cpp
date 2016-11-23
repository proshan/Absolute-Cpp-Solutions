/*Write a program that finds the temperature, as an integer, that is the same in
both Celsius and Fahrenheit. The formula to convert from Celsius to Fahrenheit
is as follows:
 Fahrenheit = 9
5
 Celsius + 32
 Your program should create two integer variables for the temperature in Celsius
and Fahrenheit. Initialize the temperature to 100 degrees Celsius. In a loop, decrement
the Celsius value and compute the corresponding temperature in Fahrenheit
until the two values are the same. */
#include <iostream>
using namespace std;
int main(){
    int fahrenheit;
    int celcius = 100;
    int temperature = 0;
    bool found = false;
    while(found == false){
        fahrenheit = ((9/static_cast<double>(5))*celcius)+32;
        if(fahrenheit == celcius){
            found = true;
            temperature = temperature + celcius;
            break;
        }
        celcius--;
    }
    cout << temperature;
    return 0;
}
