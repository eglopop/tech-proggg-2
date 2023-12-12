#include "Note.h"
#include "BirthdayNote.h"
#include <vector>
#include <algorithm>
#include "replace.h"
#include <cstring>

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

// Функция для вывода меню пользователя
void printMenu() {
    std::cout << "\nMenu:\n"
        << "1. Add new person\n"
        << "2. Edit a person's information\n"
        << "3. Delete a person\n"
        << "4. Display sorted list of people\n"
        << "5. Search by birth month\n"
        << "6. task2\n"
        << "7. Exit\n";
}

int main() {
    std::vector<Note*> notes;
    const std::string inputFilePath = "input.txt";

    char choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1': // Add new person
        {
            std::cout << "Enter data for a new person:" << std::endl;
            BirthdayNote* note = new BirthdayNote;
            std::cin >> *note;

            // Добавление нового человека в конец списка
            notes.push_back(note);
            break;
        }
        case '2': // Edit a person's information
        {
            int index;
            std::cout << "Enter the index of the person you want to edit: ";
            std::cin >> index;

            if (index >= 0 && index < notes.size()) {
                std::cout << "Enter new data for the person:" << std::endl;
                std::cin >> *notes[index];
            }
            else {
                std::cout << "Invalid index." << std::endl;
            }
            break;
        }
        case '3': // Delete a person
        {
            int index;
            std::cout << "Enter the index of the person you want to delete: ";
            std::cin >> index;

            if (index >= 0 && index < notes.size()) {
                delete notes[index];
                notes.erase(notes.begin() + index);
            }
            else {
                std::cout << "Invalid index." << std::endl;
            }
            break;
        }
        case '4': // Display sorted list of people
            // Сортировка записей по фамилии
            std::sort(notes.begin(), notes.end(), [](const Note* a, const Note* b) {
                return strcmp(a->getLastName(), b->getLastName()) < 0;
                });

            // Вывод отсортированных записей
            std::cout << "\nSorted List of People:" << std::endl;
            for (const auto& note : notes) {
                std::cout << *note << std::endl;
            }
            break;
        case '5': // Search by birth month
        {
            int searchMonth;
            std::cout << "Enter the birth month to search: ";
            std::cin >> searchMonth;

            searchByBirthMonth(notes, searchMonth);
            break;
        }
        case '6': // Exit
                processAndPrintText(inputFilePath);
            break;
        case '7':
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        }

    } while (choice != '6');

    // Освобождение памяти
    for (const auto& note : notes) {
        delete note;
    }

    return 0;
}