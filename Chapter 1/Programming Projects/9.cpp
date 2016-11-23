/*The video game machines at your local arcade output coupons depending on how
well you play the game. You can redeem 10 coupons for a candy bar or 3 coupons
for a gumball. You prefer candy bars to gumballs. Write a program that inputs the
number of coupons you win and outputs how many candy bars and gumballs you
can get if you spend all of your coupons on candy bars first and any remaining
coupons on gumballs. */
#include <iostream>
using namespace std;
int main(){
    int coupons;
    cout << "Enter how many coupons you have: ";
    cin >> coupons;
    cout << endl << "Candy bars: " << coupons/10;
    int remaining = coupons % 10;
    cout << endl << "Gum Balls: " << remaining / 3;
    cout << endl << "Remaining coupons: " << remaining % 3;
    return 0;
}
