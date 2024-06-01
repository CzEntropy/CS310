//Cristian Taylor
// 5/31/2024
//This is a C++ program that prompts the user to enter a length in feet and inches and outputs the equivalent length in centimeters.
//This program will also detect when a use enters a negative number or a nondigit number,  display the approraite error message , and prompt them to re-enter a number
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <conio.h>

//Negative number error message
class negativeNumber : public std::runtime_error {
public:
    negativeNumber() : std::runtime_error("Negative number entered.") {}
};
//Nonnumber error message
class nonNumber : public std::runtime_error {
public:
    nonNumber() : std::runtime_error("Non-digit character entered.") {}
};
// Feet/Inch to Cenimeter converter.
double convertToCentimeters(double feet, double inches) {
    const double feetToCm = 30.48;
    const double inchToCm = 2.54;
    return (feet * feetToCm) + (inches * inchToCm);
}
// Input validation. Throws nonnumber error if invalid, negative, or decimal
void validateInput(const std::string& input) {
    for (char ch : input) {
        if (!isdigit(ch) && ch != '.' && ch != '-') {
            throw nonNumber();
        }
    }
}
int main() {
    double feet, inches;
    std::string feetInput, inchesInput;

    while (true) {
        try {
            std::cout << "Enter length in feet: ";
            std::getline(std::cin, feetInput);
            validateInput(feetInput);
            feet = std::stod(feetInput);
            if (feet < 0) throw negativeNumber();

            std::cout << "Enter length in inches: ";
            std::getline(std::cin, inchesInput);
            validateInput(inchesInput);
            inches = std::stod(inchesInput);
            if (inches < 0) throw negativeNumber();

            double centimeters = convertToCentimeters(feet, inches);
            std::cout << "Equivalent length in centimeters: " << centimeters << " cm\n";
            break;

        } catch (const negativeNumber& e) {
            std::cerr << "Error: " << e.what() << " Please enter non-negative numbers.\n";
        } catch (const nonNumber& e) {
            std::cerr << "Error: " << e.what() << " Please enter valid numbers.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << " Please enter valid numbers.\n";
        }
    }
    getch();
    return 0;
}

