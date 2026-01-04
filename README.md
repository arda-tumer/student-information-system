# Student Information System

## Project Objective  
In this project, we will develop a distributed system using **Ubuntu**, **Git**, **GitHub**, and **Docker** technologies learned during the course. 
The project aims to develop your teamwork, version control, containerization, and system programming skills.
The project is designed as a **multi-container application** with internal networking.

The primary goal of the project is to demonstrate:
- System programming skills in C++.
- Containerization with Docker.
- Version control and teamwork using GitHub.
- Database integration and transaction management.

---

## :whale: Docker Hub Images
### C++ Application Image
- **Repository:**  
  https://hub.docker.com/r/ardatumer/student-information-system-app
- **Description:**  
  C++ application container.

### PostgreSQL Database Image
- **Repository:**  
  https://hub.docker.com/r/ardatumer/student-information-system-db
- **Description:**  
  PostgreSQL container with initial database configuration.

## Running the Project Locally

```bash
docker compose build
docker compose up
```
Successful startup is confirmed when PostgreSQL logs show:

```text
database system is ready to accept connections
```
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
├── .github/
│   └── workflows/        # GitHub Actions CI/CD pipelines
├── include/              # C++ header files (.h, .hpp)
├── src/                  # C++ source files (.cpp)
├── tests/                # Unit and integration tests
├── docker/               # Docker-related files
│   ├── Dockerfile        # C++ application container
│   ├── Dockerfile.db     # PostgreSQL container
│   ├── docker-compose.yml
│   ├── .dockerignore
│   └── init.sql          # Initial database schema
├── docs/                 # Project documentation
├── CONTRIBUTING.md       # Contribution guidelines
├── LICENSE               # MIT License
└── README.md             # Project overview
```
## License

This project is licensed under the MIT License.
```text
MIT License

Copyright (c) 2026

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
```
