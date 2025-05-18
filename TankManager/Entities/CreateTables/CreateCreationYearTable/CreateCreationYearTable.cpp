//
// Created by ziga zoric on 18.05.25.
//

#include "CreateCreationYearTable.h"
#include <pqxx/pqxx>
#include "../../../DbConnection/DbConnection.h"
#include <iostream>

void CreateCreationYearTable::createCreationYearTable() {
    try{
    pqxx::connection& conn = DbConnection::getInstance();

    pqxx::work xtn_createCreationYearTable(conn);
    xtn_createCreationYearTable.exec("CREATE TABLE IF NOT EXISTS creationyear(id SERIAL PRIMARY KEY,CreationYear TEXT)");
    std::cout << "CreationYearTable working!" << std::endl;
    }catch (const std::exception& e) {
        std::cerr << "Unable to create creationYearTable: " << e.what() << std::endl;
    }
}

