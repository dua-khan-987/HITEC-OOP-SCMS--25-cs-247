#ifndef HOSTELBLOCK_H
#define HOSTELBLOCK_H
#include "Room.h"
class HostelBlock {
private:
    std::string blockName;
    Room* rooms;
    int roomCount;
public:
    HostelBlock();
       HostelBlock(const std::string& blockName, int roomCount);
         HostelBlock(const HostelBlock& other);
    HostelBlock& operator=(const HostelBlock& other);
       ~HostelBlock();
    std::string getBlockName() const;
       int getRoomCount() const;
    Room* getRoom(int index);
    const Room* getRoom(int index) const;
                   void setBlockName(const std::string& blockName);
                 bool setRoom(int index, const Room& room);
    bool allocateStudent(Student* student);
    bool vacateStudent(Student* student);
        int getTotalOccupants() const;
    int getTotalCapacity() const;
    void displayBlock() const;
};
#endif 
