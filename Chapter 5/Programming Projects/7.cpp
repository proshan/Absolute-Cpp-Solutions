/*Generate a text-based histogram for a quiz given to a class of students. The quiz is
graded on a scale from 0 to 5. Write a program that allows the user to enter grades
for each student. As the grades are being entered, the program should count, using
an array, the number of 0’s, the number of 1’s, the number of 2’s, the number of
3’s, the number of 4’s, and the number of 5’s. The program should be capable of
handling an arbitrary number of student grades.
 You can do this by making an array of size 6, where each array element is initialized
to zero. Whenever a zero is entered, increment the value in the array at index 0.
Whenever a one is entered, increment the value in the array at index 1, and so on,
up to index 5 of the array.
 Output the histogram count at the end. For example, if the input grades are 3, 0,
1, 3, 3, 5, 5, 4, 5, 4, then the program should output
 1 grade(s) of 0
 1 grade(s) of 1
 0 grade(s) of 2
 3 grade(s) of 3
 2 grade(s) of 4
 3 grade(s) of 5 */

//text-based-histogram
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 20;
void getInputs(int times[]);
void printResult(int times[]);
int main(){
    int times[6] = {0, 0, 0, 0, 0, 0};
    getInputs(times);
    printResult(times);
    cout << endl;
    return 0;
}
void getInputs(int times[]){
    int numberOfValues = 0;
    int grade = 0;
    cout << "How many values you want to enter?";
    cin >> numberOfValues;
    for(int i = 0; i<numberOfValues; i++){
        cout << "Enter a grade: ";
        cin >> grade;
        if(grade < 0 || grade > 5){
            while(true){
                cout << "Sorry, the grade is not valid. Enter another value: ";
                cin >> grade;
                if(grade >= 0 && grade <=5){
                    times[grade]++;
                    break;
                }
            }
        }
        else{
            times[grade]++;
        }
    }
    return;
}
void printResult(int times[]){
    cout << endl;
    cout << setw(20) << "Score" << setw(20) << "Times" << endl;
    cout << "----------------------------------------------" << endl;
    for(int i = 0; i<6; i++){
        cout << setw(20) << i << setw(20) << times[i] << endl;
    }
    return;
}
