#include "Library.h"
#include <fstream>
#include <sstream>
LibraryItem::LibraryItem()
: itemID(""), title(""), author(""), publicationYear(0) {}
LibraryItem::LibraryItem(const std::string& itemID, const std::string& title,
const std::string& author, int publicationYear): itemID(itemID), title(title), author(author),
publicationYear(publicationYear) {}
std::string LibraryItem::getItemID() const { return itemID; }
std::string LibraryItem::getTitle() const { return title; }
std::string LibraryItem::getAuthor() const { return author; }
int LibraryItem::getPublicationYear() const { return publicationYear; }
void LibraryItem::setItemID(const std::string& itemID) { this->itemID = itemID; }
void LibraryItem::setTitle(const std::string& title) { this->title = title; }
void LibraryItem::setAuthor(const std::string& author) { this->author = author; }
void LibraryItem::setPublicationYear(int publicationYear) {
    this->publicationYear = publicationYear;
}
OverdueException::OverdueException(double fineAmount)
    : message("Overdue item returned. Fine amount: Rs. " +
              std::to_string(fineAmount)),
      fineAmount(fineAmount) {}
const char* OverdueException::what() const noexcept {
    return message.c_str();
}
double OverdueException::getFineAmount() const {
    return fineAmount;
}
Library::Library(int capacity)
    : capacity(capacity), itemCount(0), issuedCount(0) {
    items = new LibraryItem*[capacity];
    issuedRecords = new IssuedRecord[capacity];
    for (int i = 0; i < capacity; ++i) {
        items[i] = nullptr;
    }
}
Library::~Library() {
    for (int i = 0; i < itemCount; ++i) {
        delete items[i];
    }
    delete[] items;
    delete[] issuedRecords;
}
bool Library::addItem(LibraryItem* item) {
    if (itemCount >= capacity || item == nullptr) {
        return false;
    }
    items[itemCount++] = item;
    return true;
}
LibraryItem* Library::searchByTitle(const std::string& searchTitle) const {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i] != nullptr && items[i]->getTitle() == searchTitle) {
            return items[i];
        }
    }
    return nullptr;
}
LibraryItem* Library::searchByID(const std::string& itemID) const {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i] != nullptr && items[i]->getItemID() == itemID) {
            return items[i];
        }
    }
    return nullptr;
}
bool Library::issueItem(const std::string& rollNo, const std::string& itemID) {
    LibraryItem* item = searchByID(itemID);
    if (item == nullptr || issuedCount >= capacity || !item->checkout()) {
        return false;
    }
    issuedRecords[issuedCount].rollNo = rollNo;
    issuedRecords[issuedCount].itemID = itemID;
    issuedRecords[issuedCount].daysIssued = 0;
    ++issuedCount;
    return true;
}
void Library::returnItem(const std::string& rollNo, const std::string& itemID,int daysIssued) {
    const int allowedDays = 16;
    const double finePerDay = 80.0;
    if (daysIssued > allowedDays) {
        double fine = (daysIssued - allowedDays) * finePerDay;
        throw OverdueException(fine);
    }
    for (int i = 0; i < issuedCount; ++i) {
        if (issuedRecords[i].rollNo == rollNo &&
issuedRecords[i].itemID == itemID) {
issuedRecords[i] = issuedRecords[issuedCount - 1];
    --issuedCount;
            return;
        }}
}
void Library::displayCatalog() const {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i] != nullptr) {
 items[i]->displayInfo();
  std::cout << ",,,.,,,\n";
 }
    }
}
void Library::displayIssuedRecords() const {
    for (int i = 0; i < issuedCount; ++i) {
        std::cout << "Roll No: " << issuedRecords[i].rollNo<< " | Item ID: " << issuedRecords[i].itemID<< " | Days Issued: " << issuedRecords[i].daysIssued << "\n";
    }
}
bool Library::saveCatalog(const std::string& fileName) const {
    std::ofstream outFile(fileName);
    if (!outFile) {
        return false;
    }
    for (int i = 0; i < itemCount; ++i) {
        if (items[i] != nullptr) {
            outFile << items[i]->toFileString() << "\n";
        }
    }
    return true;
}
bool Library::loadCatalog(const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        return false;
    }

    for (int i = 0; i < itemCount; ++i) {
        delete items[i];
        items[i] = nullptr;
    }
    itemCount = 0;
    std::string line;
    while (std::getline(inFile, line) && itemCount < capacity) {
        std::stringstream ss(line);
        std::string type;
        std::string parts[9];
        int index = 0;
        while (index < 9 && std::getline(ss, parts[index], '|')) {
            ++index;
        }
        type = parts[0];
        if (type == "BOOK" && index >= 8) {
            addItem(new Book(parts[1], parts[2], parts[3], std::stoi(parts[4]),
                             parts[5], parts[6], std::stoi(parts[7])));
        } else if (type == "JOURNAL" && index >= 9) {
            addItem(new Journal(parts[1], parts[2], parts[3], std::stoi(parts[4]),
                                parts[5], std::stoi(parts[6]),
                                std::stoi(parts[7]), parts[8] == "1"));
        }
    }

    return true;
}

int Library::getItemCount() const { return itemCount; }
int Library::getIssuedCount() const { return issuedCount; }
