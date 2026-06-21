#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H
#include "HostelBlock.h"
#include "Reportable.h"
class HostelManager : public Accommodation, public Reportable {
private:
    HostelBlock* blocks;
    int blockCount;
public:
    explicit HostelManager(int blockCount = 1);
    ~HostelManager();
    int getBlockCount() const;
    HostelBlock* getBlock(int index);
    const HostelBlock* getBlock(int index) const;
    bool setBlock(int index, const HostelBlock& block);
    bool allocateRoom(Student* student) override;
    bool vacateRoom(Student* student) override;
    std::string generateReport() const override;
    void displayOccupancyReport() const;
};
#endif 