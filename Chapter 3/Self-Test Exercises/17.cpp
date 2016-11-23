#include <iostream>
using namespace std;
void product(int num1, int num2, int num3);
int main(){
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1;
    cin >> num2;
    cin >> num3;
    product(num1, num2, num3);
    return 0;
}
void product(int num1, int num2, int num3){
    cout << "The product of the three numbers is: " << num1*num2*num3;
}
