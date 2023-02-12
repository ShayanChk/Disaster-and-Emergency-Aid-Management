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
Date      4 / 10 / 2022
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
using namespace std;
namespace sdds {

	//const int maxYear = 2030;

	class Date
	{
		int year, month, day;
		Status objState;
		bool isFormat = true;

	public:

		//constructor
		Date();
		Date(int Year, int Month, int Day);

		//operator overload 
		bool operator==(const Date& d);
		bool operator!=(const Date& d);
		bool operator<(const Date& d);
		bool operator>(const Date& d);
		bool operator<=(const Date& d);
		bool operator>=(const Date& d);

		//accessor 
		const Status& state() const;

		//formatted modifier
		Date& formatted(bool form);

		//bool conversion 
		operator bool() const;

		//ostream 
		ostream& write(ostream& ostr) const;

		//istream
		istream& read(istream& istr);

		//friends
		friend ostream& operator<<(ostream& ostr, const Date& date);
		friend istream& operator>>(istream& istr, Date& d);

		//methods
		void clearState();
		void set(int Year, int Month, int Day);
		void setEmpty();

		//dates
		int returnYear() const;
		int returnmonth() const;
		int returnday() const;

	private :
		bool validate();
		int uniqueDateValue() const;
	};

	
}
#endif