#include <iostream>
#include <string>

using namespace std;

class Employee {
    private: 
        string name;
        string position;
        int salary;
    public:
        Employee(string name, string position, int salary): name(name), position(position), salary(salary) {}

        void promote (string newPos) {
            position = newPos;
        }

        void raiseSalary(int newSal) {
            if(newSal > salary){
                salary = newSal;
            }
        }

        void display() const {
            cout << "Name: " << name << ", Position: " << position << ", Salary: " << salary << endl;
        }

        int getSalary() const {
            return salary;
        }
};

