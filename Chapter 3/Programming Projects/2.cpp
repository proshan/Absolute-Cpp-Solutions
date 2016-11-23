/* Write a program to gauge the rate of inflation for the past year. The program asks for the
price of an item (such as a hot dog or a one-carat diamond) both one year ago and today. It
estimates the inflation rate as the difference in price divided by the year-ago price. Your
program should allow the user to repeat this calculation as often as the user wishes. Define
a function to compute the rate of inflation. The inflation rate should be a value of type
double giving the rate as a percentage, for example 5.3 for 5.3%. */
#include <iostream>
using namespace std;
float rate_of_inflation(float price_before, float price_after);
int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    char ans;
    do{
        cout << "\nEnter the price of an item one year ago: ";
        float price_before, price_after;
        cin >> price_before;
        cout << "\nEnter the price of the item after one year: ";
        cin >> price_after;
        cout << "\nThe rate of inflation is : " << rate_of_inflation(price_before, price_after) << "%" << endl;
        cout << "\nWant to run the program again? ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    cout << "\nThank You!";
    return 0;
}
float rate_of_inflation(float price_before, float price_after){
    return ((price_after - price_before)/price_before)*100;
}

