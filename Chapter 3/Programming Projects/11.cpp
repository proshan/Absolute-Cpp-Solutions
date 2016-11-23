/*The game of Pig is a simple two player dice game in which the first player to
reach 100 or more points wins. Players take turns. On each turn a player rolls a
six-sided die:
 • If the player rolls a 2–6 then he or she can either
 — ROLL AGAIN or
 — HOLD. At this point the sum of all rolls made this turn is added to the
player’s total score and it becomes the other player’s turn.
 • If the player rolls a 1 then the player loses his or her turn. The player gets no
new points and it becomes the opponent’s turn.
 If a player reaches 100 or more points after holding then the player wins.
 Write a program that plays the game of Pig, where one player is a human and the
other is the computer. Allow the human to input “r” to roll again or “h” to hold.
 The computer program should play according to the following rule: Keep rolling
on the computer’s turn until it has accumulated 20 or more points, then hold. Of
course, if the computer wins or rolls a 1 then the turn ends immediately. Allow the
human to roll first.
 Write your program using at least two functions:
 int humanTurn( int humanTotalScore);
 int computerTurn( int computerTotalScore);
 These functions should perform the necessary logic to handle a single turn for
either the computer or the human. The input parameter is the total score for the
human or computer. The functions should return the turn total to be added to the
total score upon completion of the turn. For example, if the human rolls a 3 and
6 and then holds, then humanTurn should return 9. However, if the human rolls a
3 and 6 and then a 1, then the function should return 0. */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int humanTurn(int humanTotalScore);
int main(){
    int total_human_score = 0;
    int total_computer_score = 0;
    while(total_human_score < 101 || total_computer_score < 101){
        total_human_score = total_human_score + humanTurn(total_human_score);
        total_computer_score = total_computer_score + computerTurn(total_computer_score);
    }
    cout << "The winner is: " << (total_computer_score > total_human_score ? "Computer" : "Human");
    return 0;
}
int humanTurn(int humanTotalScore){
    int total = 0;
    char ans;
    srand(time(0));
    do{
        cout << "Roll Next?";
        cin >> ans;

        if(ans == 'h'){
            cout << "\nYour total score in this set is: " << total << endl;
            cout << "\nComputer's turn now." << endl;
            break;
        }

        int number = rand() % 6 + 1;
        cout << "Player rolled a " << number << endl;
        if(number == 1){
            break;
        }
        else{
            total = total + number;
        }
    }while(ans == 'r' || ans == 'R');
    return total;
}
int computerTurn(int computerTotalScore){
    int total = 0;
    srand(time(0));
    while(total < 20){
        int number = rand() % 6 + 1;
        cout << "Computer rolled " << number << endl;
        if(number == 1){
            break;
        }
        else{
            total = total + number;
        }
    }
    cout << "Computer scored " << total << " in this set.";
    cout << "\nYour turn now.";
    return total;
}
