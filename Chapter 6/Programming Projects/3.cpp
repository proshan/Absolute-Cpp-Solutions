/*The type Point is a fairly simple data type, but under another name (the template
class pair ) this data type is defined and used in the C++ Standard Template Library,
although you need not know anything about the Standard Template Library to do
this exercise. Write a definition of a class named Point that might be used to store
and manipulate the location of a point in the plane. You will need to declare and
implement the following member functions:
 a. A member function set that sets the private data after an object of this class
is created.
 b. A member function to move the point by an amount along the vertical and
horizontal directions specified by the first and second arguments.
 c A member function to rotate the point by 90 degrees clockwise around the origin.
 d. Two const inspector functions to retrieve the current coordinates of the point.

 Document these functions with appropriate comments. Embed your class in a test
program that requests data for several points from the user, creates the points, then
exercises the member functions. */
#include <iostream>
using namespace std;
class Point{
private:
    int x;
    int y;
    int xValue;
    int yValue;
public:
    Point();
    //this constructor initializes all of the public variables to zero.
    void setValues();
    //this function sets the value of x and y coordinate
    void displace();
    //this function changes the location of the x and y coordinate
    //according to the value provided for horizontal and vertical line
    void rotateNinety();
    //rotates the point 90 degree clockwise
    void getCoordinates();
    //prints the final rotated point of x and y
};
Point::Point(){
    x = 0;
    y = 0;
    xValue = 0;
    yValue = 0;
}
void Point::setValues(){
    cout << "Enter the x point: ";
    cin >> x;
    cout << "Enter the y point: ";
    cin >> y;
    return;
}
void Point::displace(){
    cout << "Enter how many points vertical to move: ";
    cin >> xValue;
    cout << "Enter how many points horizontal to move: ";
    cin >> yValue;
    x = x + xValue;
    y = y + yValue;
    return;
}
void Point::rotateNinety(){
    int temp = x;
    //by creating a new variable temp, we are preserving the value of x
    //which is to be used later
    x = y;
    y = (-1) * temp;
    return;
}
void Point::getCoordinates(){
    cout << "The final point after rotation is: (" << x << ", " << y << ")"<< endl;
    return;
}
int main(){
    Point p;
    char ans;
    do{
        p.setValues();
        //Each time this loop is executed,
        //setValues sets the value of all the variables to zero.
        p.displace();
        p.rotateNinety();
        p.getCoordinates();
        cout << endl;
        cout << "Next point (y/n)?";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    cout << endl;
    return 0;
}

