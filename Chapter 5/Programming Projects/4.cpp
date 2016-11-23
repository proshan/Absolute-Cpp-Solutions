/*Write a program that reads in an array of type int . You may assume that there
are fewer than 50 entries in the array. Your program determines how many entries
are used. The output is to be a two-column list. The first column is a list of the
 distinct array elements; the second column is the count of the number of occurrences
of each element. The list should be sorted on entries in the first column,
largest to smallest.
 For the array values
 –12 3 –12 4 1 1 –12 1 –1 1 2 3 4 2 3 –12
 the output should be
 N Count
 4 2
 3 3
 2 2
 1 4
 –1 1
 –12 4 */
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 50;
void getValues(int arr[], int &arraySize);
void sortArray(int arr[], int arraySize);
void swapValues(int &a, int &b);
void repeatition(int arr[], int times[], int &arraySize);
void showResults(int arr[], int times[], int arraySize);
int main(){
    int arr[MAX];
    int times[MAX];
    int arraySize;
    getValues(arr, arraySize);
    sortArray(arr, arraySize);
    repeatition(arr, times, arraySize);
    showResults(arr, times, arraySize);
    cout << endl;
    return 0;
}
void getValues(int arr[], int &arraySize){
    cout << "How many values do you want to enter?";
    cin >> arraySize;
    for(int i = 0; i < arraySize; i++){
        cout << "Enter a value: ";
        cin >> arr[i];
    }
    return;
}
void sortArray(int arr[], int arraySize){
    for(int i = 0; i<arraySize; i++){
        for(int j = i+1; j<arraySize; j++){
            if(arr[i] < arr[j]){
                swapValues(arr[i], arr[j]);
            }
        }
    }
    return;
}
void swapValues(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return;
}
void repeatition(int arr[], int times[], int &arraySize){
    int repeat = 1;
    for(int i = 0; i<arraySize; i++){
        for(int j = i+1; j<arraySize; j++){
            if(arr[i] == arr[j]){
                for(int m = j; m<arraySize-1; m++){
                    if(arr[m] == arr[m+1]){
                        repeat++;
                    }
                    arr[m] = arr[m+1];
                }
                arraySize--;
            }
        }
        times[i] = repeat;
    }
    return;
}
void showResults(int arr[], int times[], int arraySize){
    cout << setw(10) << "Number" << setw(20) << "Count"<< endl << endl;
    for(int i = 0; i<arraySize; i++){
        cout << setw(10) << arr[i] << setw(20) << times[i] << endl;
    }
    return;
}
