/* A government research lab has concluded that an artificial sweetener commonly used in
diet soda will cause death in laboratory mice. A friend of yours is desperate to lose weight
but cannot give up soda. Your friend wants to know how much diet soda it is possible to
drink without dying as a result. Write a program to supply the answer. The input to the
program is the amount of artificial sweetener needed to kill a mouse, the weight of the
mouse, and the weight of the dieter. To ensure the safety of your friend, be sure the program
requests the weight at which the dieter will stop dieting, rather than the dieter’s current
weight. Assume that diet soda contains one-tenth of 1% artificial sweetener. Use a
variable declaration with the modifier const to give a name to this fraction. You may want
to express the percentage as the double value 0.001.
*/
#include <iostream>
using namespace std;
int main(){
    cout << "Enter the amount of artificial sweetener needed to kill a mouse: ";
    float amount_to_kill_mouse;
    cin >> amount_to_kill_mouse;
    cout << "\nEnter the weight of the mouse: ";
    float mouse_weight;
    cin >> mouse_weight;
    cout << "\nEnter the weight of the dieter: ";
    float dieter_weight;
    cin >> dieter_weight;
    float stop_weight;
    cout << "\nEnter the weight at which you will stop dieting: ";
    cin >> stop_weight;
    double max_sweetner;
    if(stop_weight >= dieter_weight){
        cout << "\nThis weight is high than your current age.";
    }
    else{
        max_sweetner = amount_to_kill_mouse * dieter_weight/mouse_weight;
    }
    cout << "\nIt is possible to drink " << max_sweetner << " soda without dying.";
    return 0;
}
