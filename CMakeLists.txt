cmake_minimum_required(VERSION 3.16)
project(student_information_system)

set(CMAKE_CXX_STANDARD 17)

find_package(PQXX REQUIRED)

include_directories(include)

add_executable(student_app
    src/Main.cpp
    src/database.cpp
    src/student.cpp
    src/ui.cpp
    src/logger.cpp
)

target_link_libraries(student_app pqxx)

# ---------- TEST TARGET ----------
add_executable(test_student
    test/test_student.cpp
    src/database.cpp
)

target_link_libraries(test_student pqxx)
