/*Define a class for a type called CounterType . An object of this type is used to
count things, so it records a count that is a nonnegative whole number. Include a
mutator function that sets the counter to a count given as an argument. Include
member functions to increase the count by one and to decrease the count by one.
Be sure that no member function allows the value of the counter to become negative.
Also, include a member function that returns the current count value and one
that outputs the count. Embed your class definition in a test program. */
#include <iostream>
using namespace std;
const int MAX = 5;
class CounterType{
private:
    int numbers[MAX];
    int the_count;
public:
    CounterType(void);
    void getNumbers();
    void add(int number);
    void subtract(int number);
    int getElement(int index);
    int getResult();
};
CounterType::CounterType(void){
    the_count = 0;
}
void CounterType::getNumbers(){
    cout << "Enter " << MAX << " numbers: ";
    for(int i = 0; i < MAX; i++){
        cin >> numbers[i];
    }
    return;
}
void CounterType::add(int number){
    if(number > 0){
        the_count++;
    }
    return;
}
void CounterType::subtract(int number){
    if(number < 0){
        the_count--;
    }
    return;
}
int CounterType::getElement(int index){
    return numbers[index];
}
int CounterType::getResult(){
    return the_count;
}

int main(){
    CounterType counter;
    counter.getNumbers();
    for(int i = 0; i<MAX; i++){
        counter.add(counter.getElement(i));
        counter.subtract(counter.getElement(i));
        cout << "The value of count is: " << counter.getResult() << endl;
    }
    cout << endl;
    cout << "The final value of count is: " << counter.getResult();
    cout << endl;
    return 0;
}

