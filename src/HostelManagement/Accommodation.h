#ifndef ACCOMMODATION_H
#define ACCOMMODATION_H
class Student;
class CampusService {
public:
    virtual ~CampusService() = default;
};
class Accommodation : public virtual CampusService {
public:
    virtual ~Accommodation() = default;
    virtual bool allocateRoom(Student* student) = 0;
    virtual bool vacateRoom(Student* student) = 0;
};
#endif
