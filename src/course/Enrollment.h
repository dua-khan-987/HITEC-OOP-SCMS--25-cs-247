#ifndef ENROLLMENT_H
#define ENROLLMENT_H
#include <string>
#include "/person/Student.h"
#include "Course.h"
using namespace std;
class Enrollment
{
private:
Student* student;
Course* course;
string enrollmentDate;
char grade;
public:
Enrollment(Student* s,Course* c,tring date)
{
student = s;
course = c;
enrollmentDate = date;
grade = 'N';   }
Student* getStudent() const
{
return student;}
Course* getCourse() const
{return course;}
string getEnrollmentDate() const
{
return enrollmentDate;}
char getGrade() const{
return grade;}
void setGrade(char g)
{grade = g;
}};
#endif