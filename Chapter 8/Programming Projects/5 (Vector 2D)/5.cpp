/*Write the definition for a class named Vector2D that stores information about a
two-dimensional vector. The class should have functions to get and set the x and
y components, where x and y are integers.
 Next, overload the * operator so that it returns the dot product of two vectors. The
dot product of two-dimensional vectors A and B is equal to
 (A x * B x ) + (A y * B y ).
 Finally, write a main subroutine that tests the * operation. */
//Vector2D
#include <iostream>
using namespace std;

class Vector2D{
public:
    void setX(int x_value);
    void setY(int y_value);

    friend int operator *(const Vector2D& v1, const Vector2D& v2);
    //overloading multiplication operator
private:
    int x;
    int y;

    int getX() const;
    int getY() const;
};

void Vector2D::setX(int x_value){
    x = x_value;
}
int Vector2D::getX() const{ return x; }
void Vector2D::setY(int y_value){
    y = y_value;
}
int Vector2D::getY() const{ return y; }

int operator *(const Vector2D& v1, const Vector2D& v2){
    return (v1.getX() * v2.getX()) + (v1.getY() * v2.getY());
}
int main(){
    Vector2D v1, v2;
    v1.setX(2);
    v1.setY(-3);

    v2.setX(-4);
    v2.setY(2);

    cout << "Dot product of the two given vectors is: " << v1 * v2 << endl;
    return 0;
}
