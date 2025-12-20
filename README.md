# Student Information System

## Project Objective  
In this project, we will develop a distributed system using **Ubuntu**, **Git**, **GitHub**, and **Docker** technologies learned during the course. 
The project aims to develop your teamwork, version control, containerization, and system programming skills.

The primary goal of the project is to demonstrate:
- System programming skills in C++.
- Containerization with Docker.
- Version control and teamwork using GitHub.
- Database integration and transaction management.

---

## System Architecture
The system consists of two main containers:

1. **Database Container**
   - PostgreSQL.

2. **Application Container**
   - C++ command-line application.
   - Database connection setup (libpqxx).
   - CRUD operations implementation.

---

## Project Structure
```text
student-information-system/
├── .github/    # CI/CD Workflows & Templates
├── include/    # Header files (.h, .hpp)
├── source/     # Source files (.cpp)
├── tests/      # Unit test files
├── build/      # Build artifacts
├── docker/     # Docker & orchestration files
├── docs/       # Documentation
├── README.md/  # Project documentation
└── .github/    # CI/CD workflows

