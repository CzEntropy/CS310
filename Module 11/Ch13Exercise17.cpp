//Cristian Taylor
//5/26/2024
//This is a  C++ program that uses a random number generator to generate 25 real numbers between 10 and 100.
#include <iostream>
#include <random>
#include <vector>

int main() {
    // Create a random device to seed the random number generator
    std::random_device rd;

    // Use the default random engine and an uniform distribution
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(10.0, 100.0);

    // Generate 25 random numbers
    std::vector<double> random_numbers;
    for (int i = 0; i < 25; ++i) {
        random_numbers.push_back(dis(gen));
    }

    // Print the generated numbers
    std::cout << "Generated random numbers: \n";
    for (const auto& num : random_numbers) {
        std::cout << num << "\n";
    }

    return 0;
}
