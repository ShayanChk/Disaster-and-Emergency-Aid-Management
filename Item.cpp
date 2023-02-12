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
#include <fstream>
#include <cstring>
#include <string>
#include "Utils.h"
#include "Status.h"
#include <ctype.h>
#include <stdio.h>
#include "iProduct.h"
#include "Item.h"
#include "iomanip"
using namespace std;
namespace sdds {

	void Item::setDes(const char* des)
	{
		ut.alocpy(itemDescription, des);
	}

	void Item::setSku(int sku)
	{
		stockUnitNumber = sku;
	}

	
	bool Item::linear() const
	{
		return flag;
	}

	Item::Item() : iProduct()
	{
		stockUnitNumber = 0;
		price = 0;
		quantity = 0;
		qntyNeeded = 0;
		itemDescription = nullptr;
		flag = false;
	}

	Item::Item(const Item& item) : iProduct(item)
	{
		if (item)
		{
			*this = item;
		}
	}

	Item& Item::operator=(const Item& i)
	{
		if (this != &i)
		{
			if (i)
			{
				(iProduct&)*this = i;
				delete[] itemDescription;
				itemDescription = nullptr;
				if (i.itemDescription != nullptr)
				{
					ut.alocpy(itemDescription, i.itemDescription);
				}
				price = i.price;
				quantity = i.quantity;
				qntyNeeded = i.qntyNeeded;
				flag = i.flag;
				stockUnitNumber = i.stockUnitNumber;
			}
		}

		return *this;
	}

	Item::~Item()
	{
		delete[] itemDescription;
		itemDescription = nullptr;
	}

	int Item::qtyNeeded() const
	{
		return qntyNeeded;
	}

	int Item::qty() const
	{
		return quantity;
	}

	Item::operator double()const
	{
		return price;
	}

	Item::operator bool()const
	{
		return s.operator bool();
	}

	int Item::operator-=(int qty)
	{
		quantity -= qty;
		return quantity;
	}

	int Item::operator+=(int qty)
	{
		quantity += qty;
		return quantity;
	}

	void Item::linear(bool isLinear)
	{
		flag = isLinear;
	}

	void Item::clear()
	{
		s = true;
	}

	bool Item::operator==(int sku)const
	{
		if (stockUnitNumber == sku)
			return true;
		else
			return false;
	}

	bool Item::operator==(const char* description)const
	{
		if (!description || !itemDescription)
			return false;
		string key = description;
		string descStr = itemDescription;
		if (descStr.find(key) != string::npos)
			return true;
		else return false;
	}

	ofstream& Item::save(std::ofstream& ofstr)const
	{
		if (s)
		{
			if (&ofstr)
			{
				ofstr << stockUnitNumber << "\t" << itemDescription << "\t" << quantity << "\t" << qntyNeeded << "\t" << price;
				
			}
		}
		return ofstr;
	}

	

	ifstream& Item::load(ifstream& ifstr) {

		char description[1000] = {};

		delete[] itemDescription;
		itemDescription = nullptr;
		if (ifstr.fail()) {
			s = "Input file stream read failed!";
		}
		else
		{
			ifstr >> stockUnitNumber;
			ifstr.ignore();
			ifstr.getline(description, 1000, '\t');
			ut.alocpy(itemDescription, description);
			ifstr >> quantity;
			ifstr.ignore();
			ifstr >> qntyNeeded;
			ifstr.ignore();

			ifstr >> price;
			ifstr.ignore();

		}

		return ifstr;
	}

	ostream& Item::display(std::ostream& ostr)const
	{
		
		if (!s)
		{
			ostr << s;	
		}
		else
		{
			if (linear())
			{
				int i = 0, j = 0;

				if (itemDescription != nullptr) 
				{
					for (i = 0; itemDescription[i] != '\0'; i++);
				}
				ostr.fill(' ');
				ostr.width(5);

				ostr << stockUnitNumber << " | ";

				if (itemDescription != nullptr) 
				{
					if (i <= 35) {
						ostr << left << setfill(' ') << setw(35) << itemDescription;
					}
					else {
						ostr << left << setfill(' ') << setw(35);
						for (j = 0; j < 35; j++) {
							ostr << left << setw(1) << itemDescription[j];
						}
					}
				}

				ostr << " | ";

				ostr << right << setfill(' ') << setw(4) << quantity;

				ostr << " | ";
				ostr << right << setfill(' ') << setw(4) << qntyNeeded;

				ostr << " | ";

				ostr << right << setfill(' ') << setw(7);

				ostr << fixed << setprecision(2) << price;

				ostr << " |";
			

			}
			else
			{
				ostr << "AMA Item:" << endl;
				ostr << stockUnitNumber << ": " << itemDescription << endl;
				ostr << "Quantity Needed: " << qntyNeeded << endl;
				ostr << "Quantity Available: " << quantity << endl;
				ostr << "Unit Price: $" << fixed << setprecision(2) << price << endl;
				ostr << "Needed Purchase Fund: $" << (qntyNeeded - quantity) * price << endl;
			}
		}
		return ostr;
	}

	int Item::readSku(istream& istr)
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
			else if (40000 > number || number > 99999)
			{
				cout << "Value out of range [40000<=val<=99999]:";
				istr.clear();
				istr.ignore(1000, '\n');

			}
			

		} while (40000 > number || number > 99999 || flag == 1);

		stockUnitNumber = number;

		return number;
	}	

	istream& Item::read(std::istream& istr)
	{
		delete[] itemDescription;
		itemDescription = nullptr;

		s.clear();

		cout << "AMA Item:" << endl;
		cout << "SKU: " << stockUnitNumber;
		cout << endl;
		istr.ignore();

		string x;
		cout << "Description: ";
		getline(istr, x);

		ut.alocpy(itemDescription, x.c_str());

		int flag = 0;
		
		cout << "Quantity Needed: ";

		do
		{
			
			istr >> qntyNeeded;

			flag = 0;
			
			if (!istr)
			{
				cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
				flag = 1;
			}
			else if (1 > qntyNeeded || qntyNeeded > 9999 )
			{
				cout << "Value out of range [1<=val<=9999]:";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			

		} while (1 > qntyNeeded || qntyNeeded > 99999 || flag == 1);


		cout << "Quantity On Hand: ";
		do
		{
			istr >> quantity;
			flag = 0;

			if (!istr)
			{
				cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
				flag = 1;
			}
			else if (quantity < 0 || quantity > qntyNeeded)
			{
				cout << "Value out of range [0<=val<="<<qntyNeeded<<"]:";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			

		} while (quantity < 0 || quantity > qntyNeeded || flag == 1);


		cout << "Unit Price: $";

		do
		{
			istr >> price;
			flag = 0;

			if (!istr)
			{
				cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
				flag = 1;
			}
			else if (price < 0 || price > 9999)
			{
				cout << "Value out of range [0<=val<=9999]:";
			}
			

		} while (price < 0 || price > 9999 || flag == 1);

		return istr;
	}

	istream& operator>>(istream& istr, Item& item)
	{
		item.read(istr);

		return istr;
	}

	ostream& operator<<(ostream& ostr, const Item& item)
	{
		item.display(ostr);

		return ostr;
	}

}
