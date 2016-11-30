/*Cumulatively modify the example from Display 8.7 as follows.
 a. In Display 8.7 , replace the private char members first and second with an
array of char of size 100 and a private data member named size .
 Provide a default constructor that initializes size to 10 and sets the first 10 of the
char positions to '#'. (This only uses 10 of the possible 100 slots.)
 Provide an accessor function that returns the value of the private member size .
 Test.
 b. Add an operator[] member that returns a char& that allows the user to access
or to set any member of the private data array using a non-negative index that
is less than size .
 Test.
 c. Add a constructor that takes an int argument, sz , that sets the first sz members
of the char array to '#' .
 Test.
 d. Add a constructor that takes an int argument, sz , and an array of char of size
sz . The constructor should set the first sz members of the private data array to
the sz members of the argument array of char .
 Test.
 NOTES: When you test, you should test with known good values, with data on
boundaries and with deliberately bad values. You are not required to put checks
for index out of bounds errors in your code, but that would be a nice touch. Error
handling alternatives: Issue an error message then die (that is, call exit(1) ) or give
the user another chance to make a correct entry. */
#include <iostream>
#include <cstdlib> //for exit()
using namespace std;
//setting the maximum size of the array
const int MAX_SIZE = 100;

class CharPair{
public:
    //constructor
    CharPair();
    CharPair(int sz);
    CharPair(int sz, char parameter_arr[]);

    //accessor function to return the size of Array
    int getSizeOfArray() const;

    //[] operator overloading
    char& operator [](const int index);
private:
    char arr[MAX_SIZE];
    int sizeOfArray;
};
//setting the value of first 10 of the char positions
//to "#"
CharPair::CharPair(){
    sizeOfArray = 10;
    for(int i = 0; i<sizeOfArray; i++){
        arr[i] = '#';
    }
}
CharPair::CharPair(int sz){
    if(sz > MAX_SIZE){
        cout << "Size exceeded than maximum limit.";
        exit(1);
    }
    for(int i = 0; i<sz; i++){
        arr[i] = '#';
    }
}
//copies the value of the array from parameter to the
//private class array member
CharPair::CharPair(int sz, char parameter_array[]){
    if(sz > MAX_SIZE){
        cout << "Size exceeded maximum limit.";
        exit(1);
    }
    for(int i = 0; i<sz; i++){
        arr[i] = parameter_array[i];
    }
}

//returns the size of array
int CharPair::getSizeOfArray() const{
    return sizeOfArray;
}
char& CharPair::operator [](int index){
    if(index >= 100){
        //exiting program with an error message
        cout << "Not a valid array index.";
        exit(1);
    }
    else{
        return arr[index];
    }
}

int main(){
    CharPair cp;
    cout << cp[9];
    cout << endl;
    cp[15] = 'b';
    cout << cp[15];
    cout << endl;
    char myCharArray[3] = {'a', 'b', 'c'};
    CharPair chp(3, myCharArray);
    cout << chp[2];
    cout << endl;
    return 0;
}
