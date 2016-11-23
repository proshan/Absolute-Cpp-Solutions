/*  Write a program that determines whether a meeting room is in violation of fire law regulations
regarding the maximum room capacity. The program will read in the maximum room
capacity and the number of people to attend the meeting. If the number of people is less
than or equal to the maximum room capacity, the program announces that it is legal to
hold the meeting and tells how many additional people may legally attend. If the number
of people exceeds the maximum room capacity, the program announces that the meeting
cannot be held as planned due to fire regulations and tells how many people must be
excluded in order to meet the fire regulations.*/
#include <iostream>
using namespace std;
int main(){
    int maximum_capacity, number_of_people_attending;
    cout << "Enter the number of people attending the meeting: ";
    cin >> number_of_people_attending;
    cout << endl;
    cout << "Enter the maximum number of people that can attend the meeting legally: ";
    cin >> maximum_capacity;
    cout << endl;
    if(number_of_people_attending <= maximum_capacity){
        cout << "The additional number of people that may legally attend the meeting is :" << maximum_capacity - number_of_people_attending;

    }
    else{
        int to_be_excluded = number_of_people_attending - maximum_capacity;
        cout << "The meeting cannot be held as planned due to fire regulations.";
        cout << endl;
        cout << "In order to meet the fire regulations, " << to_be_excluded;
        if(to_be_excluded == 1){
            cout << " person must be excluded.";
        }
        else{
            cout << " people must be excluded.";
        }
    }
    cout << endl;
    return 0;
}
