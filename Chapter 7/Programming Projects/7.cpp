/*Do Programming Project 6.8 , the definition of a Money class, except create a
 default constructor that sets the monetary amount to 0 dollars and 0 cents, and
create a second constructor with input parameters for the amount of the dollars
and cents variables. Modify your test code to invoke the constructors. */
#include <iostream>
using namespace std;
class Money{
public:
    Money();
    Money(int a, int b);
    int getDollars();
    int getCents();
private:
    int dollars;
    int cents;
};
Money::Money() : dollars(0), cents(0){}
Money::Money(int a, int b) : dollars(a), cents(b){}

int Money::getDollars(){ return dollars; }
int Money::getCents(){ return cents; }

int main(){
    Money mon1(25, 50), mon2;
    cout << "Mon1 : " << mon1.getDollars() << " dollars, " << mon1.getCents() << " cents.";
    cout << endl;
    cout << "MOn2 : " << mon2.getDollars() << " dollars, " << mon2.getCents() << " cents.";
    cout << endl;
    return 0;
}
