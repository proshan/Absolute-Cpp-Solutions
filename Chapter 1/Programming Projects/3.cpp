/*Workers at a particular company have won a 7.6% pay increase retroactive for six months.
Write a program that takes an employee’s previous annual salary as input and outputs the
amount of retroactive pay due the employee, the new annual salary, and the new monthly
salary. Use a variable declaration with the modifier const to express the pay increase.*/
#include <iostream>
using namespace std;
int main(){
    const float PAY_INCREASE = (7.6/100);
    cout << "Please enter your previous annual salary: $";
    float salary;
    cin >> salary;
    float retroactive_pay = (salary/12) * (7.6/100) * 6;
    cout << "Your Retroactive pay is : $" << retroactive_pay;
    cout << "\n..................................................\n";
    float new_salary = salary + retroactive_pay;
    cout << "Your new salary is : $" << new_salary;
    cout << "\n......................................................\n";
    cout << "Your current monthly salary is : $" << (new_salary/12);
    cout << endl << endl;
    return 0;
}
