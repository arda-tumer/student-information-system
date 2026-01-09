#ifndef STUDENT_H
#define STUDENT_H

#include "database.h"

class StudentManager {
public:
  static void addStudent(Database &db);
  static void listStudents(Database &db);
  static void updateStudent(Database &db);
  static void deleteStudent(Database &db);
};

#endif
