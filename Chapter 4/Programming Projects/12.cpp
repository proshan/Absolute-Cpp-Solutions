/*In the land of Puzzlevania, Aaron, Bob, and Charlie had an argument over which
one of them was the greatest puzzle-solver of all time. To end the argument once
and for all, they agreed on a duel to the death. Aaron was a poor shot and only hit
his target with a probability of 1/3. Bob was a bit better and hit his target with a
probability of 1/2. Charlie was an expert marksman and never missed. A hit means
a kill and the person hit drops out of the duel.
 To compensate for the inequities in their marksmanship skills, the three decided
that they would fire in turns, starting with Aaron, followed by Bob, and then by
Charlie. The cycle would repeat until there was one man standing. That man
would be remembered for all time as the Greatest Puzzle-Solver of All Time.
 An obvious and reasonable strategy is for each man to shoot at the most accurate
shooter still alive, on the grounds that this shooter is the deadliest and has the best
chance of hitting back.
 Write a program to simulate the duel using this strategy. Your program should use
random numbers and the probabilities given in the problem to determine whether
a shooter hits his target. You will likely want to create multiple subroutines and
functions to complete the problem. Once you can simulate a duel, add a loop to
your program that simulates 10,000 duels. Count the number of times that each
contestant wins and print the probability of winning for each contestant (e.g., for
Aaron your program might output “Aaron won 3595/10,000 duels or 35.95%”).
 An alternate strategy is for Aaron to intentionally miss on his first shot. Modify the
program to accommodate this new strategy and output the probability of winning
for each contestant. What strategy is better for*/
//Hint from: http://stackoverflow.com/questions/14994767/randomly-generated-probability-game-with-loops-and-elimination
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int shot();
void hit(bool &aaron, bool &bob, bool &charlie);
char findWinner(bool aaron, bool bob, bool charlie);
void printWinner(char winner);
void add_score(int &a_score, int &b_score, int &c_score, char winner);
void printScore(int a_score, int b_score, int c_score);
int main(){
    srand(time(0));
    int a_score = 0, b_score = 0, c_score = 0;
    for(int i=1; i<=10000; i++){
        bool aaron = true;
        bool bob = true;
        bool charlie = true;
        cout << endl;
        hit(aaron, bob, charlie);
        char winner = findWinner(aaron, bob, charlie);
        printWinner(winner);
        cout << endl;
        add_score(a_score, b_score, c_score, winner);
    }
    printScore(a_score, b_score, c_score);
    return 0;
}
int shot(){
    return rand() % 100;
}
void hit(bool &aaron, bool &bob, bool &charlie){
    int a, b, c;
    a = shot();
    if(a <= 33){
        charlie = false;
        cout << "Charlie killed." << endl;
        b = shot();
        if(b <=50 ){
            aaron = false;
            cout << "Aaron killed." << endl;
        }
        else if(b > 50){
            while(true){
                a = shot();
                if(a <= 33){
                    bob = false;
                    cout << "Bob killed." << endl;
                    break;
                }
                else if(a > 33){
                    b = shot();
                    if(b <= 50){
                        aaron = false;
                        cout << "Arron killed." << endl;
                        break;
                    }
                }
            }
        }
    }
    else if(a > 33){
        b = shot();
        if(b <= 50 ){
            charlie = false;
            cout << "Charlie killed." << endl;
            a = shot();
            if(a <= 33){
                bob = false;
                cout << "Bob killed." << endl;
            }
            else if(a > 33){
                while(true){
                    b = shot();
                    if(b <= 50){
                        aaron = false;
                        cout << "Aaron killed." << endl;
                        break;
                    }
                    else if(b > 50){
                        a = shot();
                        if(a <= 33){
                            bob = false;
                            cout << "Bob killed." << endl;
                            break;
                        }
                    }
                }
            }
        }
        else if(b > 50){
            bob = false;
            cout << "Bob killed." << endl;
            a = shot();
            if(a <= 33){
                charlie = false;
                cout << "Charlie killed." << endl;
            }
            else if(a > 33){
                aaron = false;
                cout << "Aaron killed." << endl;
            }
        }
    }
}
char findWinner(bool aaron, bool bob, bool charlie){
    char result;
    if(aaron == false && bob == false && charlie == true){
        result = 'c';
    }
    else if(aaron == true && bob == false && charlie == false){
        result = 'a';
    }
    else if(aaron == false && bob == true && charlie == false){
        result = 'b';
    }
    return result;
}
void printWinner(char winner){
    if(winner == 'a'){
        cout << "The winner is Aaron."<< endl;
    }
    else if(winner == 'b'){
        cout << "The winner is Bob." << endl;
    }
    else if(winner == 'c'){
        cout << "The winner is Charlie." << endl;
    }
    return;
}
void add_score(int &a_score, int &b_score, int &c_score, char winner){
    if(winner == 'a'){
        a_score++;
    }
    else if(winner == 'b'){
        b_score++;
    }
    else if(winner == 'c'){
        c_score++;
    }
    return;
}
void printScore(int a_score, int b_score, int c_score){
    cout << "Score of Aaron is: " << a_score << endl;
    cout << "Score of Bob is: " << b_score << endl;
    cout << "Score of Charlie is: " << c_score << endl;
    return;
}
