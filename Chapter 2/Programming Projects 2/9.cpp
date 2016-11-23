/*(This is an extension of an exercise from Chapter 1 .) The Babylonian algorithm to
compute the square root of a positive number n is as follows:
 1. Make a guess at the answer (you can pick n/2 as your initial guess).
 2. Compute r = n / guess .
 3. Set guess= (guess + r) / 2.
 4. Go back to step 2 for as many iterations as necessary. The more steps 2 and 3 are
repeated, the closer guess will become to the square root of n.
 Write a program that inputs a double for n, iterates through the Babylonian
algorithm until the guess is within 1% of the previous guess, and outputs the
answer as a double to two decimal places. Your answer should be accurate even for
large values of n. */
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double n = 45369;
    double guess;
    cout << "Enter your guess: ";
    cin >> guess;
    bool result = false;
    double r;
    double current_guess;
    while(result == false){
        r = n/guess;
        current_guess = guess;
        guess = (guess + r)/static_cast<double>(2);
        if((((guess > current_guess) ? guess-current_guess : current_guess) - guess) <= 0.01*current_guess){
            cout << endl << guess;
            result = true;
        }
    }
    return 0;
}
