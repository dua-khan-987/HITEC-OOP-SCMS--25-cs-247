#include "HostelManager.h"
#include <sstream>
HostelManager::HostelManager(int blockCount) : blockCount(blockCount) {
    blocks = new HostelBlock[blockCount];}
HostelManager::~HostelManager() {
    delete[] blocks;}
int HostelManager::getBlockCount() const { return blockCount; }
HostelBlock* HostelManager::getBlock(int index) {
    if (index < 0 || index >= blockCount) {
        return nullptr;
    }
    return &blocks[index];}
const HostelBlock* HostelManager::getBlock(int index) const {
    if (index < 0 || index >= blockCount) {
        return nullptr;}
    return &blocks[index];}
bool HostelManager::setBlock(int index, const HostelBlock& block) {
    if (index < 0 || index >= blockCount) {
        return false;}
    blocks[index] = block;
    return true;
}
bool HostelManager::allocateRoom(Student* student) {
    for (int i = 0; i < blockCount; ++i) {
        if (blocks[i].allocateStudent(student)) {
            return true;}}
    return false;
}
bool HostelManager::vacateRoom(Student* student) {
    for (int i = 0; i < blockCount; ++i) {
        if (blocks[i].vacateStudent(student))    return true;}}
    return false;
}
std::string HostelManager::generateReport() const {
    std::stringstream report;
    int totalOccupants = 0;
    int totalCapacity = 0;
report << "Hostel Occupancy Report\n";
report << "             \n";
    for (int i = 0; i < blockCount; ++i) {
        int blockOccupants = blocks[i].getTotalOccupants();
        int blockCapacity = blocks[i].getTotalCapacity();
        totalOccupants += blockOccupants;
        totalCapacity += blockCapacity;
        report << "Block: " << blocks[i].getBlockName()<< " | Occupants: " << blockOccupants<< " | Capacity: " << blockCapacity << "\n";
    }
report << "Total Occupants: " << totalOccupants << "\n";
    report << "Total Capacity: " << totalCapacity << "\n";
    return report.str();
}
void HostelManager::displayOccupancyReport() const {
    std::cout << generateReport();
}
