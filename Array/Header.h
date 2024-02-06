#pragma once
class Array {
private:
    int length;
    double* data;
public:
    Array(int L);
    ~Array();
    void print();
    void read();
    Array(const Array& arr);
    double avg();
    double minum();
    double maxim();
    void reverseArr();
    Array sort(bool s);
};
