/*Do Programming Project 6.10, the definition of a Temperature class, except overload
==, << and >> as member operators. The == operator should return true if the
two temperature values are identical, while << should output the temperature in
Fahrenheit and >> should input the temperature in Fahrenheit. Create appropriate
tests for the overloaded operators. */
//Temperature class
#include <iostream>
using namespace std;
class Temperature{
public:
    friend bool operator ==(const Temperature& temp1, const Temperature& temp2);
    friend istream& operator >>(istream& in, Temperature& t);
    friend ostream& operator <<(ostream& out, const Temperature& t);
private:
    double temp;
};
bool operator ==(const Temperature& temp1, const Temperature& temp2){
    return (temp1.temp == temp2.temp);
}
istream& operator >>(istream& in, Temperature& t){
    in >> t.temp;
    return in;
}
ostream& operator <<(ostream& out, const Temperature& t){
    out << "The temperature is: " << t.temp;
    return out;
}
int main(){
    Temperature t;
    cout << "Enter the temperature in Fahrenheit: ";
    cin >> t;
    cout << t;
    cout << endl;
    return 0;
}
