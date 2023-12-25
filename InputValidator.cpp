#include <iostream>
#include <cctype>
#include <sstream>
#include <limits>
#include <regex>
#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

using namespace std;

class InputValidator {
public:
    int validateChoice() const {
        int input;
        cout << "Enter your choice: ";

        while (!(cin >> input) || cin.peek() != '\n' || input <= 0) {
            cout << "Invalid input. Please enter a valid positive integer.\n";

            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            // Prompt again if the input is not a positive integer
            cout << "Enter your choice: ";
        }
        return input;
    }

    static bool isValidId(const string& idStr) {
    // Check if idStr is a non-negative integer without letters
    return regex_match(idStr, regex("^\\d+$"));
    }


    static bool isValidName(const string& name) {
        return regex_match(name, regex("^[A-Za-z ]+$"));
    }

    static bool isValidSex(const string& sex) {
        return (sex == "M" || sex == "F");
    }

    static bool isValidDOB(const string& dob) {
        return regex_match(dob, regex("^\\d{2}/\\d{2}/\\d{4}$"));
    }

    static bool isValidCourse(const string& course) {
        return regex_match(course, regex("^[A-Za-z ]+$"));
    }

    static bool isValidPhoneNumber(const string& phoneNumberStr) {
    // Check if phoneNumberStr is a positive integer without letters, allowing spaces
    return regex_match(phoneNumberStr, regex("^\\s*0*[1-9]\\d*\\s*$"));
}

};
#endif 
