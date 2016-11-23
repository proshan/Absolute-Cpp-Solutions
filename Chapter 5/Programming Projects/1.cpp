/* Write a program that reads in the average monthly rainfall for a city for each month
of the year and then reads in the actual monthly rainfall for each of the previous
12 months. The program then prints out a nicely formatted table showing the rainfall
for each of the previous 12 months as well as how much above or below average the
rainfall was for each month. The average monthly rainfall is given for the months
 January, February, and so forth, in order. To obtain the actual rainfall for the previous
12 months, the program first asks what the current month is and then asks for the rainfall
figures for the previous 12 months. The output should correctly label the months.
 There are a variety of ways to deal with the month names. One straightforward
method is to code the months as integers and then do a conversion before doing the
output. A large switch statement is acceptable in an output function. The month
input can be handled in any manner you wish, as long as it is relatively easy and
pleasant for the user.
After you have completed the previous program, produce an enhanced version
that also outputs a graph showing the average rainfall and the actual rainfall for
each of the previous 12 months. The graph should be similar to the one shown in
 Display 5.4 , except that there should be two bar graphs for each month and they
should be labeled as the average rainfall and the rainfall for the most recent month.
Your program should ask the user whether he or she wants to see the table or the
bar graph, and then should display whichever format is requested. Include a loop
that allows the user to see either format as often as the user wishes until the user
requests that the program end. */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int MONTHS = 12;
void getAverageMonthlyRainfall(double avgRainfall[], string month[]);
int currentMonth(string month[]);
void getActualMontlyRainfall(double actlRainfall[], string month[], int current);
void showDifference(double actlRainfall[], double avgRainfall[], string month[]);
int scale(double number);
void inputScale(double actlRainfall[], double avgRainfall[]);
void showGraph(double actlRainfall[], double avgRainfall[], string month[]);
void stars(int number);
int main(){
    string month[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double averageRainfall[MONTHS];
    double actlRainfall[MONTHS];
    char user_input;
    getAverageMonthlyRainfall(averageRainfall, month);
    cout << endl;
    int current = currentMonth(month);
    cout << endl;
    getActualMontlyRainfall(actlRainfall, month, current);
    cout << endl;
    cout << "Which format do you want? Tabular or Graph (t/g): ";
    cin >> user_input;
    if(user_input == 't' || user_input == 'T'){
        showDifference(actlRainfall, averageRainfall, month);
    }
    else if(user_input == 'g' || user_input == 'G'){
        inputScale(actlRainfall, averageRainfall);
        showGraph(actlRainfall, averageRainfall, month);
    }
    return 0;
}
void getAverageMonthlyRainfall(double avgRainfall[], string month[]){
    for(int i = 0; i<MONTHS; i++){
        cout << "Enter the average rainfall for " << month[i] << " : ";
        cin >> avgRainfall[i];
    }
    return;
}
int currentMonth(string month[]){
    //returns the index of month
    //from month[] inputted by the user
    string m = "";
    int monthIndex = 0;
    cout << "Enter the current month: ";
    cin >> m;
    for(int i = 0; i<MONTHS; i++){
        if(month[i] == m){
            monthIndex = i;
            break;
        }
    }
    return monthIndex;
}
void getActualMontlyRainfall(double actlRainfall[], string month[], int current){
    //12 months before the current month
    int temp_end = current - 1;
    int temp_start = temp_end + 1;
    int after_twelve = 0;
    while(after_twelve <= temp_end){
        if(temp_start > 11){
            cout << "Enter the actual rainfall in " << month[after_twelve] << " of this year: ";
            cin >> actlRainfall[after_twelve];
            after_twelve++;
        }
        else{
            cout << "Enter the actual rainfall in " << month[temp_start] << " of previous year: ";
            cin >> actlRainfall[temp_start];
            temp_start++;
        }
    }
    return;
}
void showDifference(double actlRainfall[], double avgRainfall[], string month[]){
    cout << setw(10) << "Month"  << setw(25) << "Average Rainfall" << setw(20) << "Actual Rainfall"
        << setw(20) << "Difference" << endl << "---------------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i<MONTHS; i++){
        cout << setw(10) << month[i]
            << setw(6) << "|" << setw(17) << avgRainfall[i]
            << setw(20) << actlRainfall[i]
            << setw(20) << abs(actlRainfall[i] - avgRainfall[i]) << endl;
    }
    return;
}
void inputScale(double actlRainfall[], double avgRainfall[]){
    double current_actl = 0;
    double current_avg = 0;
    for(int i = 0; i<MONTHS; i++){
        current_actl = actlRainfall[i];
        current_avg = avgRainfall[i];
        actlRainfall[i] = scale(current_actl);
        avgRainfall[i] = scale(current_avg);
    }
    return;
}
int scale(double number){
    return static_cast<int>(floor(round(number/100.0)+0.5));
}
void showGraph(double actlRainfall[], double avgRainfall[], string month[]){
    for(int i = 0; i<MONTHS; i++){
        cout << endl;
        cout << setw(20) << "Average"  << setw(10);
        stars(avgRainfall[i]);
        cout << endl;
        cout << month[i] << endl;
        cout << setw(20) << "Actual" << setw(10);
        stars(actlRainfall[i]);
        cout << endl;
        cout << endl;
    }
    return;
}
void stars(int number){
    for(int i = 1; i<=number; i++){
        cout << "* ";
    }
    return;
}

