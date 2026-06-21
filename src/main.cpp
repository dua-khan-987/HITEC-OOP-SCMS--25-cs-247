#include <iostream>
#include <string>
#include "person/Student.h"
#include "person/Faculty.h"
#include "person/Staff.h"
#include "course/Course.h"
#include "course/Enrollment.h"
#include "utils/CapacityException.h"
#include "library/Library.h"
#include "hostel/HostelManager.h"
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
cout << "\n            \n" << endl;
cout << "Module 2: Testing Course & Enrollment Management\n" << endl;
Course oopCourse("CS-247", "Object Oriented Programming", 4, &f, 2); 
Course dsaCourse("CS-247", "Data Structures", 4, &f, 4); 
cout << "[Testing == Operator]:" << endl;
if (oopCourse == dsaCourse) {
cout << "Alert: Both courses share the same Course Code!\n" << endl;
}
cout << "[Testing Enrollment & Exception Handling]:" << endl;
try {
cout << "Enrolling Student 1 (Arham)";
oopCourse.enrollStudent(); 
cout << "Enrolling Student 2 (Dua) ";
oopCourse.enrollStudent(); 
cout << "Enrolling Student 3 (Zara) ";
oopCourse.enrollStudent(); 
}
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
cout << "\n            \n" << endl;
cout << "Module 3: Testing Library System \n" << endl;
Library library;
library.addItem(new Book("B101", "OOP Basics", "Robert Lafore", 2018, "978-123", "Programming", 3));
library.addItem(new Journal("J201", "AI Research", "HITEC Journal", 2024, "ISSN-456", 2, 5));
library.displayCatalog();
LibraryItem *foundItem = library.searchByTitle("OOP Basics");
if (foundItem != NULL) {
cout << "\nSearched Item Found:" << endl;
foundItem->displayInfo();
}
else {
cout << "Item not found." << endl;
}
library.issueItem("25-CS-41", "B101");
try {
library.returnItem("25-CS-41", "B101", 2);
}
catch (OverdueException& e) {
cout << e.what() << endl;
}
library.saveToFile("library_catalog.txt");
library.loadFromFile("library_catalog.txt");
cout << "\n              \n" << endl;
cout << " Module 5: Testing Hostel Management\n" << endl;
HostelBlock blockA("A");
blockA.addRoom(Room(101, "single", 1));
blockA.addRoom(Room(102, "double", 1));
blockA.addRoom(Room(201, "triple", 2));
HostelManager hostelManager;
hostelManager.addBlock(blockA);
hostelManager.allocateRoom(&s);
hostelManager.generateReport();
hostelManager.vacateRoom(&s);
hostelManager.generateReport();
return 0;
}