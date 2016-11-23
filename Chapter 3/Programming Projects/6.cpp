/*Write a function that computes the average and standard deviation of four scores.
The standard deviation is defined to be the square root of the average of the four
values: (s i - a )^2 , where a is the average of the four scores s 1 , s 2 , s 3 , and s
4 . The function
will have six parameters and will call two other functions. Embed the function
in a program that allows you to test the function again and again until you tell the
program you are finished. */
#include <iostream>
#include <cmath>
using namespace std;
double average(int s1, int s2, int s3, int s4);
double deviation(int s1, int s2, int s3, int s4);
int main(){
    int s1, s2, s3, s4;
    cout << "Enter the numbers (separated by spaces): ";
    cin >> s1 >> s2 >> s3 >> s4;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The standard deviation of those numbers is: " << deviation(s1, s2, s3, s4);
    cout << endl;
    return 0;
}
double average(int s1, int s2, int s3, int s4){
    return (s1+s2+s3+s4)/static_cast<double>(4);
}
double deviation(int s1, int s2, int s3, int s4){
    double mean = average(s1, s2, s3, s4);
    double result=0;
    result = result + pow((s1-mean), 2) + pow((s2-mean), 2) + pow((s3-mean), 2) + pow((s4-mean), 2);
    return sqrt(result/4);
}




