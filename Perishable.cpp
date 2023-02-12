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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Perishable.h"
#include "Item.h"
#include "Utils.h"
#include <string>
#include <string.h>
using namespace std;
namespace sdds {

	Perishable::Perishable(): Item()
	{
		expiryDate.setEmpty();
		instructions = nullptr;
	}

	Perishable::Perishable(const Perishable& p): Item(p)
	{
			expiryDate = p.expiryDate;
		
			if (p.instructions != nullptr)
			{
				instructions = nullptr;
				ut.alocpy(instructions, p.instructions);
			}
			else
			{
				instructions = nullptr;

			}

	}

	Perishable& Perishable::operator=(const Perishable& p)
	{
		if (this != &p)
		{
			if (p)
			{
				(Item&)*this = p;

				delete[] instructions;
				instructions = nullptr;
				if (p.instructions != nullptr)
				{
					ut.alocpy(instructions, p.instructions);
				}
				expiryDate = p.expiryDate;

			}
			
		}

		return *this;
	}

	Perishable::~Perishable()
	{
		delete[] instructions;
		instructions = nullptr;
	}

	Perishable::operator bool() const
	{
		if ((stockUnitNumber <= 39999 && stockUnitNumber >= 10000) && s) 
			return true;
		
		return false;
	}

	int Perishable::readSku(istream& istr)
	{
		int number = -100;
		int flag = 0;
		cout << "SKU: ";

		do
		{

			istr >> number;
			flag = 0;

			if (!istr)
			{
				cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
				flag = 1;
			}
			else if (10000 > number || number > 39999)
			{
				cout << "Value out of range [10000<=val<=39999]:";
				istr.clear();
				istr.ignore(1000, '\n');

			}


		} while (10000 > number || number > 39999 || flag == 1);

		Item::setSku(number);

		return number;
	}

	ofstream& Perishable::save(ofstream& ofstr) const
	{
		if (s)
		{
			if (&ofstr)
			{
				Item::save(ofstr);

				ofstr << "\t";
				
				if(instructions)
					ofstr << instructions;

				ofstr << "\t" << expiryDate.returnYear() << expiryDate.returnmonth() << expiryDate.returnday();

				
			}
			
		}

		return ofstr;
	}

	ifstream& Perishable::load(ifstream& ifstr) {
		char instruction[1000] = {};

		Item::load(ifstr);

		delete[] instructions;
		instructions = nullptr;
		if (ifstr.fail()) {
			s = "Input file stream read (perishable) failed!";
		}
		else
		{
			ifstr.getline(instruction, 1000, '\t');
			ut.alocpy(instructions, instruction);
			ifstr >> expiryDate;
			ifstr.ignore();
		}
		return ifstr;

	}
	
	
	ostream& Perishable::display(std::ostream& ostr)const
	{
		if (!s)
		{
			ostr << s << endl; 
		}
		else
		{
			if(linear())
			{

				Item::display(ostr);

				if (instructions && strcmp(instructions, ""))
				{
					ostr << '*';
				}
				else
				{
					ostr << ' ';
				}

				ostr << expiryDate;
			}
			else
			{

				ostr << "Perishable ";

				Item::display(ostr);

				ostr << "Expiry date: " << expiryDate; //make it formatted
				ostr << endl;

				if (instructions)
				{
					ostr << "Handling Instructions: " << instructions << endl;
				}
			}
		}

		return ostr;
	}

	istream& Perishable::read(std::istream& istr)
	{
		Item::read(istr);

		delete[] instructions;
		instructions = nullptr;

		cout << "Expiry date (YYMMDD): ";
		istr >> expiryDate;
		//istr.ignore('\n');

		
		cout << "Handling Instructions, ENTER to skip: ";
		istr.ignore();
		string userInput;

		if (istr.peek() != '\n')
		{
			getline(istr, userInput);
			ut.alocpy(instructions, userInput.c_str());
		}
		

		if (istr.fail())
		{
			s = "Perishable console date entry failed!";
		}

		return istr;
	}

	const Date& Perishable::expiry() const
	{
		return expiryDate;
	}


}