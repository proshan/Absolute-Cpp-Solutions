/*Your time machine is capable of going forward in time up to 24 hours. The machine
is configured to jump ahead in minutes. To enter the proper number of minutes
into your machine, you would like a program that can take a start time and an
end time and calculate the difference in minutes between them. The end time will
always be within 24 hours of the start time. Use military notation for both the start
and end times (e.g., 0000 for midnight and 2359 for one minute before midnight).
 Write a function that takes as input a start time and an end time represented as an
int , using military notation. The function should return the difference in minutes
as an integer. Write a driver program that calls your subroutine with times entered
by the user. */
//Calculates the time difference of the two military notated times
#include <iostream>
using namespace std;
void getTime(int &startTime, int &endTime);
void convert(int &time);
int getMinutes(int startTime, int endTime);
int hourDifference(int start_hours, int end_hours);
int main(){
    int startTime, endTime;
    getTime(startTime, endTime);
    cout << "The minutes is: " << getMinutes(startTime, endTime);
    cout << endl;
    return 0;
}
void getTime(int &startTime, int &endTime){
    cout << "Enter the start time: ";
    cin >> startTime;
    convert(startTime);
    cout << "Enter the end time: ";
    cin >> endTime;
    convert(endTime);
    return;
}
void convert(int &time){
    int last_two = time % 100;
    if(time/100 == 00){
        time = 24*100 + last_two;
    }
    return;
}
int getMinutes(int startTime, int endTime){
    int start_hours = startTime/100;
    int start_minutes = startTime%100;
    int end_hours = endTime/100;
    int end_minutes = endTime%100;
    int hours = 0;
    int minutes = 0;
    if(start_hours > end_hours){
        hours = hourDifference(start_hours, end_hours);
    }
    else{
        hours = end_hours - start_hours;
    }
    minutes = (hours * 60) - start_minutes + end_minutes;
    return minutes;
}
int hourDifference(int start_hours, int end_hours){
    return (24-start_hours) + end_hours;
}
