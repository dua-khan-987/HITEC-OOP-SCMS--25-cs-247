#include "Book.h"
Book::Book() : LibraryItem(), isbn(""), genre(""), copiesAvailable(0) {}
Book::Book(const std::string& itemID, const std::string& title,
           const std::string& author, int publicationYear,
    const std::string& isbn, const std::string& genre,
           int copiesAvailable): LibraryItem(itemID, title, author, publicationYear),
      isbn(isbn), genre(genre), copiesAvailable(copiesAvailable) {}
std::string Book::getISBN() const { return isbn; }
std::string Book::getGenre() const { return genre; }
int Book::getCopiesAvailable() const { return copiesAvailable; }
void Book::setISBN(const std::string& isbn) { this->isbn = isbn; }
void Book::setGenre(const std::string& genre) { this->genre = genre; }
void Book::setCopiesAvailable(int copiesAvailable) {
    this->copiesAvailable = copiesAvailable;
}
bool Book::checkout() {
    if (copiesAvailable <= 0) {
        return false;}
    --copiesAvailable;
    return true;
}
void Book::displayInfo() const {
    std::cout << "Book ID: " << itemID<< "\nTitle: " << title<< "\nAuthor: " << author
    << "\nYear: " << publicationYear<< "\nISBN: " << isbn<< "\nGenre: " << genre
    << "\nCopies Available: " << copiesAvailable << "\n";
}
std::string Book::toFileString() const {
    return "BOOK|" + itemID + "|" + title + "|" + author + "|" +std::to_string(publicationYear) + "|" + isbn + "|" + genre + "|" +
           std::to_string(copiesAvailable);
}