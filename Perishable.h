/* Citationand Sources...
Final Project Milestone ?
Module : Status
Filename : Status.cpp
Version 1.0
Author	John Doe
Revision History
Name : Shayan Chabook
student ID : 159844208
email address : schabook@myseneca.ca
---------------------------------------------------------- -
Date      4 / 7 / 2022
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include "Status.h"
#include "Item.h"
#include "Date.h"
using namespace std;
namespace sdds {

	class Perishable : public Item
	{
		char* instructions;
		Date expiryDate;

	public:


		Status s;
		//Item itm;
		//defult constructor
		Perishable();

		//rule of three
		Perishable(const Perishable& p);
		Perishable& operator=(const Perishable& p);
		~Perishable();

		//querry 
		operator bool() const;

		int readSku(istream& istr);
		ofstream& save(ofstream& ofstr) const;
		ifstream& load(std::ifstream& ifstr);
		ostream& display(std::ostream& ostr)const;
		istream& read(std::istream& istr);

		const Date& expiry() const;

	};




}
#endif