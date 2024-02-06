#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

class Entry {
private: 
	static int seqNum;
protected:
	string description;
public:
	Entry(string D = "")
	{
		for (int i = 0; i < D.length(); i++)
			if (D[i] != ' ' && !isalpha(D[i])) throw logic_error("Invalid Description");
		description = D;
		seqNum++;
	}
	Entry(Entry& E)
	{
		seqNum++;
		description = E.description;
	}
	virtual ~Entry()
	{
		cout << "Entry " << description << " destroyed\n";
	}
	string getDescrption()
	{
		return description;
	}
	void setDescription(string newD)
	{
		for (int i = 0; i < newD.length(); i++)
			if (newD[i] != ' ' && !isalpha(newD[i])) throw logic_error("Invalid Description");
		description = newD;
	}
	virtual string getContents() = 0;
};

class PhoneEntry : public Entry {
protected:
	int phoneNum;
public:
	PhoneEntry(string D = "", int pNum = 000000000) : Entry(D)
	{
		if (pNum <= 0) throw logic_error("Invalid phone number");
		phoneNum = pNum;
	}
	~PhoneEntry()
	{
		cout << "PhoneEntry destroyed\n";
	}
	int getNumber()
	{
		return phoneNum;
	}
	void setNum(int pNum)
	{
		if (pNum <= 0) throw logic_error("Invalid phone number");
		phoneNum = pNum;
	}
	string getContents()
	{
		return "phone " + phoneNum;
	}	
};

class EmailEntry : public Entry {
protected:
	string email;
public:
	EmailEntry(string D = "", string E = "###########@gmail.com") : Entry(D)
	{
		for (int i = 0; i < E.length(); i++)
		{
			if (E[i] != ' ') throw logic_error("Invalid Description");
		}
		email = E;
	}
	~EmailEntry()
	{
		cout << "EmailEntry destroyed\n";
	}
	string getEmail()
	{
		return email;
	}
	void setEmail(string E)
	{
		for (int i = 0; i < E.length(); i++)
		{
			if (E[i] != ' ') throw logic_error("Invalid Description");
		}
		email = E;
	}
	string getContents()
	{
		return "e-mail " + email;
	}
};

class AddressEntry : public Entry {
protected:
	string city,street;
	int houseNum;
public:
	AddressEntry(string D = "", string C = "", string S = "", int H = 0) : Entry(D)
	{
		city = C;
		street = S;
		houseNum = H;
	}
	~AddressEntry()
	{
		cout << "AddressEntry destroyed\n";
	}
	string getCity()
	{
		return city;
	}
	void setCity(string C)
	{
		city = C;
	}
	string getStreet()
	{
		return street;
	}
	void setStreet(string S)
	{
		street = S;
	}
	int getHouseNum()
	{
		return houseNum;
	}
	void setHouseNum(int H)
	{
		houseNum = H;
	}
	string getContents()
	{
		string num = to_string(houseNum);
		return city + ", " + street + ". " + num;
	}
};