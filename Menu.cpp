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
#include <ctime>
#include <cstring>
#include <string>
#include "Utils.h"
#include "Status.h"
#include "Menu.h"
using namespace std;
namespace sdds {

	Menu::Menu()
	{
		option = nullptr;
		optnAvlb = -1;
	}

	Menu::Menu(unsigned int numOfOptn, const char* optn)
	{
		if (numOfOptn < 15 && optn != nullptr)
		{
			optnAvlb = numOfOptn;
			ut.alocpy(option, optn);
		}
		else
		{
			operator bool();
		}
	}

	Menu::~Menu()
	{
		delete[] option;
		option = nullptr;
	}

	unsigned int Menu::run()
	{
		int number = -100, count = -1;
		unsigned int i;
		int flag = 0;
		for (i = 0; i < strlen(option); i++)
		{
			if (option[i] != '\n')
			{
				cout << option[i];
			}
			else
			{
				cout << '\n';
				count += 1;
			}

		}
		cout << "0- Exit" << endl;

		cout << "> ";

		do
		{
			cin >> number;
			flag = 0;

			if (number < 0 || number > count)
			{
				cout << "Value out of range [0<=val<=" << count << "]: ";
			}
			else if (!cin)
			{
				cout << "Invalid Integer, retry: ";
				cin.clear();
				cin.ignore(1000, '\n');
				flag = 1;
			}

		} while (number < 0 || number > count || flag == 1);

		return number;
	}

	Menu::operator bool() const
	{
		if (optnAvlb > 15 || option == nullptr)
			return false;
		else
			return true;
	}

	void Menu::setMenu(const char* optn)
	{
		ut.alocpy(option, optn);
	}

	void Menu::menuSet(const char* option, int number)
	{
		if (number < 15 || option != nullptr)
		{
			optnAvlb = number;
			ut.alocpy(this->option, option);
		}
		else
		{
			this->option = nullptr;
			optnAvlb = 0;
		}
	}

}