#include "Room.h"
Room::Room() : roomNumber(0), type("single"), floor(0), occupantCount(0) {
    capacity = capacityFromType(type);
    for (int i = 0; i < MAX_OCCUPANTS; ++i) {
        occupants[i] = nullptr;
    }}
Room::Room(int roomNumber, const std::string& type, int floor)
    : roomNumber(roomNumber), type(type), floor(floor), occupantCount(0) {
    capacity = capacityFromType(type);
    for (int i = 0; i < MAX_OCCUPANTS; ++i) {
        occupants[i] = nullptr;
    }}
int Room::capacityFromType(const std::string& roomType) const {
    if (roomType == "double") {
        return 2; }
    if (roomType == "triple") {
        return 3;}
    return 1;}
int Room::getRoomNumber() const { return roomNumber; }
std::string Room::getType() const { return type; }
int Room::getFloor() const { return floor; }
int Room::getOccupantCount() const { return occupantCount; }
int Room::getCapacity() const { return capacity; }
void Room::setRoomNumber(int roomNumber) { this->roomNumber = roomNumber; }
void Room::setType(const std::string& type) {
    this->type = type;
    capacity = capacityFromType(type);
    if (occupantCount > capacity) {
        occupantCount = capacity;
    }}
void Room::setFloor(int floor) { this->floor = floor; }

bool Room::hasSpace() const {
    return occupantCount < capacity;
}
bool Room::hasStudent(Student* student) const {
    for (int i = 0; i < occupantCount; ++i) {
        if (occupants[i] == student) {
            return true;
        }}
    return false;}
bool Room::addOccupant(Student* student) {
    if (student == nullptr || !hasSpace() || hasStudent(student)) {
        return false;}
    occupants[occupantCount++] = student;
    return true;}
bool Room::removeOccupant(Student* student) {
    for (int i = 0; i < occupantCount; ++i) {
        if (occupants[i] == student) {
    occupants[i] = occupants[occupantCount - 1];
 occupants[occupantCount - 1] = nullptr;
--occupantCount;
            return true;
        }}
    return false;}
void Room::displayRoom() const {
    std::cout << "Room No: " << roomNumber << " | Type: " << type<< " | Floor: " << floor<< " | Occupants: " << occupantCount << "/" << capacity << "\n";
}
