#include "student.h"
#include "logger.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <pqxx/pqxx>
#include <regex>
#include <stdexcept>

/* ---------- Logging ---------- */

void logMessage(const std::string &level, const std::string &message) {
  std::ofstream logFile("/app/logs/app.log", std::ios::app);
  if (!logFile.is_open())
    return;

  std::time_t now = std::time(nullptr);
  char buf[32];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

  logFile << "[" << buf << "] " << "[" << level << "] " << message << "\n";
}

/* ---------- Input Validation ---------- */

bool isEmpty(const std::string &value) { return value.empty(); }

bool isValidEmail(const std::string &email) {
  static const std::regex emailRegex(
      R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
  return std::regex_match(email, emailRegex);
}

/* ---------- CRUD Operations ---------- */

void StudentManager::addStudent(Database &db) {
  try {
    std::string name, surname, department, email;

    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    std::cout << "Enter department: ";
    std::getline(std::cin, department);

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    if (isEmpty(name) || isEmpty(surname) || isEmpty(department) ||
        isEmpty(email)) {
      throw std::runtime_error("Fields cannot be empty");
    }

    if (!isValidEmail(email)) {
      throw std::runtime_error("Invalid email format");
    }

    pqxx::work txn(db.getConnection());
    txn.exec_params("INSERT INTO students (name, surname, department, email) "
                    "VALUES ($1, $2, $3, $4)",
                    name, surname, department, email);
    txn.commit();

    std::cout << "Student added successfully.\n";
    logMessage("INFO", "Student added: " + email);

  } catch (const pqxx::sql_error &e) {
    logMessage("ERROR", std::string("SQL error: ") + e.what());
    std::cerr << "Database error.\n";
  } catch (const std::exception &e) {
    logMessage("ERROR", e.what());
    std::cerr << "Error: " << e.what() << "\n";
  }
}

void StudentManager::listStudents(Database &db) {
  try {
    pqxx::work txn(db.getConnection());
    pqxx::result r = txn.exec("SELECT id, name, surname, department, email "
                              "FROM students ORDER BY id");

    if (r.empty()) {
      std::cout << "No records found.\n";
      logMessage("INFO", "List requested – no records");
      return;
    }

    for (const auto &row : r) {
      std::cout << row["id"].as<int>() << " | " << row["name"].c_str() << " "
                << row["surname"].c_str() << " | " << row["department"].c_str()
                << " | " << row["email"].c_str() << "\n";
    }

    logMessage("INFO", "Students listed");

  } catch (const std::exception &e) {
    logMessage("ERROR", e.what());
    std::cerr << "Database error.\n";
  }
}

void StudentManager::updateStudent(Database &db) {
  try {
    int id;
    std::string name, surname, department, email;

    std::cout << "Student ID: ";
    std::cin >> id;

    std::cout << "New name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "New surname: ";
    std::getline(std::cin, surname);

    std::cout << "New department: ";
    std::getline(std::cin, department);

    std::cout << "New email: ";
    std::getline(std::cin, email);

    if (isEmpty(name) || isEmpty(surname) || isEmpty(department) ||
        isEmpty(email)) {
      throw std::runtime_error("Fields cannot be empty");
    }

    if (!isValidEmail(email)) {
      throw std::runtime_error("Invalid email format");
    }

    pqxx::work txn(db.getConnection());
    pqxx::result r = txn.exec_params("UPDATE students SET name=$1, surname=$2, "
                                     "department=$3, email=$4 WHERE id=$5",
                                     name, surname, department, email, id);

    if (r.affected_rows() == 0) {
      txn.abort();
      logMessage("WARN", "Update failed: ID not found");
      std::cout << "Student not found.\n";
      return;
    }

    txn.commit();
    std::cout << "Student updated.\n";
    logMessage("INFO", "Student updated: ID " + std::to_string(id));

  } catch (const std::exception &e) {
    logMessage("ERROR", e.what());
    std::cerr << "Update failed: " << e.what() << "\n";
  }
}

void StudentManager::deleteStudent(Database &db) {
  try {
    int id;
    std::cout << "Student ID: ";
    std::cin >> id;

    pqxx::work txn(db.getConnection());
    pqxx::result r = txn.exec_params("DELETE FROM students WHERE id=$1", id);

    if (r.affected_rows() == 0) {
      txn.abort();
      logMessage("WARN", "Delete failed: ID not found");
      std::cout << "Student not found.\n";
      return;
    }

    txn.commit();
    std::cout << "Student deleted.\n";
    logMessage("INFO", "Student deleted: ID " + std::to_string(id));

  } catch (const std::exception &e) {
    logMessage("ERROR", e.what());
    std::cerr << "Delete failed.\n";
  }
}
