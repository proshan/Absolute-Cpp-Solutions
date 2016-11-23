#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    int seed;
    cout << "Please ente the value of seed: ";
    cin >> seed;
    cout << endl;
    srand(seed);
    for(int i =1; i<=10; i++){
        cout << rand() % (2);
        cout << endl;
    }
    cout << "The generation of random numbers has ended.";
    cout << rand();
    return 0;
}
