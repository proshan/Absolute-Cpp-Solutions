/*Define a class for a type called Fraction . This class is used to represent a ratio
of two integers. Include mutator functions that allow the user to set the numerator
and the denominator. Also include a member function that returns the value
of the numerator divided by the denominator as a double. Include an additional
member function that outputs the value of the fraction reduced to lowest terms.
For example, instead of outputting 20/60 the function should output 1/3. This will
require finding the greatest common divisor for the numerator and denominator,
and then dividing both by that number. Embed your class in a test program. */
#include <iostream>
using namespace std;
class Fraction{
    //represents a ration of two integers
private:
    int numerator;
    int denominator;
public:
    void setNumerator();
    //sets the value of numerator
    void setDenominator();
    //sets the value of denominator
    double division();
    //returns the value of division of numerator by denominator
    //of double return type
    void fraction();
    //changes the value of numerator and denominator by
    //reducing to the lowest terms
    void printResult();
};
void Fraction::setNumerator(){
    cout << "Enter the numerator: ";
    cin >> numerator;
    return;
}
void Fraction::setDenominator(){
    cout << "Enter the denominator: ";
    cin >> denominator;
    return;
}
double Fraction::division(){
    //since the data type of numerator is int,
    //for the division we must convert
    //the int data type to the double data type
    return static_cast<double>(numerator)/denominator;
}
void Fraction::fraction(){
    int greatest_number = (numerator > denominator) ? numerator : denominator;
    //testing the divisibility from the largest number among the two
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
void Fraction::printResult(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The result of the division is: " << division() << endl;
    cout << "The reduced fraction is: " << numerator << "/" << denominator;
    return;
}
int main(){
    Fraction f;
    f.setNumerator();
    f.setDenominator();
    f.fraction();
    f.printResult();
    cout << endl;
    return 0;
}
