//
// Created by ziga zoric on 18.05.25.
//

#include "PrintFromCountry.h"
#include <iostream>
#include <pqxx/pqxx>
#include "../../../../DbConnection/DbConnection.h"
void PrintFromCountry::printFromCountry() {

    pqxx::connection& conn = DbConnection::getInstance();
    while (true){
    {
        pqxx::nontransaction print_country(conn);
        pqxx::result r = print_country.exec("SELECT * FROM country");
        for (auto row: r) {
            std::cout << "ID: " << row["id"].as<int>() << " || Country: "  << row["country"].as<std::string>() << std::endl;;
        }
    }
        std::cout << "Enter country Id to find tanks for specific country\nSelect: ";
        int countryId{0};
        std::cin >> countryId;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Only numbers!" << std::endl;
        }

        pqxx::nontransaction print_tank_by_country(conn);
        std::string query = "SELECT * FROM tanks WHERE country_id = " +print_tank_by_country.quote(countryId);
        pqxx::result p = print_tank_by_country.exec(query);
        if (p.empty()) {
            std::cout << "No tanks found for this country." << std::endl;
        }else {
            for (const auto& tank:p) {
                std::cout << "Tank Id: " << tank["id"].as<int>()
                          << " || Name: " << tank["name"].as<std::string>()
                          << " || Year: " << tank["creationYear"].as<std::string>() << std::endl;
            }
        }

    }


}
