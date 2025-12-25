#include "database.h"

Database::Database() {
    // database starts empty
}

std::vector<Student>& Database::getStudents() {
    return students;
}
