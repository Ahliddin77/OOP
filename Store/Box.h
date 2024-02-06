#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <math.h>
using namespace std;

class Box
{
private:
	static int numOfBox;
protected:
	string label;
	int number;
public:
	Box(string L = "", int N = 0)
	{
		for (int i = 0; i < L.length(); i++) {
			if (L[i] == ' ' || !isalpha(L[i])) throw logic_error("Incorrect Label");
		}
		if (N <= 0) throw logic_error("Wrong number");
		label = L;
		number = N;
		numOfBox++;
	}
	Box(Box& B)
	{
		label = B.label;
		number = B.number;
		numOfBox++;
	}
	virtual ~Box()
	{
		numOfBox--;
		cout << label << " " << number << " destroyed\n";
	}
	string getLabel()
	{
		return label;
	}
	int getNumber()
	{
		return number;
	}
	void setLabel(string newLabel)
	{
		for (int i = 0; i < newLabel.length(); i++) {
			if (newLabel[i] == ' ' || !isalpha(newLabel[i])) throw logic_error("Incorrect Label");
		}
		label = newLabel;
	}
	void setNumber(int newNum)
	{
		if (newNum <= 0) throw logic_error("Invalid number");
		number = newNum;
	}
	static int count()
	{
		return numOfBox;
	}
	virtual float getCapacity() = 0;
};

class BrickBox : public Box
{
protected:
	float length = 0.0, width = 0.0, height = 0.0;
public:
	BrickBox(string L = "", int N = 0, float ln = 0.0, float w = 0.0, float h = 0.0) : Box(L, N)
	{
		if (ln <= 0 || w <= 0 || h <= 0) throw logic_error("Invalid input BrickBox");
		length = ln;
		width = w;
		height = h;
	}
	~BrickBox()
	{
		cout << "BrickBox destroyed\n";
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
	void setLength(float newL)
	{
		if (newL <= 0) throw logic_error("Invalid Length");
		length = newL;
	}
	void setWidth(float newW)
	{
		if (newW <= 0) throw logic_error("Invalid Width");
		width = newW;
	}
	void setHeight(float newH)
	{
		if (newH <= 0) throw logic_error("Invalid Height");
		height = newH;
	}
	float getCapacity()
	{
		return length * width * height;
	}
};

class TubeBox : public Box
{
protected:
	float radius = 0.0, height = 0.0;
public:
	TubeBox(string L = "", int N = 0, float r = 0.0, float h = 0.0) : Box(L, N)
	{
		if (r <= 0 || h <= 0) throw logic_error("Invalid input TubeBox");
		radius = r;
		height = h;
	}
	~TubeBox()
	{
		cout << "TubeBox destroyed\n";
	}
	float getRadius()
	{
		return radius;
	}
	float getHeight()
	{
		return height;
	}
	void setRadius(float newR)
	{
		if (newR <= 0) throw logic_error("Invalid Radius");
		radius = newR;
	}
	void setHeight(float newH)
	{
		if (newH <= 0) throw logic_error("Invalid Height");
		height = newH;
	}
	float getCapacity()
	{
		double pi = 2 * acos(0.0);
		return pi * pow(radius,2) * height;
	}
};
 
class BubbleBox : public Box
{
protected:
	float radius;
public:
	BubbleBox(string L = "", int N = 0, float r = 0.0) : Box(L, N)
	{
		if (r <= 0) throw logic_error("Incorrect radius");
		radius = r;
	}
	~BubbleBox()
	{
		cout << "BubbleBox destroyed\n";
	}
	float getRadius()
	{
		return radius;
	}
	void setRadius(float newR)
	{
		if (newR <= 0) throw logic_error("Incorrect radius");
		radius = newR;
	}
	float getCapacity()
	{
		double pi = 2 * acos(0.0);
		return pow(radius,3) * pi *(2.0/3.0);
	}
};