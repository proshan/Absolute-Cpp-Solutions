/*You operate several hot dog stands distributed throughout town. Define a class named
HotDogStand that has a member variable for the hot dog stand’s ID number and a
member variable for how many hot dogs the stand sold that day. Create a constructor
that allows a user of the class to initialize both values.
 Also create a function named JustSold that increments the number of hot dogs
the stand has sold by one. This function will be invoked each time the stand sells a
hot dog so that you can track the total number of hot dogs sold by the stand. Add
another function that returns the number of hot dogs sold.
 Finally, add a static variable that tracks the total number of hot dogs sold by all
hot dog stands and a static function that returns the value in this variable. Write
a main function to test your class with at least three hot dog stands that each sell a
variety of hot dogs. */
#include <iostream>
using namespace std;
class HotDogStand{
public:
    HotDogStand(int id, int numberSold);
    HotDogStand();
    void justSold();
    //increments the numbers of hot dogs sold by 1.
    void setID(int id);
    int getID();
    static int getTotalHotDogs();
    //returns total hot dogs
    int getNumberOfHotDogsSold();
    //returns the number of hot dogs sold.
private:
    int hotDogID;
    int hotDogsSold;

    static int totalHotDogsSold;
    //to hold total number of sold hot dogs.1
};
int HotDogStand::totalHotDogsSold = 0;
//static variables are initialized outside the class.
//initialized the static variable's value to 0.
int main(){
    HotDogStand h1(1, 0);
    HotDogStand h2;

    h1.justSold();
    h1.justSold();

    h2.justSold();
    h2.justSold();
    h2.justSold();

    cout << "h1 id number " << h1.getID() << " sold " << h1.getNumberOfHotDogsSold() << endl;
    cout << "h2 id number " << h2.getID() << " sold " << h2.getNumberOfHotDogsSold() << endl;
    cout << endl;
    cout << "Total number of hot dogs sold: " << h1.getTotalHotDogs() << endl;
    cout << endl;
    return 0;
}
HotDogStand::HotDogStand(int id, int numberSold) : hotDogID(id), hotDogsSold(numberSold){}
//initializes the parameters to hotDogID and hotDogSold.
HotDogStand::HotDogStand() : hotDogID(0), hotDogsSold(0){}
//initializes the hotDogID to 1 and hotDogsSold to 0.
void HotDogStand::justSold(){
    hotDogsSold++;
    totalHotDogsSold++;
}
void HotDogStand::setID(int id){
    hotDogID = id;
}
int HotDogStand::getID(){
    return hotDogID;
}
int HotDogStand::getTotalHotDogs(){ return totalHotDogsSold; }
int HotDogStand::getNumberOfHotDogsSold(){ return hotDogsSold; }
