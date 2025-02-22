#include <iostream>
#include <string>
#include "DFA.h"

int main() {
    std::string first, last, input;
 
    std::cout << "Enter first name you will be using (lowercase): ";
    std::getline(std::cin, first);
    std::cout << "Enter last name you will be using (lowercase): ";
    std::getline(std::cin, last);

    std::cout << "Enter input string: ";
    std::getline(std::cin, input);

    if (searchString(input, first, last))
        std::cout << "accept" << std::endl;
    else
        std::cout << "reject" << std::endl;

    return 0;
}
