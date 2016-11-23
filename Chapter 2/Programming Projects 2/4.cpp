/*Write a program that finds and prints all of the prime numbers between 3 and 100.
A prime number is a number that can only be divided by one and itself (i.e., 3, 5,
7, 11, 13, 17, …).
 One way to solve this problem is to use a doubly-nested loop. The outer loop can
iterate from 3 to 100, while the inner loop checks to see whether the counter value
for the outer loop is prime. One way to decide whether the number n is prime is
to loop from 2 to n - 1 ; if any of these numbers evenly divides n , then n cannot be
prime. If none of the values from 2 to n - 1 evenly divide n , then n must be prime.
(Note that there are several easy ways to make this algorithm more efficient.) */
#include <iostream>
using namespace std;
int main(){
    for(int i=3; i<=100; i++){
        bool prime = true;
        for(int j=2; j<i; j++){
            if((i % j) == 0){
                prime = false;
                break;
            }
        }
        if(prime == true){
            cout << endl << i;
        }
    }
    return 0;
}
