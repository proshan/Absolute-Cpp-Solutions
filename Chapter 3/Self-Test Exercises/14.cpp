/* Write a function definition for a function isDigit that takes one argument of type char
and returns a bool value. The function returns true if the argument is a decimal digit; otherwise,
it returns false. */
#include <iostream>
using namespace std;
bool isDigit(char ch);
int main(){
    char character = 'h';
    cout << isDigit(character);
    return 0;
}
bool isDigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }
    else{
        return false;
    }
}
