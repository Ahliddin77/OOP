#pragma once
#include <string>
using namespace std;

class Student {
private:
    string  firstname;
    string  surname;
    float* listOfMarks;
    int numOfMarks;
    int index;
public:
    Student(int modIndex = 0, string  modFirstname = " ", string modSurname = " ");
    Student(const Student& st);
    Student& operator = (const Student& st);
    ~Student();
    void setFirtsname(string nameToAssign);
    void setSurname(string nameToAssign);
    void setIndex(int indexToAssign);
    string getFirstname() const;
    string getSurname() const;
    int getIndex() const;
    void addMark(float newMark);
    float avgMark() const;
    friend ostream& operator <<(ostream& os, const Student& st);
};

ostream& operator <<(ostream& os, const Student& st);

class Group {
private:
    int groupNum;
    Student* listOfStudents;
    int numOfStudents = 0;
public:
    Group(int modGroupNum = 0);
    Group(const Group& gr);
    Group& operator = (const Group& gr);
    ~Group();
    void setNumber(int indexToAssign);
    int getNumber() const;
    void addMark(Student newStudent);
};
