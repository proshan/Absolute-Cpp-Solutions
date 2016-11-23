/*In the game of craps, a “Pass Line” bet proceeds as follows. The first roll of the two,
six-sided dice in a craps round is called the “come out roll.” The bet immediately
wins when the come out roll is 7 or 11, and loses when the come out roll is 2, 3,
or 12. If 4, 5, 6, 8, 9, or 10 is rolled on the come out roll, that number becomes
“the point.” The player keeps rolling the dice until either 7 or the point is rolled.
If the point is rolled first, then the player wins the bet. If the player rolls a 7 first,
then the player loses.
 Write a program that plays craps using those rules so that it simulates a game without
human input. Instead of asking for a wager, the program should calculate whether
the player would win or lose. Create a function that simulates rolling the two dice
and returns the sum. Add a loop so that the program plays 10,000 games. Add
counters that count how many times the player wins, and how many times the
player loses. At the end of the 10,000 games, compute the probability of winning,
as Wins / (Wins + Losses), and output this value. Over the long run, who is going
to win more games of craps, you or the house? */
//Game of craps
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int sum_of_rolled();
string check(int sum);
int main(){
    srand(time(0));
    //including 'srand(time(0)) in other function except main() function
    //didn't return perfectly random number
    int roll = 0;
    int won = 0;
    int lost = 0;
    for(int i = 1; i<=10000; i++){
        roll = sum_of_rolled();
        string result = check(roll);
        if(result == "won"){
            won++;
        }
        else if(result == "lost"){
            lost++;
        }
        else if(result == "point"){
            int point = roll;
            while(true){
                roll = sum_of_rolled();
                if(roll == point){
                    won++;
                    break;
                }
                else if(roll == 7){
                    lost++;
                    break;;
                }
            }
        }
    }
    cout << "The probability of winning is: " << won << "/" << (won+lost)
     << " i.e. " << won/static_cast<double>(won+lost);
    cout << endl;
    return 0;
}
int sum_of_rolled(){
    //returns the sum of two rolled dice.
    int roll = rand() % 12 + 2;
    return roll;
}
string check(int sum){
    string result = "";
    if(sum == 7 || sum == 11){
        result = "won";
    }
    else if(sum == 2 || sum == 3 || sum == 12){
        result = "lost";
    }
    else{
        result = "point";
    }
    return result;
}
