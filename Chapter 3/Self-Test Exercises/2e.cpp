#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float a = 1;
    float b = 3;
    float c = 2;
    float root = sqrt(pow(b,2) - (4*a*c));
    float result = (-b + root)/(2*a);
    cout << result;
    return 0;
}
