/*Write a function declaration and a function definition for a function that takes one argument
of type double. The function returns the character value ’P’ if its argument is positive
and returns ’N’ if its argument is zero or negative */
#include <iostream>
using namespace std;
char result(double number);
int main(){
    cout << "Enter a number: ";
    int number;
    cin >> number;
    cout << "\n" << result(number);
    return 0;
}
char result(double number){
    if(number > 0){
        return 'P';
    }
    else{
        return 'N';
    }
}
