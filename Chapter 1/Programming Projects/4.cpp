/*Negotiating a consumer loan is not always straightforward. One form of loan is the discount
installment loan, which works as follows. Suppose a loan has a face value of $1,000,
the interest rate is 15%, and the duration is 18 months. The interest is computed by multiplying
the face value of $1,000 by 0.15, yielding $150. That figure is then multiplied by
the loan period of 1.5 years to yield $225 as the total interest owed. That amount is immediately
deducted from the face value, leaving the consumer with only $775. Repayment is
made in equal monthly installments based on the face value. So the monthly loan payment
will be $1,000 divided by 18, which is $55.56. This method of calculation may not be too
bad if the consumer needs $775 dollars, but the calculation is a bit more complicated if the
consumer needs $1,000. Write a program that will take three inputs: the amount the consumer
needs to receive, the interest rate, and the duration of the loan in months. The program
should then calculate the face value required in order for the consumer to receive the
amount needed. It should also calculate the monthly payment.*/
#include <iostream>
using namespace std;
int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Enter the amount you want to receive: $";
    float want_to_receive;
    cin >> want_to_receive;
    cout << "\nEnter the rate of interest: ";
    float interest_rate;
    cin >> interest_rate;
    cout << "\nEnter the duration of loan in months: ";
    float duration;
    cin >> duration;
    duration = duration/12;
    float face_value = (want_to_receive*100)/(100-duration*interest_rate);
    cout << "\nThe face value required in order to receive $" << want_to_receive << " is: $" << face_value;
    cout << endl;
    cout << "The monthly loan payment is: $" << face_value/(duration/12);
    cout << endl;
    return 0;
}
