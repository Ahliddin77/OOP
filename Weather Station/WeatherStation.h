#pragma once
#include<list>
#include<string>
#include<sstream>
#include "Measure.h"
using namespace std;


class WeatherStation
{
private:
    string location, instituteName;
    int devicesAllowed;
    list<Measure*> ML; ///list of pointers to Measure
public:
    WeatherStation(string L = "", string IN = "", int dev = 3)
    {
        if (dev <= 0) throw logic_error("Invalid Capacity");
        location = L;
        instituteName = IN;
        devicesAllowed = dev;
    }
    ~WeatherStation()
    {
        for (list<Measure*>::iterator i = ML.begin(); i != ML.end(); i++)
            delete* i; ///polymorfic destructor call
    }

    void clear()
    {
        for (list<Measure*>::iterator i = ML.begin(); i != ML.end(); i++)
            delete* i; ///polymorfic destructor call
        ML.clear();
    }

    friend ostream& operator<<(ostream& os, WeatherStation& e)
    {
        os << e.instituteName << ", " << e.location << ",  max. spread: " << e.maxSpread() << ":" << endl;
        int j = 0;
        for (list<Measure*>::iterator i = e.ML.begin(); i != e.ML.end(); i++)
        {
            j++;
            os << j << ". " << (*i)->getName() << ", result: " << (*i)->getResult() << endl;
        }
        return os;
    }

    void add(Measure* newMeasure)
    {
        if (newMeasure->count() > devicesAllowed)
        {
            ostringstream os;
            os << "only " << devicesAllowed << " measure devices allowed";
            string info = os.str();
            delete newMeasure;
            throw LimitError(info);
        }
        else
        {
            ML.push_back(newMeasure);
        }
    }

    class LimitError : public logic_error
    {
    public:
        LimitError(string msg) : logic_error(msg)
        {}
    };

    void remove(string searchName)
    {
        int j = 0;
        for (list<Measure*>::iterator i = ML.begin(); i != ML.end(); )
        {
            if ((*i)->getName() == searchName)
            {
                delete* i;
                i = ML.erase(i);
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == 0) throw logic_error("NameError");
    }


    float maxSpread()
    {
        list<Measure*>::iterator j = ML.begin();
        float max = (*j)->getMax() - (*j)->getMin();
        for (list<Measure*>::iterator i = ML.begin(); i != ML.end(); i++)
        {
            if (max < (*i)->getMax() - (*i)->getMin())
                max = (*i)->getMax() - (*i)->getMin();
        }
        return max;
    }

    Measure& operator[](int n)
    {
        if (n < 1 || n > ML.size())
        {
            ostringstream os;
            os << "item no. " << n << " not found";
            string info = os.str();
            throw IndexError(info);
        }
        list<Measure*>::iterator i = ML.begin();
        advance(i, n - 1);
        return **i;
    }

    class NameError : public logic_error
    {
    public:
        NameError(string msg) : logic_error(msg)
        {}
    };
    class IndexError : public logic_error
    {
    public:
        IndexError(string msg) : logic_error(msg)
        {}
    };
};

