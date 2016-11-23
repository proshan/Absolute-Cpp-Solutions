#include <iostream>
using namespace std;
void addTax(double taxRate, double& cost);
int main(){
    double cost = 250;
    addTax(10, cost);
    cout << cost;
    cout << endl;
}
void addTax(double taxRate, double & cost){
    cost = cost + (taxRate/100) *cost;
}

