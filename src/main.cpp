#include <iostream>
#include "person/Student.h"
#include "person/Faculty.h"
#include "person/Staff.h"
using namespace std;
int main()
{
cout << "=== Smart Campus Management System ===" << endl;
Student s("Arham", "15432", 17, "8906", "25-CS-41", 3, 3.9);
Faculty f("Ayesha", "65409", 19, "1111", "G241", "CS", "Lecturer");
Staff st("Hashir", "14521", 25, "0353", "D341", "Clerk", 60000);
s.displayInfo();
s.calculateGrade();
f.displayInfo();
st.displayInfo();
return 0;
}