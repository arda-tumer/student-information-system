#ifndef STUDENT_H
#define STUDENT_H

#include <pqxx/pqxx>
#include <string>

class StudentManager {
public:
    
    static void add(pqxx::connection &c, const std::string &name,
                    const std::string &surname, const std::string &dept,
                    const std::string &email);

    static void listAll(pqxx::connection &c);

    static void update(pqxx::connection &c, int id,
                       const std::string &name, const std::string &surname,
                       const std::string &dept, const std::string &email);

    static void remove(pqxx::connection &c, int id);
};

#endif

