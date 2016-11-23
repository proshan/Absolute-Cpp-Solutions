/*It is difficult to make a budget that spans several years, because prices are not stable. If your
company needs 200 pencils per year, you cannot simply use this year’s price as the cost of
pencils two years from now. Because of inflation the cost is likely to be higher than it is
today. Write a program to gauge the expected cost of an item in a specified number of
years. The program asks for the cost of the item, the number of years from now that the
item will be purchased, and the rate of inflation. The program then outputs the estimated
cost of the item after the specified period. Have the user enter the inflation rate as a percentage,
such as 5.6 (percent). Your program should then convert the percentage to a fraction,
such as 0.056, and should use a loop to estimate the price adjusted for inflation.
(Hint: Use a loop.)*/
#include <iostream>
using namespace std;
int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    float cost_of_item;
    cout << "Enter the cost of the item: ";
    cin >> cost_of_item;
    int number_of_years;
    cout << "\nEnter the number of years from now that the item will be purchased: ";
    cin >> number_of_years;
    float rate_of_inflation;
    cout << "\nEnter the rate of inflation: ";
    cin >> rate_of_inflation;
    float inflated_rate = cost_of_item;
    for(int i=1; i<=number_of_years; i++){
        inflated_rate = inflated_rate + ((rate_of_inflation/100)*inflated_rate);
    }
    cout << "\nInflated rate of an item is: " << inflated_rate << endl;
    return 0;
}
