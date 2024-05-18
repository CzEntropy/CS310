/*
* Student Name: Rebecca Hahn
 * File Name: Hahn_M10 debug.cpp
 * Date: 5/16/2024
 * Description: This is a file that contains bugs. This file should not run.
*Debugged by Cristian Taylor on 5/17
*/



#include <iostream>
using namespace std;
int main() {
    int var = 8;

    // store address of variable
    int* point_var = &var; // *Fix* Corrected the line so point_var is appropriatley pointing to the address of 'var' instead of the value of var.

    // print variable
    cout << "var = " << var << endl;

    // print *point_var
    cout << "*point_var = " << *point_var << endl
        << endl;

    cout << "Changing value of var to 3:" << endl;

    // change value of variable to 3
    var = 3;

    // print variable
    cout << "var = " << var << endl; //*Fix* addded a semi colon to fix this variable output 

    // print *point_var
    cout << "*point_var = " << *point_var << endl
        << endl;

    cout << "Changing value of *point_var to 13:" << endl;

    // change value of variable to 13
    *point_var = 13;

    // print variable
    cout << "var = " << var << endl;

    // print *point_var
    cout << "*point_var = " << *point_var << endl;
    return 0;
}