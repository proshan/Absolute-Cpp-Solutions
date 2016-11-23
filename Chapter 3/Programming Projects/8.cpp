/*Write a program that outputs all 99 stanzas of the “Ninety-Nine Bottles of Beer
on the Wall” song. Your program should print the number of bottles in English,
not as a number:
 Ninety-nine bottles of beer on the wall,
 Ninety-nine bottles of beer,
 Take one down, pass it around,
 Ninety-eight bottles of beer on the wall.
 …
 One bottle of beer on the wall,
 One bottle of beer,
 Take one down, pass it around,
 Zero bottles of beer on the wall.
 Your program should not use ninety-nine different output statements! */
#include <iostream>
#include <string>
using namespace std;
string single_digit(int number);
string exceptions(int number);
string tens(int number);
string number_word(int number);
string capital(string word);
int main(){
    for(int i=99; i>0; i--){
        cout << capital(number_word(i)) << " bottles of beer on the wall,";
        cout << endl;
        cout << capital(number_word(i)) << " bottles of beer,";
        cout << endl;
        cout << "Take one down, pass it around,";
        cout << endl;
        cout << capital(number_word(i-1)) << " bottles of beer on the wall.";
        cout << endl;
        cout << "-----------------------";
        cout << endl;
    }
    return 0;
}
string single_digit(int number){
    string value;
    switch(number){
    case 0:
        value = "zero";
    break;
    case 1:
        value = "one";
    break;
    case 2:
        value = "two";
    break;
    case 3:
        value = "three";
    break;
    case 4:
        value = "four";
    break;
    case 5:
        value = "five";
    break;
    case 6:
        value = "six";
    break;
    case 7:
        value = "seven";
    break;
    case 8:
        value = "eight";
    break;
    case 9:
        value = "nine";
    break;
    default:
        value = "unknown";
    }
    return value;
}
string tens(int number){
    string value;
    switch(number){
    case 1:
        value = "ten";
    break;
    case 2:
        value = "twenty";
    break;
    case 3:
        value = "thirty";
    break;
    case 4:
        value = "forty";
    break;
    case 5:
        value = "fifty";
    break;
    case 6:
        value = "sixty";
    break;
    case 7:
        value = "seventy";
    break;
    case 8:
        value = "eighty";
    break;
    case 9:
        value = "ninety";
    break;
    default:
        value = "unknown";
    }
    return value;
}
string exceptions(int number){
    string value;
    switch(number){
    case 11:
        value = "eleven";
    break;
    case 12:
        value = "twelve";
    break;
    case 13:
        value = "thirteen";
    break;
    case 14:
        value = "fourteen";
    break;
    case 15:
        value = "fifteen";
    break;
    case 16:
        value = "sixteen";
    break;
    case 17:
        value = "seventeen";
    break;
    case 18:
        value = "eighteen";
    break;
    case 19:
        value = "nineteen";
    break;
    default:
        value = "unknown";
    }
    return value;
}
string number_word(int number){
    string result;
    //Checking whether the number has only one digit
    if(number/10 == 0){
        result = single_digit(number);
    }
    //if the number has two digits,
    else{
        int first_number = number/10;
        int second_number = number%10;
        //checking if the number is like 10, 20, 30, 40
        if(number % 10 == 0){
            result = tens(first_number);
        }
        //if the number is eleven, twelve, ....., nineteen
        else if(number > 10 && number < 20){
            result = exceptions(number);
        }
        else{
            result = tens(first_number) + "-" + single_digit(second_number);
        }
    }
    return result;
}
string capital(string word){
    int ascii_value = static_cast<int>(word[0]);
    word[0] = static_cast<char>(ascii_value-32);
    return word;
}

