#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"
class Faculty : public Person
{
private:
    string employeeID;
    string department;
    string designation;
public:
    Faculty(string n, string c, int a, string con, string id, string dep, string des)
        : Person(n, c, a, con)
    {
        employeeID = id;
        department = dep;
        designation = des;
    }
    void displayInfo() override
    {
        cout << "\n--- Faculty Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
  cout << "Age: " << age << endl;
 cout << "Contact: " << contact << endl;
        cout << "Employee ID: " << employeeID << endl;
     cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl; }
    string getEmployeeID() const { return employeeID; }
    string getDepartment() const { return department; }
    string getDesignation() const { return designation; }
};
#endif