//
// Created by ziga zoric on 18.05.25.
//

#include "SelectCountry.h"
#include <iostream>
#include <pqxx/pqxx>
#include "../../../DbConnection/DbConnection.h"

std::string SelectCountry::selectCountry() {
    std::string selectedCountry;
    pqxx::connection& conn = DbConnection::getInstance();
    {
    pqxx::nontransaction stx(conn);
    pqxx::result r = stx.exec("SELECT * FROM country;");
    for (auto row:r) {
        std::cout << "ID: "<< row["id"].as<int>() << " || Country: " << row["country"].as<std::string>() << std::endl;
    }
    }
    try {
        int selectedcounty{0};
        std::string newCountry;
        while (true){
            std::cout << "Enter country ID: ";
            std::cin >> selectedcounty;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Number only!" << std::endl;
            }else break;
        }

        while (true){
            pqxx::nontransaction stxc(conn);
            pqxx::result x = stxc.exec("SELECT * FROM country;");
            for (auto row : x) {
                if (selectedcounty < 1 ||selectedcounty  > 8) {
                    std::cout << "Only int (1-8)" << std::endl;
                }

                if (selectedcounty == row["id"].as<int>()){
                    newCountry = row["country"].as<std::string>();
                    break;
            }

        }
            return newCountry;
    }
    }catch (const std::exception&e) {
        std::cerr << "" << std::endl;
    }
}
