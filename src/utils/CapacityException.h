#ifndef CAPACITY_EXCEPTION_H
#define CAPACITY_EXCEPTION_H
#include <exception>
using namespace std;
class CapacityExceededException : public exception
{
public:
const char* what() const throw()
{
return "Capacity exceeded!";
}
};
#endif