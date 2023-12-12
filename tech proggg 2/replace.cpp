#include "replace.h"
void processAndPrintText(const std::string& inputFilePath) {
    system("chcp 1251");
    auto isVowel = [](char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    };

    std::ifstream inputFile(inputFilePath);

    if (inputFile.is_open()) {
        std::ostringstream buffer;
        buffer << inputFile.rdbuf();
        std::string inputText = buffer.str();

        std::cout << "Исходный текст:\n" << inputText << "\n\n";

        std::istringstream stream(inputText);
        std::ostringstream result;

        std::string word;
        while (stream >> word) {
            if (isVowel(word[0])) {
                result << (char)toupper(word[0]) << word.substr(1);
            }
            else {
                result << word;
            }

            result << ' ';
        }

        std::cout << "Текст с измененными гласными:\n" << result.str() << "\n";

        inputFile.close();
    }
    else {
        std::cerr << "Ошибка открытия файла: " << inputFilePath << std::endl;
    }
}