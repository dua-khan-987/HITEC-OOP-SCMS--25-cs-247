#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Journal.h"
#include <exception>
struct IssuedRecord {
    std::string rollNo;
    std::string itemID;
    int daysIssued;
};
class OverdueException : public std::exception {
private:
    std::string message;
    double fineAmount;
public:
    explicit OverdueException(double fineAmount);
 const char* what() const noexcept override;
    double getFineAmount() const;
};
class Library {
private:
    LibraryItem** items;
IssuedRecord* issuedRecords;
    int capacity;
    int itemCount;
    int issuedCount;
public:
    explicit Library(int capacity = 100);
    ~Library();
bool addItem(LibraryItem* item);
    LibraryItem* searchByTitle(const std::string& searchTitle) const;
    LibraryItem* searchByID(const std::string& itemID) const;
bool issueItem(const std::string& rollNo, const std::string& itemID);
    void returnItem(const std::string& rollNo, const std::string& itemID,
int daysIssued);
void displayCatalog() const;
    void displayIssuedRecords() const;
bool saveCatalog(const std::string& fileName) const;
    bool loadCatalog(const std::string& fileName);
    int getItemCount() const;
    int getIssuedCount() const;
};
#endif