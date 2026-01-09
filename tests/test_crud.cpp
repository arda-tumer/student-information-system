#include <iostream>
#include <cstdlib>
#include <pqxx/pqxx>

int main() {
    try {
        std::string conn_str =
            "dbname=" + std::string(std::getenv("POSTGRES_DB")) +
            " user=" + std::string(std::getenv("POSTGRES_USER")) +
            " password=" + std::string(std::getenv("POSTGRES_PASSWORD")) +
            " host=db";

        pqxx::connection conn(conn_str);
        pqxx::work txn(conn);

        // INSERT all required fields
        txn.exec(
            "INSERT INTO students (name, surname, department, email) VALUES "
            "('TestUser', 'TestSurname', 20, 'testuser@example.com')"
        );

        // SELECT
        pqxx::result r = txn.exec(
            "SELECT name, surname, department, email FROM students WHERE email='testuser@example.com'"
        );

        txn.commit();

        if (r.empty()) {
            std::cerr << "[FAIL] CRUD test failed: no data returned\n";
            return 1;
        }

        std::cout << "[PASS] CRUD test successful\n";
        std::cout << "Student: "
                  << r[0]["name"].c_str() << " | "
                  << r[0]["surname"].c_str() << " | "
                  << r[0]["department"].c_str() << " | "
                  << r[0]["email"].c_str()
                  << "\n";

        return 0;
    }
    catch (const std::exception &e) {
        std::cerr << "[FAIL] Exception: " << e.what() << "\n";
        return 1;
    }
}

