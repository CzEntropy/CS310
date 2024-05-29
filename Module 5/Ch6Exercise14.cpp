//Cristian Taylor
//5/28/2024
//This is a  C++ program that outputs the billing amount of J&J accounting based on user inputs ( hourly rate, total consulting time, and amount of income).
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

double calculate_billing_amount(double hourly_rate, int consulting_time, bool is_low_income) {
    if (is_low_income) {
        if (consulting_time <= 30) {
            return 0.0;
        } else {
            int excess_time = consulting_time - 30;
            double billing_amount = hourly_rate * 0.40 * (excess_time / 60.0);
            return billing_amount;
        }
    } else {
        if (consulting_time <= 20) {
            return 0.0;
        } else {
            int excess_time = consulting_time - 20;
            double billing_amount = hourly_rate * 0.70 * (excess_time / 60.0);
            return billing_amount;
        }
    }
}

int main() {
    double hourly_rate;
    int consulting_time;
    char low_income_char;
    bool is_low_income;

    cout << "Enter the hourly rate: ";
    cin >> hourly_rate;

    cout << "Enter the consulting time in minutes: ";
    cin >> consulting_time;

    cout << "Does the person have low income? (y/n): ";
    cin >> low_income_char;
    is_low_income = (low_income_char == 'y' || low_income_char == 'Y');

    double billing_amount = calculate_billing_amount(hourly_rate, consulting_time, is_low_income);

    cout << fixed << setprecision(2);
    cout << "The billing amount is: $" << billing_amount << endl;

    getch();
    return 0;
}

