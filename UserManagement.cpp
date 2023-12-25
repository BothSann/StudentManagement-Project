#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Authentication.cpp"

using namespace std;


class UserManagement : public User {  //Inheriting from User class
private:
    Authentication authentication;
    bool loggedIn;

public:
    UserManagement() : loggedIn(false) {}

    void registerUser() {
        string username, password;

        cout << "-Enter username for registration: ";
        cin >> username;

        cout << "-Enter password for registration: ";
        cin >> password;

        authentication.registerUser(username, password);
    }

    void loginUser() {
        string username, password;

        cout << "-Enter username for login: ";
        cin >> username;

        cout << "-Enter password for login: ";
        cin >> password;


        if (authentication.loginUser(username, password)) {
            loggedIn = true;
            cout << "-Redirecting to the main menu...\n";
        }
    }

    bool isLoggedIn() const {
        return loggedIn;
    }

    void logout() {
        loggedIn = false;
    }


    void saveCredentialsToFile() {
        ofstream file("user_credentials.txt", ios::app); // Open the file in append mode
        if (file.is_open()) {
            file << "Username: " << getUsername() << "\n";
            file << "Password: " << getPassword() << "\n";
            file << "-----------------------------\n";
            file.close();
            cout << "-Credentials saved to user_credentials.txt.\n";
        } else {
            cout << "-Error: Unable to save credentials to file.\n";
        }
    }
};