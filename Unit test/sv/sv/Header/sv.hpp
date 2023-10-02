#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"


using namespace std;

class Student{
public:
    Student(int id, string name, double score);
    int getID();
    string getName();
    double getScore();
private:
    int id;
    string name;
    double score;
};

Student::Student(int id, string name, double score) : id(id), name(name), score(score) {}

int Student::getID() {
    return id;
}

string Student::getName() {
    return name;
}

double Student::getScore() {
    return score;
}

class StudentManagement {
public:
    void addStudent(int id, string name, double score);
    bool delStudent(int id);
    double getScore();
    vector<Student> getListStudent();
private:
    vector<Student> listStudent;
};

void StudentManagement::addStudent(int id, string name, double score) {
    listStudent.emplace_back(id, name, score);
}

bool StudentManagement::delStudent(int id) {
    auto it = remove_if(listStudent.begin(), listStudent.end(),
        [id](Student& sv) {return sv.getID() == id; });

    if (it != listStudent.end()) {
        listStudent.erase(it, listStudent.end());
        return true;
    }
    return false;
}

double StudentManagement::getScore() {
    if (listStudent.empty()) return 0.0;

    double tongDiem = 0.0;

    for (Student& sv : listStudent) {
        tongDiem += sv.getScore();
    }
    return tongDiem / listStudent.size();
}

vector<Student> StudentManagement::getListStudent() {
    return listStudent;
}
