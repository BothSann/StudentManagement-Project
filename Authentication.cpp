#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "User.cpp"
using namespace std;
class Authentication {
private:
    vector<User> users;

public:

    bool registerUser(const string& username, const string& password) {
        // Check if the username is already taken
        
        for (const auto& user : users) {
            if (user.getUsername() == username) {
                cout << "Username '" << username << "' is already taken. Please choose another username.\n";
                return false;
            }
        }

        // If the username is unique, register the user
        users.push_back(User(username, password));
        cout << "Registration successful for username '" << username << "'.\n";
        return true;
    }



    bool loginUser(const string& username, const string& password) {
        // Find the user in the vector based on username
        
        auto it = find_if(users.begin(), users.end(), [username](const User& user) {
            return user.getUsername() == username;
            });

        if (it != users.end() && it->getPassword() == password) {
            cout << "Login successful for username '" << username << "'.\n";
            return true;
        }
        else {
            cout << "Invalid username or password. Please try again.\n";
            return false;
        }
    }
};