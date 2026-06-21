#include "HostelBlock.h"
HostelBlock::HostelBlock() : blockName(""), rooms(nullptr), roomCount(0) {}
HostelBlock::HostelBlock(const std::string& blockName, int roomCount)
    : blockName(blockName), roomCount(roomCount) {
    rooms = new Room[roomCount];
}
HostelBlock::HostelBlock(const HostelBlock& other)
    : blockName(other.blockName), roomCount(other.roomCount) {
    rooms = new Room[roomCount];
    for (int i = 0; i < roomCount; ++i) {
        rooms[i] = other.rooms[i];
    }}
HostelBlock& HostelBlock::operator=(const HostelBlock& other) {
    if (this != &other) {
        delete[] rooms;
        blockName = other.blockName;
             roomCount = other.roomCount;
        rooms = new Room[roomCount];
        for (int i = 0; i < roomCount; ++i) {
            rooms[i] = other.rooms[i];}}
    return *this;}
HostelBlock::~HostelBlock() {
    delete[] rooms;
}
std::string HostelBlock::getBlockName() const { return blockName; }
            int HostelBlock::getRoomCount() const { return roomCount; }
Room* HostelBlock::getRoom(int index) {
    if (index < 0 || index >= roomCount) {
        return nullptr;
    }
    return &rooms[index];}
const Room* HostelBlock::getRoom(int index) const {
    if (index < 0 || index >= roomCount) {
                  return nullptr;
    }
    return &rooms[index];}
void HostelBlock::setBlockName(const std::string& blockName) {
    this->blockName = blockName;
}
bool HostelBlock::setRoom(int index, const Room& room) {
    if (index < 0 || index >= roomCount) {
        return false;}
    rooms[index] = room;
    return true;}
bool HostelBlock::allocateStudent(Student* student) {
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i].addOccupant(student)) {
            return true;
        } }
    return false;}
bool HostelBlock::vacateStudent(Student* student) {
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i].removeOccupant(student)) {
            return true;}}
    return false;}
int HostelBlock::getTotalOccupants() const {
    int total = 0;
    for (int i = 0; i < roomCount; ++i) {
        total += rooms[i].getOccupantCount();
    }
    return total;
}
int HostelBlock::getTotalCapacity() const {
    int total = 0;
    for (int i = 0; i < roomCount; ++i) {
        total += rooms[i].getCapacity();
    }
    return total;
}
void HostelBlock::displayBlock() const {
    std::cout << "Hostel Block: " << blockName << "\n";
    for (int i = 0; i < roomCount; ++i) {
        rooms[i].displayRoom();
    }
}
