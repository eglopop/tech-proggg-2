#ifndef BIRTHDAYNOTE_H
#define BIRTHDAYNOTE_H

#include "Note.h"

class BirthdayNote : public Note {
private:
    int birthday[3]; // Используем нестатический массив

public:
    BirthdayNote();
    BirthdayNote(const char* last, const char* first, const char* phone, int day, int month, int year);
    ~BirthdayNote();

    const int* getBirthday() const;
    void setBirthday(int day, int month, int year);

    friend std::ostream& operator<<(std::ostream& os, const BirthdayNote& note);
    friend std::istream& operator>>(std::istream& is, BirthdayNote& note);
};

#endif