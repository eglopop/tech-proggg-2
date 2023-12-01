#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class NOTE {
public:
    std::string lastName;
    std::string firstName;
    std::string phoneNumber;
    int birthDate[3]; // День, месяц, год

    // Конструктор класса
    NOTE(std::string last, std::string first, std::string phone, int day, int month, int year) {
        lastName = last;
        firstName = first;
        phoneNumber = phone;
        birthDate[0] = day;
        birthDate[1] = month;
        birthDate[2] = year;
    }

    // Методы доступа
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getPhoneNumber() const { return phoneNumber; }
    int getDay() const { return birthDate[0]; }
    int getMonth() const { return birthDate[1]; }
    int getYear() const { return birthDate[2]; }
};

// Перегруженные операции для объектов типа NOTE
std::ostream& operator<<(std::ostream& os, const NOTE& note) {
    os << note.getLastName() << " " << note.getFirstName() << "\t" << note.getPhoneNumber() << "\t"
        << note.getDay() << "." << note.getMonth() << "." << note.getYear();
    return os;
}

bool operator<(const NOTE& note1, const NOTE& note2) {
    return note1.getLastName() < note2.getLastName();
}

int main() {
    std::vector<NOTE> notes; // Вектор объектов типа NOTE

    // Ввод информации о людях
    std::cout << "Введите информацию о людях (для завершения введите exit):\n";
    while (true) {
        std::string last, first, phone;
        int day, month, year;

        std::cout << "Фамилия: ";
        std::cin >> last;
        if (last == "exit") break;

        std::cout << "Имя: ";
        std::cin >> first;

        std::cout << "Номер телефона: ";
        std::cin >> phone;

        std::cout << "День рождения (дд мм гггг): ";
        std::cin >> day >> month >> year;

        notes.push_back(NOTE(last, first, phone, day, month, year));
    }

    // Сортировка записей по алфавиту
    std::sort(notes.begin(), notes.end());

    // Вывод информации о людях с днями рождения в указанном месяце
    int searchMonth;
    std::cout << "Введите номер месяца для поиска (1-12): ";
    std::cin >> searchMonth;

    bool found = false;
    for (const auto& note : notes) {
        if (note.getMonth() == searchMonth) {
            std::cout << note << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Нет записей с днями рождения в указанном месяце." << std::endl;
    }

    return 0;
}