//
// Created by ziga zoric on 18.05.25.
//

#include "PrintFromDatabase.h"
#include <pqxx/pqxx>
#include <iostream>
#include "../../../DbConnection/DbConnection.h"
#include "PrintFromCountry/PrintFromCountry.h"

void normalPrint() {
    pqxx::connection& conn = DbConnection::getInstance();

    pqxx::nontransaction print_dota(conn);
    pqxx::result r = print_dota.exec("SELECT * FROM tanks");
    for (auto row:r) {
        std::cout << "Id: " << row["id"].as<int>() << " || Name: " << row["name"].as<std::string>() << " || Country: " << row["country"].as<std::string>() << " || Creation year: " << row["creationYear"].as<std::string>() << std::endl;
    }

}

void PrintFromDatabase::printFromDatabase() {
    std::cout << "1.Normal print\n2.Print from specific country\nSelect: ";
    int chooser{0};
    std::cin >> chooser;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Only numbers!" << std::endl;
    }
    switch (chooser) {
        case 1:
            normalPrint();
            break;
        case 2:
            PrintFromCountry pfc;
            pfc.printFromCountry();
            break;
    }



}

