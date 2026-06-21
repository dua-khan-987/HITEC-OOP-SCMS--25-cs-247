#include "Journal.h"
Journal::Journal(): LibraryItem(), issn(""), volume(0), issueNumber(0), available(true) {}
Journal::Journal(const std::string& itemID, const std::string& title,
const std::string& author, int publicationYear,
const std::string& issn, int volume, int issueNumber,
bool available) : LibraryItem(itemID, title, author, publicationYear),
issn(issn), volume(volume), issueNumber(issueNumber),available(available) {}
std::string Journal::getISSN() const { return issn; }
int Journal::getVolume() const { return volume; }
int Journal::getIssueNumber() const { return issueNumber; }
bool Journal::isAvailable() const { return available; }
void Journal::setISSN(const std::string& issn) { this->issn = issn; }
void Journal::setVolume(int volume) { this->volume = volume; }
void Journal::setIssueNumber(int issueNumber) { this->issueNumber = issueNumber; }
void Journal::setAvailable(bool available) { this->available = available; }
bool Journal::checkout() {
    if (!available) {
        return false;
    }
    available = false;
    return true;
}
void Journal::displayInfo() const {
    std::cout << "Journal ID: " << itemID<< "\nTitle: " << title<< "\nAuthor: " << author
<< "\nYear: " << publicationYear<< "\nISSN: " << issn<< "\nVolume: " << volume
<< "\nIssue Number: " << issueNumber<< "\nAvailable: " << (available ? "Yes" : "No") << "\n";
}
std::string Journal::toFileString() const {
    return "JOURNAL|" + itemID + "|" + title + "|" + author + "|" +std::to_string(publicationYear) + "|" + issn + "|" +
std::to_string(volume) + "|" + std::to_string(issueNumber) + "|" +(available ? "1" : "0");
}