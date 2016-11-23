/*The Babylonian algorithm to compute the square root of a positive number n is as
follows:
 1. Make a guess at the answer (you can pick n/2 as your initial guess).
 2. Compute r = n / guess .
 3. Set guess = (guess + r) / 2 .
 4. Go back to step 2 for as many iterations as necessary. The more steps 2 and 3
are repeated, the closer guess will become to the square root of n .
 Write a program that inputs a double for n , iterates through the Babylonian algorithm
five times, and outputs the answer as a double to two decimal places. Your
answer will be most accurate for small values of n .  */
#include <iostream>
using namespace std;
int main(){
    double n = 36;
    double guess;
    cout << "Enter guess: ";
    cin >> guess;
    for(int i = 1; i <= 5; i++){
       double r = n/guess;
        guess = (guess+r)/2;
    }
    cout << "\nThe guess is: " << guess;
    return 0;
}
