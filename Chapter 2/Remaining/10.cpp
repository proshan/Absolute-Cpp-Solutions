#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    string text;
    fstream fileStream;
    fileStream.open("10.txt");
    while(fileStream >> text){
        if(text == "hate"){
            text = "love";
            cout << text << " ";
        }
        else{
            cout << text << " ";
        }
    }
    return 0;
}
