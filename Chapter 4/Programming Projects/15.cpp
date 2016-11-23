/*Write a function named convertToLowestTerms that inputs two integer parameters
by reference named numerator and denominator . The function should treat
these variables as a fraction and reduce them to lowest terms. For example, if
numerator is 20 and denominator is 60, then the function should change the
variables to 1 and 3, respectively. This will require finding the greatest common
divisor for the numerator and denominator then dividing both variables by that
number. If the denominator is zero, the function should return false , otherwise the
function should return true . Write a test program that uses convertToLowestTerms
to reduce and output several fractions. */
#include <iostream>
using namespace std;
void get_numbers(int &numerator, int &denominator);
void convert_to_lowest(int &numerator, int &denominator);
void print_result(int numerator, int denominator);
int main(){
    int numerator, denominator;
    get_numbers(numerator, denominator);
    convert_to_lowest(numerator, denominator);
    print_result(numerator, denominator);
}
void get_numbers(int &numerator, int &denominator){
    cout << "Enter the numerator: " ;
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    return;
}
void convert_to_lowest(int &numerator, int &denominator){
    int greatest_number = (numerator > denominator) ? numerator : denominator;
        for(int i = greatest_number; i>1; i--){
            if(numerator % i == 0 && denominator % i == 0){
                numerator = numerator / i;
                denominator = denominator /i;
                if(numerator == 1 || denominator == 1){
                    break;
                }
            }
        }
    return;
}
void print_result(int numerator, int denominator){
    cout << "Numerator: " << numerator;
    cout << endl;
    cout << "Denominator: " << denominator;
    cout << endl;
    return;
}

