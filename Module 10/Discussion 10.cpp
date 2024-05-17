//Cristian Taylor
//5-16/2024
//This is a program that attempts to create a pointer and 
#include <iostream>

int main() {
    int x = 10;
    int *ptr; // Uninitialized pointer (error 1)

    *ptr = x; // Dereferencing an uninitialized pointer (error 2)
    
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl; // This will also cause an issue

    return 0;
}
