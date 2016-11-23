/*
Write a program that will allow two users to play tic-tac-toe. The program should
ask for moves alternately from player X and player O. The program displays the
game positions as follows:
1 2 3
 4 5 6
 7 8 9
 The players enter their moves by entering the position number they wish to mark.
After each move, the program displays the changed board. A sample board configuration
is as follows:
X X O
 4 5 6
 O 8 9
 */
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 3;
void printResult(int arr[][MAX]);
void makeMove(int arr[][MAX], int player);
bool checkHorizontal(int arr[][MAX], int player);
bool checkVertical(int arr[][MAX], int player);
bool checkDiagonal(int arr[][MAX], int player);
bool checkIsSame(int value, int player);
int main(){
    int ttt[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printResult(ttt);
    while(true){
        makeMove(ttt, 88);
        printResult(ttt);
        if(checkHorizontal(ttt, 88) == true || checkVertical(ttt, 88) == true || checkDiagonal(ttt, 88) == true){
            cout << endl << "Player X won!";
            break;
        }
        makeMove(ttt, 0);
        printResult(ttt);
        if(checkHorizontal(ttt, 0) == true || checkVertical(ttt, 0) == true || checkDiagonal(ttt, 88) == true){
            cout << endl << "Player 0 won!";
            break;
        }
    }
    cout << endl;
    return 0;
}
void printResult(int arr[][MAX]){
    for(int i = 0; i<MAX; i++){
        cout << setw(2) << "|";
        for(int j = 0; j<MAX; j++){
            cout << setw(4);
            if(arr[i][j] == 88){
                cout << "X" << setw(4) << "|";
            }
            else{
                cout << arr[i][j] << setw(4) << "|";
            }
            cout<< setw(4);
        }
        cout << endl;
        cout << " -------------------------"<< endl;
    }
    return;
}
void makeMove(int arr[][MAX], int player){
    int userChoice = 0;
    cout << "Player ";
    if(player == 88){
        cout << 'X';
    }
    else if(player == 0){
        cout << 0;
    }
    cout << "'s turn: ";
    cin >> userChoice;
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            if(arr[i][j] == userChoice){
                arr[i][j] = player;
                break;
            }
        }
    }
    return;
}
bool checkHorizontal(int arr[][MAX], int player){
    bool result = false;
    bool h1 = true;
    bool h2 = true;
    bool h3 = true;
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            if(i == 0){
                if(checkIsSame(arr[i][j], player) == false){
                    h1 = false;
                    break;
                }
            }
            else if(i == 1){
                if(checkIsSame(arr[i][j], player) == false){
                    h2 = false;
                    break;
                }
            }
            else if(i == 2){
                if(checkIsSame(arr[i][j], player) == false){
                    h3 = false;
                    break;
                }
            }
        }
    }
    if(h1 == true || h2 == true || h3 == true){
        result = true;
    }
    return result;
}
bool checkVertical(int arr[][MAX], int player){
    bool result = false;
    bool v1 = true;
    bool v2 = true;
    bool v3 = true;
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            if(i == 0){
                if(checkIsSame(arr[j][i], player) == false){
                    v1 = false;
                    break;
                }
            }
            else if(i == 1){
                if(checkIsSame(arr[j][i], player) == false){
                    v2 = false;
                    break;
                }
            }
            else if(i == 2){
                if(checkIsSame(arr[j][i], player) == false){
                    v3 = false;
                    break;
                }
            }
        }
    }
    if(v1 == true || v2 == true || v3 == true){
            result = true;
    }
    return result;
}
bool checkDiagonal(int arr[][MAX], int player){
    bool result = false;
    bool d1 = true;
    bool d2 = true;
    for(int i =0; i<MAX; i++){
        if(checkIsSame(arr[i][i], player) == false){
            d1 = false;
            break;
        }
    }
    int counter = 2;
    for(int i = 0; i<MAX; i++){
        if(checkIsSame(arr[i][counter], player) == false){
            d2 = false;
            break;
        }
        counter--;
    }
    if(d1 == true || d2 == true){
        result = true;
    }
    return result;
}
bool checkIsSame(int value, int player){
    bool result = false;
    if(value == player){
        result = true;
    }
    return result;
}

