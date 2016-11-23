/*A common memory matching game played by young children is to start with a
deck of cards that contains identical pairs. For example, given six cards in the deck,
two might be labeled “1”, two might be labeled “2”, and two might be labeled “3”.
The cards are shuffled and placed facedown on the table. The player then selects
two cards that are facedown, turns them faceup, and if they match they are left
faceup. If the two cards do not match, they are returned to their original position
facedown. The game continues in this fashion until all cards are faceup.
 Write a program that plays the memory matching game. Use 16 cards that are
laid out in a 4 * 4 square and are labeled with pairs of numbers from 1 to 8. Your
program should allow the player to specify the cards through a coordinate system.
 For example, in the following layout
   1 2 3 4

1  8 * * *
2  * * * *
3  * 8 * *
4  * * * *
 all of the cards are facedown except for the pair of 8’s, which has been located at
coordinates (1,1) and (2,3). To hide the cards that have been temporarily placed
faceup, output a large number of newlines that force the old board off the screen.
 Hint: Use a 2D array for the arrangement of cards and another 2D array that indicates
whether a card is faceup or facedown. Write a function that “shuffles” the cards in the
array by repeatedly selecting two cards at random and swapping them. */
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;
const int MAX = 4;
void assignValues(int numbers[][MAX]);
void printValues(int numbers[][MAX]);
void shuffle(int numbers[][MAX]);
void swapValues(int &a, int &b);
int main(){
    srand(time(0));
    int numbers[MAX][MAX];
    assignValues(numbers);
    printValues(numbers);
    cout << endl;
    return 0;
}
void assignValues(int numbers[][MAX]){
    int numberToPut = 1;
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j=j+2){
            numbers[i][j] = numberToPut;
            numbers[i][j+1] = numberToPut;
            numberToPut++;
        }
    }
    return;
}
void printValues(int numbers[][MAX]){
    cout << setw(4) << "|" << setw(2);
    for(int i = 1; i<=4; i++){
        cout << i  << setw(6);
    }
    cout << endl << "------------------------------" << endl;
    for(int i = 0; i<MAX; i++){
        cout << setw(2) << i+1 << setw(2) << "|" << setw(2);
        for(int j = 0; j<MAX; j++){
            cout << numbers[i][j] << setw(6);
        }
        cout << endl;
    }
    return;
}
void shuffle(int numbers[][MAX]){
    int r;
    int c;
    //defined rows and columns for first number
    for(int i = 0; i<8; i++){
        for(int j = 0; j<MAX; j++){
            for(int k = 0; k<MAX; k++){
                if(numbers[j][k] == i){
                    r = j;
                    k = k;
                    break;
                }
            }
        }

    }
}
void swapValues(int &a, int &b){
    int temp = a;
    a = b;
    b = a;
    return;
}
