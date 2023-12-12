#ifndef NOTE_H
#define NOTE_H

#include <iostream>

class Note {
private:
    char* lastName;
    char* firstName;
    char* phoneNumber;

public:
    Note();
    Note(const char* last, const char* first, const char* phone);
    Note(const Note& other);
    virtual ~Note(); // Сделаем деструктор виртуальным

    virtual const int* getBirthday() const;
    const char* getLastName() const;
    const char* getFirstName() const;
    const char* getPhoneNumber() const;

    void setLastName(const char* last);
    void setFirstName(const char* first);
    void setPhoneNumber(const char* phone);

    Note& operator=(const Note& other);
    friend std::ostream& operator<<(std::ostream& os, const Note& note);
    friend std::istream& operator>>(std::istream& is, Note& note);
};

#endif

