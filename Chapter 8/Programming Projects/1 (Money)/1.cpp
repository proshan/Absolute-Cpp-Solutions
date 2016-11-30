/*Modify the definition of the class Money shown in Display 8.5 so that the following
are added:
 a. The operators < , <=, > , and >= have each been overloaded to apply to the type
Money . ( Hint: See Self-Test Exercise 8 .)
 The following member function has been added to the class definition. (We
show the function declaration as it should appear in the class definition. The
definition of the function itself will include the qualifier Money ::.)
const Money percent( int percentFigure) const;
//Returns a percentage of the money amount in the calling
//object. For example, if percentFigure is 10, then the value
//returned is 10% of the amount of money represented by the
//calling object.
 For example, if purse is an object of type Money whose value represents the
amount $100.10, then the call
purse.percent(10);
 returns 10% of $100.10; that is, it returns a value of type Money that represents
the amount $10.01.
*/
//Money Class
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
class Money{
public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;

    friend const Money operator +(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);

    friend bool operator <(const Money& amount1, const Money& amount2);
    friend bool operator >(const Money& amount1, const Money& amount2);
    friend bool operator <=(const Money& amount1, const Money& amount2);
    friend bool operator >=(const Money& amount1, const Money& amount2);

    friend const Money operator -(const Money& amount);
    friend ostream& operator <<(ostream& outputStream, const Money& amount);
    friend istream& operator >>(istream& inputStream, Money& amount);


    const Money percent(int percentage) const;
private:
    int dollars, cents;
    int dollarsPart(double amount) const;
    int centsPart(double amoun) const;
    int round(double number) const;

};

int main(){
    Money yourAmount, myAmount(10, 9);
    cout << "Enter an amount of money: ";
    cin >> yourAmount;
    cout << "Your amount is " << yourAmount << endl;
    cout << "My amount is: " << myAmount << endl;

    if(yourAmount == myAmount){
        cout << "We have the same amounts.\n";
    }
    else{
        cout << "One of us is richer.\n";
    }
    Money ourAmount = yourAmount + myAmount;
    cout << yourAmount << " + " << myAmount << " equals " << ourAmount << endl;

    Money diffAmount = yourAmount - myAmount;
    cout << yourAmount << " - " << myAmount << " equals " << diffAmount << endl;

    if(yourAmount > myAmount){
        cout << yourAmount << " is greater than " << myAmount << endl;
    }
    else{
        cout << yourAmount << " is not greater than " << myAmount << endl;
    }
    if(yourAmount <= myAmount){
        cout << yourAmount << " is less than or equal to " << myAmount << endl;
    }
    else{
        cout << yourAmount << " is neither less than nor equal to " << myAmount << endl;
    }

    cout << endl << "40 % of " << yourAmount << " is " << yourAmount.percent(40) << endl;
    return 0;
}
Money::Money() : dollars(0), cents(0) {}
Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount)){}
Money::Money(int theDollars) : dollars(theDollars), cents(0){}
Money::Money(int theDollars, int theCents){
    if((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0)){
        cout << "Inconsistent money data.\n";
        exit(1);
    }
    dollars = theDollars;
    cents = theCents;
}
double Money::getAmount() const{
    return (dollars + cents * 0.01);
}
int Money::getDollars() const{
    return dollars;
}
int Money::getCents() const{
    return cents;
}

ostream& operator <<(ostream& outputStream, const Money& amount){
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if(amount.dollars < 0 || amount.cents < 0){
        outputStream << "$-";
    }
    else{
        outputStream << "$";
    }
    outputStream << absDollars;
    if(absCents >= 10){
        outputStream << "." << absCents;
    }
    else{
        outputStream << "." << '0' << absCents;
    }
    return outputStream;
}
int Money::dollarsPart(double amount) const{
    return static_cast<int>(amount);
}
int Money::centsPart(double amount) const{
    double doubleCents = amount * 100;
    int intCents = (round(fabs(doubleCents))) % 100;
    if(amount < 0){
        intCents = -intCents;
    }
    return intCents;
}
int Money::round(double number) const{
    return static_cast<int>(floor(number + 0.5));
}

istream& operator >>(istream& inputStream, Money& amount){
    char dollarSign;
    inputStream >> dollarSign;
    if(dollarSign != '$'){
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }
    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);
    amount.cents = amount.centsPart(amountAsDouble);
    return inputStream;
}

const Money operator +(const Money& amount1, const Money& amount2){
    int allCents1 = amount1.cents + amount1.dollars * 100;
    int allCents2 = amount2.cents + amount2.dollars * 100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents);
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents%100;

    if(sumAllCents < 0){
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2){
    int allCents1 = amount1.cents + amount1.dollars * 100;
    int allCents2 = amount2.cents + amount2.dollars * 100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);

    int finalDollars = absAllCents/100;
    int finalCents = absAllCents % 100;
    if(diffAllCents < 0){
        finalDollars = -finalDollars;
        finalCents =  -finalCents;
    }
    return Money(finalDollars, finalCents);
}
bool operator ==(const Money& amount1, const Money& amount2){
    return ((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}
bool operator <(const Money& amount1, const Money& amount2){
    int dollars1 = amount1.getDollars();
    int dollars2 = amount2.getDollars();
    int cents1 = amount1.getCents();
    int cents2 = amount2.getCents();
    return (dollars1 < dollars2) || ((dollars1 == dollars2) && (cents1 < cents2));
}
bool operator >(const Money& amount1, const Money& amount2){
    int dollars1 = amount1.getDollars();
    int dollars2 = amount2.getDollars();
    int cents1 = amount1.getCents();
    int cents2 = amount2.getCents();
    return ((dollars1 > dollars2)) || ((dollars1 == dollars2) && (cents1 > cents2));
}
bool operator <=(const Money& amount1, const Money& amount2){
    int dollars1 = amount1.getDollars();
    int dollars2 = amount2.getDollars();
    int cents1 = amount1.getCents();
    int cents2 = amount2.getCents();
    return ((dollars1 <= dollars2)) || ((dollars1 == dollars2) && (cents1 <= cents2));
}
bool operator >=(const Money& amount1, const Money& amount2){
    int dollars1 = amount1.getDollars();
    int dollars2 = amount2.getDollars();
    int cents1 = amount1.getCents();
    int cents2 = amount2.getCents();
    return ((dollars1 >= dollars2)) || ((dollars1 == dollars2) && (cents1 >= cents2));
}
const Money operator -(const Money& amount){
    return Money(-amount.dollars, -amount.cents);
}
const Money Money::percent(int percentage) const{
    int dollars = dollars * 100;
    int cents = (dollars * percentage % 100) + (cents*percentage)/100;
    return Money(dollars, cents);
}
