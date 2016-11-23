/* Scientists estimate that consuming roughly 10 grams of caffeine at once is a lethal overdose. Write a program
that inputs the number of milligrams of caffeine in a drink and outputs how many of those drinks it would take to
kill a person. A 12-ounce can of cola has approximately 34 mg of caffeine, while a 16-ounce cup of coffee has
approximately 160 mg of caffeine. */
#include <iostream>
using namespace std;
int main(){
    double milligrams;
    cout << "Enter the number of milligrams of caffeine in a drink: ";
    cin >> milligrams;
    int number_of_drinks = 10/(milligrams/1000);
    cout << "\nThe number of drinks to kill a person is: " << number_of_drinks;
    return 0;
}
