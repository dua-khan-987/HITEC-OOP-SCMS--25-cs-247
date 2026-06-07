#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string name;
    string cnic;
    int age;
    string contact;
public:
    Person(string n, string c, int a, string con)
    {
        name = n;
        cnic = c;
        age = a;
        contact = con;
    }
    virtual void displayInfo() = 0;
    virtual ~Person() {}
};
#endif