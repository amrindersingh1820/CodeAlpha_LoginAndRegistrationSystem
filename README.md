# 🔐 Login and Registration System — C++

[![CodeAlpha Internship](https://img.shields.io/badge/CodeAlpha-C%2B%2B%20Internship-blue)](https://www.codealpha.tech/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B11-green)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Console%20Application-orange)]()

A simple **Login and Registration System** developed in **C++** using **Object-Oriented Programming (OOP)** and **File Handling**.

This project was created as **Task 2** for the **CodeAlpha C++ Programming Internship**.

---

# 📌 Project Overview

This application allows users to create an account and securely log in using a username and password.

The project demonstrates:

- Object-Oriented Programming (OOP)
- File Handling
- Password Hashing
- Input Validation
- Local Database Management
- User Authentication

User credentials are stored locally inside a **database** folder.

---

# ✨ Features

- 👤 User Registration
- 🔑 User Login
- 🔒 Password Hashing using `std::hash`
- 📁 File-Based Storage
- 🚫 Duplicate Username Detection
- ✅ Username Validation
- ✅ Password Length Validation
- 💾 Persistent User Data
- 🖥️ Console-Based Interface

---

# ⚙️ Working

## Registration

1. User enters a username.
2. System checks whether the username already exists.
3. User enters a password.
4. Password is hashed.
5. Username and hashed password are stored inside:

```
database/username.txt
```

---

## Login

1. User enters username.
2. System checks whether the account exists.
3. User enters password.
4. Password is hashed.
5. Hash is compared with the stored hash.
6. Login succeeds if both hashes match.

---

# 🛠 Technologies Used

- C++
- Object-Oriented Programming
- File Handling (`fstream`)
- STL
- String Manipulation
- `std::hash`
- Console Application

---

# 📂 Project Structure

```
CodeAlpha_LoginAndRegistrationSystem/
│
├── database/
│   ├── user1.txt
│   ├── user2.txt
│   └── ...
│
├── main.cpp
├── CMakeLists.txt
├── README.md
└── .gitignore
```

---

# 🚀 Getting Started

## Prerequisites

- C++11 or later
- GCC / Clang / MSVC
- CLion, VS Code, CodeBlocks or any C++ IDE

---

## Clone Repository

```bash
git clone https://github.com/YourUsername/CodeAlpha_LoginAndRegistrationSystem.git

cd CodeAlpha_LoginAndRegistrationSystem
```

---

## Compile

Using GCC

```bash
g++ -std=c++11 main.cpp -o login_system
```

or

```bash
g++ -std=c++17 main.cpp -o login_system
```

---

## Run

### Linux / macOS

```bash
./login_system
```

### Windows

```bash
login_system.exe
```

---

# 📷 Sample Output

```
====================================
     LOGIN & REGISTRATION SYSTEM
====================================

1. Register
2. Login
3. Exit

Choose an option (1-3): 1

--- USER REGISTRATION ---

Enter username: amrinder
Enter password: mypassword123

Success: Registration successful for user 'amrinder'!
```

```
====================================
     LOGIN & REGISTRATION SYSTEM
====================================

1. Register
2. Login
3. Exit

Choose an option (1-3): 2

--- USER LOGIN ---

Enter username: amrinder
Enter password: mypassword123

Success: Welcome back, amrinder! Login successful.
```

---

# 🔒 Password Storage

The project hashes passwords using C++'s `std::hash<std::string>` before saving them to disk.

Example database file:

```
amrinder
16827542819430773471
```

> **Note:** `std::hash` is used only for educational purposes. It is **not intended for production-grade password security**. Real-world applications should use dedicated password hashing algorithms such as **bcrypt**, **Argon2**, or **PBKDF2**.

---

# 📚 Concepts Demonstrated

- Classes & Objects
- Encapsulation
- Constructors
- File Handling
- Password Hashing
- Functions
- Conditional Statements
- Loops
- String Processing
- Authentication System Design

---

# 🎯 Learning Outcomes

This project helped in understanding:

- C++ Object-Oriented Programming
- File Management
- User Authentication
- Password Hashing
- Local Data Persistence
- Console Application Development

---

# 🚀 Future Improvements

- Password masking while typing
- Password reset feature
- Email verification
- Admin panel
- User profile management
- Better password hashing (bcrypt / Argon2)
- SQLite/MySQL database support
- GUI using Qt

---

# 📜 Repository Name

```
CodeAlpha_LoginAndRegistrationSystem
```

---

# 📄 License

This project is developed for educational purposes as part of the **CodeAlpha C++ Programming Internship**.

---

# 🙏 Acknowledgements

- CodeAlpha
- C++ Programming Internship
- ISO C++ Documentation

---

# 👨‍💻 Author

**Amrinder Singh**

B.Tech CSE Student

---

⭐ If you found this project helpful, consider giving it a **Star** on GitHub.