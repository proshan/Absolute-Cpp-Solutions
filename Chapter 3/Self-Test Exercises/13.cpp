/* Write a function definition for a function called even that takes one argument of type int
and returns a bool value. The function returns true if its one argument is an even number;
otherwise, it returns false. */
#include <iostream>
using namespace std;
bool even(int number);
int main(){
    int number = 9;
    cout << even(number);
    cout << endl;
    return 0;
}
bool even(int number){
    if(number % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}
