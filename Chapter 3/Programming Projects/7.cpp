/*In cold weather, meteorologists report an index called the wind chill factor , which
takes into account the wind speed and the temperature. The index provides a
measure of the chilling effect of wind at a given air temperature. Wind chill may
be approximated by the following formula,
 //formula
 where
 v = wind speed in m/sec
 t = temperature in degrees Celsius: t 6= 10
 W = wind chill index (in degrees Celsius)
 Write a function that returns the wind chill index. Your code should ensure that
the restriction on the temperature is not violated. Look up some weather reports
in back issues of a newspaper in your library and compare the wind chill index you
calculate with the result reported in the newspaper. */
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
bool check_temperature(float temperature);
int main(){
    float wind_speed, temperature;
    cout << "Enter wind speed in mph: ";
    cin >> wind_speed;
    cout << "\nEnter temperature in Fahrenheit: ";
    cin >> temperature;
    if(!check_temperature(temperature)){
        cerr << "\nTemperature must be below 10C.";
        exit(1);
    }
    float wind_chill_index;
    //wind_chill_index = 13.12 + 0.6215*temperature - 11.37 * pow(wind_speed, 0.16) + 0.3965*temperature*pow(wind_speed, 0.016);
    wind_chill_index = 33 - (((10*sqrt(wind_speed) - wind_speed + 10.5) * (33-temperature))/23.1);
    cout << "----------------------------------------------------------------------";
    cout << "\nWind Chill index for the given data is: " << wind_chill_index;
    cout << endl;
    return 0;
}
bool check_temperature(float temperature){
    if(temperature < 10){
        return true;
    }
    else{
        return false;
    }
}

