/*In the sport of diving, seven judges award a score between 0 and 10, where each
score may be a floating-point value. The highest and lowest scores are thrown
out and the remaining scores are added together. The sum is then multiplied by
the degree of difficulty for that dive. The degree of difficulty ranges from 1.2 to
3.8 points. The total is then multiplied by 0.6 to determine the diver’s score.
 Write a computer program that inputs a degree of difficulty and seven judges’
scores, and outputs the overall score for that dive. The program should ensure that
all inputs are within the allowable data ranges. */
#include <iostream>
int MAX = 7;
using namespace std;
void getValues(double score[]);
void checkScore(double &score);
double getDifficulty();
void minMax(double score[], double &highest, double &lowest);
void removeElement(double score[], double value);
double calculation(double score[]);
int main(){
    double score[MAX];
    getValues(score);
    double highest, lowest;
    minMax(score, highest, lowest);
    removeElement(score, highest);
    removeElement(score, lowest);
    double result = calculation(score);
    cout << "The driver's score is: " << result;
    cout << endl;
    return 0;
}
void getValues(double score[]){
    for(int i = 0; i<MAX; i++){
        cout << "Score from judge " << i+1 << " : ";
        cin >> score[i];
        checkScore(score[i]);
    }
    return;
}
void checkScore(double &score){
    if(score > 10 || score < 1){
        while(true){
            cout << "The score is not valid. Enter another value: ";
            cin >> score;
            if(score <= 10 && score >= 1){
                break;
            }
        }
    }
    return;
}
double getDifficulty(){
    double result = 0;
    cout << "Enter the degree of difficulty: ";
    cin >> result;
    if(result > 3.8 || result < 1.2){
        while(true){
            cout << "The degree of difficulty is not valid. Enter another value: ";
            cin >> result;
            if(result <= 3.8 && result >= 1.2){
                break;
            }
        }
    }
    return result;
}
void minMax(double score[], double &highest, double &lowest){
    highest = score[0];
    lowest = score[0];
    for(int i = 1; i<MAX; i++){
        if(score[i] > highest){
            highest = score[i];
        }
        if(score[i] < lowest){
            lowest = score[i];
        }
    }
    return;
}
void removeElement(double score[], double value){
    for(int i = 0; i<MAX; i++){
        if(score[i] == value){
            for(int m = i; m<MAX-1; m++){
                score[m] = score[m+1];
            }
            MAX--;
        }
    }
    return;
}
double calculation(double score[]){
    double result = 0;
    for(int i = 0; i< MAX; i++){
        result += score[i];
    }
    double difficulty = getDifficulty();
    result *= difficulty;
    result *= 0.6;
    return result;
}
