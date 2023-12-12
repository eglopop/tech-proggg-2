#define _CRT_SECURE_NO_WARNINGS
#include "Note.h"
#include <cstring>

Note::Note() : lastName(nullptr), firstName(nullptr), phoneNumber(nullptr) {
    std::cout << "Default constructor called for Note object." << std::endl;
}

Note::Note(const char* last, const char* first, const char* phone) :
    lastName(nullptr), firstName(nullptr), phoneNumber(nullptr) {
    setLastName(last);
    setFirstName(first);
    setPhoneNumber(phone);
}

Note::Note(const Note& other) : lastName(nullptr), firstName(nullptr), phoneNumber(nullptr) {
    setLastName(other.lastName);
    setFirstName(other.firstName);
    setPhoneNumber(other.phoneNumber);
}

Note::~Note() {
    delete[] lastName;
    delete[] firstName;
    delete[] phoneNumber;
    std::cout << "Destructor called for Note object." << std::endl;
}

const char* Note::getLastName() const {
    return lastName;
}

const char* Note::getFirstName() const {
    return firstName;
}

const char* Note::getPhoneNumber() const {
    return phoneNumber;
}

void Note::setLastName(const char* last) {
    delete[] lastName;
    lastName = new char[strlen(last) + 1];
    strcpy(lastName, last);
}

void Note::setFirstName(const char* first) {
    delete[] firstName;
    firstName = new char[strlen(first) + 1];
    strcpy(firstName, first);
}

void Note::setPhoneNumber(const char* phone) {
    delete[] phoneNumber;
    phoneNumber = new char[strlen(phone) + 1];
    strcpy(phoneNumber, phone);
}

Note& Note::operator=(const Note& other) {
    if (this != &other) {
        setLastName(other.lastName);
        setFirstName(other.firstName);
        setPhoneNumber(other.phoneNumber);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Note& note) {
    os << "Last Name: " << note.lastName << "\nFirst Name: " << note.firstName
        << "\nPhone Number: " << note.phoneNumber << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Note& note) {
    char last[100], first[100], phone[100];
    std::cout << "Enter Last Name: ";
    is >> last;
    note.setLastName(last);

    std::cout << "Enter First Name: ";
    is >> first;
    note.setFirstName(first);

    std::cout << "Enter Phone Number: ";
    is >> phone;
    note.setPhoneNumber(phone);

    return is;
}
const int* Note::getBirthday() const {
    return nullptr; // Note не содержит информации о дате рождения
}