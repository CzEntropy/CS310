// Week9DiscussionBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h> // Include for _getch()

class Animal {
public:
    void speak() const {
        std::cout << "Some sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const {
        std::cout << "Bark!" << std::endl;
    }

    void fetch() {
        std::cout << "Fetching the stick!" << endl; 
    }
};

class Cat : public Animal {
public:
    void speak() const {
        std::cout << "Meow!" << std::endl;
    }

    void purr() const {
        cout << "Purring..." << std::endl; 
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    myDog.speak();
    myDog.fetch();

    myCat.speak();
    myCat.purr();

    std::cout << "Press any key to continue...";
    _getch(); // Wait for user input without showing the input

    return 0;
}

