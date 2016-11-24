/*Define a class for rational numbers. A rational number is a number that can be
represented as the quotient of two integers. For example, 1/2, 3/4, 64/2, and so
forth are all rational numbers. (By 1/2 and so on we mean the everyday fraction, not
the integer division this expression would produce in a C++ program.) Represent
rational numbers as two values of type int , one for the numerator and one for
the denominator. Call the class Rational . Include a constructor with two arguments
that can be used to set the member variables of an object to any legitimate
values. Also include a constructor that has only a single parameter of type int ;
call this single parameter wholeNumber and define the constructor so that the
object will be initialized to the rational number wholeNumber /1. Include a default
constructor that initializes an object to 0 (that is, to 0/1). Overload the input and
output operators >> and << . Numbers are to be input and output in the form
1/2 , 15/32 , 300/401 , and so forth. Note that the numerator, the denominator, or
both may contain a minus sign, so -1/2 , 15/-32 , and -300/-401 are also possible
inputs. Overload all the following operators so that they correctly apply to the type
Rational : == , < , <= , > , >= , + , - , * , and / . Write a test program to test your class.
Hints: Two rational numbers a/b and c/d are equal if a*d equals c*b. If b and d are
positive rational numbers, a/b is less than c/d provided a*d is less than c*b . You
should include a function to normalize the values stored so that, after normalization,
the denominator is positive and the numerator and denominator are as small
as possible. For example, after normalization 4/-8 would be represented the same
as -1/2. */
#include <iostream>
#include <cmath>
using namespace std;
class Rational{
public:
    Rational(int num, int den);
    //constructor with two parameters
    //sets numerator and denominator to
    //arguments passed
    Rational(int wholeNumber);
    //constructor with one parameter
    //sets numerator to argument passed
    //and denominator to 1
    Rational();
    //constructor that sets numerator to 0
    //and denominator to 1

    //overloading operators prototype
    friend Rational operator +(const Rational& fraction1, const Rational& fraction2);
    //overloading + operator
    friend Rational operator -(const Rational& fraction1, const Rational& fraction2);
    //overloading - operator
    friend Rational operator *(const Rational& fraction1, const Rational& fraction2);
    //overloading * operator
    friend Rational operator /(const Rational& fraction1, const Rational& fraction2);
    //overloading / operator
    friend bool operator ==(const Rational& fraction1, const Rational& fraction2);
    //overloading == operator
    friend bool operator >(const Rational& fraction1, const Rational& fraction2);
    //overloading > operator
    friend bool operator <(const Rational& fraction1, const Rational& fraction2);
    //overloading < operator
    friend bool operator >=(const Rational& fraction1, const Rational& fraction2);
    //overloading >= operator
    friend bool operator <=(const Rational& fraction1, const Rational& fraction2);
    //overloading <= operator

    int getNumerator();
    int getDenominator();

    //normalization
    void printNormalizedValue();

private:
    int numerator;
    int denominator;
};

//Constructors definitions
Rational::Rational(int num, int den) : numerator(num), denominator(den){}
Rational::Rational(int wholeNumber) : numerator(wholeNumber), denominator(1){}
Rational::Rational() : numerator(0), denominator(1){}

//Overloaded operators definitions
Rational operator +(const Rational& fraction1, const Rational& fraction2){
    Rational temp1;
    Rational temp2;
    Rational result;
    //creating an object called 'temp'
    if(fraction1.denominator == fraction2.denominator){
        //if this is the case, the result will be
        //numerators added / denominator
        result.numerator = fraction1.numerator + fraction2.numerator;
        result.denominator = fraction1.denominator;
    }
    else{
        temp1.numerator = fraction1.numerator * fraction2.denominator;
        temp1.denominator = fraction1.denominator * fraction2.denominator;

        temp2.numerator = fraction2.numerator * fraction1.denominator;
        temp2.denominator = fraction2.denominator * fraction1.denominator;

        result.numerator = temp1.numerator + temp2.numerator;
        result.denominator = temp1.denominator;
        //we could also have used
        //result.denominator = temp2.denominator;
        //temp1.denominator and temp2.denominator has the same value
    }
    return result;
}

Rational operator -(const Rational& fraction1, const Rational& fraction2){
    Rational temp1;
    Rational temp2;
    Rational result;
    if(fraction1.denominator == fraction2.denominator){
        result.numerator = fraction1.numerator - fraction2.numerator;
        result.denominator = fraction1.numerator;
    }
    //if the denominator is not same
    else{
        temp1.numerator = fraction1.numerator * fraction2.denominator;
        temp1.denominator = fraction1.denominator * fraction2.denominator;

        temp2.numerator = fraction1.denominator * fraction2.numerator;
        temp2.denominator = fraction1.denominator * fraction2.numerator;

        //the value of temp1.denominator and temp2.denominator is same
        result.numerator = temp1.numerator-temp2.numerator;
        result.denominator = temp1.denominator;
    }
    return result;
}

Rational operator *(const Rational& fraction1, const Rational& fraction2){
    Rational result;
    result.numerator = fraction1.numerator * fraction2.numerator;
    result.denominator = fraction1.denominator * fraction2.denominator;
    return result;
}

Rational operator /(const Rational& fraction1, const Rational& fraction2){
    Rational result;
    result.numerator = fraction1.numerator * fraction2.denominator;
    result.denominator = fraction1.denominator * fraction2.numerator;
    return result;
}

int Rational::getNumerator(){ return numerator; }
int Rational::getDenominator(){ return denominator; }


bool operator ==(const Rational& fraction1, const Rational& fraction2){
    return ((fraction1.numerator * fraction2.denominator) == (fraction1.denominator * fraction2.numerator));
}

bool operator >(const Rational& fraction1, const Rational& fraction2){
    return ((fraction1.numerator * fraction2.denominator) > (fraction2.numerator * fraction1.denominator));
}

bool operator <(const Rational& fraction1, const Rational& fraction2){
    return ((fraction1.numerator * fraction2.denominator) < (fraction2.numerator * fraction1.denominator));
}

bool operator >=(const Rational& fraction1, const Rational& fraction2){
    return (((fraction1.numerator * fraction2.denominator) > (fraction2.numerator * fraction1.denominator))
            || (fraction1.numerator * fraction2.denominator) == (fraction2.numerator * fraction1.denominator));
}

bool operator <=(const Rational& fraction1, const Rational& fraction2){
    return (((fraction1.numerator * fraction2.denominator) < (fraction2.numerator * fraction1.denominator))
            || (fraction1.numerator * fraction2.denominator));
}

void Rational::printNormalizedValue(){
    int temp_numerator = abs(numerator);
    int temp_denominator = abs(denominator);
    int smallest = (temp_numerator < temp_denominator) ? temp_numerator : temp_denominator;
    for(int i = smallest; i>1; i--){
        if((temp_numerator % i) == 0 && (temp_denominator % i) == 0){
            temp_numerator = temp_numerator/i;
            temp_denominator = temp_denominator/i;
        }
        if(temp_numerator == 1 || temp_denominator == 1){
            break;
        }
    }
    cout << "The Normalized value is: ";
    if(numerator < 0){
        cout << "-";
    }
     cout << temp_numerator << "/" << temp_denominator << endl;
}

int main(){
    Rational r1(55, 35), r2(-20, 46);
    cout << "First Fraction is: " << r1.getNumerator() << "/" << r1.getDenominator();
    cout << " and second Fraction is: " << r2.getNumerator() << "/" << r2.getDenominator() << endl << endl;
    Rational r3 = r1 + r2;
    cout << "The result of addition is: " << r3.getNumerator() << "/" << r3.getDenominator()<< endl;
    r3 = r1-r2;
    cout << "The result of subtraction is: " << r3.getNumerator() << "/" << r3.getDenominator()<< endl;
    r3 = r1 * r2;
    cout << "The result of multiplication is: " << r3.getNumerator() << "/" << r3.getDenominator() << endl;
    r3 = r1/r2;
    cout << "The result of division is: " << r3.getNumerator() << "/" << r3.getDenominator() << endl;
    if(r1 == r2){
        cout << r1.getNumerator() << "/" << r1.getDenominator() << " is equal to "
        << r2.getNumerator() << "/" << r2.getDenominator() << endl;
    }
    else{
        cout << r1.getNumerator() << "/" << r1.getDenominator() << " is not equal to " <<
        r2.getNumerator() << "/" << r2.getDenominator() << endl;
    }
    if(r1 > r2){
        cout << r1.getNumerator() << "/" << r1.getDenominator() << " is greater than "
        << r2.getNumerator() << "/" << r2.getDenominator() << endl;
    }
    else{
        cout << r1.getNumerator() << "/" << r1.getDenominator() << " is not greater than " <<
        r2.getNumerator() << "/" << r2.getDenominator()<<endl;
    }
    if(r1 >= r2){
        cout << "Either " << r1.getNumerator() << "/" << r1.getDenominator() << " is greater or equal to " <<
        r2.getNumerator() << "/" << r2.getDenominator() << endl;
    }
    else{
        cout << "Neither " << r1.getNumerator() << "/" << r1.getDenominator() << " is greater or equal to " <<
        r2.getNumerator() << "/" << r2.getDenominator() << endl;
    }
    cout << endl;
    cout << r2.getNumerator() << "/" << r2.getDenominator() << " normalized to ";
    r2.printNormalizedValue();
    cout << endl;
    return 0;
}
