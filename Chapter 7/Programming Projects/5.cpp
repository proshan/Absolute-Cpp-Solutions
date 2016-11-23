/*In an ancient land, the beautiful princess Eve had many suitors. She decided on
the following procedure to determine which suitor she would marry. First, all of
the suitors would be lined up one after the other and assigned numbers. The first
suitor would be number 1, the second number 2, and so on up to the last suitor,
number n. Starting at the first suitor she would then count three suitors down
the line (because of the three letters in her name) and the third suitor would be
eliminated from winning her hand and removed from the line. Eve would then
continue, counting three more suitors, and eliminating every third suitor. When
she reached the end of the line she would continue counting from the beginning.
 For example, if there were six suitors then the elimination process would proceed
as follows:
 123456 initial list of suitors, start counting from 1
 12456 suitor 3 eliminated, continue counting from 4
 1245 suitor 6 eliminated, continue counting from 1
 125 suitor 4 eliminated, continue counting from 5
 15 suitor 2 eliminated, continue counting from 5
 1 suitor 5 eliminated, 1 is the lucky winner
 Write a program that uses a vector to determine which position you should stand
in to marry the princess if there are n suitors. You will find the following function
from the Vector class useful:
v.erase(iter);
// Removes element at position iter
 For example, to use this function to erase the fourth element from the beginning
of a vector variable named theVector , use
theVector.erase(theVector.begin( ) + 3);
 The number 3 is used because the first element in the vector is at index position 0. */
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    int n;
    int counter = 0;
    cout << "Enter the value of n: ";
    cin >> n;
    for(int i = 0; i<n; i++){
        v.push_back(i+1);
        cout << v[i] << " ";
    }
    cout << endl;
    do{
        for(int i = 0; i<v.size(); i++){
            counter = counter + 1;
            if(counter == 3){
                cout << "The " << v[i] << " suitor is eliminated." << endl;
                v.erase(v.begin() + i);
                counter = 0;
                i--;
            }
        }
    }while(v.size() > 1);
    cout << endl;
    return 0;
}
