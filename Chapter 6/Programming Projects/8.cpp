/*Define a class named Money that stores a monetary amount. The class should have
two private integer variables, one to store the number of dollars and another to
store the number of cents. Add accessor and mutator functions to read and set both
member variables. Add another function that returns the monetary amount as a
double. Write a program that tests all of your functions with at least two different
Money objects. */
#include <iostream>
using namespace std;
class Money{
private:
    int dollars;
    int cents;
public:
    void setDollars(int d);
    void setCents(int c);
    int getDollars();
    int getCents();
};
void Money::setDollars(int d){
    dollars = d;
}
void Money::setCents(int c){
    cents = c;
}
int Money::getDollars(){
    return dollars;
}
int Money::getCents(){
    return cents;
}
int main(){
    Money m;
    m.setDollars(5);
    m.setCents(45);
    cout << "Dollars is: $" << m.getDollars() << endl;
    cout << "Cents is: $" << m.getCents() << endl;
    return 0;
}
