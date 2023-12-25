#pragma once
#include <iostream>

using namespace std;
class User {
private:
    string username;
    string password;

public:
    User() {
        username = "";
        password = "";
    }

    User(const string& u, const string& p) {
        username = u;
        password = p;
    }

    string getUsername() const{
        return username;
    }

    string getPassword() const {
        return password;
    }

};