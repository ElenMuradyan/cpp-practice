#include <iostream>
#include <string>

using namespace std;

class Temperature {
    private:
        float temp;
        string scale;
    public:
        Temperature(float temp): temp(temp), scale("Celsius") {}

        float convertFahrenheit () {
            if(scale == "Celsius"){
                const float val = temp * 1.8 + 32; 
                temp = val;
                scale = "Fahrenheit";
                return val;
            }
            if(scale == "Kelvin"){
                const float val = (temp - 273.15) * 1.8 + 32; 
                temp = val;
                scale = "Fahrenheit";
                return val;
            }
            return temp;
        }

        float convertKelvin () {
            if(scale == "Celsius"){
                const float val = temp + 273.15; 
                temp = val;
                scale = "Kelvin";
                return val;
            }
            if(scale == "Fahrenheit"){
                const float val = (temp - 32) * 5 / 9 + 273.15; 
                temp = val;
                scale = "Kelvin";
                return val;
            }
            return temp;
        }

        float convertCelsius () {
            if(scale == "Kelvin"){
                const float val = temp - 273.15; 
                temp = val;
                scale = "Celsius";
                return val;
            }
            if(scale == "Fahrenheit"){
                const float val = (temp - 32) * 5 / 9; 
                temp = val;
                scale = "Celsius";
                return val;
            }
            return temp;
        }

        friend ostream &operator<< (ostream &out, Temperature &item){
            out << item.temp << " " << item.scale;
            return out;
        }
};