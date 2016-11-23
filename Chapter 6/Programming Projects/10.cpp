/*Create a Temperature class that internally stores a temperature in degrees
 Kelvin. Create functions named setTempKelvin , setTempFahrenheit , and
setTempCelsius that take an input temperature in the specified temperature
scale, convert the temperature to Kelvin, and store that temperature in the
class member variable. Also, create functions that return the stored temperature
in degrees Kelvin, Fahrenheit, or Celsius. Write a main function to test your class.
Use the equations shown next to convert between the three temperature scales.
 Kelvin = Celsius + 273.15
 Celsius = (5.0/9) * (Fahrenheit - 32) */
#include <iostream>
using namespace std;
class Temperature{
private:
    double KelvTemperature;
public:
    Temperature();
    void setTempKelvin(double temperature);
    void setTempFahrenheit(double temperature);
    void setTempCelsius(double temperature);
    void printResult();
};
Temperature::Temperature(){
    KelvTemperature = 0;
}
void Temperature::setTempKelvin(double temperature){
    KelvTemperature = temperature;
}
void Temperature::setTempFahrenheit(double temperature){
    KelvTemperature = (5.0/9) * (temperature - 32);
}
void Temperature::setTempCelsius(double temperature){
    KelvTemperature = temperature + 273.15;
}
void Temperature::printResult(){
    cout << "The converted temperature into Kelvin is: " << KelvTemperature << "K";
}
int main(){
    Temperature temp;
    temp.setTempCelsius(59.3);
    temp.printResult();
    cout << endl;
    return 0;
}
