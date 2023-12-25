#pragma once
#include <iostream>
using namespace std;
class Student {
private:
    int id;
    string name;
    string sex;
    string dob;
    string course;
    int phone_number;

public:
    Student() {
        id = 0;
        name = "N/A";
        sex = "N/A";
        dob = "N/A";
        course = "N/A";
        phone_number = 0;
    }

    Student(int i, string n, string s, string d, string c, int p) {
        id = i;
        name = n;
        sex = s;
        dob = d;
        course = c;
        phone_number = p;
    }

    void setID(int i) {
        id = i;
    }
    void setName(string n) {
        name = n;
    }
    void setSex(string s) {
        sex = s;
    }
    void setDob(string d) {
            dob = d;
    }
    void setCourse(string c) {
        course = c;
    }
    void setPhonenumber(int p) {
        phone_number = p;
    }
    int getID() const {
        return id;
    }
    string getName() const {
        return name;
    }
    string getSex() const {
        return sex;
    }
    string getDOB() const {
        return dob;
    }
    string getCourse() const {
        return course;
    }
    int getPhonenumber() const {
        return phone_number;
    }
};