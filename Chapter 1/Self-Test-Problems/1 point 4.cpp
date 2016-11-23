#include <iostream>
using namespace std;
int main(){
    const double RATE = 3.5;
    int money;
    cout << "Enter the amount of money: ";
    cin >> money;
    cout << "\nReady to get the final amount?\n";
    cout << "Enter 'y' for Yes and 'n' for No\n";
    char user_input;
    cin >> user_input;
    if(user_input == 'y'){
        double result = money + money*(RATE/100);
        cout << "Your final money after adding the rate is : " << result;
    }
    else{
        cout << "Sorry, you pressed No";
    }
    return 0;
}
