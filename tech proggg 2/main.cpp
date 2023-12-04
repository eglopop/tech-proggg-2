#include "Note.h"
#include "BirthdayNote.h"
#include <vector>
#include <algorithm>

// Функция для поиска людей по месяцу рождения
void searchByBirthMonth(const std::vector<Note*>& notes, int searchMonth) {
    bool found = false;

    for (const auto& note : notes) {
        const BirthdayNote* bNote = dynamic_cast<const BirthdayNote*>(note);
        if (bNote && bNote->getBirthday()[1] == searchMonth) {
            std::cout << "Found: " << *bNote << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No birthdays found for the specified month." << std::endl;
    }
}

int main() {
    std::vector<Note*> notes;

    char choice;
    do {
        std::cout << "Enter data for a person:" << std::endl;

        BirthdayNote* note = new BirthdayNote;
        std::cin >> *note;

        notes.push_back(note);

        std::cout << "Do you want to enter data for another person? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    // Сортировка записей по фамилии
    std::sort(notes.begin(), notes.end(), [](const Note* a, const Note* b) {
        return strcmp(a->getLastName(), b->getLastName()) < 0;
    });

    // Вывод отсортированных записей
    std::cout << "\nSorted List of People:" << std::endl << std::endl;
    for (const auto& note : notes) {
        std::cout << *note << std::endl;
    }

    // Поиск по месяцу дня рождения
    int searchMonth;
    std::cout << "Enter the birth month to search: " << std::endl;
    std::cin >> searchMonth;

    searchByBirthMonth(notes, searchMonth);

    // Освобождение памяти
    for (const auto& note : notes) {
        delete note;
    }

    return 0;
}