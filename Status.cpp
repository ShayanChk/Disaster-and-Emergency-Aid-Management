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
#include "Utils.h"
#include "Status.h"
using namespace std;
namespace sdds {

	Status::Status()
	{
		setEmpty();
	}

	void Status::setEmpty()
	{
		objDcrp = nullptr;
		stsCode = 0;
	}

	Status::Status(char* description)
	{
		ut.alocpy(objDcrp, description);
		stsCode = 0;
	}

	Status::Status(const Status& s)
	{
		stsCode = s.stsCode;
		ut.alocpy(objDcrp, s.objDcrp);
	}

	Status& Status::operator=(const Status& s)
	{
		if (this != &s)
		{
			stsCode = s.stsCode;
			ut.alocpy(objDcrp, s.objDcrp);
		}

		return *this;
	}

	Status::~Status()
	{
		delete[] objDcrp;
		objDcrp = nullptr;
	}

	void Status::operator=(int statusCode)
	{
		this->stsCode = statusCode;
	}

	void Status::operator=(const char* description)
	{	
		ut.alocpy(objDcrp, description);
	
		//return *this;
	}

	Status::operator int() const
	{
		return stsCode;
	}

	Status::operator char* () const
	{
		return objDcrp;
	}

	Status::operator bool() const
	{
		if (objDcrp == nullptr)
			return true;
		else
			return false;
	}

	Status& Status::clear()
	{
		delete[] objDcrp;
		objDcrp = nullptr;

		stsCode = 0;

		return *this;
	}

	ostream& operator << (ostream& ostr, const Status& s)
	{
		if (!s)
		{
			if (s.stsCode != 0)
				ostr << "ERR#" << s.stsCode << ": ";
			
			ostr << s.objDcrp;
		}

		return ostr;
	}

	void Status::set(int code)
	{
		stsCode = code;
	}

	void Status::setObjSts(const char* sts)
	{
		ut.alocpy(objDcrp, sts);
	}

}