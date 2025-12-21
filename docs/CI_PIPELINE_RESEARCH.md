# CI Pipeline Research

## What is a CI/CD pipeline?

CI/CD pipelines are a practice focused on improving software delivery throughout the software
development life cycle via automation.

By automating CI/CD throughout development, testing, production, and monitoring 
phases of the software development lifecycle, teams are able to develop higher quality 
code, faster and more securely. Automated testing also allows dependencies and 
other issues to be identified earlier in the software development lifecycle, saving time later.

## 1. Objective
The goal of the CI pipeline is to automatically verify that the project builds and functions correctly
after every change. CI ensures code quality, early error detection, and stable integration.

---

## 2. Selected Technology: Github Actions
- Native integration with GitHub repositories.
- Supports Docker and C++ workflows.

---

## 3. CI Pipeline Responsibilities
- Building the C++ application.
- Running automated tests.
- Detecting build or test errors.
- Preventing unstable code from being merged.

---

## 4. Proposed CI Workflow Stages

1. **Checkout Source Code**
   - Retrieve repository content.

2. **Install Dependencies**
   - C++ compiler.
   - Makefile (or CMake).
   - libpqxx.

3. **Build Application**
   - Configure project with Makefile (or CMake).
   - Compile source code.

4. **Run Tests**
   - Execute unit and integration tests.
   - Fail pipeline on test errors.

5. **Result Reporting**
   - Show test result status in Pull Requests.

---

## 5. Trigger Conditions
- Pull Requests to `develop`.
- Pull Requests to `main`.
- Push events on `develop` and `main`.

---

## 6. Docker Build Pipeline (`docker-build.yml)
- Build Docker images after merge to `main`
- Tag images using semantic versioning
- Push images to Docker Hub

---

## 7. 🔐Security
Sensitive credentials will be managed using GitHub Secrets:
- Docker Hub username.
- Docker Hub access token.

No credentials will be stored in the repository.

---

## 8. Benefits of CI/CD Integration
- Early detection of errors
- Improved code quality
- Automated testing

---

## 9. Conclusion
The CI pipeline is designed to support reliable development and stable releases.
By automating builds and tests, the project ensures consistency & maintainability.

