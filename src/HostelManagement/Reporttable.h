#ifndef REPORTABLE_H
#define REPORTABLE_H
#include "Accommodation.h"
#include <string>
class Reportable : public virtual CampusService {
public:
    virtual ~Reportable() = default;
    virtual std::string generateReport() const = 0;
};
#endif