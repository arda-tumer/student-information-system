# Installation Guide

This document describes how to install and run the **Student Information System** using Docker and Docker Compose.

---

## Prerequisites

Make sure the following tools are installed on your system:

- **Git**
- **Docker**
- **Docker Compose**

Verify installation:
```bash
git -v
docker -v
docker compose version
```

## Clone the Repository
```bash
git clone https://github.com/arda-tumer/student-information-system.git
cd student-information-system
```

## Build and Run the System
Start all services using Docker Compose:
```bash
docker compose up --build
```
To run in detached mode:
```bash
docker compose up -d
```
This will:

- Build the C++ application image.

- Start the PostgreSQL database container.

- Create required networks and volumes.

- Initialize the database schema.

To run in interactive mode:
```bash
docker compose up -d
docker compose run app
```

## Verify Running Containers
```bash
docker compose ps
```
Expected services:
- postgres_db -> PostgreSQL database
- student_app -> C++ application

## Stop the System
```bash
docker compose down
```
To also remove volumes:
```bash
docker compose down -v
```

## Troublesshooting
- View logs:
```bash
docker compose logs -f
```
- Rebuild images:
```bash
docker compose build --no-cache
```
- Check container health:
```bash
docker inspect postgres_db
```
## Supported Platforms
- Linux (Ubuntu, Debian recommended)
- macOS
- Windows (WSL required)

**Installation Complete!**
