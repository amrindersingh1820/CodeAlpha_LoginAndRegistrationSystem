#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <algorithm>

std::string hashPassword(const std::string& password) {
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}

class User {
private:
    std::string username;
    std::string passwordHash;

public:
    User() = default;
    User(const std::string& uname, const std::string& pwd)
        : username(uname), passwordHash(hashPassword(pwd)) {}

    std::string getUsername() const { return username; }
    std::string getPasswordHash() const { return passwordHash; }
};

class AuthSystem {
private:
    const std::string dbFolder = "database/";

    std::string getFilePath(const std::string& username) const {
        return dbFolder + username + ".txt";
    }

    bool userExists(const std::string& username) const {
        std::ifstream file(getFilePath(username));
        return file.good();
    }

    void createDatabaseDirectory() const {
#ifdef _WIN32
        mkdir(dbFolder.c_str());
#else
        mkdir(dbFolder.c_str(), 0777);
#endif
    }

public:
    AuthSystem() {
        createDatabaseDirectory();
    }

    bool registerUser() {
        std::string username, password;

        std::cout << "\n--- USER REGISTRATION ---\n";
        std::cout << "Enter username: ";
        std::cin >> username;

        if (username.empty() || username.find(' ') != std::string::npos) {
            std::cout << "Error: Username cannot be empty or contain spaces.\n";
            return false;
        }

        if (userExists(username)) {
            std::cout << "Error: Username '" << username << "' already exists. Please choose another.\n";
            return false;
        }

        std::cout << "Enter password: ";
        std::cin >> password;

        if (password.length() < 4) {
            std::cout << "Error: Password must be at least 4 characters long.\n";
            return false;
        }

        User newUser(username, password);

        std::ofstream file(getFilePath(username));
        if (file.is_open()) {
            file << newUser.getUsername() << "\n";
            file << newUser.getPasswordHash() << "\n";
            file.close();
            std::cout << "Success: Registration successful for user '" << username << "'!\n";
            return true;
        } else {
            std::cout << "Error: Unable to save user data.\n";
            return false;
        }
    }

    bool loginUser() {
        std::string username, password;

        std::cout << "\n--- USER LOGIN ---\n";
        std::cout << "Enter username: ";
        std::cin >> username;

        if (!userExists(username)) {
            std::cout << "Error: Username '" << username << "' does not exist.\n";
            return false;
        }

        std::cout << "Enter password: ";
        std::cin >> password;

        std::ifstream file(getFilePath(username));
        if (file.is_open()) {
            std::string storedUser, storedHash;
            std::getline(file, storedUser);
            std::getline(file, storedHash);
            file.close();

            if (hashPassword(password) == storedHash) {
                std::cout << "Success: Welcome back, " << username << "! Login successful.\n";
                return true;
            } else {
                std::cout << "Error: Incorrect password. Access denied.\n";
                return false;
            }
        }

        std::cout << "Error: Failed to read account details.\n";
        return false;
    }
};

int main() {
    AuthSystem auth;
    int choice;

    while (true) {
        std::cout << "\n====================================\n";
        std::cout << "     LOGIN & REGISTRATION SYSTEM     \n";
        std::cout << "====================================\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                auth.registerUser();
                break;
            case 2:
                auth.loginUser();
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid selection. Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}