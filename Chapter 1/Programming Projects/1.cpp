/* A metric ton is 35,273.92 ounces. Write a program that will read the weight of a package of
breakfast cereal in ounces and output the weight in metric tons as well as the number of
boxes needed to yield one metric ton of cereal.*/
#include <iostream>
using namespace std;
int main(){
    cout << "Enter the weight of package of breakfast cereal in ounces: ";
    float ounces;
    cin >> ounces;
    float result = ounces/35273.92;
    cout << endl;
    cout << "The weight in metric tons is : " << result;
    cout << endl;
    cout << "You need " << (1/result) << " boxes to yield one metric ton of cereal.";
    cout << endl;
    return 0;
}
