/*Write a program that converts from 24-hour notation to 12-hour notation. For
example, it should convert 14:25 to 2:25 P.M. The input is given as two integers.
There should be at least three functions: one for input, one to do the conversion,
and one for output. Record the A.M./P.M. information as a value of type char ,
'A' for A.M. and 'P' for P.M. Thus, the function for doing the conversions will
have a call-by-reference formal parameter of type char to record whether it is A.M.
or P.M. (The function will have other parameters as well.) Include a loop that lets
the user repeat this computation for new input values again and again until the user
says he or she wants to end the program. */
#include <iostream>
using namespace std;
void getTime(int& hours, int& minutes);
char conversion(int& hours);
void output(int hours, int minutes, char cp);
int main(){
    int hours, minutes;
    char ans;
    do{
        getTime(hours, minutes);
        char cp = conversion(hours);
        output(hours, minutes, cp);
        cout << "\nCalculate again? ";
        cin>> ans;
    }while(ans == 'Y' || ans == 'y');
    return 0;
}
void getTime(int& hours, int& minutes){
    //input the hours and minutes as call-by-reference parameters
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
}
char conversion(int& hours){
    char cp;
    int division;
    if(hours <= 12){
        cp = 'A';
    }
    else{
        division = hours % 12;
        if(division == 0){
            hours = 00;
        }
        else{
            hours = division;
        }
        cp = 'P';
    }
    return cp;
}
void output(int hours, int minutes, char cp){
    cout << "The time is: " << hours<< ":" << minutes << " " << cp << "M";
    cout << endl;
}


