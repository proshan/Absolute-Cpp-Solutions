#include <iostream>
using namespace std;
int main(){
    /*Suppose savings and expenses are variables of type double that have been given values.
Write an if-else statement that outputs the word Solvent, decreases the value of savings
by the value of expenses, and sets the value of expenses to zero provided that
savings is at least as large as expenses. If, however, savings is less than expenses, the
if-else statement simply outputs the word Bankrupt and does not change the value of
any variables
    */
    double savings, expenses;
    savings = 1000;
    expenses = 1500;
    if (savings >= expenses){
        cout << "Solovent";
        savings = savings-expenses;
        expenses = 0;
    }
    else{
        cout << "\nBankrupt";
    }
    cout << endl;
    return 0;
}
