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
            std::cout << "нашелся: " << *bNote << std::endl ;
            found = true;
        }
    }

    if (!found) {
        std::cout << "дни рождения за указанный месяц не найдены." << std::endl;
    }
}

// Функция для вывода меню пользователя
void printMenu() {
    std::cout << "\nMenu:\n"
        << "1. добавить человека\n"
        << "2. редактировать информацию \n"
        << "3. удалить человека\n"
        << "4. показать отсортированный список\n"
        << "5. искать людей по месяцу рождения\n"
        << "6. 2 задание\n"
        << "7. выход\n";
}

int main() {
    system("chcp 1251");
    std::vector<Note*> notes;
    const std::string inputFilePath = "input.txt";

    char choice;
    do {
        printMenu();
        std::cout << "введите команду: ";
        std::cin >> choice;

        switch (choice) {
        case '1': // Add new person
        {
            std::cout << "Введите данные для нового человека:" << std::endl;
            BirthdayNote* note = new BirthdayNote;
            std::cin >> *note;

            // Добавление нового человека в конец списка
            notes.push_back(note);
            break;
        }
        case '2': // Edit a person's information
        {
            int index;
            std::cout << "Введите индекс человека, которого вы хотите отредактировать: ";
            std::cin >> index;

            if (index >= 0 && index < notes.size()) {
                std::cout << "Введите новые данные для этого человека:" << std::endl;
                std::cin >> *notes[index];
            }
            else {
                std::cout << "Недопустимый индекс." << std::endl;
            }
            break;
        }
        case '3': // Delete a person
        {
            int index;
            std::cout << "Введите индекс человека, которого вы хотите удалить: ";
            std::cin >> index;

            if (index >= 0 && index < notes.size()) {
                delete notes[index];
                notes.erase(notes.begin() + index);
            }
            else {
                std::cout << "Недопустимый индекс." << std::endl;
            }
            break;
        }
        case '4': // Display sorted list of people
            // Сортировка записей по фамилии
            std::sort(notes.begin(), notes.end(), [](const Note* a, const Note* b) {
                return strcmp(a->getLastName(), b->getLastName()) < 0;
                });

            // Вывод отсортированных записей
            std::cout << "\nОтсортированный список людей:" << std::endl;
            for (const auto& note : notes) {
                std::cout << *note << std::endl;
            }
            break;
        case '5': // Search by birth month
        {
            int searchMonth;
            std::cout << "Введите месяц рождения для поиска: ";
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
            std::cout << "Неверный выбор. Пожалуйста, введите число от 1 до 6." << std::endl;
        }

    } while (choice != '6');

    // Освобождение памяти
    for (const auto& note : notes) {
        delete note;
    }

    return 0;
}