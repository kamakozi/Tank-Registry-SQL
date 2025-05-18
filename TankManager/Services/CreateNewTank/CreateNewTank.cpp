
#include "CreateNewTank.h"
#include <iostream>
#include <pqxx/pqxx>
#include "CreateName/CreateName.h"
#include "CreateCreationYear/CreateCreationYear.h"
#include "SelectCountry/SelectCountry.h"
#include "../../DbConnection/DbConnection.h"

Tank* CreateNewTank::createNewTank() {
    pqxx::connection& conn = DbConnection::getInstance();
    std::cout << "Create your own tank!" << std::endl;

    //Create tank name!
    CreateName cn;
    std::string name = cn.createName();

    //Create creation year!
    CreateCreationYear ccy;
    std::string year = ccy.creationYear();

    //Selects the country!
    SelectCountry sc;
    std::string country = sc.selectCountry();
    pqxx::nontransaction find_country(conn);
    pqxx::result r = find_country.exec("SELECT id FROM country WHERE name = " + find_country.quote(country));
    if (r.empty()) {
        std::cerr << "Country not found!" << std::endl;
        return nullptr;
    }
    int countryId = r[0][0].as<int>();



    pqxx::work add_tank_table(conn);
    add_tank_table.exec("INSERT INTO tanks(name,CreationYear,Country) VALUES ("+
        add_tank_table.quote(name) + " , " +
            add_tank_table.quote(year) + " , " +
            add_tank_table.quote(countryId) +")"
            );
    add_tank_table.commit();





    std::cout << "Tank added to database!" << std::endl;
   return new Tank(name,year,country);




}
