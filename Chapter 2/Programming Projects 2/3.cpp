/* Suppose you can buy a chocolate bar from the vending machine for $1 each. Inside
every chocolate bar is a coupon. You can redeem seven coupons for one chocolate
bar from the machine. You would like to know how many chocolate bars you can
eat, including those redeemed via coupon, if you have n dollars.
 For example, if you have 20 dollars then you can initially buy 20 chocolate bars.
This gives you 20 coupons. You can redeem 14 coupons for two additional chocolate
bars. These two additional chocolate bars give you two more coupons, so you
now have a total of eight coupons. This gives you enough to redeem for one final
chocolate bar. As a result you now have 23 chocolate bars and two leftover coupons. */
#include <iostream>
using namespace std;
int main(){
    int dollars;
    cout << "Enter the number of dollars: ";
    cin >> dollars;
    int chocolates = dollars;
    int coupons = dollars;
    while(coupons >= 7){
        int extra_chocolates = coupons/7;
        chocolates = chocolates + extra_chocolates;
        int extra_coupons = coupons % 7;
        coupons = (coupons/7) + extra_coupons;
    }
    cout << "\nYou can have: " << chocolates << " chocolates.";
    cout << "\nThe number of coupons is: " << coupons;
    return 0;
}
