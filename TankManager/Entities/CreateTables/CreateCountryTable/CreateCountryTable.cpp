#include <pqxx/pqxx>
#include "CreateCountryTable.h"
#include <iostream>
#include "../../../DbConnection/DbConnection.h"

void CreateCountryTable::createCountryTable() {
    try{
        pqxx::connection& conn = DbConnection::getInstance();

        pqxx::work xtn_create_country_table(conn);
        xtn_create_country_table.exec("CREATE TABLE IF NOT EXISTS country (id SERIAL PRIMARY KEY,Country TEXT UNIQUE)");
        xtn_create_country_table.commit();
        std::cout << "Country table working!" << std::endl;

        pqxx::work insert_into_database(conn);
        insert_into_database.exec("INSERT INTO country(country) VALUES "
    "('slovenia'),"
    "('german'),"
    "('russia'),"
    "('usa'),"
    "('france'),"
    "('spain'),"
    "('china'),"
    "('austria')"
    "ON CONFLICT DO NOTHING");
        insert_into_database.commit();
    }catch (const std::exception& e) {
        std::cerr << "Unable to create country table: " << e.what() << std::endl;
    }
}
