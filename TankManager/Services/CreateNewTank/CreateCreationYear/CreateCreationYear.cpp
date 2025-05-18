//
// Created by ziga zoric on 18.05.25.
//

#include <iostream>
#include "CreateCreationYear.h"

std::string CreateCreationYear::creationYear() {
    std::string creationYear;

    while (true) {
        std::cout << "Enter creation year: ";
        getline(std::cin>>std::ws,creationYear);
        if (creationYear.empty()) {
            std::cout << "Creation Year can''t be empty!" << std::endl;
        }
        int num = std::stoi(creationYear);
        if (num < 1800 || num > 2025) {
            std::cout << "Year can't be lower than 1800 or greater than 2025!" << std::endl;
        }else break;

    }
    return creationYear;
}
