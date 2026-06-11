#include <iostream>
#include <string>
#include "person/Student.h"
#include "person/Faculty.h"
#include "person/Staff.h"
#include "course/Course.h"
#include "course/Enrollment.h"
#include "utils/CapacityException.h"
using namespace std;
int main()
{
cout << "=== Smart Campus Management System ===" << endl;
Student s("Arham", "15432", 17, "8906", "25-CS-41", 3, 3.9);
Faculty f("Ayesha", "65409", 19, "1111", "G241", "Lecturer", 75000); 
Staff st("Hashir", "14521", 25, "0353", "D341", "Clerk", 60000);
s.displayInfo();
s.calculateGrade();
f.displayInfo();
st.displayInfo();
cout << "\n==========================================\n" << endl;
cout << "--- Module 2: Testing Course & Enrollment Management ---\n" << endl;
Course oopCourse("CS-247", "Object Oriented Programming", 4, &f, 2); 
Course dsaCourse("CS-247", "Data Structures", 4, &f, 4); 
cout << "[Testing == Operator]:" << endl;
if (oopCourse == dsaCourse) {
cout << "Alert: Both courses share the same Course Code!\n" << endl;}
cout << "[Testing Enrollment & Exception Handling]:" << endl;
try {cout << "Enrolling Student 1 (Arham)";
oopCourse.enrollStudent(); 
cout << "Enrolling Student 2 (Dua) ";
oopCourse.enrollStudent(); 
cout << "Enrolling Student 3 (Zara) ";
oopCourse.enrollStudent(); }
catch (const CapacityExceededException& e) {
cout << "\nCaught Custom Exception: " << e.what() << endl;
cout << "Course capacity is full. Adding student to the waiting list instead." << endl;
oopCourse.addToWaitingList(&s); 
}
cout << "\n[Testing << Operator (Course Details)]:" << endl;
cout << oopCourse;
cout << "\n[Testing Enrollment Class]:" << endl;
Enrollment entry1(&s, &oopCourse, "11-06-2026");
cout << "Initial Grade: " << entry1.getGrade() << endl;
entry1.setGrade('A'); 
cout << "Updated Grade: " << entry1.getGrade() << endl;
return 0;
}