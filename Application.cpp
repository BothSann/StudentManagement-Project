#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include "Student.cpp"
#include "Authentication.cpp"
#include "StudentManagement.cpp"
#include "UserManagement.cpp"
#include "InputValidator.cpp"
using namespace std;
class Application {
private:
    vector<Student> students;
    Authentication authentication;
    StudentManagement SM;
    UserManagement UM;
    InputValidator IV;
    bool loggedIn;
public:
    Application (){}

    void welcomeScreen() {
        cout << "==========================================\n";
        cout << "                      MENU\n";
        cout << "==========================================\n";
        cout << "[1]. Register\n";
        cout << "[2]. Login\n";
        cout << "[3]. Exit\n";
    }

    void showMenu() {
        cout << "\n================= Welcome to IT STEP ACADEMY =================\n";
        cout << "[1]. Add New Student\n";
        cout << "[2]. Update Student Information\n";
        cout << "[3]. Display All Students' Information\n";
        cout << "[4]. Search Student\n";
        cout << "[5]. Delete Student\n";
        cout << "[6]. Sort Students\n";
        cout << "[7]. Save Students Data\n";
        cout << "[8]. Logout\n";
        cout << "[9]. Exit\n";
    }

    
    void run() {
        int choice;
        do {
            if (!UM.isLoggedIn()) {
                welcomeScreen();
                choice = IV.validateChoice();

                switch (choice) {
                case 1:
                    UM.registerUser();
                    break;
                case 2:
                    UM.loginUser();
                    break;
                case 3:
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            }
            else {
                // User is logged in, display the main menu
                
                showMenu();    
                choice = IV.validateChoice();
                

                switch (choice) {
                case 1:
                    system("cls");
                    SM.addNewStudents(students);
                    break;
                case 2:
                    system("cls");  
                    SM.updateStudentInformation(students);
                    break;
                case 3:
                    system("cls");
                    SM.displayAllStudents(students);
                    break;
                case 4:
                    system("cls");
                    SM.searchStudent(students);
                    break;
                case 5:
                    system("cls");
                    SM.deleteStudent(students);
                    break;
                case 6:
                    system("cls");
                    SM.sortStudents(students);
                    break;
                case 7:
                    system("cls");
                    SM.saveStudents(students, "student_data.txt");
                    UM.saveCredentialsToFile();
                    break;
                case 8:
                    system("cls");
                    UM.logout();
                    cout << "Logged out successfully. Redirecting to the welcome screen...\n";
                    break;
                case 9:
                    system("cls");
                    cout << "Exiting the program. Goodbye!\n";
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } while (true);
    }
};