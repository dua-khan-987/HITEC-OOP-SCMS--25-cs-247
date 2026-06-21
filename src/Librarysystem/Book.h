#ifndef BOOK_H
#define BOOK_H
#include "LibraryItem.h"
class Book : public LibraryItem {
private:
    std::string isbn;
std::string genre;
    int copiesAvailable;
public:
    Book();
    Book(const std::string& itemID, const std::string& title,
const std::string& author, int publicationYear,
         const std::string& isbn, const std::string& genre,
         int copiesAvailable);
std::string getISBN() const;
std::string getGenre() const;
    int getCopiesAvailable() const;
    void setISBN(const std::string& isbn);
    void setGenre(const std::string& genre);
void setCopiesAvailable(int copiesAvailable);
    bool checkout() override;
    void displayInfo() const override;
    std::string toFileString() const override;
};

#endif 