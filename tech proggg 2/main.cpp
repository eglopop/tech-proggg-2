#include "Note.h"
#include "BirthdayNote.h"
#include <vector>
#include <algorithm>
#include "replace.h"
#include <cstring>

// ������� ��� ������ ����� �� ������ ��������
void searchByBirthMonth(const std::vector<Note*>& notes, int searchMonth) {
    bool found = false;

    for (const auto& note : notes) {
        const BirthdayNote* bNote = dynamic_cast<const BirthdayNote*>(note);
        if (bNote && bNote->getBirthday()[1] == searchMonth) {
            std::cout << "�������: " << *bNote << std::endl ;
            found = true;
        }
    }

    if (!found) {
        std::cout << "��� �������� �� ��������� ����� �� �������." << std::endl;
    }
}

// ������� ��� ������ ���� ������������
void printMenu() {
    std::cout << "\nMenu:\n"
        << "1. �������� ��������\n"
        << "2. ������������� ���������� \n"
        << "3. ������� ��������\n"
        << "4. �������� ��������������� ������\n"
        << "5. ������ ����� �� ������ ��������\n"
        << "6. 2 �������\n"
        << "7. �����\n";
}

int main() {
    system("chcp 1251");
    std::vector<Note*> notes;
    const std::string inputFilePath = "input.txt";

    char choice;
    do {
        printMenu();
        std::cout << "������� �������: ";
        std::cin >> choice;

        switch (choice) {
        case '1': // Add new person
        {
            std::cout << "������� ������ ��� ������ ��������:" << std::endl;
            BirthdayNote* note = new BirthdayNote;
            std::cin >> *note;

            // ���������� ������ �������� � ����� ������
            notes.push_back(note);
            break;
        }
        case '2': // Edit a person's information
        {
            int index;
            std::cout << "������� ������ ��������, �������� �� ������ ���������������: ";
            std::cin >> index;

            if (index >= 0 && index < notes.size()) {
                std::cout << "������� ����� ������ ��� ����� ��������:" << std::endl;
                std::cin >> *notes[index];
            }
            else {
                std::cout << "������������ ������." << std::endl;
            }
            break;
        }
        case '3': // Delete a person
        {
            int index;
            std::cout << "������� ������ ��������, �������� �� ������ �������: ";
            std::cin >> index;

            if (index >= 0 && index < notes.size()) {
                delete notes[index];
                notes.erase(notes.begin() + index);
            }
            else {
                std::cout << "������������ ������." << std::endl;
            }
            break;
        }
        case '4': // Display sorted list of people
            // ���������� ������� �� �������
            std::sort(notes.begin(), notes.end(), [](const Note* a, const Note* b) {
                return strcmp(a->getLastName(), b->getLastName()) < 0;
                });

            // ����� ��������������� �������
            std::cout << "\n��������������� ������ �����:" << std::endl;
            for (const auto& note : notes) {
                std::cout << *note << std::endl;
            }
            break;
        case '5': // Search by birth month
        {
            int searchMonth;
            std::cout << "������� ����� �������� ��� ������: ";
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
            std::cout << "�������� �����. ����������, ������� ����� �� 1 �� 6." << std::endl;
        }

    } while (choice != '6');

    // ������������ ������
    for (const auto& note : notes) {
        delete note;
    }

    return 0;
}