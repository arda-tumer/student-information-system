#include "student.h"
#include <iostream>

void StudentManager::add(pqxx::connection &c, const std::string &name,
                         const std::string &surname, const std::string &dept,
                         const std::string &email)
{
    pqxx::work w(c);

    w.exec_params(
        "INSERT INTO students(name, surname, department, email) "
        "VALUES ($1, $2, $3, $4)",
        name, surname, dept, email
    );

    w.commit();
    std::cout << "Student added.\n";
}

void StudentManager::listAll(pqxx::connection &c)
{
    pqxx::nontransaction n(c);
    auto r = n.exec("SELECT * FROM students ORDER BY id");

    std::cout << "\n--- Student List ---\n";
    for (auto row : r) {
        std::cout << row["id"].as<int>() << " | "
                  << row["name"].as<std::string>() << " "
                  << row["surname"].as<std::string>() << " | "
                  << row["department"].as<std::string>() << " | "
                  << row["email"].as<std::string>() << "\n";
    }
}

void StudentManager::update(pqxx::connection &c, int id,
                            const std::string &name, const std::string &surname,
                            const std::string &dept, const std::string &email)
{
    pqxx::work w(c);

    w.exec_params(
        "UPDATE students SET name=$1, surname=$2, department=$3, email=$4 "
        "WHERE id=$5",
        name, surname, dept, email, id
    );

    w.commit();
    std::cout << "Student updated.\n";
}

void StudentManager::remove(pqxx::connection &c, int id)
{
    pqxx::work w(c);
    w.exec_params("DELETE FROM students WHERE id=$1", id);
    w.commit();

    std::cout << "Student deleted.\n";
}
