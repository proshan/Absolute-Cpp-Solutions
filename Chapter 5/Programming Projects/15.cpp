/*Traditional password entry schemes are susceptible to “shoulder surfing” in which
an attacker watches an unsuspecting user enter their password or PIN number and
uses it later to gain access to the account. One way to combat this problem is with
a randomized challenge-response system. In these systems, the user enters different
 information every time based on a secret in response to a randomly generated
 challenge. Consider the following scheme in which the password consists of a five-digit
PIN number (00000 to 99999). Each digit is assigned a random number that is
1, 2, or 3. The user enters the random numbers that correspond to their PIN
 instead of their actual PIN numbers.
 For example, consider an actual PIN number of 12345. To authenticate, the user
would be presented with a screen such as
 PIN: 0 1 2 3 4 5 6 7 8 9
 NUM: 3 2 3 1 1 3 2 2 1 3
 The user would enter 23113 instead of 12345. This does not divulge the password
even if an attacker intercepts the entry because 23113 could correspond to other
PIN numbers, such as 69440 or 70439. The next time the user logs in, a different
sequence of random numbers would be generated, such as
 PIN: 0 1 2 3 4 5 6 7 8 9
 NUM: 1 1 2 3 1 2 2 3 3 3
 Your program should simulate the authentication process. Store an actual PIN
number in your program. The program should use an array to assign random
numbers to the digits from 0 to 9. Output the random digits to the screen, input
the response from the user, and output whether or not the user’s response correctly
matches the PIN number. */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
const int NUM_PIN_SIZE = 10;
const int PASSWORD_SIZE = 5;
void setupPin(int pin[]);
void setupNum(int num[]);
void getInput(char userInput[], int pin[], int num[]);
void printPinNum(int pin[], int num[]);
bool checkPassword(int password[], int pin[], int num[], char userInput[]);
int main(){
    srand(time(0));
    int password[PASSWORD_SIZE] = {4, 6, 1, 9, 3};
    int pin[NUM_PIN_SIZE];
    int num[NUM_PIN_SIZE];
    setupPin(pin);
    setupNum(num);
    char userInput[PASSWORD_SIZE];
    getInput(userInput, pin, num);
    if(checkPassword(password, pin, num, userInput) == true){
        cout << "Your password is correct.";
    }
    else{
        cout << "Your password is incorrect.";
    }
    cout << endl;
    return 0;
}
void setupPin(int pin[]){
    for(int i = 0; i<NUM_PIN_SIZE; i++){
        pin[i] = i;
    }
    return;
}
void setupNum(int num[]){
    int randomNumber = 0;
    for(int i = 0; i<NUM_PIN_SIZE; i++){
        randomNumber = rand() % 3 + 1;
        num[i] = randomNumber;
    }
    return;
}
void getInput(char userInput[], int pin[], int num[]){
    printPinNum(pin, num);
    cout << "Enter your password: ";
    cin >> userInput;
    return;
}
void printPinNum(int pin[], int num[]){
    //printing pin
    cout << "PIN: ";
    for(int i = 0; i<NUM_PIN_SIZE; i++){
        cout << "   " << pin[i];
    }
    cout << endl;
    //printing num
    cout << "NUM: ";
    for(int i = 0; i<NUM_PIN_SIZE; i++){
        cout << "   " << num[i];
    }
    cout << endl;
    return;
}
bool checkPassword(int password[], int pin[], int num[], char userInput[]){
    for(int i = 0; i<PASSWORD_SIZE; i++){
        for(int j = 0; j<NUM_PIN_SIZE; j++){
            if(password[i] == pin[j]){
                password[i] = num[j];
                break;
            }
        }
    }
    bool passwordMatches = true;
    for(int i = 0; i<PASSWORD_SIZE; i++){
        if((userInput[i] - 48) != password[i]){
            passwordMatches = false;
            break;
        }
    }
    return passwordMatches;
}
