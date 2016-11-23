/*Write a program to assign passengers seats in an airplane. Assume a small airplane
with seat numbering as follows:
 1 A B C D
 2 A B C D
 3 A B C D
 4 A B C D
 5 A B C D
 6 A B C D
 7 A B C D
 The program should display the seat pattern, with an 'X' marking the seats already
assigned. For example, after seats 1A, 2B, and 4C are taken, the display should look
like this:
 1 X B C D
 2 A X C D
 3 A B C D
 4 A B X D
 5 A B C D
 6 A B C D
 7 A B C D
 After displaying the seats available, the program prompts for the seat desired, the
user types in a seat, and then the display of available seats is updated. This continues
until all seats are filled or until the user signals that the program should end.
If the user types in a seat that is already assigned, the program should say that that
seat is occupied and ask for another choice. */
#include <iostream>
#include <iomanip>
using namespace std;
const int ROW = 7;
const int COLUMN = 4;
void firstAssign(char arr[][COLUMN], char values[]);
void printResult(char arr[][COLUMN]);
void bookSeats(char arr[][COLUMN]);
int main(){
    char values[4] = {'A', 'B', 'C', 'D'};
    char seats[ROW][COLUMN];
    firstAssign(seats, values);
    printResult(seats);
    bookSeats(seats);
    cout << endl;
    return 0;
}
void firstAssign(char arr[][COLUMN], char values[]){
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUMN; j++){
            arr[i][j] = values[j];
        }
    }
    return;
}
void bookSeats(char arr[][COLUMN]){
    char ans;
    string seat;
    do{
        cout << "Which seat you want to book? ";
        cin >> seat;
        cout << endl;
        int seatRow = seat[0] - 48;
        char seatColumn = seat[1];
        for(int i = 0; i<COLUMN; i++){
            if(arr[seatRow-1][i] == seatColumn){
                arr[seatRow-1][i] = 'X';
                break;
            }
        }
        printResult(arr);
        cout << "Want to book next seat?";
        cin >> ans;
    }while(ans == 'Y' || ans == 'y');
    return;
}
void printResult(char arr[][COLUMN]){
    for(int i = 0; i<ROW; i++){
        cout << setw(5) << i+1 << setw(5);
        for(int j = 0; j<COLUMN; j++){
            cout << arr[i][j] << setw(3);
        }
        cout << endl;
    }
    cout << endl;
    return;
}
