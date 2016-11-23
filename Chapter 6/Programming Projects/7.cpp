/*Define a class called Pizza that has member variables to track the type of pizza
(either deep dish, hand tossed, or pan) along with the size (either small, medium,
or large) and the number of pepperoni or cheese toppings. You can use constants to
represent the type and size. Include mutator and accessor functions for your class.
Create a void function, outputDescription( ) , that outputs a textual description
of the pizza object. Also include a function, computePrice( ) , that computes the
cost of the pizza and returns it as a double according to the following rules:
 Small pizza = $10 + $2 per topping
 Medium pizza = $14 + $2 per topping
 Large pizza = $17 + $2 per topping
 Write a suitable test program that creates and outputs a description and price of
various pizza objects. */
#include <iostream>
using namespace std;
class Pizza{
private:
    string typeOfPizza;
    char sizeOfPizza;
    int numberOfPepperoniCheese;
    double price;
public:
    void outputDescription();
    void getInputs();
    void computePrice();
    void printResult();
};

void Pizza::outputDescription(){
    //outputs textual description of the pizza object
    cout << "Small pizza = $10 + $2 per topping" << endl;
    cout << "Medium pizza = $14 + $2 per topping" << endl;
    cout << "Large pizza = $17 + $2 per topping" << endl;
}
void Pizza::getInputs(){
    cout << "Enter the type of pizza: (deep dish-deepd, hand tossed-handt, pan-pan): ";
    cin >> typeOfPizza;
    cout << "Enter the size of the pizza: (small-s, medium-m, large-l): ";
    cin >> sizeOfPizza;
    cout << "Enter the number of pepperoni or cheese toppings: ";
    cin >> numberOfPepperoniCheese;
}
void Pizza::computePrice(){
    //computes the cost of the pizza
    //and returns it
    if(sizeOfPizza == 's'){
        price = 10 + numberOfPepperoniCheese * 2;
    }
    else if(sizeOfPizza = 'm'){
        price = 14 + numberOfPepperoniCheese * 2;
    }
    else if(sizeOfPizza = 'l'){
        price = 17 + numberOfPepperoniCheese * 2;
    }
}
void Pizza::printResult(){
    cout << endl << "Pizza type: " << typeOfPizza << endl;
    cout << "Number of Pepperoni or Cheese is: " << numberOfPepperoniCheese << endl;
    cout << "Size of Pizza: " << sizeOfPizza << endl;
    cout << "---------------------------" << endl;
    cout << "Price of the Pizza: $" << price << endl;
}
int main(){
    Pizza p;
    p.outputDescription();
    cout << endl;
    p.getInputs();
    p.computePrice();
    p.printResult();
    cout << endl;
    return 0;
}
