/* Write a function definition for a function called inOrder that takes three arguments of
type int. The function returns true if the three arguments are in ascending order; otherwise,
it returns false. For example, inOrder(1, 2, 3) and inOrder(1, 2, 2) both
return true, whereas inOrder(1, 3, 2) returns false. */
#include <iostream>
using namespace std;
bool inOrder(int num1, int num2, int num3);
int main(){
    int num1 = 3, num2 = 3, num3 = 4;
    cout << inOrder(num1, num2, num3)<< endl;
    return 0;
}
bool inOrder(int num1, int num2, int num3){
    if((num2 - num1) == 1 && (num3 - num2) == 1){
        return true;
    }
    else{
        return false;
    }
}
