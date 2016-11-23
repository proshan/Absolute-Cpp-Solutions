#include <iostream>
using namespace std;
int main(){
    /* Write a complete C++ program that reads two whole numbers into two variables of type
int and then outputs both the whole number part and the remainder when the first number
is divided by the second. This can be done using the operators / and %. */
    int num1, num2;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "\nEnter num2: ";
    cin >> num2;
    cout << "\nThe whole number part is: " << num1/num2;
    cout << "\nThe remainder part is: " << num1 % num2;
    return 0;
}
