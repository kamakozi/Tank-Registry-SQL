
#include "TankManager.h"
#include <iostream>
#include "Entities/CreateTables/CreateCountryTable/CreateCountryTable.h"
#include "Entities/CreateTables/CreateCreationYearTable/CreateCreationYearTable.h"
#include "Entities/CreateTables/CreateTank/CreateTankTable.h"
#include "Services/CreateNewTank/CreateNewTank.h"
#include "Services/PrintTanksManager/PrintTanksManager.h"



void TankManager::run() {

    //Creates new tables if not existing!
    CreateCountryTable cct;CreateCreationYearTable ccyt;CreateTankTable ctt;
    ccyt.createCreationYearTable();
    cct.createCountryTable();
    ctt.createTankTable();

    std::cout << "Tank manager!" << std::endl;
    int chooser{0};
    while (chooser != 4) {
        std::cout << "1.Create new tank\n2.See all tanks\n3.Manage tanks\nSelect: ";
        std::cin >> chooser;
        switch (chooser) {
            case 1: {
                CreateNewTank cnw;
                Tank *newTank = cnw.createNewTank();
                tanks.emplace_back(*newTank);
                std::cout << "Tank added to the vector!" << std::endl;
                break;
            }case 2:
                PrintTanksManager ptm;
                ptm.printTanksManager();
                break;
        }
    }



}

