cmake_minimum_required(VERSION 3.16)
project(student_app)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

add_executable(student_app
    src/Main.cpp
    src/database.cpp
    src/student.cpp
    src/ui.cpp
    src/logger.cpp
)

target_link_libraries(student_app pqxx pq)

