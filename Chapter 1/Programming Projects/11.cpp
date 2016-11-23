/*Write a program that inputs an integer that represents a length of time in seconds.
The program should then output the number of hours, minutes, and seconds that
corresponds to that number of seconds. For example, if the user inputs 50391 total
seconds then the program should output 13 hours, 59 minutes, and 51 seconds.  */
#include <iostream>
using namespace std;
int main(){
    int number_of_seconds;
    cout << "Enter the number of seconds: ";
    cin >> number_of_seconds;
    int hrs = number_of_seconds/3600;
    int remaining_seconds = number_of_seconds % 3600;
    int minutes = remaining_seconds/60;
    int seconds = remaining_seconds % 60;
    cout << endl << "Hrs: " << hrs;
    cout << endl << "Minutes: " << minutes;
    cout << endl << "Seconds: " << seconds;
    return 0;
}

