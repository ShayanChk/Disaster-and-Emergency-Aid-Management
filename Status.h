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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>

using namespace std;
namespace sdds {

	class Status
	{
		char* objDcrp{};
		int stsCode;

	public:
		//construction 
		Status();
		Status(char* description);
		~Status();
		

		//rule of three
		Status(const Status& s);
		Status& operator=(const Status& s);

		///assignment operator
		void operator=(int statusCode);
		void operator=(const char* description);

		//conversions
		operator int() const;
		operator char* () const;
		operator bool() const;

		Status& clear();

		friend std::ostream& operator << (std::ostream& ostr, const Status& s);

		void setEmpty();

		void set(int code);

		void setObjSts(const char* sts);
			
	};

}
#endif 