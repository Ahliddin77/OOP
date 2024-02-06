#pragma once
#include<string>
#include<iostream>
#include<stdexcept>
#include<math.h>
using namespace std;

class Case {
private:
    static int numOfCase;
protected:
    string label;
    int color;
public:
    Case(string L = "", int C = 0x000000)
    {
        label = L;
        color = C;
        numOfCase++;
    }
    Case(Case& s) 
    {
        label = s.label;
        color = s.color;
        numOfCase++;
    }
    virtual ~Case()
    {
        numOfCase--;
        cout << "Case " << label << " " << showbase << hex << color << dec <<" destroyed \n";
    }
    static int count()
    {
        return numOfCase;
    }
    string getLabel()
    {
        return label;
    }
    int getColor()
    {
        return color;
    }
    void setLabel(string L)
    {
        label = L;
    }
    void setColor(int C)
    {
        color = C;
    }
    virtual float getCapacity() = 0;
};

class BrickCase : public Case
{
protected:
    float length;
    float width;
    float height;
public:
    BrickCase(string L = "", int C = 0x000000, float ln = 0.0, float w = 0.0, float h = 0.0) : Case(L, C)
    {
        if (ln < 0 || w < 0 || h < 0) throw logic_error("Wrong data");
        length = ln;
        width = w;
        height = h;
    }
    ~BrickCase()
    {
        cout << "BrickCase destroyed \n";
    }

    float getLength()
    {
        return length;
    }
    float getWidth()
    {
        return width;
    }
    float getHeight()
    {
        return height;
    }
    void setLength(float ln)
    {
        if (ln < 0) throw logic_error("Wrong input");
        length = ln;
    }
    void setWidth(float w)
    {
        if (w < 0) throw logic_error("Wrong input");
        width = w;
    }
    void setHeight(float h)
    {
        if (h < 0) throw logic_error("Wrong input");
        height = h;
    }
    float getCapacity()
    {
        return length * width * height;
    }
};

class TubeCase : public Case
{
protected:
    float radius;
    float height;
public:
    TubeCase(string L = "", int C = 0x000000, float r = 0.0, float h = 0.0) : Case(L, C)
    {
        if (r < 0 || h < 0) throw logic_error("Wrong data");
        radius = r;
        height = h;
    }
    ~TubeCase()
    {
        cout << "TubeCase destroyed \n";
    }

    float getRadius()
    {
        return radius;
    }
    float getHeight()
    {
        return height;
    }
    void setRadius(float r)
    {
        if (r < 0) throw logic_error("Wrong input");
        radius = r;
    }
    void setHeight(float h)
    {
        if (h < 0) throw logic_error("Wrong input");
        height = h;
    }
    float getCapacity()
    {
        double pi = 2 * acos(0.0);
        return pi * pow(radius, 2) * height;
    }
};

class PrismCase : public Case
{
protected:
    float base;
    float height;
public:
    PrismCase(string L = "", int C = 0x000000, float b = 0.0, float h = 0.0) : Case(L, C)
    {
        if (b < 0 || h < 0) throw logic_error("Wrong data");
        base = b;
        height = h;
    }
    ~PrismCase()
    {
        cout << "PrismCase destroyed \n";
    }

    float getBase()
    {
        return base;
    }
    float getHeight()
    {
        return height;
    }
    void setBase(float b)
    {
        if (b < 0) throw logic_error("Wrong input");
        base = b;
    }
    void setHeight(float h)
    {
        if (h < 0) throw logic_error("Wrong input");
        height = h;
    }
    float getCapacity()
    {
        return base * height;
    }
};