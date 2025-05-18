
#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include <pqxx/pqxx>

class DbConnection {
public:
    static pqxx::connection& getInstance() {
        static pqxx::connection conn("host=localhost port=5432 dbname=tankdb user=postgres password=secret");
        return conn;
    }
};

#endif //DBCONNECTION_H
