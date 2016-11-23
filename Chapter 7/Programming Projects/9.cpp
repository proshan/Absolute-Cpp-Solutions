/*Prior to 2009 the bar code on an envelope used by the U.S. Postal Service represented
a five (or more) digit zip code using a format called POSTNET. The bar
code consists of long and short bars as shown here:
        //figure goes here
For this program, we will represent the bar code as a string of digits. The digit 1
represents a long bar, and the digit 0 represents a short bar. Therefore, the bar code
shown would be represented in our program as follows:
 110100101000101011000010011
 The first and last digits of the bar code are always 1. Removing these leave 25 digits.
If these 25 digits are split into groups of five digits each then we have the following:
 10100 10100 01010 11000 01001
 Next, consider each group of five digits. There always will be exactly two 1’s in
each group of digits. Each digit stands for a number. From left to right, the digits
encode the values 7, 4, 2, 1, and 0. Multiply the corresponding value with the digit
and compute the sum to get the final encoded digit for the zip code. The following
table shows the encoding for 10100.

Bar Code Digits 1 0 1 0 0
Value 7 4 2 1 0
Product of
Digit * Value
702 0 0
Zip Code Digit = 7 + 0 + 2 + 0 + 0 = 9

Repeat this for each group of five digits and concatenate to get the complete zip
code. There is one special value. If the sum of a group of five digits is 11, then this
represents the digit 0 (this is necessary because with two digits per group it is not
possible to represent zero). The zip code for the sample bar code decodes to 99504.
While the POSTNET scheme may seem unnecessarily complex, its design allows
machines to detect if errors have been made in scanning the zip code.
 Write a zip code class that encodes and decodes five-digit bar codes used by the
U.S. Postal Service on envelopes. The class should have two constructors. The first
constructor should input the zip code as an integer, and the second constructor
should input the zip code as a bar code string consisting of 0’s and 1’s as described
above. Although you have two ways to input the zip code, internally, the class
should only store the zip code using one format. (You may choose to store it as a
bar code string or as a zip code number.) The class also should have at least two
public member functions: one to return the zip code as an integer and the other
to return the zip code in bar code format as a string. All helper functions should be
declared private. Embed your class definition in a suitable test program. */
#include <iostream>
#include <string>
#include <cstdlib>
//for exit()
using namespace std;
class PostalCode{
public:
    PostalCode(int zip);
    //inputs zip code as an integer
    PostalCode(string bar);
    //inputs zip code as a string (0, 1)

    int getZipCode();
    //returns the zip code as an integer
    string getBarCode();
    //returns the zip code as a string
private:
    int zipCode;
    string barCode;

    bool checkBarCode();
    //returns true if first and last digits of the bar code is 1
    //and length of bar code is 27
    bool checkTwoOnes();
    //returns true if there is exactly two 1's in each group of 5 digits
    int calculateZipCode();
    //returns the final zip value
    string getFiveDigitValues();
};
PostalCode::PostalCode(int zip) : zipCode(zip){}
PostalCode::PostalCode(string bar) : barCode(bar){}

int PostalCode::getZipCode(){
    if(checkBarCode()){
        //if bar code is in right format
        if(checkTwoOnes()){
            //if two ones in every five digits
            zipCode = calculateZipCode();
        }
        else{
            cout << "Error validating two ones in every five digits!";
            exit(1);
        }
    }
    else{
        cout << "Bar-Code Validation Error!";
        exit(1);
    }
    return zipCode;
}

string PostalCode::getBarCode(){
    barCode = getFiveDigitValues();
    barCode = "1"+barCode+"1";
    return barCode;
}
bool PostalCode::checkBarCode(){
    bool result;
    if((barCode.length() == 27) && ((static_cast<int>(barCode[0]) - 48) == 1)
       &&  ((static_cast<int>(barCode[26]) - 48) == 1)){
        result = true;
       }
    else{ result = false; }
    return result;
}
bool PostalCode::checkTwoOnes(){
    bool fiveCases[5];
    //stores true if each five digit group contains
    //two ones
    int arrCount = 0;
    int numberOnes;
    //number of number ones
    bool result = true;
    for(int i = 1; i<=25; i=i+5){
        numberOnes = 0;
        //resetting the value of numberOnes for next loop
        for(int j = i; j<=i+4; j++){
            if((static_cast<int>(barCode[j]) - 48) == 1){
                numberOnes++;
            }
        }
        if(numberOnes == 2){
            fiveCases[arrCount] = true;
        }
        else{ fiveCases[arrCount] = false; }
        arrCount++;
    }
    for(int i = 0; i<5; i++){
        if(fiveCases[i] == false){
            result = false;
            break;
        }
    }
    return result;
}
int PostalCode::calculateZipCode(){
    int result = 0;
    int sumArr[5];
    //stores sum of five five digit group of numbers
    int arrCounter = 0;
    int sum;
    int tempCounter;
    //to count first, second third, fourth, fifth value
    for(int i = 1; i<=25; i=i+5){
        sum = 0;
        //reseting the value of sum after each five digits
        tempCounter = 1;
        //reseting the value of tempCounter
        for(int j = i; j<=i+4; j++){
            if(tempCounter == 1){
                sum += (static_cast<int>(barCode[j]) - 48)*7;
                tempCounter++;
            }
            else if(tempCounter == 2){
                sum += (static_cast<int>(barCode[j]) - 48)*4;
                tempCounter++;
            }
            else if(tempCounter == 3){
                sum += (static_cast<int>(barCode[j]) - 48)*2;
                tempCounter++;
            }
            else if(tempCounter == 4){
                sum += (static_cast<int>(barCode[j]) - 48)*1;
                tempCounter++;
            }
            else if(tempCounter == 5){
                sum += (static_cast<int>(barCode[j]) - 48)*0;
                tempCounter++;
            }

        }
        if(sum == 11){
            sum = 0;
        }
        sumArr[arrCounter] = sum;
        //storing the sum in array
        arrCounter++;
    }
    int multiplier = 10000;
    //now, converting the values in arr into an integer number
    for(int i = 0; i<5; i++){
        result += sumArr[i] * multiplier;
        multiplier = multiplier/10;
    }
    return result;
}
string PostalCode::getFiveDigitValues(){
    string result = "";
    int divisor = 10000;
    int number = zipCode;
    int currentDigit;
    for(int i = 0; i<5; i++){
        currentDigit = number/divisor;
        switch(currentDigit){
        case 0:
            result += "11000";
            break;
        case 1:
            result += "00011";
            break;
        case 2:
            result += "00101";
            break;
        case 3:
            result += "00110";
            break;
        case 4:
            result += "01001";
            break;
        case 5:
            result += "01010";
            break;
        case 6:
            result += "01100";
            break;
        case 7:
            result += "10001";
            break;
        case 8:
            result += "10010";
            break;
        case 9:
            result += "10100";
            break;
        default:
            result += "00000";
            cout << "Error!" << endl;
        }
        number = number % divisor;
        divisor = divisor/10;
    }
    return result;
}
int main(){
    PostalCode pc("110100101000101011000010011");
    cout << "The ZIP code is: " << pc.getZipCode();
    cout << endl;
    PostalCode pstl(99504);
    cout << "The Bar Code is: " << pc.getBarCode();
    cout << endl;
    return 0;
}
