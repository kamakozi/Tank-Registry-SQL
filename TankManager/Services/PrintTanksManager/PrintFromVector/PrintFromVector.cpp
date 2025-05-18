//
// Created by ziga zoric on 18.05.25.
//

#include "PrintFromVector.h"
#include <iostream>

#include "../../../TankManager.h"

void PrintFromVector::printFromVector() {
    if (tanks.empty()) {
        std::cout << "No tanks inside the vector! "<< std::endl;
    }

    for (int i = 0 ; i < tanks.size();i++) {
        std::cout << "Name: " << tanks[i].getName() << " || Creation year: " << tanks[i].getCreationYear() << " || Country: " << tanks[i].getCountry() << std::endl;
    }

}
