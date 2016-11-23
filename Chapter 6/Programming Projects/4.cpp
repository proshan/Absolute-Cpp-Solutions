/*Write the definition for a class named GasPump to be used to model a pump at an
automobile service station. Before you go further with this programming exercise,
write down the behavior you expect from a gas pump from the point of view of the
purchaser.
 The following are listed things a gas pump might be expected to do. If your list
differs, and you think your list is as good or better than these, then consult your
instructor. You and your instructor should jointly decide what behavior you are to
implement. Then implement and test the agreed upon design for a gas pump class.
 a. A display of the amount dispensed
 b. A display of the amount charged for the amount dispensed
 c. A display of the cost per gallon, liter, or other unit of volume that is used where
you reside
 d. Before use, the gas pump must reset the amount dispensed and amount charged
to zero.
 e. Once started, a gas pump continues to dispense fuel, keep track of the amount
dispensed, and compute the charge for the amount dispensed until stopped.
 f. A stop dispensing control of some kind is needed.
 Implement the behavior of the gas pump as declarations of member functions of
the gas pump class, then write implementations of these member functions. You
will have to decide if there is data the gas pump has to keep track of that the user
of the pump should not have access to. If so, make these private member variables. */
#include <iostream>
using namespace std;
const double CPG = 1.20;
class GasPump{
private:
    double dispensedAmount;
    double charge;
    double gasAmount;
    double returnAmount;
public:
    GasPump();
    void dispenseAmount(double amount);
    void fillGas(double amount);
    void stopDispensing();
    void printResult();
};
GasPump::GasPump(){
    dispensedAmount = 0;
    charge = 0;
    gasAmount = 0;
    returnAmount = 0;
    cout << "Cost per gallon: " << CPG << endl;
    cout << endl;
}
void GasPump::dispenseAmount(double amount){
    dispensedAmount = amount;
}
void GasPump::fillGas(double amount){
    gasAmount += amount;
    charge += amount * CPG;
}
void GasPump::stopDispensing(){
    returnAmount = dispensedAmount - charge;
}
void GasPump::printResult(){
    cout << "Amount dispensed: " << dispensedAmount << endl;
    cout << "Total gas amount: " << gasAmount << endl;
    cout << "Total charge: " << charge << endl;N
    cout << "Return amount: " << returnAmount << endl;
}
int main(){
    GasPump gp;
    gp.dispenseAmount(50);
    gp.fillGas(10);
    gp.fillGas(4.5);
    gp.fillGas(12);
    gp.stopDispensing();
    gp.printResult();
    cout << endl;
    return 0;
}
