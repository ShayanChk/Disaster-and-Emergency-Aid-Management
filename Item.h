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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "iProduct.h"
#include "Status.h"
using namespace std;
namespace sdds {

	class Item: public iProduct {

		double price;
		int quantity;
		int qntyNeeded;
		char* itemDescription{};
		bool flag;

	protected:

		Status s; ///to hold the status of the item 
		int stockUnitNumber{};
		bool linear() const;

	public:

		Item();

		//rule of three
		Item(const Item& item);
		Item& operator=(const Item& i);
		~Item();

		int qtyNeeded() const;
		int qty() const;
		operator double()const;
		operator bool()const;

		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		void clear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		ofstream& save(std::ofstream& ofstr)const;
		ifstream& load(std::ifstream& ifstr);
		ostream& display(std::ostream& ostr)const;
		int readSku(istream& istr);
		istream& read(std::istream& istr);
		void setDes(const char* des);
		void setSku(int sku);
	};
	std::istream& operator>>(std::istream& istr, Item& item);
	std::ostream& operator<<(std::ostream& ostr, const Item& item);

	extern Item m_item;
}
#endif