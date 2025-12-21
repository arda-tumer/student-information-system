#ifndef DATABASE_H
#define DATABASE.H

#include <pqxx/pqxx>
#include <string>

class Database {
public:
    Database(const std::string& conninfo);
    pqxx::connection& getConnection();


private:
    pqxx::connection conn;

};

#endif