#include <iostream>
#include <string>
#include "DFA.h"

int main() {
    std::string first, last, input;

    // Allow the user to set the target first and last names.
    std::cout << "Enter first name to search for (lowercase): ";
    std::getline(std::cin, first);
    std::cout << "Enter last name to search for (lowercase): ";
    std::getline(std::cin, last);

    // Input the string to be searched.
    std::cout << "Enter input string: ";
    std::getline(std::cin, input);

    // Check if the input contains first name followed by last name.
    if (searchString(input, first, last))
        std::cout << "accept" << std::endl;
    else
        std::cout << "reject" << std::endl;

    return 0;
}
