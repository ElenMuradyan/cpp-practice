#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    private:
        string name;
        int age;
        vector<int> grades;
    public:
        Student(string name, int age, vector<int> grades): name(name), age(age), grades(grades) {}

        void addGrade(int a) {
            if(a > 0) {
                grades.push_back(a);
            }
        } 

        double averageGrade() const {
            int sum = 0;
            for(int i = 0; i < grades.size(); i++) {
                sum += grades[i];
            }
            return grades.size() > 0 ? static_cast<double>(sum) / grades.size() : 0;
        }

        void printInfo() const {
            string gradesString = "";
            for(int i = 0; i < grades.size(); i++) {
                string sign = i == grades.size() - 1 ? "." :  ", ";
                gradesString = gradesString + to_string(grades[i]) + sign;
            }

            cout << "Name: " << name << ", Age: " << age << ", Grades: " << gradesString << endl;
        }
};