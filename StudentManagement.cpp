#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Student.cpp"
#include "InputValidator.cpp"


using namespace std;

class StudentManagement {
private:
	vector<Student> students;
    InputValidator IV;
public:
    void displayAllStudents(const vector<Student>& students) {
    cout << "                                    All Students' Information\n";
    cout << "========================================================================================================\n";
    cout << "  ID   |        Name        |  Sex  |  Birth of Date  |       Course       |      Phone Number     \n";
    cout << "========================================================================================================\n";

    for (const auto& student : students) {
        cout << setw(6) << student.getID() << " | "
             << setw(18) << student.getName() << " | "
             << setw(5) << student.getSex() << " | "
             << setw(15) << student.getDOB() << " | "
             << setw(16) << student.getCourse() << " | "
             << setw(18) << student.getPhonenumber() << endl;
    }

    cout << "========================================================================================================\n";
    }
    
    void addNewStudents(vector<Student>& students) {
    int numStudents;
    cout << "How many students do you want to add? ";
    cin >> numStudents;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numStudents; ++i) {
        int id, phone_number;
        string idStr, phoneNumberStr,name, sex, dob, course;

        cout << "\nEnter Details For Student(s) " << i + 1 << ":\n";

        // Validate and get ID
        do {
            cout << "Enter Student's ID (MUST BE POSITIVE NUMBER): ";
            cin >> idStr;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!IV.isValidId(idStr)) {
                cout << "Invalid ID. Please enter a positive number.\n";
            }
        } while (!IV.isValidId(idStr));
        id = stoi(idStr);

        // Validate and get Name
        do {
            cout << "Enter Student's Name (CANNOT BE A NUMBER): ";
            //cin.ignore();
            getline(cin, name);
            if (!IV.isValidName(name)) {
                cout << "Invalid name. Please enter a valid name without numbers.\n";
            }
        } while (!IV.isValidName(name));

        // Validate and get Sex
        do {
            cout << "Enter Student's Sex (M/F): ";
            getline(cin, sex);
            if (!IV.isValidSex(sex)) {
                cout << "Invalid sex. Please enter 'M' or 'F'.\n";
            }
        } while (!IV.isValidSex(sex));

        // Validate and get Date of Birth
        do {
            cout << "Enter Student's Date of Birth (DD/MM/YYYY): ";
            getline(cin, dob);
            if (!IV.isValidDOB(dob)) {
                cout << "Invalid date of birth. Please enter a valid date in the format DD/MM/YYYY.\n";
            }
        } while (!IV.isValidDOB(dob));

        // Validate and get Course
        do {
            cout << "Enter Course: ";
            getline(cin, course);
            if (!IV.isValidCourse(course)) {
                cout << "Invalid course. Please enter a valid course without numbers.\n";
            }
        } while (!IV.isValidCourse(course));

        // Validate and get Phone Number
        do {
            cout << "Enter Student's Phone Number (MUST BE A POSITIVE NUMBER): ";
            cin >> phoneNumberStr;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!IV.isValidPhoneNumber(phoneNumberStr)) {
                cout << "Invalid phone number. Please enter a positive number.\n";
            }
        } while (!IV.isValidPhoneNumber(phoneNumberStr));
        phone_number = stoi(phoneNumberStr);

        students.push_back(Student(id, name, sex, dob, course, phone_number));

        cout << "Student " << i + 1 << " added successfully!\n";
    }
}
    void updateStudentInformationById(vector<Student>& students) {
    int updateID;
    bool studentFound = false;

    do {
        cout << "Enter Student's ID to update student's information: ";
        cin >> updateID;

        // Find the student in the vector based on ID
        auto it = find_if(students.begin(), students.end(), [updateID](const Student& student) {
            return student.getID() == updateID;
        });

        if (it != students.end()) {
            studentFound = true;
            // Student found, update information
            updateStudentInformation(*it);
        } else {
            cout << "Student with ID " << updateID << " not found. Please try again.\n";
        }
    } while (!studentFound);
}

void updateStudentInformationByName(vector<Student>& students) {
    string updateName;
    bool studentFound = false;

    do {
        cout << "Enter Student's Name to update student's information: ";
        getline(cin, updateName);

        // Find the student in the vector based on Name
        auto it = find_if(students.begin(), students.end(), [updateName](const Student& student) {
            return student.getName() == updateName;
        });

        if (it != students.end()) {
            studentFound = true;
            // Student found, update information
            updateStudentInformation(*it);
        } else {
            cout << "Student with Name " << updateName << " not found. Please try again.\n";
        }
    } while (!studentFound);
}

void updateStudentInformation(Student& student) {
    // Student found, update information
    int id, phone_number;
    string idStr, phoneNumberStr, name, sex, dob, course;

    do {
        cout << "Enter Student's New ID: ";
        cin >> idStr;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!IV.isValidId(idStr));
    id = stoi(idStr);


    // Validate Name
    do {
        cout << "Enter Student's New Name: ";
        getline(cin, name);
    } while (!IV.isValidName(name));

    // Validate Sex
    do {
        cout << "Enter Student's New Sex (M/F): ";
        getline(cin, sex);
    } while (!IV.isValidSex(sex));

    // Validate Date of Birth
    do {
        cout << "Enter Student's New DOB (DD/MM/YYYY): ";
        getline(cin, dob);
    } while (!IV.isValidDOB(dob));

    // Validate Course
    do {
        cout << "Enter Student's New Course: ";
        getline(cin, course);
    } while (!IV.isValidCourse(course));

    // Validate Phone Number
    do {
        cout << "Enter Student's New Phone Number: ";
        cin >> phoneNumberStr;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!IV.isValidPhoneNumber(phoneNumberStr));
    phone_number = stoi(phoneNumberStr);


    // Update the student's information
    student.setID(id);
    student.setName(name);
    student.setSex(sex);
    student.setDob(dob);
    student.setCourse(course);
    student.setPhonenumber(phone_number);

    cout << "STUDENT'S INFORMATION UPDATED SUCCESSFULLY!\n";
}


void updateStudentInformation(vector<Student>& students) {
    int choice;
    cout << "Choose update option: \n";
    cout << "1. Update by ID\n";
    cout << "2. Update by Name\n";
    cin >> choice;

    if (choice == 1) {
        updateStudentInformationById(students);
    } else if (choice == 2) {
        cin.ignore();  
        updateStudentInformationByName(students);
    } else {
        cout << "Invalid choice. Please try again.\n";
    }
}


    void searchStudent(const vector<Student>& students) {
        int searchChoice;
        cout << "Search by:\n";
        cout << "1. Student's ID\n";
        cout << "2. Student's Name\n";
        cout << "Enter your choice: ";
        searchChoice = IV.validateChoice();

        if (searchChoice == 1) {
            // Search by Student ID
            int searchID;
            cout << "Enter Student ID to search: ";
            cin >> searchID;

            auto it = find_if(students.begin(), students.end(), [searchID](const Student& student) {
                return student.getID() == searchID;
                });

            if (it != students.end()) {

                cout << "                                              STUDENT FOUND!\n";
                cout << "========================================================================================================\n";
                cout << "  ID   |        Name        |  Sex  |  Birth of Date  |       Course       |      Phone Number     \n";
                cout << "========================================================================================================\n";

                cout << setw(6) << it->getID() << " | "
                        << setw(18) << it->getName() << " | "
                        << setw(5) << it->getSex() << " | "
                        << setw(15) << it->getDOB() << " | "
                        << setw(14) << it->getCourse() << " | "
                        << setw(14) << it->getPhonenumber() << endl;
                cout << "========================================================================================================\n";
            }
            else {
                cout << "Student with ID " << searchID << " not found.\n";
            }
        }
        else if (searchChoice == 2) {
            // Search by Student Name
            string searchName;
            cout << "Enter Student's Name To Search: ";
            getline(cin, searchName);

            auto it = find_if(students.begin(), students.end(), [searchName](const Student& student) {
                return student.getName() == searchName;
                });

            if (it != students.end()) {
                cout << "STUDENT FOUND!\n";
                cout << "Student's ID: " << it->getID() << endl;
                cout << "Name: " << it->getName() << endl;
                cout << "Sex: " << it->getSex() << endl;
                cout << "Date of Birth: " << it->getDOB() << endl;
                cout << "Course: " << it->getCourse() << endl;
            }
            else {
                cout << "Student with Name \"" << searchName << "\" not found.\n";
            }
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    void deleteStudent(vector<Student>& students) {
    int deleteChoice;
    cout << "Delete by:\n";
    cout << "1. Student's ID\n";
    cout << "2. Student's Name\n";
    cout << "Enter your choice: ";
    
    deleteChoice = IV.validateChoice(); 

    if (deleteChoice == 1) {
        // Delete by Student ID
        int deleteID;
        cout << "Enter Student ID to delete: ";
        cin >> deleteID;

        auto it = find_if(students.begin(), students.end(), [deleteID](const Student& student) {
            return student.getID() == deleteID;
        });

        if (it != students.end()) {
            cout << "STUDENT DELETED SUCCESSFULLY:\n";
            
            students.erase(it);
        } else {
            cout << "STUDENT WITH ID " << deleteID << " NOT FOUND.\n";
        }
    } else if (deleteChoice == 2) {
        // Delete by Student Name
        string deleteName;
        cout << "Enter Student's Name To Delete: ";
        cin.ignore(); 
        getline(cin, deleteName);

        auto it = find_if(students.begin(), students.end(), [deleteName](const Student& student) {
            return student.getName() == deleteName;
        });

        if (it != students.end()) {
            cout << "STUDENT DELETED SUCCESSFULLY:\n";
            
            students.erase(it);
        } else {
            cout << "STUDENT WITH NAME \"" << deleteName << "\" NOT FOUND!\n";
        }
    } else {
        cout << "Invalid choice. Please try again.\n";
    }
}

    
    void sortStudents(std::vector<Student>& students) {
            int sortChoice;
            cout << "Sort by:\n";
            cout << "1. Student's ID\n";
            cout << "2. Student's Name\n";
            cout << "Enter your choice: ";
            sortChoice = IV.validateChoice();

            int sortOrder;
            cout << "Sort order:\n";
            cout << "1. Ascending\n";
            cout << "2. Descending\n";
            cout << "Enter your choice: ";
            sortOrder = IV.validateChoice();

            if (sortOrder != 1 && sortOrder != 2) {
                cout << "Invalid sort order choice. Defaulting to Ascending.\n";
                sortOrder = 1;
            }

            if (sortChoice == 1) {
                // Sort by Student ID
                sort(students.begin(), students.end(), [sortOrder](const Student& a, const Student& b) {
                    if (sortOrder == 1) {
                        return a.getID() < b.getID();
                    } else {
                        return a.getID() > b.getID();
                    }
                });
                cout << "Students sorted by ID.\n";
            } else if (sortChoice == 2) {
                // Sort by Student Name
                sort(students.begin(), students.end(), [sortOrder](const Student& a, const Student& b) {
                    if (sortOrder == 1) {
                        return a.getName() < b.getName();
                    } else {
                        return a.getName() > b.getName();
                    }
                });
                cout << "Students sorted by Name.\n";
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        }

    void saveStudents(const vector<Student>& students, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& student : students) {
            outputFile << student.getID() << ","
                        << student.getName() << ","
                        << student.getSex() << ","
                        << student.getDOB() << ","
                        << student.getCourse() << ","
                        << student.getPhonenumber() << "\n";
        }

        outputFile.close();
        cout << "Student data saved successfully.\n";
    } else {
        cerr << "Unable to open the file for saving.\n";
    }
}
};