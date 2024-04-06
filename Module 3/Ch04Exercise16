#include <iostream>

// Constants
const double FIXED_ROYALTY_DELIVERY = 5000;
const double FIXED_ROYALTY_PUBLICATION = 20000;
const double ROYALTY_RATE_OPTION_2 = 0.125;
const double ROYALTY_RATE_OPTION_3_FIRST_4000 = 0.1;
const double ROYALTY_RATE_OPTION_3_AFTER_4000 = 0.14;
const int COPIES_THRESHOLD_OPTION_3 = 4000;

// Function to calculate royalties for each option
void calculateRoyalties(double netPricePerCopy, int estimatedCopiesSold) {
    // Option 1
    double royaltiesOption1 = FIXED_ROYALTY_DELIVERY + FIXED_ROYALTY_PUBLICATION;

    // Option 2
    double royaltiesOption2 = ROYALTY_RATE_OPTION_2 * netPricePerCopy * estimatedCopiesSold;

    // Option 3
    double royaltiesOption3;
    if (estimatedCopiesSold <= COPIES_THRESHOLD_OPTION_3) {
        royaltiesOption3 = ROYALTY_RATE_OPTION_3_FIRST_4000 * netPricePerCopy * estimatedCopiesSold;
    } else {
        royaltiesOption3 = (ROYALTY_RATE_OPTION_3_FIRST_4000 * netPricePerCopy * COPIES_THRESHOLD_OPTION_3) + 
                           (ROYALTY_RATE_OPTION_3_AFTER_4000 * netPricePerCopy * (estimatedCopiesSold - COPIES_THRESHOLD_OPTION_3));
    }

    // Output
    std::cout << "Option 1: $" << royaltiesOption1 << std::endl;
    std::cout << "Option 2: $" << royaltiesOption2 << std::endl;
    std::cout << "Option 3: $" << royaltiesOption3 << std::endl;

    // Determine the best option
    if (royaltiesOption1 > royaltiesOption2 && royaltiesOption1 > royaltiesOption3) {
        std::cout << "The best option is Option 1 with $" << royaltiesOption1 << std::endl;
    } else if (royaltiesOption2 > royaltiesOption1 && royaltiesOption2 > royaltiesOption3) {
        std::cout << "The best option is Option 2 with $" << royaltiesOption2 << std::endl;
    } else {
        std::cout << "The best option is Option 3 with $" << royaltiesOption3 << std::endl;
    }
}

int main() {
    // Input
    double netPricePerCopy;
    int estimatedCopiesSold;

    std::cout << "Enter the net price of each copy of the novel: ";
    std::cin >> netPricePerCopy;
    std::cout << "Enter the estimated number of copies that will be sold: ";
    std::cin >> estimatedCopiesSold;

    // Calculate royalties
    calculateRoyalties(netPricePerCopy, estimatedCopiesSold);

    return 0;
}
