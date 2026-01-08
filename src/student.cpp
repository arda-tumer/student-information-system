#include "student.h"
#include <iostream>
#include <pqxx/pqxx>

void StudentManager::addStudent(Database &db) {
    std::string name, email;

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;

    pqxx::work txn(db.getConnection());
    txn.exec_params(
        "INSERT INTO students (name, email) VALUES ($1, $2)",
        name, email
    );
    txn.commit();

    std::cout << "Student added.\n";
}

void StudentManager::listStudents(Database &db) {
    pqxx::work txn(db.getConnection());
    pqxx::result r = txn.exec("SELECT id, name, email FROM students");

    for (const auto &row : r) {
        std::cout << row["id"].as<int>() << " | "
                  << row["name"].c_str() << " | "
                  << row["email"].c_str() << "\n";
    }
}

void StudentManager::updateStudent(Database &db) {
    int id;
    std::string name, email;

    std::cout << "Student ID: ";
    std::cin >> id;
    std::cout << "New name: ";
    std::cin >> name;
    std::cout << "New email: ";
    std::cin >> email;

    pqxx::work txn(db.getConnection());
    txn.exec_params(
        "UPDATE students SET name=$1, email=$2 WHERE id=$3",
        name, email, id
    );
    txn.commit();

    std::cout << "Student updated.\n";
}

void StudentManager::deleteStudent(Database &db) {
    int id;
    std::cout << "Student ID: ";
    std::cin >> id;

    pqxx::work txn(db.getConnection());
    txn.exec_params(
        "DELETE FROM students WHERE id=$1",
        id
    );
    txn.commit();

    std::cout << "Student deleted.\n";
}

