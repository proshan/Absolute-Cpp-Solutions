#include <iostream>
using namespace std;
int main(){
    /*  Given the following fragment that purports to convert from degrees Celsius to degrees
Fahrenheit, answer the following questions:
double c = 20;
double f;
f = (9/5) * c + 32.0;
a. What value is assigned to f?
b. Explain what is actually happening, and what the programmer likely wanted.
c. Rewrite the code as the programmer intended.
    */
    double c = 20;
    double f;
    f = (9/5)*c + 32.0;
    cout << f;
    //a. 52 is the value assigned to f.
    //b. "Integer division discards remainder". So, the program is not working like the programmer wanted.
    //Rewritten code:
    cout << endl << "Rewritten Code:";
    f = (9.0/5.0) * c + 32.0;
    cout << f;
    return 0;

}
