#ifndef JOURNAL_H
#define JOURNAL_H
#include "LibraryItem.h"
class Journal : public LibraryItem {
private:
std::string issn;
int volume;
int issueNumber;
bool available;
public:
    Journal();
    Journal(const std::string& itemID, const std::string& title,
            const std::string& author, int publicationYear,
const std::string& issn, int volume, int issueNumber,
            bool available = true);
    std::string getISSN() const;
int getVolume() const;
    int getIssueNumber() const;
    bool isAvailable() const;
    void setISSN(const std::string& issn);
    void setVolume(int volume);
    void setIssueNumber(int issueNumber);
    void setAvailable(bool available);
    bool checkout() override;
    void displayInfo() const override;
    std::string toFileString() const override;
};
#endif 