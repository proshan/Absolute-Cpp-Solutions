/*This Programming Project requires you to first complete Programming
Project 6.7 from Chapter 6 , which is an implementation of a Pizza class. Add
an Order class that contains a private vector of type Pizza . This class represents
a customer’s entire order, where the order may consist of multiple pizzas. Include
appropriate functions so that a user of the Order class can add pizzas to the order
(type is deep dish, hand tossed, or pan; size is small, medium, or large; number
of pepperoni or cheese toppings). You can use constants to represent the type and
size. Also write a function that outputs everything in the order along with the total
price. Write a suitable test program that adds multiple pizzas to an order(s). */
//Pizza and Order class
#include <iostream>
#include <vector>
using namespace std;
const int DEEPDISH = 1;
const int HANDTOSSED = 2;
const int PAN = 3;
const int SMALL = 1;
const int MEDIUM = 2;
const int LARGE = 3;
class Pizza{
private:
    int type;
    int pizzaSize;
    bool cheeseTopping;
    bool pepperoniTopping;
public :
    Pizza();
    int getType();
    int getSize();
    bool getCheese();
    bool getPepperoni();
    void setType(int t);
    void setSize(int s);
    void setCheese(bool choice);
    void setPepperoni(bool choice);
    void outputDescription();
    double computePrice();
};
Pizza::Pizza(){
    type = DEEPDISH;
    pizzaSize =  SMALL;
}
int Pizza::getType(){ return type; }
int Pizza::getSize(){ return pizzaSize; }
bool Pizza::getCheese(){ return cheeseTopping; }
bool Pizza::getPepperoni(){ return pepperoniTopping; }
void Pizza::setType(int t){ type = t; }
void Pizza::setSize(int s){ pizzaSize = s; }
void Pizza::setCheese(bool choice){ cheeseTopping = choice; }
void Pizza::setPepperoni(bool choice){ pepperoniTopping = choice; }
void Pizza::outputDescription(){
    switch(pizzaSize){
        case SMALL: cout << "Small ";
        break;
        case MEDIUM: cout << "Medium ";
        break;
        case LARGE: cout << "Large ";
        break;
        default: cout << "Unknown sized ";
    }
    switch(type){
        case DEEPDISH: cout << "deepdish ";
        break;
        case HANDTOSSED: cout << "hand tossed ";
        break;
        case PAN: cout << "pan ";
        break;
        default: cout << "unknown type ";
    }
    cout << "pizza";
}
double Pizza::computePrice(){
    double cost = 0.0;
    switch(pizzaSize){
        case SMALL: cost += 10;
        break;
        case MEDIUM: cost += 14;
        break;
        case LARGE: cost += 17;
        break;
    }
    if(cheeseTopping){ cost+= 2.0; }
    if(pepperoniTopping){ cost += 2.0; }
    return cost;
}

class Order{
private:
    vector<Pizza> customer;
public:
    void customerOrder();
    void customerTotal();
};
void Order::customerOrder(){
    char pType, pSize, topping, temp;
    int type = 0, pizzaSize = 0;
    cout << "What size pizza do you like (S/M/L): ";
    cin >> pSize;
    switch(pSize){
        case 'S': case 's' : pizzaSize= SMALL;
        break;
        case 'M' : case 'm' :  pizzaSize = MEDIUM;
        break;
        case 'L': case 'l': pizzaSize = LARGE;
        break;
    }
    cout << "What type pizza do you like (D)eepdish/(H)and-tossed/(P)an): ";
    cin >> pType;
    switch(pType){
        case 'D': case 'd' : type = DEEPDISH;
        break;
        case 'H' : case 'h' :  type = HANDTOSSED;
        break;
        case 'P': case 'p': type = PAN;
        break;
    }
    Pizza myPizza;
    myPizza.setSize(pizzaSize);
    myPizza.setType(type);
    cout << "Do you want cheese topping? (y/n) ";
    cin >> topping;
    if(topping == 'Y' || topping == 'y'){
        myPizza.setCheese(true);
    }
    cout << "Do you want pepperoni topping (y/n) ? ";
    cin >> topping;
    if(topping == 'Y' || topping == 'y'){
        myPizza.setPepperoni(true);
    }
    cout << endl;
    cout << "Customer order is: ";
    myPizza.outputDescription();
    cout << endl;
    cout << "Cost: $" << myPizza.computePrice() << endl;
    customer.push_back(myPizza);
}
void Order::customerTotal(){
    double total = 0;
    cout << "Customer total order: " << endl;
   for(int i = 0; i<customer.size(); i++){
        customer[i].outputDescription();
        cout << endl;
        cout << customer[i].computePrice();
        cout << endl;
        total += customer[i].computePrice();
   }
   cout << "Total cost of the order is: " << total;
   cout << endl;
}
int main(){
    char ans;
    Order customer1;
    do{
        customer1.customerOrder();
        cout << "Do you want order one more pizza? Press y.";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    customer1.customerTotal();
}
