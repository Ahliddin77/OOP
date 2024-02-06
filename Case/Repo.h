#pragma once
#include<list>
#include<string>
#include<sstream>
#include "Case.h"
using namespace std;


class Repository
{
private:
    string descripton;
    float totalCap;
    list<Case*> CL; ///list of pointers to Case
    static float volOfCases;
    float free_space;
public:
    Repository(string D = "", float totCap = 0.0)
    {
        if (totCap <= 0) throw logic_error("Invalid Capacity");
        descripton = D;
        totalCap = totCap;
        free_space = totalCap;
    }
    ~Repository()
    {
        for (list<Case*>::iterator i = CL.begin(); i != CL.end(); i++)
            delete* i; ///polymorfic destructor call
    }

    void clear()
    {
        for (list<Case*>::iterator i = CL.begin(); i != CL.end(); i++)
            delete* i; ///polymorfic destructor call
        CL.clear();
        free_space = totalCap;
    }

    friend ostream& operator<<(ostream& os, Repository& e)
    {
        os << e.descripton << ",  total capacity: " << e.totalCap << ",  free space: " << e.free_space << ":" << endl;
        int j = 0;
        for (list<Case*>::iterator i = e.CL.begin(); i != e.CL.end(); i++)
        {
            j++;
            os << j << ". " << (*i)->getLabel() << "  " << showbase << hex <<(*i)->getColor() << dec << "  volume: " << (*i)->getCapacity() << endl;
        }
        return os;
    }

    void add(Case* newCase)
    {
        double v = newCase->getCapacity();
        if (free_space < v)
        {
            ostringstream os;
            os << newCase->getLabel() << " too large - only " << free_space << " free space";
            string info = os.str();
            delete newCase;
            throw CapacityError(info);
        }
        else
        {
            CL.push_back(newCase);
            free_space = free_space - v;
            volOfCases += v;
        }
    }

    class CapacityError : public logic_error
    {
    public:
        CapacityError(string msg) : logic_error(msg)
        {}
    };

    void remove(string searchLabel)
    {
        int j = 0;
        for (list<Case*>::iterator i = CL.begin(); i != CL.end();)
        {
            if ((*i)->getLabel() == searchLabel)
            {
                volOfCases -= (*i)->getCapacity();
                delete* i;
                CL.erase(i);
                i = CL.begin();
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == 0) throw NameError("Name not found");
    }


    float summaryVolume()
    {
        return volOfCases;
    }

    Case& operator[](int n)
    {
        if (n < 1 || n > CL.size())
        {
            ostringstream os;
            os << "item no. "<<n<<" not found";
            string info = os.str();
            throw IndexError(info);
        }
        list<Case*>::iterator i = CL.begin();
        advance(i, n-1);
        return **i;
    }

    class IndexError : public logic_error
    {
    public:
        IndexError(string msg) : logic_error(msg)
        {}
    };
    class NameError : public logic_error
    {
    public:
        NameError(string msg) : logic_error(msg)
        {}
    };
};
