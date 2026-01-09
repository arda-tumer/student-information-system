#include "database.h"
#include "logger.h"
#include "student.h"
#include <iostream>

int main() {

  logMessage("INFO", "Application started");

  Database db;
  int choice;

  while (true) {
    std::cout << "\n--- Student System ---\n";
    std::cout << "1. Add student\n";
    std::cout << "2. List students\n";
    std::cout << "3. Update student\n";
    std::cout << "4. Delete student\n";
    std::cout << "5. Exit\n";
    std::cout << "Choice: ";

    std::cin >> choice;

    if (choice == 1) {
      StudentManager::addStudent(db);
    } else if (choice == 2) {
      StudentManager::listStudents(db);
    } else if (choice == 3) {
      StudentManager::updateStudent(db);
    } else if (choice == 4) {
      StudentManager::deleteStudent(db);
    } else if (choice == 5) {
      break;
    } else {
      std::cout << "Invalid option.\n";
    }
  }

  return 0;
}
