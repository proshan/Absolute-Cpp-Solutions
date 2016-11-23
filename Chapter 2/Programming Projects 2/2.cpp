/*You have just purchased a stereo system that cost $1000 on the following credit plan: no
down payment, an interest rate of 18% per year (and hence 1.5% per month), and
monthly payments of $50. The monthly payment of $50 is used to pay the interest, and
whatever is left is used to pay part of the remaining debt. Hence, the first month you pay
1.5% of $1000 in interest. That is $15 in interest. The remaining $35 is deducted from
your debt, which leaves you with a debt of $965.00. The next month you pay interest of
1.5% of $965.00, which is $14.48. Hence, you can deduct $35.52 (which is $50–$14.48)
from the amount you owe.
Write a program that will tell you how many months it will take you to pay off the loan, as
well as the total amount of interest paid over the life of the loan. Use a loop to calculate the
amount of interest and the size of the debt after each month. (Your final program need not
output the monthly amount of interest paid and remaining debt, but you may want to
write a preliminary version of the program that does output these values.) Use a variable to
count the number of loop iterations and hence the number of months until the debt is
zero. You may want to use other variables as well. The last payment may be less than $50 if
the debt is small, but do not forget the interest. If you owe $50, then your monthly payment
of $50 will not pay off your debt, although it will come close. One month’s interest
on $50 is only 75 cents.*/
#include <iostream>
using namespace std;
int main(){
    double months;
    const double RATE = 1.5;
    double cost;
    double interest;
    double total_interest;
    double to_pay_debt;
    cout << "Enter the cost of the item: ";
    cin >> cost;
    double debt = cost;
    while(debt > 0){
        interest = debt*(RATE/100);
        total_interest = interest+total_interest;
        to_pay_debt = 50-interest;
        debt = debt - to_pay_debt;
        months++;
    }
    cout << "\nMonths: " << months;
    cout << "\nTotal Interest: " << total_interest;
    return 0;
}


