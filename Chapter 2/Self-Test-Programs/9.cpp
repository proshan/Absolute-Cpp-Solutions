#include <iostream>
using namespace std;
int main(){
    /*Write an if-else statement that outputs the word Warning provided that either the value
of the variable temperature is greater than or equal to 100, or the value of the variable
pressure is greater than or equal to 200, or both. Otherwise, the if-else statement outputs
the word OK. The variables temperature and pressure are both of type int.
    */
    int temperature, pressure;
    if((temperature >= 100) || (pressure >= 200)){
        cout << "Warning!";
    }
    else{
        cout << "\nOK!";
    }
    return 0;
}
