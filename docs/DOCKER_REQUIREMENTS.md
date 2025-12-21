# Docker Requirements and Architecture

## 1. Usage
In this project we use docker for in order to ensure environment consistency, portability, and isolated execution of application components.
Using Docker eliminates dependency conflicts and simplifies deployment and evaluation.

---

## 2. Container Overview

| Container | Base Image | Responsibility |
|---------|-----------|----------------|
| Database | postgres:latest | Persistent storage of student information |
| Application | Custom C++ image | Executes CRUD operations and business logic |

Each container has a single responsibility.

---

## 3. Docker Images

### 3.a PostgreSQL Database Image
- Base image: `postgres:latest`.
- Database initialization handled via `init.sql`.
- Data persistence ensured using Docker volumes.
- Environment variables used for credentials and configuration.

### 3.b C++ Application Image
- Custom Dockerfile.
- Built using Makefile (or CMake).
- Linked with `libpqxx` for PostgreSQL communication.

---

## 4. Docker Compose Orchestration
Docker Compose is used to orchestrate the system.

### Services:
- `db`: PostgreSQL database container.
- `app`: C++ application container.

### Orchestration Features
- Private Docker network for inter-container communication.
- Service dependency management (`app` depends on `db`).
- Centralized configuration via environment variables.

---

## 5. Volume Management
Docker volume is used to persist PostgreSQL data.
- Prevents data loss when containers restart
- Allows clean container recreation without data deletion

---

## 6. Environment Variables
Sensitive and configurable values are managed using environment variables to ensure security and flexibility.

- `POSTGRES_DB`
- `POSTGRES_USER`
- `POSTGRES_PASSWORD`
- `DB_HOST`
- `DB_PORT`

---

## 7. Health Check
- PostgreSQL: `pg_isready` command
- Application: startup validation and exit status monitoring

---

## 8. Resource Limits and Logging
- CPU and memory limits will be configured
- Docker logging mechanisms will be used for debugging and monitoring

---

## 9. Docker Hub
- Images will be pushed to Docker Hub using school email accounts.
- Images will be publicly accessible.



