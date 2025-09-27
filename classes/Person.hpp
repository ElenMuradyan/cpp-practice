#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        string name;
        int age;
        Person(string name, int age): name(name), age(age) {}
        virtual void display(){
            cout << name << " " << age << endl;
        }
        virtual ~Person() {}
};

class Teacher: public Person {
    public:
        string subject;
        int yearsOfExperience;
        Teacher(string name, int age, string subjectArg, int yearsOfExperienceArg): Person(name, age) {
            subject = subjectArg;
            yearsOfExperience = yearsOfExperienceArg;
        }
        void display() override{
            cout << name << " " << age << " " << subject << " " << yearsOfExperience << endl;
        }
};

class Student: public Person {
    public:
        int grade;
        int rollNumber;
        Student(string name, int age, int gradeArg, int rollNumberArg): Person(name, age) {
            grade = gradeArg;
            rollNumber = rollNumberArg;
        }
        void display() override{
            cout << name << " " << age << " " << grade << " " << rollNumber << endl;
        }
};
