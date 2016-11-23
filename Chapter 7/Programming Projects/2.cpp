/*Redefine the implementation of the class Month described in Programming
Project 7.1 (or do the definition for the first time, but do the implementation as
described here). This time the month is implemented as three member variables of
type char that store the first three letters in the name of the month. Embed your
definition in a test program. */
#include <iostream>
#include <string>
using namespace std;
class Month{
public:
    Month();
    //default constructor
    Month(char l1, char l2, char l3);
    //sets the value of first three letters
    //of the month
    int getMonthNumber();
    //returns the respective value of month
    //as integer number
    string getMonthValue();
    //returns the value of month;
private:
    char letter1;
    char letter2;
    char letter3;
    string month;
};

Month::Month() : letter1('j'), letter2('a'), letter3('n'){}
Month::Month(char l1, char l2, char l3) : letter1(l1), letter2(l2), letter3(l3){}

int Month::getMonthNumber(){
    int mNumber;
    string months[12] = {"January", "February", "March", "April", "May",
                    "June", "July", "August", "September", "October",
                    "November", "December"};
    string currentMonth;
    for(int i = 0; i<12; i++){
        currentMonth = months[i];
        if(static_cast<char>(currentMonth[0]) == letter1 && static_cast<char>(currentMonth[1]) == letter2 &&
           static_cast<char>(currentMonth[2]) == letter3){
            mNumber = i+1;
            break;
        }
    }
    month = months[mNumber-1];
    return mNumber;
}
string Month::getMonthValue(){ return month; };
int main(){
    Month m('M', 'a', 'r');
    cout << m.getMonthNumber();
    cout << endl << m.getMonthValue();
    cout << endl;
    return 0;
}
