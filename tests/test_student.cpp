#include <cassert>
#include <iostream>
#include <pqxx/pqxx>
#include "../include/database.h"

int main() {
    std::cout << "Running basic database test...\n";

    Database db(
        std::string("dbname=students user=postgres password=postgres host=localhost port=5432")
    );

    assert(db.getConnection().is_open());
    std::cout << "Connection OK\n";

    pqxx::work w(db.getConnection());
    auto r = w.exec("SELECT 1");
    w.commit();

    assert(r.size() == 1);
    std::cout << "Query OK\n";

    return 0;
}
