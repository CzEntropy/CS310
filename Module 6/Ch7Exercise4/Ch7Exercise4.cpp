#include <iostream>
#include <string>

// Function to check if a character is a vowel
bool isVowel(char ch) {
    ch = tolower(ch); // Convert to lowercase for case insensitivity
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Function to remove all vowels from a string
std::string removeVowels(const std::string& str) {
    std::string result = "";
    for (char ch : str) {
        if (!isVowel(ch)) {
            result += ch;
        }
    }
    return result;
}

int main() {
    std::string input;

    // Prompt the user to input a string
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Remove vowels from the input string
    std::string result = removeVowels(input);

    // Output the string without vowels
    std::cout << "String without vowels: " << result << std::endl;

    return 0;
}
