# Contribution Guidelines

This document defines the contribution ruleset for the **Student Information System** project.

>[!CAUTION]
>All team members must follow these rules strictly.

---

## Direct Push Prohibition
- Direct pushes to `main` & `develop` branches are **prohibited**.
- All development must be done in `feature/*` branches.
- Feature branches are merged into `develop`.
- `develop` is merged into `main` on a weekly basis (between Friday and Monday 23:59).

---

## Issue Management
- Every task must have a corresponding **GitHub Issue**.
- Issues should describe the task and acceptance criteria.

---

## Commit Messages
- Commits must be **meaningful**.
- Example format:

text
feat: add student insert functionality
- Implement insert_student() function
- Add input validation for email field
- Update database schema to version 1.2
Closes #45

- Each commit should relate to a specific issue.

---

## Pull Request Process
- All changes must be submitted via **Pull Requests**.
- Each Pull Request must:
- Reference an issue.
- Have a clear description of changes.
- Pass CI checks.
- Receive at least one review before merging.

---

## Regular Contribution 
>[!WARNING]
>Last-minute commits will receive lower points.

## Code Quality
- Use code formatting (`clang-format`).
- Handle errors and exceptions properly and logging.
- Memory leak checking.
- Write unit and inegration tests.

---

## Review Process
- Reviewers should provide constructive feedback.
- Code must not be merged without approval.
- Discussions should be documented in the Pull Request.

---

## Teamwork Rules:
- **Active Participation**: All students must actively contribute to the project.
- **Weekly Meetings**: Hold at least one meeting per week, notes added to GitHub Wiki.
- **Task Distribution**: Tasks must be tracked and updated via GitHub Projects.
- **Communication**: All technical discussions must be conducted via GitHub Issues.

---

## Academic Integrity:
- **Plagiarism Prohibition**: Copying code from other projects is strictly prohibited.
- **Individual Work**: Each student must complete their own tasks individually.
- **Reference Citation**: External sources must be properly cited.




