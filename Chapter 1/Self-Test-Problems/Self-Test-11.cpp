#include <iostream>
using namespace std;
int main(){
    /* What statements should you include in your program to ensure that when a number of
type double is output, it will be output in ordinary notation with three digits after the decimal
point?
    */
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    double number = 10;
    cout << number;
    return 0;
}
