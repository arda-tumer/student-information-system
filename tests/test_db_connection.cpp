#include <iostream>
#include <cstdlib>
#include <pqxx/pqxx>

int main() {
    try {
        const char* db   = std::getenv("POSTGRES_DB");
        const char* user = std::getenv("POSTGRES_USER");
        const char* pass = std::getenv("POSTGRES_PASSWORD");

        if (!db || !user || !pass) {
            std::cerr << "Environment variables not set\n";
            return 1;
        }

        std::string conn_str =
            "dbname=" + std::string(db) +
            " user=" + std::string(user) +
            " password=" + std::string(pass) +
            " host=db";

        pqxx::connection conn(conn_str);

        if (conn.is_open()) {
            std::cout << "[PASS] Database connection successful\n";
            conn.disconnect();
            return 0;
        } else {
            std::cerr << "[FAIL] Database connection failed\n";
            return 1;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "[FAIL] Exception: " << e.what() << "\n";
        return 1;
    }
}

