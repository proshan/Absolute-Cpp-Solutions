/*Write a program that outputs a histogram of grades for an assignment given to
a class of students. The program should input each student’s grade as an integer
and store the grade in a vector. Grades should be entered until the user enters -1
for a grade. The program should then scan through the vector and compute the
histogram. In computing the histogram, the minimum value of a grade is 0, but
your program should determine the maximum value entered by the user. Output
the histogram to the console. See Programming Project 5.7 for information on how
to compute a histogram. */
//cpp program to output a histogram of grades for an assignment
//given to a class of students.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> m;
    int mark = 0;
    cout << "Enter the marks obtained by students: ";
    while(true){
        cin >> mark;
        if(mark < 0){
            break;
        }
        m.push_back(mark);
    }
    int maxMark = m[0];
    for(unsigned int i = 1; i<m.size(); i++){
        if(m[i] > maxMark){
            maxMark = m[i];
        }
    }
    if(maxMark % 10 != 0){
        maxMark = ((maxMark/10)+1)*10;
    }
    //for(unsigned int i = 0; i<m.size(); i++){
        //m[i] = m[i]/5;
    //}
    cout << endl;
    cout << "Printing Histogram: ";
    cout << endl;
    for(unsigned int i = 0; i<m.size(); i++){
        cout << m[i] << ":      ";
        for(int j = 1; j<=m[i]/5; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
