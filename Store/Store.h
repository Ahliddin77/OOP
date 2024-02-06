#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include <sstream>
#include <list>
#include "Box.h"
using namespace std;

class Store
{
private: 
	string description;
	float totCap;
	list<Box*> BL;
	static float volOfBox;
public:
	Store(string D = "", float T = 0)
	{
		if (T <= 0) throw logic_error("Incorrect capacity");
		description = D;
		totCap = T;
		volOfBox = 0;
	}
	~Store()
	{
		for (list<Box*>::iterator i = BL.begin(); i != BL.end(); i++)
			delete* i;
	}
	void addFirst(Box* B)
	{
		if ((totCap - volOfBox) < B->getCapacity())
		{
			ostringstream os;
			os << B->getLabel() << " too large - only " << (totCap - volOfBox) << " free space";
			string info = os.str();
			delete B;
			throw CapacityError(info);
		}
		else 
		{
			BL.push_front(B);
			volOfBox += B->getCapacity();
		}
	}
	class CapacityError : public logic_error
	{
	public:
		CapacityError(string msg) : logic_error(msg)
		{}
	};
	void addLast(Box* B)
	{
		if ((totCap - volOfBox) < B->getCapacity())
		{
			ostringstream os;
			os << B->getLabel() << " too large - only " << (totCap - volOfBox) << " free space";
			string info = os.str();
			delete B;
			throw CapacityError(info);
		}
		else
		{
			BL.push_back(B);
			volOfBox += B->getCapacity();
		}
	}
	void removeFirst()
	{
		if (BL.empty()) throw EmptyError("Store is empty");
		else
		{
			volOfBox -= BL.front()->getCapacity();
			delete BL.front();
			BL.pop_front();
		}
	}
	class EmptyError : public logic_error
	{
	public:
		EmptyError(string msg) : logic_error(msg)
		{}
	};
	void clear()
	{
		for (list<Box*>::iterator i = BL.begin(); i != BL.end(); i++)
			delete* i;
		BL.clear();
		volOfBox = 0;
	}
	static float summaryVolume()
	{
		return volOfBox;
	}
	Box& operator[](int n)
	{
		if (n < 1 || n > BL.size())
		{
			ostringstream os;
			os << "item no. " << n << "not found\n";
			string info = os.str();
			throw IndexError(info);
		}
		list<Box*>::iterator i = BL.begin();
		advance(i, n-1);
		return **i;
	}
	class IndexError : public logic_error
	{
	public:
		IndexError(string msg) : logic_error(msg)
		{}
	};
	friend ostream& operator<<(ostream& os, Store& s)
	{
		os << s.description << ", total capacity: " << s.totCap << ", free space: " << (s.totCap - s.volOfBox) << ";\n";
		int j = 0;
		for (list<Box*>::iterator i = s.BL.begin(); i != s.BL.end(); i++)
		{
			j++;
			os << j << ". " << (*i)->getLabel() << ", " << (*i)->getNumber() << ", volume: " << (*i)->getCapacity() << endl;
		}
		return os;
	}
};
