#include <string>
#include <sstream>

int countWordsInFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return -1; // Return -1 to indicate an error
    }

    std::string word;
    int wordCount = 0;

    while (file >> word) {
        wordCount++;
    }

    file.close();
    return wordCount;
}

int main() {
    std::string filename;

    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;

    int wordCount = countWordsInFile(filename);

    if (wordCount >= 0) {
        std::cout << "Total word count in the file: " << wordCount << std::endl;
    }

    return 0;
}
