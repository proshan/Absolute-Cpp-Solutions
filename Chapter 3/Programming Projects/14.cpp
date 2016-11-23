/*Programming Project 2.9 asked you to implement the Babylonian Algorithm to
compute the square root of a number.
 Put this algorithm into a function and test it by using it to calculate the square root
of several numbers. The function should return the square root as a double and
also process the number n as a double . */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
double square_root(double n);
int main(){
    double n;
    cout << "Enter a number to find the square root: ";
    cin >> n;
    cout << "\nThe square root of " << n << " is: " << square_root(n);
    return 0;
}
double square_root(double n){
    double answer = 0;
    srand(time(0));
    double guess = rand() % static_cast<int>(n) + 1;
    double r;
    bool result = false;
    double current_guess;
    while(result == false){
        current_guess = guess;
        r = n/guess;
        guess = (guess+r)/static_cast<double>(2);
        if((((guess > current_guess) ? guess-current_guess : current_guess) - guess) <= 0.01*current_guess){
            answer = guess;
            result = true;
        }
    }
    return answer;
}



