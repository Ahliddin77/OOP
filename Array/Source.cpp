#include "Header.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Array::Array(int L) {
    if (L < 0) throw logic_error("Negative length");
    else if (L == 0) {
        length = L;
        data = nullptr;
    }
    else {
        length = L;
        data = new double[L];
    }
}
Array::~Array() {
    if (length > 0)
        delete[] data;
    cout << "Array of length " << length << " deleted" << endl;
}
void Array::print() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
void Array::read() {
    for (int i = 0; i < length; i++) {
        cout << "Array[" << i + 1 << "]" << " = ";
        cin >> data[i];
    }
}
Array::Array(const Array& arr) {
    length = arr.length;
    data = new double[length];
    for (int i = 0; i < arr.length; i++) {
        data[i] = arr.data[i];
    }
}
double Array::avg() {
    if (length <= 0) {
        throw logic_error("Length value = 0 warning");
    }
    else {
        double sum = 0.0;
        for (int i = 0; i < length; i++) {
            sum += data[i];
        }
        return sum / length;
    }
}
double Array::minum() {
    if (length <= 0) {
        throw logic_error("Length value = 0 warning");
    }
    else {
        double minum = data[0];
        for (int i = 1; i < length; i++) {
            if (minum > data[i])
                minum = data[i];
        }
        return minum;
    }
}
double Array::maxim() {
    if (length == 0) {
        throw logic_error("Length value = 0 warning");
    }
    else {
        double maxim = data[0];
        for (int i = 1; i < length; i++) {
            if (maxim < data[i])
                maxim = data[i];
        }
        return maxim;
    }
}
void Array::reverseArr() {
    if (length == 0) {
        throw logic_error("Length value = 0 warning");
    }
    else {
        int i = 0;
        Array temp(*this);
        for (int j = length - 1; j >= 0; j--) {
            data[i] = temp.data[j];
            i++;
        }
    }
}
Array Array::sort(bool s) {
    Array temp(*this);
    if (s == true) {
        int tmp;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j + 1 < length - i; j++)
            {
                if (temp.data[j] > temp.data[j + 1])
                {
                    tmp = temp.data[j];
                    temp.data[j] = temp.data[j + 1];
                    temp.data[j + 1] = tmp;
                }
            }
        }
    }
    else if (s == false) {
        int tmp;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j + 1 < length - i; j++)
            {
                if (temp.data[j] < temp.data[j + 1])
                {
                    tmp = temp.data[j];
                    temp.data[j] = temp.data[j + 1];
                    temp.data[j + 1] = tmp;
                }
            }
        }
    }
    return temp;
}