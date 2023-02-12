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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include <iostream>
#include "Menu.h"
#include "Item.h"
#include "iProduct.h"
using namespace std;
namespace sdds {

	class AidMan
	{
		const int sdds_max_num_items = 100;
		
		iProduct* iproduct[100];  //sus
		int iproductItems{}; //can't be more than 100
		char* fileName;
		Menu m_menu;

		unsigned int menu();

	public:

		Item item;
		AidMan(const char* fN) = delete;
		AidMan& operator=(const AidMan& a) = delete;
		AidMan();
		~AidMan();
		void run();

		void save() const;
		void deallocate();
		bool load();
		int list(const char* sub_desc = nullptr);
		int search(int sku)const;
		void add();
		void remove(int index);

	};

}
#endif