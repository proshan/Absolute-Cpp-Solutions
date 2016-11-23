#include <iostream>
using namespace std;
int main(){
    /* Write an if-else statement that outputs the word High if the value of the variable score
is greater than 100 and Low if the value of score is at most 100. The variable score is of
type int.
    */
    cout << "Enter the score: ";
    int score;
    cin >> score;
    if (score > 100){
        cout << "\nHigh!";
    }
    else{
        cout << "\nLow!";
    }
    cout << endl;
    return 0;
}
