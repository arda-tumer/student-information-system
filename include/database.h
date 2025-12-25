#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>

// simple struct for student data
struct Student {
    int id;
    std::string name;
    std::string surname;
    std::string department;
    std::string email;
};

class Database {
public:
    Database();

    // gives access to stored students
    std::vector<Student>& getStudents();

private:
    std::vector<Student> students;
};

#endif
