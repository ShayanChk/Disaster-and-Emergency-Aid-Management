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
Date      3 / 22 / 2022
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

using namespace std;
namespace sdds {

	class Menu
	{
		char* option;
		unsigned int optnAvlb;

	public:
		Menu();
		Menu(unsigned int numOfOptn, const char* optn);
		~Menu();

		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;

		unsigned int run();
		operator bool() const;
		void setMenu(const char* optn);
		void menuSet(const char* option, int number);
	};

}
#endif 