#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "/person/Faculty.h"
#include "/person/Student.h"
#include "/utils/CapacityException.h"
using namespace std;
class Course
{
private:
string courseCode;
string courseName;
int creditHours;
Faculty* instructor;
int maxCapacity;
int enrolledCount;
public:
Course(string code, string name, int ch,
Faculty* inst, int capacity)
{
courseCode = code;
courseName = name;
creditHours = ch;
instructor = inst;
maxCapacity = capacity;
enrolledCount = 0;
}
string getCourseCode()

{
return courseCode;}
string getCourseName()
{
return courseName;}
int getCreditHours()
{
return creditHours;
}
void setCourseName(string name)
{
courseName = name;
}
void enrollStudent()
{
if (enrolledCount >= maxCapacity)
{
throw CapacityExceededException("Course Capacity Exceeded!");
}
enrolledCount++; }
bool operator==(Course &other)
    {
return courseCode == other.courseCode;}
int operator+(Course &other)
{
return enrolledCount + other.enrolledCount;}
friend ostream& operator<<(ostream& out,const Course& c);
};
ostream& operator<<(ostream& out,const Course& c)
{
cout << "Course Code: "<< c.courseCode << endl;
cout << "Course Name: "<< c.courseName << endl;
cout << "Credit Hours: "<< c.creditHours << endl;
cout << "Max Capacity: "<< c.maxCapacity << endl;
cout << "Enrolled Count: "<< c.enrolledCount << endl;
return out;
}
#endif