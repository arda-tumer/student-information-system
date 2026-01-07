#include "student.h"
#include <iostream>

void StudentManager::addStudent(Database &db) {
    Student s;
    auto &list = db.getStudents();

    // simple id generation
    s.id = list.size() + 1;

    std::cout << "Enter name: ";
    std::cin >> s.name;

    std::cout << "Enter surname: ";
    std::cin >> s.surname;

    std::cout << "Enter department: ";
    std::cin >> s.department;

    std::cout << "Enter email: ";
    std::cin >> s.email;

    list.push_back(s);
    std::cout << "Student added successfully.\n";
}

void StudentManager::listStudents(Database &db) {
    auto &list = db.getStudents();

    if (list.empty()) {
        std::cout << "No students available.\n";
        return;
    }

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i].id << " | "
                  << list[i].name << " "
                  << list[i].surname << " | "
                  << list[i].department << " | "
                  << list[i].email << "\n";
    }
}

void StudentManager::updateStudent(Database &db) {
    int id;
    auto &list = db.getStudents();

    std::cout << "Enter student ID to update: ";
    std::cin >> id;

    for (int i = 0; i < list.size(); i++) {
        if (list[i].id == id) {
            std::cout << "New name: ";
            std::cin >> list[i].name;

            std::cout << "New surname: ";
            std::cin >> list[i].surname;

            std::cout << "New department: ";
            std::cin >> list[i].department;

            std::cout << "New email: ";
            std::cin >> list[i].email;

            std::cout << "Student updated.\n";
            return;
        }
    }

    std::cout << "Student not found.\n";
}

void StudentManager::deleteStudent(Database &db) {
    int id;
    auto &list = db.getStudents();

    std::cout << "Enter student ID to delete: ";
    std::cin >> id;

    for (int i = 0; i < list.size(); i++) {
        if (list[i].id == id) {
            list.erase(list.begin() + i);
            std::cout << "Student deleted.\n";
            return;
        }
    }

    std::cout << "Student not found.\n";
}
