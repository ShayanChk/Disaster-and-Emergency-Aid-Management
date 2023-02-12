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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include "Utils.h"
#include "Status.h"
#include "iProduct.h"
using namespace std;
namespace sdds {

	istream & operator>>(istream& istr, iProduct& P)
	{
		P.read(istr);
		
		return istr;
	}

	ostream& operator<<(ostream& ostr, iProduct& P)
	{
		P.display(ostr);

		return ostr;
	}


}
