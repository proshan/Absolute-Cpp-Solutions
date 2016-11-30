/*Define a class named PrimeNumber that stores a prime number. The default constructor
should set the prime number to 1. Add another constructor that allows
the caller to set the prime number. Also, add a function to get the prime number.
Finally, overload the prefix and postfix ++ and -- operators so they return a
PrimeNumber object that is the next largest prime number (for ++) and the next
smallest prime number (for --). For example, if the object's prime number is set
to 13, then invoking ++ should return a PrimeNumber object whose prime number
is set to 17. Create an appropriate test program for the class. */
//PrimeNumber Class
#include <iostream>
using namespace std;
class PrimeNumber{
public:
    PrimeNumber(); //default constructor sets prime number to 1
    PrimeNumber(int numberValue); //sets the value of number to argument passed

    int getNumber() const; //returns the current value in the number

    PrimeNumber operator ++(int); //sets the value of number to next prime number
private:
    int number;
    bool isPrimeNumber(int number); //checks whether the number is prime
    int nextPrimeNumber(int number);  //returns the next prime number
};
PrimeNumber::PrimeNumber() : number(1){}
PrimeNumber::PrimeNumber(int numberValue) : number(numberValue){}

int PrimeNumber::getNumber() const{ return number; }

bool PrimeNumber::isPrimeNumber(int number){
    bool result = true;
    for(int i = 2; i<number/2; i++){
        if(number % i == 0){
            result = false;
            break;
        }
    }
    return result;
}
int PrimeNumber::nextPrimeNumber(int number){
    int next = 0;
    while(true){
        number++;
        if(isPrimeNumber(number)){
            next = number;
            break;
        }
    }
    return next;
}
PrimeNumber PrimeNumber::operator ++(int){
    PrimeNumber pn;
    pn.number = nextPrimeNumber(number);
    return pn;
}
int main(){
    PrimeNumber p(7), incremented;
    incremented = p++;
    cout << "Next prime number is: " << incremented.getNumber();
    cout << endl;
    return 0;
}
