# Use Ubuntu as base image
FROM ubuntu:latest

# Maintainer label
LABEL maintainer="arda.tumer@stu.fbu.edu.tr"

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libpqxx-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

CMD ["bash", "-c", "echo 'C++ container running' && sleep infinity"]
