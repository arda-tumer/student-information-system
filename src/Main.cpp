#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

#include "database.h"
#include "student.h"
#include "ui.h"

int main() {
    Database db;
    int choice;

    showLoading("Initializing Student Information System", 1500);
    showProgressBar("Loading modules", 2000);

    while (true) {
        printMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printError("Please enter a valid number (1-5).");
            std::this_thread::sleep_for(std::chrono::milliseconds(1200));
            continue;
        }

        switch (choice) {
            case 1:
                showLoading("Opening add student form", 800);
                StudentManager::addStudent(db);
                break;

            case 2:
                showProgressBar("Fetching student list", 1200);
                StudentManager::listStudents(db);
                break;

            case 3:
                showLoading("Preparing update mode", 800);
                StudentManager::updateStudent(db);
                break;

            case 4:
                showLoading("Deleting student", 800);
                StudentManager::deleteStudent(db);
                break;

            case 5:
                showProgressBar("Shutting down system", 1200);
                printSuccess("Goodbye!");
                return 0;

            default:
                printError("Invalid option. Please select 1–5.");
        }

        std::cout << "\nPress ENTER to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
