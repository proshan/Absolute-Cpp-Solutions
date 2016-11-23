/*In cryptarithmetic puzzles, mathematical equations are written using letters. Each
letter can be a digit from 0 to 9, but no two letters can be the same. Here is a
sample problem:
 SEND + MORE = MONEY
 A solution to the puzzle is S = 9, R = 8, O = 0, M = 1, Y = 2, E = 5, N = 6, D = 7
 Write a program that fi nds solutions to the following cryptarithmetic puzzle:
 TOO + TOO + TOO + TOO = GOOD
 The simplest technique is to use a nested loop for each unique letter (in this case T,
O, G, D). The loops would systematically assign the digits from 0–9 to each letter.
For example, it might first try T = 0, O = 0, G = 0, D = 0, then T = 0, O = 0, G =0,
D = 1, then T = 0, O = 0, G = 0, D = 2, etc. up to T = 9, O = 9, G = 9, D = 9.
In the loop body, test that each variable is unique and that the equation is satisfied.
Output the values for the letters that satisfy the equation. */
#include <iostream>
using namespace std;
int main(){
    int T, O, G, D;
    for(int T = 0; T<=9; T++){
        for(int O =0; O<=9; O++){
            for(int G=0; G<=9; G++){
                for(int D=0; D<=9; D++){
                    if(T == O || T == G || T == D || O == G || O == D || G == D){
                        continue;
                    }
                    else if(400* T + 40 * O + 4 * O == 1000 * G + 100 * O + 10 * O + D){
                        cout << endl << "T: " << T;
                        cout << endl << "O: " << O;
                        cout << endl << "G: " << G;
                        cout << endl << "D: " << D;
                        cout << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
//Hint From: http://www.rpgcodex.net/forums/index.php?threads/cryptarithmetic-puzzle-and-c.75483/

