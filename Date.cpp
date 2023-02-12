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
#include <iomanip>
#include "Date.h"
#include <string>
//#include "Status.h"
using namespace std;
namespace sdds {


		bool Date::validate()
		{
		int currentYearValue;
		ut.getSystemDate(&currentYearValue);
		if (year == 0 && month == 0 && day == 0)
		{
			objState = "Invalid date value";
			return false;
		}
		if (year < 2022 || year > 2030)
		{ 
			objState = "Invalid year in date";
			objState = 1;
			return false;
		}
		else if (month < 1 || month > 12)
		{
			objState = "Invalid month in date";
			objState = 2;
			return false;
		}
		else if (day < 1 || day > ut.daysOfMon(month, year))
		{
			objState = "Invalid day in date";
			objState = 3;
			return false;
		}
		else
		{
			objState.clear();
			return true;
		}
	}

	void Date::clearState()
	{
		objState = nullptr;
	}

	int Date::uniqueDateValue() const
	{
		return year * 372 + month * 31 + day;
	}

	void Date::set(int Year, int Month, int Day)
	{
		year = Year;
		month = Month;
		day = Day;
	}

	Date::Date(int Year, int Month, int Day)
	{
		set(Year, Month, Day);
		this->validate();
	}

	Date::Date()
	{
		
		ut.getSystemDate(&year, &month, &day);
	}

	

	bool Date::operator==(const Date& d)
	{
		return this->uniqueDateValue() == d.uniqueDateValue();
	}

	bool Date::operator!=(const Date& d)
	{
		return this->uniqueDateValue() != d.uniqueDateValue();
	}

	bool Date::operator<(const Date& d)
	{
		return this->uniqueDateValue() < d.uniqueDateValue();
	}

	bool Date::operator>(const Date& d)
	{
		return this->uniqueDateValue() > d.uniqueDateValue();
	}

	bool Date::operator<=(const Date& d)
	{
		return this->uniqueDateValue() <= d.uniqueDateValue();
	}

	bool Date::operator>=(const Date& d)
	{
		return this->uniqueDateValue() >= d.uniqueDateValue();
	}

	const Status& Date::state() const
	{
		return objState;
	}

	Date& Date::formatted(bool form)
	{
		if (form)
			isFormat = true;
		else
			isFormat = false;

		return *this;
	}

	Date::operator bool() const
	{
		if (objState == nullptr)
			return true;
		else
			return false;

		return objState;
	}

	ostream& Date::write(ostream& ostr) const
	{
		if (isFormat)
		{

			ostr << setw(4) << setfill('0') << year << '/';

			ostr << setw(2) << setfill('0') << month << '/';

			ostr << setw(2) << setfill('0') << day;
			
		}
		else
		{
			string yr = to_string(year);

			ostr << yr[2] << yr[3] << setw(2) << setfill('0') << month << day;
		}
		
		return ostr;
	}

	std::istream & Date::read(std::istream & istr)
	{
		string s;
		istr >> s;

		if (s.length() == 2)
		{
			month = 0;
		}
		if (s.length() == 3)
		{
			year = 0;
			month = 0;
			day = 0;
		}
		if (s.length() == 4)
		{
			ut.getSystemDate(&year);
			month = stoi(s.substr(0, 2));
			day = stoi(s.substr(2, 2));
		}
		else if (s.length() == 6)
		{
			year = stoi(s.substr(0, 2));
			year += 2000;
			month = stoi(s.substr(2, 2));
			day = stoi(s.substr(4, 2));
		}
		else
		{

		}

		if (!validate())
			istr.setstate(ios::badbit);

		return istr;
	}

	std::istream& operator >> (std::istream& istr, Date& d)
	{
		d.read(istr);
	
		return istr;
	}

	ostream& operator << (ostream& ostr, const Date& date)
	{
		if (!date.operator bool())
			ostr << "Bad name";
		else
			date.write(ostr);
		
		return ostr;
	}

	int Date::returnYear() const
	{
		return (this->year - 2000);
	}

	int Date::returnmonth() const
	{
		return month;
	}

	int Date::returnday() const
	{
		return day;
	}

	void Date::setEmpty()
	{
		day = 0;
		month = 0;
		year = 0;
	}

}