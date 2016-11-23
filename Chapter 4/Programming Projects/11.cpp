/*You are a contestant on a game show and have won a shot at the grand prize.
Before you are three doors. $1,000,000 in cash has randomly been placed behind
one door. Behind the other two doors are the consolation prizes of dishwasher
 detergent. The game show host asks you to select a door, and you randomly pick
one. However, before revealing the prize behind your door, the game show host
reveals one of the other doors that contains a consolation prize. At this point, the
game show host asks if you would like to stick with your original choice or to
switch to the remaining door.
 Write a function to simulate the game show problem. Your function should randomly
select locations for the prizes, select a door at random chosen by the contestant,
and then determine whether the contestant would win or lose by sticking with
the original choice or switching to the remaining door. You may wish to create
 additional functions invoked by this function.
 Next, modify your program so that it simulates playing 10,000 games. Count the
number of times the contestant wins when switching versus staying. If you are
the contestant, what choice should you make to optimize your chances of winning
the cash, or does it not matter? */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
char stick();
int user_choice();
int main(){
    srand(time(0));
    char ans;
    int switch_won = 0;
    int sticking_won = 0;
    int opening_door;
    for(int i=1; i<= 10000; i++){
        int prize_door = rand() % 3 + 1;
        int user_door = user_choice();
        cout << "\nChoose a door number: " << user_door << endl;
        for(int i = 0; i<=3; i++){
            if(i == user_door || i == prize_door){
                continue;
            }
            else{
                opening_door = i;
            }
        }
        cout << "Door " << opening_door << " contains a consolation prize.";
        cout << endl << "Would you like to stick with your original choice or switch? ";
        ans = stick();
        cout << ans << endl;
        if(ans == 'y' || ans == 'Y'){
            if(user_door == prize_door){
                switch_won++;
                cout << "You won $1,000,000.";
            }
            else{
                cout << "You won consolation prize.";
            }
            cout << endl;
        }
        else{
            for(int i = 1; i<=3; i++){
                if(user_door == i || opening_door == i){
                    continue;
                }
                else{
                    user_door = i;
                }
            }
            if(user_door == prize_door){
                sticking_won++;
                cout << "You won $1,000,000.";
            }
            else{
                cout << "You won consolation prize.";
            }
            cout << endl;
        }
    }
    cout << endl;
    cout << "Switching won : " << switch_won << " times.";
    cout << endl << "Sticking won: " << sticking_won << " times.";
    cout << endl;
    return 0;
}
char stick(){
    char ans;
    int number = rand() % 2 + 1;
    if(number == 1){
        ans = 'y';
    }
    else{
        ans = 'n';
    }
    return ans;
}
int user_choice(){
    return (rand()% 3 + 1);
}
