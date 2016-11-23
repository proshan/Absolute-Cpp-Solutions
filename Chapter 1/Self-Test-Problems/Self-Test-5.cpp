#include <iostream>
using namespace std;
int main(){
    char a = 'b';
    char b = 'c';
    char c = a;
    cout << a << b << c << 'c';
    return 0;
    //Output is: b c b c
}
