
# 📘 User Manual

This document explains how to use the **Student Information System** application.

---

## Overview

The Student Information System is a **C++ command-line application** that allows users to manage student records stored in a PostgreSQL database.

The system supports:
- Adding students
- Listing students
- Updating student information
- Deleting students

---

## Starting the Application

Ensure the system is running:
```bash
docker compose up -d
docker compose run app
```

## Main Menu

When the application starts, the following menu is displayed:
```text
--- Student System ---
1. Add student
2. List students
3. Update student
4. Delete student
5. Exit
```
## Menu Options 

### 1- Add Student
Allows you to add a new student.

You will be prompted for:

- Name
- Surname
- Department
- Email

The student is saved in the PostgreSQL database.

### 2- List Students

Displays all stored students in the system.

Each record includes:
- Student ID
- Name and surname
- Department
- Email

### 3- Update Student

Updates an existing student record.

Steps:
1. Enter the student ID.
2. Provide new values for fields.

### 4- Delete Student

Deletes a student by ID.

Steps:
1. Enter the student ID.
2. The record is permanently removed.

### 5- Exit

Terminates the application safely.

---

## Data Persistence

- Student data is stored in PostgreSQL.
- Database data is persisted using Docker volumes.
- Data remains intact after container restarts.

## Error Handling

- Invalid menu options are rejected.
- Non-existent student IDs return an error message.
- Database connectivity issues are logged.

## Security Notes

- The application runs inside a containerized environment
- Database access is restricted to internal Docker networking
- Containers run with reduced privileges


**End of User Manual.**
