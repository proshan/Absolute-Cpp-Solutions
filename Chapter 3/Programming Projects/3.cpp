/* Enhance your program from the previous exercise by having it also print out the estimated
price of the item in one and in two years from the time of the calculation. The increase in
cost over one year is estimated as the inflation rate times the price at the start of the year.
Define a second function to determine the estimated cost of an item in a specified number
of years, given the current price of the item and the inflation rate as arguments. */
#include <iostream>
using namespace std;
float rate_of_inflation(float price_before, float price_after);
float estimation(int year, float price_after, float rate);
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
        float rate = rate_of_inflation(price_before, price_after);
        cout << "\nThe rate of inflation is : " << rate << "%";
        cout << "\nAfter 1 year, the estimated price is: " << estimation(1, price_after, rate);
        cout << "\nAfter 2 years, the estimated price is: " << estimation(2, price_after, rate);
        cout << "\nWant to run the program again? ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    cout << "\nThank You!";
    return 0;
}
float rate_of_inflation(float price_before, float price_after){
    return ((price_after - price_before)/price_before)*100;
}
float estimation(int year, float price_after, float rate){
    for (int i=1; i<=year; i++){
        price_after = price_after + (price_after*(rate/100));
    }
    return price_after;
}
