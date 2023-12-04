#include "BirthdayNote.h"

BirthdayNote::BirthdayNote() : Note(), birthday{ 0, 0, 0 } {
    std::cout << "Default constructor called for BirthdayNote object." << std::endl;
}

BirthdayNote::BirthdayNote(const char* last, const char* first, const char* phone, int day, int month, int year)
    : Note(last, first, phone), birthday{ day, month, year } {}

BirthdayNote::~BirthdayNote() {
    std::cout << "Destructor called for BirthdayNote object." << std::endl;
}

const int* BirthdayNote::getBirthday() const {
    return birthday;
}

void BirthdayNote::setBirthday(int day, int month, int year) {
    birthday[0] = day;
    birthday[1] = month;
    birthday[2] = year;
}

std::ostream& operator<<(std::ostream& os, const BirthdayNote& note) {
    os << static_cast<const Note&>(note) << "\nBirthday: " << note.getBirthday()[0]
        << "." << note.getBirthday()[1] << "." << note.getBirthday()[2];
    return os;
}

std::istream& operator>>(std::istream& is, BirthdayNote& note) {
    is >> static_cast<Note&>(note);

    std::cout << "Enter Birthday (day month year): ";
    is >> note.birthday[0] >> note.birthday[1] >> note.birthday[2];

    return is;
}