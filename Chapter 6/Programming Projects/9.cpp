/*Do Programming Project 6.8 , except remove the two private integer variables and
use a single variable of type double to store the monetary value in their place. The
rest of the functions should have the same headers. For several functions, this will
require code to convert from an integer format to appropriately modify the double.
For example, if the monetary amount stored in the double is 4.55 (representing
$4.55) and if the function to set the dollar amount is invoked with the value 13,
then the double should be changed to 13.55. While this will take some work, the
code in your test program from Programming Project 6.8 should still work without
requiring any changes. This is the benefit of encapsulating the member variables. */
#include <iostream>
using namespace std;
class Money{
private:
    double money;
public:
    Money();
    void setValue(double amount);
    double getValue();
};
Money::Money(){
    money = 0;
}
void Money::setValue(double amount){
    money = amount;
}
double Money::getValue(){
    return money;
}
int main(){
    Money mon;
    mon.setValue(59.34);
    cout << "The money is: " << mon.getValue();
    cout << endl;
    return 0;
}
