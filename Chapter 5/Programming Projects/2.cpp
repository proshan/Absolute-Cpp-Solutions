/* Write a function called deleteRepeats that has a partially filled array of characters
as a formal parameter and that deletes all repeated letters from the array. Since a
partially filled array requires two arguments, the function will actually have two
formal parameters: an array parameter and a formal parameter of type int that
gives the number of array positions used. When a letter is deleted, the remaining
letters are moved forward to fill in the gap. This will create empty positions at
the end of the array so that less of the array is used. Since the formal parameter is
a partially filled array, a second formal parameter of type int will tell how many
array positions are filled. This second formal parameter will be a call-by-reference
parameter and will be changed to show how much of the array is used after the
repeated letters are deleted. For example, consider the following code:
 char a[10];
 a[0] = 'a';
 a[1] = 'b';
 a[2] = 'a';
 a[3] = 'c';
 int size = 4;
 deleteRepeats(a, size);
 After this code is executed, the value of a[0] is 'a' , the value of a[1] is 'b' , the
value of a[2] is 'c' , and the value of size is 3 . (The value of a[3] is no longer of
any concern, since the partially filled array no longer uses this indexed variable.)
You may assume that the partially filled array contains only lowercase letters.
Embed your function in a suitable test program. */
#include <iostream>
using namespace std;
const int SIZE = 10;
void getValues(char arr[], int &arraySize);
void deleteRepeats(char arr[], int &arraySize);
void showResult(char arr[], int arraySize);
int main(){
    int arraySize;
    char arr[SIZE];
    getValues(arr, arraySize);
    deleteRepeats(arr, arraySize);
    showResult(arr, arraySize);
    return 0;
}
void getValues(char arr[], int &arraySize){
    cout << "How many values you want to insert: ";
    cin >> arraySize;
    for(int i = 0; i < arraySize; i++){
        cout << "Enter a value: ";
        cin >> arr[i];
    }
    return;
}
void deleteRepeats(char arr[], int &arraySize){
    for(int i = 0; i<arraySize; i++){
        for(int j = i+1; j<arraySize; j++){
            if(arr[i] == arr[j]){
                for(int m = j; m<arraySize-1; m++){
                    arr[m] = arr[m+1];
                }
                arraySize--;
            }
        }
    }
}
void showResult(char arr[], int arraySize){
    for(int i = 0; i<arraySize; i++){
        cout << arr[i] << endl;
    }
    return;
}
