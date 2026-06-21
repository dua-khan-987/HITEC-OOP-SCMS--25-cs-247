#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
class Student;
class Room {
private:
    static const int MAX_OCCUPANTS = 3;
    int roomNumber;
 std::string type;
    int floor;
    Student* occupants[MAX_OCCUPANTS];
int occupantCount;
int capacity;
    int capacityFromType(const std::string& roomType) const;
public:
    Room();
    Room(int roomNumber, const std::string& type, int floor);
    int getRoomNumber() const;
    std::string getType() const;
    int getFloor() const;
    int getOccupantCount() const;
    int getCapacity() const;
    void setRoomNumber(int roomNumber);
    void setType(const std::string& type);
    void setFloor(int floor);
    bool hasSpace() const;
    bool hasStudent(Student* student) const;
    bool addOccupant(Student* student);
    bool removeOccupant(Student* student);
    void displayRoom() const;
};
#endif 
