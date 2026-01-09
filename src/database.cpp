#include "database.h"
#include <stdexcept>

Database::Database()
{
    connStr = "host=db "
              "dbname=studentdb "
              "user=studentuser "
              "password=studentpass";

    try
    {
        conn = std::make_unique<pqxx::connection>(connStr);

        if (!conn->is_open())
        {
            throw std::runtime_error("Failed to open database connection");
        }

        pqxx::work txn(*conn);
        txn.exec("SET client_encoding TO 'UTF8'");
        txn.commit();
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error(std::string("Database connection error: ") + e.what());
    }
}

pqxx::connection &Database::getConnection() { return *conn; }
