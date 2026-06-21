#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
#include <string>
class LibraryItem {
protected:
    std::string itemID;
std::string title;
 std::string author;
    int publicationYear;
public:
    LibraryItem();
 LibraryItem(const std::string& itemID, const std::string& title, const std::string& author, int publicationYear);
    virtual ~LibraryItem() = default;
    std::string getItemID() const;
 std::string getTitle() const;
std::string getAuthor() const;
    int getPublicationYear() const;
 void setItemID(const std::string& itemID);
    void setTitle(const std::string& title);
void setAuthor(const std::string& author);
    void setPublicationYear(int publicationYear);
virtual bool checkout() = 0;
virtual void displayInfo() const = 0;
    virtual std::string toFileString() const = 0;
};
#endif 
