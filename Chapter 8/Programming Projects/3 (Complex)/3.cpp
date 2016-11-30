/*Define a class for complex numbers. A complex number is a number of the form
a + b*i
 where for our purposes, a and b are numbers of type double , and i is a number
that represents the quantity root(-1) . Represent a complex number as two values of type double . Name the member variables real and imaginary . (The variable
for the number that is multiplied by i is the one called imaginary .) Call
the class Complex . Include a constructor with two parameters of type double
that can be used to set the member variables of an object to any values. Include a
constructor that has only a single parameter of type double ; call this parameter
realPart and define the constructor so that the object will be initialized to
realPart + 0*i . Include a default constructor that initializes an object to 0 (that is, to
0 + 0*i ). Overload all the following operators so that they correctly apply to the
type Complex : == , + , - , * , >> , and << . You should also write a test program to test
your class. Hints: To add or subtract two complex numbers, add or subtract the
two member variables of type double . The product of two complex numbers is
given by the following formula:
(a + b*i)*(c + d*i) = = (a*c - b*d) + (a*d + b*c)*i
 In the interface file, you should define a constant i as follows:
const Complex i(0, 1);
 This defined constant i will be the same as the i discussed above. */
/*Complex numbers*/
#include <iostream>
using namespace std;

class Complex{
public:
    //CONSTRUCTORS
    Complex(double r);  //sets real number to r and imaginary number to 0
    Complex(double r, double i);  //sets two supplied values to
    //real and imaginary numbers
    Complex();
    //sets both real and imaginary numbers to 0

    //OTHER OVERLOADING FUNCTIONS
    friend Complex operator ==(const Complex& complex1, const Complex& complex2);

    friend Complex operator +(const Complex& complex1, const Complex& complex2);

    friend Complex operator -(const Complex& complex1, const Complex& complex2);

    friend Complex operator *(const Complex& complex1, const Complex& complex2);

    //overloading insertion and extraction operators
    friend istream& operator >>(istream& in, Complex& c);
    friend ostream& operator <<(ostream& out, const Complex& c);

private:
    //two variables to hold real
    //and imaginary part of a
    //complex number
    double real;
    double imaginary;
};

//defining const for imaginary number
const Complex i(0, 1);


Complex::Complex(double r, double i) : real(r), imaginary(i){}
Complex::Complex(double r) : real(r), imaginary(0){}
Complex::Complex() : real(0), imaginary(0){}

//overloading operators definitions
Complex operator ==(const Complex& complex1, const Complex& complex2){
    return (complex1.real == complex2.real && complex1.imaginary == complex2.imaginary);
}
Complex operator +(const Complex& complex1, const Complex& complex2){
    Complex result;
    result.real = complex1.real + complex2.real;
    result.imaginary = complex1.imaginary + complex2.imaginary;
    return result;
}
Complex operator -(const Complex& complex1, const Complex& complex2){
    Complex result;
    result.real = complex1.real - complex2.real;
    result.imaginary = complex1.imaginary - complex2.imaginary;
    return result;
}
// (a+b*i) * (c+d*i) == (a*c - b*d) + (a*d + b*c)*i
Complex operator *(const Complex& complex1, const Complex& complex2){
    Complex result;
    result.real = complex1.real * complex2.real - complex1.imaginary * complex2.imaginary;
    result.imaginary = complex1.real * complex2.imaginary + complex1.imaginary * complex2.real;
    return result;
}
ostream& operator <<(ostream& out, const Complex& c){
    out << "(";
    out << c.real;
    out << ", ";
    out << c.imaginary;
    out << ")\n";
    return out;
}
istream& operator >>(istream& in, Complex& c){
    char charact;
    in >> charact;  //ignoring '('
    in >> c.real;
    in >> charact;  //ignoring ','
    in >> c.imaginary;
    in >> charact;  //ignoring ')'
    return in;
}

int main(){
    Complex c1(5, 6);
    Complex c2;
    cout << "Enter complex number: ";
    cin >> c2;
    cout << c2;
    cout << endl;
    return 0;
}


