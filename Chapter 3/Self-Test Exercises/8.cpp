/* Write a function declaration (function prototype) and a function definition for a function
that takes three arguments, all of type int, and that returns the sum of its three arguments
*/
#include <iostream>
using namespace std;
int sum(int num1, int num2, int num3);
int main(){
    int number1 = 5;
    int number2 = 6;
    int number3 = 7;
    cout << sum(number1, number2, number3);
    return 0;
}
int sum(int num1, int num2, int num3){
    return num1+num2+num3;
}
