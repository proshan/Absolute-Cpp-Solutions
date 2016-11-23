/*Write a function named sort that takes three integer parameters by reference. The
function should rearrange the parameter values so that the first parameter gets set
to the smallest value, the second parameter gets set to the second smallest value,
and the third parameter gets set to the largest value. For example, given the variable
assignments a = 30; b = 10; c = 20; then the function call sort(a,b,c)
should result in a = 10, b = 20, and c = 30. Note that the array construct covered
in Chapter 5 will give you a way to solve this problem for an arbitrary number of
items instead of only for three items. */
#include <iostream>
using namespace std;
void getNumbers(int &a, int &b, int &c);
void sortNumbers(int &a, int &b, int &c);
void printNumbers(int a , int b, int c);
int main(){
    int a, b, c;
    getNumbers(a, b, c);
    sortNumbers(a, b, c);
    printNumbers(a, b, c);
    return 0;
}
void getNumbers(int &a, int &b, int &c){
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    return;
}
void sortNumbers(int &a, int &b, int &c){
    int lowest = a;
    if(b < a && b < c){
        lowest = b;
    }
    else if(c < a && c < b){
        lowest = c;
    }
    int greatest = c;
    if(a > b && a > c){
        greatest = a;
    }
    else if(b > a && b > c){
        greatest = b;
    }
    int middle;
    if(lowest == a && greatest == b){
        middle = c;
    }
    if(lowest == b && greatest == c){
        middle = a;
    }
    if(lowest == c && greatest == a){
        middle = b;
    }
    a = lowest;
    b = middle;
    c = greatest;
    return;
}
void printNumbers(int a, int b, int c){
    cout << "The sorted numbers are: " << a << ", " << b << ", " << c << endl;
    return;
}

