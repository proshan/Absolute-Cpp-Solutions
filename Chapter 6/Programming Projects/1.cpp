/*Write a grading program for a class with the following grading policies:
 a. There are two quizzes, each graded on the basis of 10 points.
 b. There is one midterm exam and one final exam, each graded on the basis of
100 points.
 c. The final exam counts for 50% of the grade, the midterm counts for 25%, and
the two quizzes together count for a total of 25%. (Do not forget to normalize
the quiz scores. They should be converted to a percentage before they are averaged
in.)
 Any grade of 90 or more is an A, any grade of 80 or more (but less than 90) is a
B, any grade of 70 or more (but less than 80) is a C, any grade of 60 or more (but
less than 70) is a D, and any grade below 60 is an F. The program will read in the
student’s scores and output the student’s record, which consists of two quiz and
two exam scores as well as the student’s average numeric score for the entir*/
#include <iostream>
#include <cstdlib>
using namespace std;
class Grade{
private:
    double quiz1;
    double quiz2;
    double midTerm;
    double finalTerm;
    double grade;
public:
    void getScores();
    void findGrade();
    double convertToHundred(double value);
    double percentToValue(double percent, double marks);
    void printResult();
};
void Grade::getScores(){
    cout << "Enter score for quiz1: ";
    cin >> quiz1;
    cout << "Enter score for quiz2: ";
    cin >> quiz2;
    cout << "Enter score for mid term: ";
    cin >> midTerm;
    cout << "Enter score for final term: ";
    cin >> finalTerm;
    return;
}
void Grade::findGrade(){
    grade = percentToValue(12.5, convertToHundred(quiz1)) + percentToValue(12.5, convertToHundred(quiz2))
            + percentToValue(25, midTerm) + percentToValue(50, finalTerm);
}
double Grade::convertToHundred(double value){
    return value * 10;
}
double Grade::percentToValue(double percent, double marks){
    return (percent/100)*marks;
}
void Grade::printResult(){
    string result;
    if(grade < 60){
        result = "F";
    }
    else if(grade > 50 && grade < 60){
        result = "E";
    }
    else if(grade > 60 && grade < 70){
        result = "D";
    }
    else if(grade > 70 && grade < 80){
        result = "C";
    }
    else if(grade > 80 && grade < 90){
        result = "B";
    }
    else if(grade > 90){
        result = "A";
    }
    cout << "Score in quiz1: " << quiz1;
    cout << endl << "Score in quiz2: " << quiz2;
    cout << "Your grade is: " << result;
}
int main(){
    Grade mygrade;
    mygrade.getScores();
    mygrade.findGrade();
    mygrade.printResult();
    cout << endl;
    return 0;
}
