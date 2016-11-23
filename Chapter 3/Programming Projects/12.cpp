/*Write a program that inputs a date (e.g., July 4, 2008) and outputs the day of
the week that corresponds to that date. The following algorithm is from http://
en.wikipedia.org/wiki/Calculating_the_day_of_the_week. The implementation
will require several functions:
 bool isLeapYear(int year);
 This function should return true if year is a leap year and false if it is not. Here
is pseudocode to determine a leap year:
 leap_year = ((year divisible by 400) or (year divisible by 4 and year not divisible
by 100))
 int getCenturyValue(int year);
 This function should take the first two digits of the year (i.e., the century), divide
by 4, and save the remainder. Subtract the remainder from 3 and return this
value multiplied by 2. For example, the year 2008 becomes (20/4) = 5 remainder
0. 3 - 0 = 3. Return 3 * 2 = 6.
 int getYearValue(int year);
 This function computes a value based on the years since the beginning of the
century. First, extract the last two digits of the year. For example, 08 is extracted
for 2008. Next, factor in leap years. Divide the value from the previous step by 4
and discard the remainder. Add the two results together and return this value. For
example, from 2008 we extract 08. Then (8/4) = 2 remainder 0. Return 2 + 8 = 10.
 int getMonthValue( int month, int year);
 This function should return a value based on the following table and will require
invoking the isLeapYear function:
Finally, to compute the day of the week, compute the sum of the date’s
day plus the values returned by getMonthValue, getYearValue , and
getCenturyValue . Divide the sum by 7 and compute the remainder. A
remainder of 0 corresponds to Sunday, 1 corresponds to Monday, etc.—up to
6—which corres ponds to Saturday. For example, the date July 4, 2008 should
be computed as (day of month) + ( getMonthValue ) + ( getYearValue ) +
(get CenturyValue ) = 4 + 6 + 10 + 6 = 26. 26/7 = 3 remainder 5. The fifth
day of the week corresponds to Friday.
 Your program should allow the user to enter any date and output the corresponding
day of the week in English. */
#include <iostream>
#include <string>
using namespace std;
bool isLeapyear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
string getDay(int remainder);
int main(){
    int day, month, year;
    cout << "Enter the date(day month, year): ";
    cin >> day >> month >> year;
    int sum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
    int remainder = sum % 7;
    cout << "The day is: " << getDay(remainder);
    cout << endl;
    return 0;
}
bool isLeapyear(int year){
    bool isleap;
    if((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0)){
        isleap = true;
    }
    else{
        isleap = false;
    }
    return isleap;
}
int getCenturyValue(int year){
    int century = year / 100;
    int remainder = century % 4;
    int century_value = (3-remainder);
    return century_value * 2;
}
int getYearValue(int year){
    int last_digits = year % 100;
    int division = last_digits/4;
    return division + last_digits;
}
int getMonthValue(int month, int year){
    int value;
    switch(month){
    case 1:
        if(isLeapyear(year) == true){
            value = 6;
        }
        else{
            value = 0;
        }
    break;
    case 2:
        if(isLeapyear(year) == true){
            value = 2;
        }
        else{
            value = 3;
        }
    break;
    case 3:
        value = 3;
    break;
    case 4:
        value = 6;
    break;
    case 5:
        value = 1;
    break;
    case 6:
        value = 4;
    break;
    case 7:
        value = 6;
    break;
    case 8:
        value = 2;
    break;
    case 9:
        value = 5;
    break;
    case 10:
        value = 0;
    break;
    case 11:
        value = 3;
    break;
    case 12:
        value = 5;
    break;
    default:
        value = 1;
    }
    return value;
}
string getDay(int remainder){
    string value;
    switch(remainder){
    case 0:
        value = "Sunday";
    break;
    case 1:
        value = "Monday";
    break;
    case 2:
        value = "Tuesday";
    break;
    case 3:
        value = "Wednesday";
    break;
    case 4:
        value = "Thursday";
    break;
    case 5:
        value = "Friday";
    break;
    case 6:
        value = "Saturday";
    break;
    default:
        value = "unknown";
    }
    return value;
}

