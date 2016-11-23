#include <iostream>
using namespace std;
void zeroBoth(int &num1, int &num2);
int main(){
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    zeroBoth(num1, num2);
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    return 0;
}
void zeroBoth(int &num1, int &num2){
    num1 = 0;
    num2= 0;
}
