/*The standard deviation of a list of numbers is a measure of how much the numbers
deviate from the average. If the standard deviation is small, the numbers are
clustered close to the average. If the standard deviation is large, the numbers are
scattered far from the average. The standard deviation, S , of a list of N numbers xi
is defined as follows,
        formula goes here..
where x is the average of the N numbers x1, x2, …. Define a function that takes a
partially filled array of numbers as its argument and returns the standard deviation
of the numbers in the partially filled array. Since a partially filled array requires two
arguments, the function will actually have two formal parameters: an array parameter  and a formal parameter of type int that gives the number of array positions used.
The numbers in the array will be of type double . Embed your function in a suitable
test program.
*/
#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 10;
void getValues(double arr[], int &arraySize);
double calculateSd(double arr[], int arraySize);
double getAverage(double arr[], int arraySize);
int main(){
    double arr[MAX];
    int arraySize;
    getValues(arr, arraySize);
    double sd = calculateSd(arr, arraySize);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The standard deviation of given numbers is: " << sd;
    cout << endl;
    return 0;
}
void getValues(double arr[], int &arraySize){
    cout << "How many values do you want to enter? ";
    cin >> arraySize;
    for(int i = 0; i<arraySize; i++){
        cout << "Enter a value: ";
        cin >> arr[i];
    }
    return;
}
double calculateSd(double arr[], int arraySize){
    double average = getAverage(arr, arraySize);
    double square_sum = 0;
    for(int i = 0; i<arraySize; i++){
        square_sum += pow((arr[i] - average), 2);
    }
    return sqrt(square_sum/arraySize);
}
double getAverage(double arr[], int arraySize){
    double sum = 0;
    double average = 0;
    for(int i = 0; i<arraySize; i++){
        sum += arr[i];
    }
    average = sum / arraySize;
    return average;
}

