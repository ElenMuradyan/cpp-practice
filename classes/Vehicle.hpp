#include <iostream>
#include <string>

using namespace std;

class Vehicle {
    protected:
        int speed;
        string fuelType;
        int fuelAmount;
    public:
        Vehicle(int speed, string fuelType, int fuelAmount): speed(speed), fuelType(fuelType), fuelAmount(fuelAmount) {}
        virtual void display() const{
            cout << speed << " " << fuelType << " " << fuelAmount << endl;
        }
};

class Car : public Vehicle {
    public:
        int seats; 
        Car(int speed, string fuelType, int fuelAmount, int seatNum): Vehicle(speed, fuelType, fuelAmount) {
            seats = seatNum;
        }
        void display() const override{
            cout << speed << " " << fuelType << " " << fuelAmount << " " << seats << endl;
        }
};

class Bike : public Vehicle {
    public:
        string type; 
        Bike(int speed, string fuelType, int fuelAmount, string typeArg): Vehicle(speed, fuelType, fuelAmount) {
            type = typeArg;
        }
        void display() const override{
            cout << speed << " " << fuelType << " " << fuelAmount << " " << type << endl;
        }
};