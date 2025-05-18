//
// Created by ziga zoric on 18.05.25.
//
#include "../../../DbConnection/DbConnection.h"
#include "CreateTankTable.h"
#include <pqxx/pqxx>
#include <iostream>

void CreateTankTable::createTankTable() {
    pqxx::connection& conn = DbConnection::getInstance();

    try{
    pqxx::work txn_create_tank_Table(conn);

    txn_create_tank_Table.exec("CREATE TABLE IF NOT EXISTS tanks(id SERIAL PRIMARY KEY,Name TEXT,CreationYear TEXT,country_id INTEGER REFERENCES country(id))");
        txn_create_tank_Table.commit();
        std::cout << "CreateTankTable working!" << std::endl;
    }catch (const std::exception& e) {
        std::cerr << "Unable to create table : " << e.what() << std::endl;
    }
}

