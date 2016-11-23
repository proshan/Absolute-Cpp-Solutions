/*Write a program that calculates the total grade for N classroom exercises as a percentage.
The user should input the value for N followed by each of the N scores
and totals. Calculate the overall percentage (sum of the total points earned divided
by the total points possible) and output it as a percentage. Sample input and output
are shown as follows:
 How many exercises to input? 3
 Score received for exercise 1: 10
 Total points possible for exercise 1: 10
 Score received for exercise 2: 7
 Total points possible for exercise 2: 12
 Score received for exercise 3: 5
 Total points possible for exercise 3: 8
 Your total is 22 out of 30, or 73.33%. */
#include <iostream>
using namespace std;
int main(){
    int number_of_exercises;
    cout << "How many exercises to input?";
    cin >> number_of_exercises;
    double obtained = 0;
    double total = 0;
    for(int i=1; i<=number_of_exercises; i++){
        cout << "\nScore received for exercise " << i << " :";
        double score;
        cin >> score;
        obtained += score;
        cout << "\nTotal points possible for exercise " << i << " :";
        double total_points;
        cin >> total_points;
        total += total_points;
    }
    cout << "\nYour total is " << obtained << " out of " << total <<
        ", or " << (static_cast<double>(obtained)/total)*100 << "%";
    cout << endl;
    return 0;
}
