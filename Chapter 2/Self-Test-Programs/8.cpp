#include <iostream>
using namespace std;
int main(){
    /*Write an if-else statement that outputs the word Passed provided the value of the variable
exam is greater than or equal to 60 and also the value of the variable programsDone is
greater than or equal to 10. Otherwise, the if-else statement outputs the word Failed.
The variables exam and programsDone are both of type int.
    */
    int exam, programsDone;
    if((exam >= 60) && (programsDone >= 10)){
        cout << "Passed!";
    }
    else{
        cout << "\nFailed!";
    }
    cout << endl;
    return 0;
}
