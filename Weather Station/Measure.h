#pragma once
#include<string>
#include<iostream>
#include<stdexcept>
using namespace std;

class Measure {
private:
    static int numOfMeasures;
protected:
    string name;
    int number;
public:
    Measure(string N = "", int Num = 0)
    {
        name = N;
        number = Num;
        numOfMeasures++;
    }
    Measure(Measure& s)
    {
        name = s.name;
        number = s.number;
        numOfMeasures++;
    }
    virtual ~Measure()
    {
        numOfMeasures--;
        cout << "Measure " << number << " " << name << " destroyed \n";
    }
    static int count()
    {
        return numOfMeasures;
    }
    string getName()
    {
        return name;
    }
    int getNumber()
    {
        return number;
    }
    void setName(string N)
    {
        name = N;
    }
    void setNumber(int num)
    {
        number = num;
    }
    virtual float getResult() = 0;
    virtual float getMax() = 0;
    virtual float getMin() = 0;
};

class MinMeasure : public Measure
{
protected:
    float first,sec,third;
public:
    MinMeasure(int Num = 0, string N = "", float f = 0.0, float s = 0.0, float th = 0.0) : Measure(N, Num)
    {
        first = f;
        sec = s;
        third = th;
    }
    ~MinMeasure()
    {
        cout << "MinMeasure destroyed \n";
    }

    float getFirst()
    {
        return first;
    }
    float getSecond()
    {
        return sec;
    }
    float getThird()
    {
        return third;
    }
    void setFirst(float f)
    {
        first = f;
    }
    void setSecond(float s)
    {
        sec = s;
    }
    void setThird(float th)
    {
        third = th;
    }
    float getResult()
    {
        float min = first;
        if (min > sec)
            min = sec;
        if (min > third)
            min = third;
        return min;
    }
    float getMax()
    {
        float max = first;
        if (max < sec)
            max = sec;
        if (max < third)
            max = third;
        return max;
    }
    float getMin()
    {
        float min = first;
        if (min > sec)
            min = sec;
        if (min > third)
            min = third;
        return min;
    }
};

class MaxMeasure : public Measure
{
protected:
    float first, sec, third;
public:
    MaxMeasure(int Num = 0, string N = "", float f = 0.0, float s = 0.0, float th = 0.0) : Measure(N, Num)
    {
        first = f;
        sec = s;
        third = th;
    }
    ~MaxMeasure()
    {
        cout << "MaxMeasure destroyed \n";
    }

    float getFirst()
    {
        return first;
    }
    float getSecond()
    {
        return sec;
    }
    float getThird()
    {
        return third;
    }
    void setFirst(float f)
    {
        first = f;
    }
    void setSecond(float s)
    {
        sec = s;
    }
    void setThird(float th)
    {
        third = th;
    }
    float getResult()
    {
        float min = first;
        if (min < sec)
            min = sec;
        if (min < third)
            min = third;
        return min;
    }
    float getMin()
    {
        float min = first;
        if (min > sec)
            min = sec;
        if (min > third)
            min = third;
        return min;
    }
    float getMax()
    {
        float max = first;
        if (max < sec)
            max = sec;
        if (max < third)
            max = third;
        return max;
    }
};

class AvgMeasure : public Measure
{
protected:
    float first, sec, third;
public:
    AvgMeasure(int Num = 0, string N = "", float f = 0.0, float s = 0.0, float th = 0.0) : Measure(N, Num)
    {
        first = f;
        sec = s;
        third = th;
    }
    ~AvgMeasure()
    {
        cout << "AverageMeasure destroyed \n";
    }

    float getFirst()
    {
        return first;
    }
    float getSecond()
    {
        return sec;
    }
    float getThird()
    {
        return third;
    }
    void setFirst(float f)
    {
        first = f;
    }
    void setSecond(float s)
    {
        sec = s;
    }
    void setThird(float th)
    {
        third = th;
    }
    float getResult()
    {
        return (first + sec + third) / 3;
    }
    float getMin()
    {
        float min = first;
        if (min > sec)
            min = sec;
        if (min > third)
            min = third;
        return min;
    }
    float getMax()
    {
        float max = first;
        if (max < sec)
            max = sec;
        if (max < third)
            max = third;
        return max;
    }
};