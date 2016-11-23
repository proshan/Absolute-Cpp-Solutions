/* An employee is paid at a rate of $16.78 per hour for regular hours worked in a week. Any
hours over that are paid at the overtime rate of one and one-half times that. From the
worker’s gross pay, 6% is withheld for Social Security tax, 14% is withheld for federal income tax, 5% is withheld for state income tax, and $10 per week is withheld for union
dues. If the worker has three or more dependents, then an additional $35 is withheld to
cover the extra cost of health insurance beyond what the employer pays. Write a program
that will read in the number of hours worked in a week and the number of dependents as
input and that will then output the worker’s gross pay, each withholding amount, and the
net take-home pay for the week.*/
#include <iostream>
using namespace std;
int main(){
    //Taking regular hours as 7 hours
    float worked_hours;
    int dependents;
    cout << "Enter your number of working hours: ";
    cin >> worked_hours;
    cout << "\nEnter the number of dependents: ";
    cin >> dependents;

    const float regular_hours = 48;
    float extra_hours = worked_hours - regular_hours;
    float total_income = 0;
    if(worked_hours > regular_hours){
        total_income = (regular_hours*16.78) + (extra_hours * 1.5*16.78);
    }
    else{
        total_income = worked_hours * 16.78;
    }
    cout << "\nYour gross income in a week is : $" << total_income;
    float social_security_tax = (static_cast<float>(6)/100) * total_income;
    float federal_income_tax = (static_cast<float>(14)/100) * total_income;
    float state_income_tax = (static_cast<float>(5)/100) * total_income;
    const int UNION_DUES = 10;
    float withholding_amount = 0;
    if(dependents > 3){
        const int EXTRA_HEALTH_FEES = 35;
        withholding_amount = social_security_tax + federal_income_tax + state_income_tax + UNION_DUES + EXTRA_HEALTH_FEES;
    }
    else{
        withholding_amount = social_security_tax + federal_income_tax + state_income_tax + UNION_DUES;
    }
    cout << "\nYour withholding amount is: $" << withholding_amount;
    cout << "\nYour take-home pay for the week is: $" << total_income - withholding_amount;
    cout << endl;
    return 0;
}
