#ifndef DATABASE_H
#define DATABASE_H

#include <memory>
#include <pqxx/pqxx>
#include <string>

class Database
{
  private:
    std::unique_ptr<pqxx::connection> conn;
    std::string connStr;

  public:
    Database();
    pqxx::connection &getConnection();
};

#endif
