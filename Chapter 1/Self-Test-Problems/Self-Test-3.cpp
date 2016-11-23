#include <iostream>
using namespace std;
int main(){
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    cout << num1 << "\n";
    cout << num2 << "\n";
    cout << num3 << "\n";
    cout << num4 << "\n";
    cout << num5 << "\n";
    return 0;
    /* This returns the following output:
    4309822
    6946708
    4309728
    1981379677
    1981379434
    What is happening here is the uninitialized variables are returning the garbage data when they are printed.
    */
}
