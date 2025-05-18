//
// Created by ziga zoric on 18.05.25.
//

#include "PrintTanksManager.h"
#include <iostream>
#include "PrintFromVector/PrintFromVector.h"
#include "PrintFromDatabase/PrintFromDatabase.h"

void PrintTanksManager::printTanksManager() {
    int chooser{0};
    std::cout << "1.Print from vector\n2.Print for database\nSelect: ";
    std::cin >> chooser;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Only numbers!" << std::endl;
    }
    switch (chooser) {
        case 1:
            PrintFromVector pfv;
            pfv.printFromVector();
            break;
        case 2:
            PrintFromDatabase pfd;
            pfd.printFromDatabase();
            break;
    }
}
