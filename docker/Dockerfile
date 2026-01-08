# Base image.
FROM ubuntu:22.04

# Metadata.
LABEL maintainer="arda.tumer@stu.fbu.edu.tr"
LABEL project="Student Information System"
LABEL course="System Programming"

# Environment variables.
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies.
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    g++ \
    cmake \
    libpqxx-dev \
    libpq-dev \
    ca-certificates && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Working directory.
WORKDIR /app

# Copy source files.
COPY include/ ./include/
COPY src/ ./src/
COPY CMakeLists.txt .

# Build application.
RUN cmake -S . -B build && \
    cmake --build build

# Non-root user.
RUN addgroup --system appgroup && \
    adduser --system --ingroup appgroup appuser && \
    chown -R appuser:appgroup /app

USER appuser

# Healthcheck.
HEALTHCHECK --interval=30s --timeout=5s \
    CMD pgrep student_app || exit 1

# Runtime behavior.
ENTRYPOINT ["./build/student_app"]

