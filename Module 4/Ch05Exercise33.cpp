//Cristian Taylor
//5/25/2024
//This is a  C++ program that helps  the user calculate how many dishes one can make 
//in a given amount of time.
#include <iostream>
#include <conio.h>


int main() {
    // Prompt the user for input values
    int a, b, t;
    std::cout << "Enter the time to prepare the first dish (in minutes): ";
    std::cin >> a;
    std::cout << "Enter the additional time for each subsequent dish (in minutes): ";
    std::cin >> b;
    std::cout << "Enter the total time available (in minutes): ";
    std::cin >> t;

    // Initialize variables
    int total_time = 0;
    int dish_count = 0;
    int current_dish_time = a;

    // Calculate the number of dishes
    while (total_time + current_dish_time <= t) {
        total_time += current_dish_time;
        dish_count++;
        current_dish_time += b;
    }

    // Output the result
    std::cout << "Bianca can prepare " << dish_count << " dishes in " << t << " minutes." << std::endl;
   
    getch();
    return 0;

}
