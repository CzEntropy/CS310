/*
Cristian Taylor
5/23/24
Create a simple C++ program using templates and at least two errors. 
//The program should not execute and there should be at least two errors in the code.
*/

#include <iostream>

// Template function to add two numbers
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Template class to hold a value
template [typename T]
class ValueHolder {
public:
    ValueHolder(T value) : value(value) {}
    T getValue() const { return value; }
private:
    T value;
};

int main() {
  
 ValueHolder intHolder(10); 


    std::string result = add<std::string>("Hello, ", "world!"); 


    std::cout << "Integer Value: " << intHolder.getValue() << std::endl;
    std::cout << "Addition Result: " << result << std::endl;

    return 0;
}
