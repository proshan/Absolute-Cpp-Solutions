/*You have four identical prizes to give away and a pool of 25 finalists. The finalists
are assigned numbers from 1 to 25. Write a program to randomly select the
numbers of 4 finalists to receive a prize. Make sure not to pick the same number
twice. For example, picking finalists 3, 15, 22, and 14 would be valid but picking
3, 3, 31, and 17 would be invalid, because finalist number 3 is listed twice and 31
is not a valid finalist number. */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void check_number(int &num1, int &num2, int &num3, int &num4);
int main(){
    srand(time(0));
    int num1, num2, num3, num4;
    num1 = rand() % 25 + 1;
    num2 = rand() % 25 + 1;
    num3 = rand() % 25 + 1;
    num4 = rand() % 25 + 1;
    check_number(num1, num2, num3, num4);
    cout << "The prize getting numbers are: " << num1 << ", " << num2 << ", " << num3 << " and " << num4 << ".";
    cout << endl;
    return 0;
}
void check_number(int &num1, int &num2, int &num3, int &num4){
    bool random = false;
    while(random == false){
        if(num1 != num2 && num1 != num3 && num1 != num4 && num2 != num3 && num2 != num4 && num3 != num4){
            random = true;
        }
        else{
            num1 = rand() % 25 + 1;
            num2 = rand() % 25 + 1;
            num3 = rand() % 25 + 1;
            num4 = rand() % 25 + 1;
        }
    }
}

