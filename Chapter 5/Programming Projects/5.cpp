/*An array can be used to store large integers one digit at a time. For example, the
integer 1234 could be stored in the array a by setting a[0] to 1 , a[1] to 2 , a[2]
to 3 , and a[3] to 4 . However, for this exercise you might find it more useful to
store the digits backward, that is, place 4 in a[0] , 3 in a[1] , 2 in a[2] , and 1 in
a[3] . In this exercise you will write a program that reads in two positive integers
that are 20 or fewer digits in length and then outputs the sum of the two numbers.
Your program will read the digits as values of type char so that the number
1234 is read as the four characters '1' , '2' , '3' , and '4' . After they are read into
the program, the characters are changed to values of type int . The digits will be
read into a partially filled array, and you might find it useful to reverse the order
of the elements in the array after the array is filled with data from the keyboard.
(Whether or not you reverse the order of the elements in the array is up to you. It
can be done either way, and each way has its advantages and disadvantages.) Your
program will perform the addition by implementing the usual paper-and-pencil
addition algorithm. The result of the addition is stored in an array of size 20 and
the result is then written to the screen. If the result of the addition is an integer with
more than the maximum number of digits (that is, more than 20 digits), then your
program should issue a message saying that it has encountered “integer overflow.”
You should be able to change the maximum length of the integers by changing
only one globally defined constant. Include a loop that allows the user to continue
to do more additions until the user says the program should end. */
#include <iostream>
using namespace std;
const int MAX = 20;
void getValues(char num[], int &arraySize);
void reverseOrder(char num[], int arraySize);
void swapValues(char &a, char &b);
int findNumber(char num[], int arraySize);
int main(){
    char num1[MAX];
    char num2[MAX];
    int num1Size;
    int num2Size;
    getValues(num1, num1Size);
    getValues(num2, num2Size);
    reverseOrder(num1, num1Size);
    reverseOrder(num2, num2Size);
    int number1 = findNumber(num1, num1Size);
    int number2 = findNumber(num2, num2Size);
    cout << "The sum of " << number 1 << " and " << number2 << " is: " << number1 + number2;
    cout << endl;
    return 0;
}
void getValues(char num[], int &arraySize){
    cout << "How many values do you want to enter in the number?";
    cin >> arraySize;
    for(int i = 0; i<arraySize; i++){
        cout << "Enter a value: ";
        cin >> num[i];
    }
    return;
}
void reverseOrder(char num[], int arraySize){
    for(int i = 0; i<arraySize/2; i++){
        swapValues(num[i], num[arraySize-1-i]);
    }
    return;
}
void swapValues(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
    return;
}
int findNumber(char num[], int arraySize){
    int result = 0;
    int multiplier = 1;
    for(int i = 0; i<arraySize; i++){
        result += (num[i] - 48) * multiplier;
        multiplier *= 10;
    }
    return result;
}

