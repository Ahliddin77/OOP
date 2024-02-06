#include <iostream>
#include "Header.h"
#include <stdexcept>
using namespace std;
Student::Student(int modIndex, string  modFirstname, string modSurname) {
    firstname = modFirstname;
    surname = modSurname;
    index = modIndex;
    listOfMarks = nullptr;
    numOfMarks = 0;
}
Student::Student(const Student& st) {
    firstname = st.firstname;
    surname = st.surname;
    index = st.index;
    numOfMarks = st.numOfMarks;
    if (st.listOfMarks == nullptr)
        listOfMarks = nullptr;
    else {
        listOfMarks = new float[st.numOfMarks];
        for (int i = 0; i < numOfMarks; i++)
            listOfMarks[i] = st.listOfMarks[i];
    }
}
Student& Student::operator = (const Student& st) {
    if (this != &st) {
        firstname = st.firstname;
        surname = st.surname;
        index = st.index;
        if (listOfMarks != nullptr)
            delete[] listOfMarks;
        if (st.listOfMarks == nullptr)
            listOfMarks = nullptr;
        else {
            listOfMarks = new float[st.numOfMarks];
            for (int i = 0; i < numOfMarks; i++)
                listOfMarks[i] = st.listOfMarks[i];
        }
    }
    return *this;
}
Student::~Student() {
    if (listOfMarks != nullptr)
        delete[] listOfMarks;
    cout << "Student " << firstname << " " << surname <<" Removed " << endl;
}
void Student::setFirtsname(string nameToAssign) {
    for (int i = 0;i < nameToAssign.length();i++)
    {
        if (nameToAssign[i] == ' ' || isdigit(nameToAssign[i])) throw logic_error("incorrect name");
    }
    firstname = nameToAssign;
}
void Student::setSurname(string nameToAssign) {
    for (int i = 0;i < nameToAssign.length();i++)
    {
        if (nameToAssign[i] == ' ' || isdigit(nameToAssign[i])) throw logic_error("incorrect name");
    }
    surname = nameToAssign;
}
void Student::setIndex(int indexToAssign) {
    index = indexToAssign;
}
string Student::getFirstname() const {
    return firstname;
}
string Student::getSurname() const {
    return surname;
}
int Student::getIndex() const {
    return index;
}
void Student::addMark(float newMark) {
    if (newMark <= 0) throw logic_error("Invalid Mark");

    float* temp;
    temp = new float[numOfMarks + 1];
    for (int i = 0; i < numOfMarks; i++)
        temp[i] = listOfMarks[i];
    temp[numOfMarks] = newMark;

    delete[] listOfMarks;
    listOfMarks = temp;
    numOfMarks++;
}
float Student::avgMark() const {
    float sum = 0;
    for (int i = 0; i < numOfMarks;i++) {
        if (listOfMarks[i] > 0)
            sum += listOfMarks[i];
    }
    return sum/numOfMarks;
}
ostream& operator <<(ostream& os, const Student& st) {
    os << "Firstname:       " << st.firstname << endl;
    os << "Surname  :       " << st.surname << endl;
    os << "Index    :       " << st.index << endl;
    if (st.numOfMarks > 0) {
        os << "Mark:  ";
        for (int i = 0; i < st.numOfMarks; i++)
            cout << st.listOfMarks[i] << " ";
        cout << endl;
    }
    else
        cout << "No Grades History";
    cout << endl;
    return os;
}


Group::Group(int modGroupName) {
    groupNum = modGroupName;
    listOfStudents = nullptr;
    numOfStudents = 0;
}
Group::Group(const Group& gr) {
    groupNum = gr.groupNum;
    numOfStudents = gr.numOfStudents;
    if (gr.listOfStudents == nullptr)
        listOfStudents = nullptr;
    else {
        listOfStudents = new Student[gr.numOfStudents];
        for (int i = 0; i < numOfStudents; i++)
            listOfStudents[i] = gr.listOfStudents[i];
    }
}
Group& Group::operator = (const Group& gr) {
    if (this != &gr) {
        groupNum = gr.groupNum;
        if (listOfStudents != nullptr)
            delete[] listOfStudents;
        if (gr.listOfStudents == nullptr)
            listOfStudents = nullptr;
        else {
            listOfStudents = new Student[gr.numOfStudents];
            for (int i = 0; i < numOfStudents; i++)
                listOfStudents[i] = gr.listOfStudents[i];
        }
    }
    return *this;
}
Group::~Group() {
    if (listOfStudents != nullptr)
        delete[] listOfStudents;
    cout << "Group " << groupNum << " Removed " << endl;
}
void Group::setNumber(int indexToAssign) {
    if (indexToAssign < 0) throw logic_error("Invalid group number");
    groupNum = indexToAssign;
}
int Group::getNumber() const {
    return groupNum;
}
