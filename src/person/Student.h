#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
class Student : public Person
{
private:
string rollNo;
int semester;
float GPA;
string enrolledCourses[10]; 
int courseCount;            
public:
Student(string n, string c, int a, string con, string r, int s, float g)
: Person(n, c, a, con)
{
rollNo = r;
semester = s;
GPA = g;
courseCount = 0; 
}
void displayInfo() override
{
cout << "\n--- Student Information ---" << endl;
cout << "Name: " << name << endl;
cout << "CNIC: " << cnic << endl;
cout << "Age: " << age << endl;
cout << "Contact: " << contact << endl;
cout << "Roll No: " << rollNo << endl;
cout << "Semester: " << semester << endl;
cout << "GPA: " << gpa << endl;
}
void calculateGrade()
{
if (GPA >= 3.2)
cout << "Grade: A" << endl;
else if (GPA >= 2.3)
cout << "Grade: B" << endl;
else if (GPA >= 1.5)
cout << "Grade: C" << endl;
else
cout << "Grade: F" << endl;
}
string getRollNo() const { return rollNo; }
int getSemester() const { return semester; }
Sfloat getGPA() const { return GPA; }
};
#endif