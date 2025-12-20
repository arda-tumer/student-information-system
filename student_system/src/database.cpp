#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>
#include <string>

class Database {
public:
   
    Database(const std::string &conninfo);

    
    pqxx::connection& getConn();

private:
    pqxx::connection conn;
};

#endif
