/*
* Student Name: Jaeyun Jung
* File Name: M10 Discussion; Debugging Assignment
* Date: 5/16/2024
* 
* This simple program uses pointers. 
* The program prompts the user to enter in the radius. Then the program will display the radius, 
* calculate the circumference, and display the area of the circle. (Numbers are rounded to 3 decimal places.) 
* 
* There are 2 errors! Good luck! 
* *Debugged by Cristian Taylor on 5/17*
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std; 

const double PI = 3.1416; // Value  of PI 

void getCircleData(double* radius);
double calculateCircumference(double* radius);
double calculateArea(double* radius);


int main()
{
    //Pointer to hold the radius of the circle
    double radius; // *FIX* doub was a misspelling of the variable 'double'. Corrected.
    double* radiusPtr = &radius; 

    cout << fixed << showpoint << setprecision(3) << endl;

    //Prompt user to input radius of the circle 
    getCircleData(radiusPtr); 

    //Calculate the circumference and area using the pointer
    double circumference = calculateCircumference(radiusPtr);
    double area = calculateArea(radiusPtr);

    //Display results

    cout << "\n Circle with radius: " << radius << endl; 
    cout << "\n Circumference is " << circumference << endl; 
    cout << "\n Area is " << area << endl; 

    cout << "\n Press any key to exit the program..." << endl; 
    _getch(); //Pause the program 

    return 0; 
}

//Function to prompt user to enter the radius. 
void getCircleData(double* radius)
{
    cout << "Enter the radius of the circle (2 decimal places at most): ";
    cin >> *radius; 
}

//Function to calculate the circumference
double calculateCircumference(double* radius)
{
    return 2 * PI * (*radius); // *FIX* PIEE was a misspelling of the constant PI. Corrected.
}

//Function to calculate the area of the circle
double calculateArea(double* radius)
{
    return PI * (*radius) * (*radius);
}