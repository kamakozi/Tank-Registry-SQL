#include "CreateName.h"
#include <iostream>

#include "CreateName.h"
#include <limits>

std::string CreateName::createName() {
    std::string tankName;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        std::cout << "Create name: ";
        std::getline(std::cin, tankName);  // No ignore here!

        if (tankName.empty()) {
            std::cout << "Name can't be empty!" << std::endl;
        } else break;
    }

    return tankName;

}

