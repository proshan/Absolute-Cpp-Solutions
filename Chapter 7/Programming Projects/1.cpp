/*Define a class called Month that is an abstract data type for a month. Your class will
have one member variable of type int to represent a month (1 for January, 2 for
February, and so forth). Include all the following member functions: a constructor
to set the month using the first three letters in the name of the month as three
arguments, a constructor to set the month using an integer as an argument (1 for
January, 2 for February, and so forth), a default constructor, an input function that
reads the month as an integer, an input function that reads the month as the first
three letters in the name of the month, an output function that outputs the month
as an integer, an output function that outputs the month as the first three letters
in the name of the month, and a member function that returns the next month as
a value of type Month . Embed your class definition in a test program. */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
const int SIZE = 12;
class Month{
public:
    Month(char m_firstLetter, char m_secondLetter, char m_thirdLetter);
    Month(int monthInt);
    Month();
    void setMonths();
    void outputMonthInt();
    void outputMonthLetters();
    void outputNextMonth();
private:
    int month;
    string months[SIZE];
};
int main(){
    Month month1('J', 'a', 'n');
    Month month2(2);
    Month month3(3);

    month1.outputMonthInt();
    month1.outputMonthLetters();
    month1.outputNextMonth();
    cout << endl;
    month2.outputMonthInt();
    month2.outputMonthLetters();
    month2.outputNextMonth();
    cout << endl;
    month3.outputMonthInt();
    month3.outputMonthLetters();
    month3.outputNextMonth();

    cout << endl;
    return 0;
}
void Month::setMonths(){
    string tempMonths[SIZE] = {"January", "February", "March", "April", "May",
                    "June", "July", "August", "September", "October",
                    "November", "December"};
    for(int i = 0; i<SIZE; i++){
        months[i] = tempMonths[i];
    }
}
Month::Month(char m_firstLetter, char m_secondLetter, char m_thirdLetter){
    setMonths();
    bool matched = false;
    for(int i = 0; i<SIZE; i++){
        string currentMonth = months[i];
        if(static_cast<char>(currentMonth[0]) == m_firstLetter && static_cast<char>(currentMonth[1]) == m_secondLetter &&
           static_cast<char>(currentMonth[2]) == m_thirdLetter){
            month = i+1;
            matched = true;
            break;
        }
    }
    if(!matched){
        cout << "The month did not match!";
        exit(1);
    }
}
Month::Month(int monthInt) : month(monthInt){ setMonths(); }
Month::Month() : month(1){ setMonths(); }

void Month::outputMonthInt(){
    cout << "The month number is: ";
    if(month >=1 || month <=12){
        cout << month;
    }
    else{
        cout << "Error!";
    }
    cout << endl;
}
void Month::outputMonthLetters(){
    string currentMonth;
    for(int i = 0; i<SIZE; i++){
        if(month == i+1){
            currentMonth = months[i];
            cout << "The month is: " << currentMonth[0] << currentMonth[1] << currentMonth[2] << endl;
            break;
        }
    }
}
void Month::outputNextMonth(){
    cout << "The next month is: " << month + 1 << " or " << months[month] << endl;
}

