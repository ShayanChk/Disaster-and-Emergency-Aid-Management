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
#include <fstream>
#include "Utils.h"
#include "Menu.h"
#include "AidMan.h"
#include "Perishable.h"
#include "Item.h"
#include <iomanip>
#include <limits>
#include "Date.h"
#include <string>
using namespace std;
namespace sdds {

	unsigned int AidMan::menu()
	{
		int year = 0, month = 0, day = 0;

		ut.getSystemDate(&year, &month, &day);

		cout << "Aid Management System" << endl;
		cout << "Date: " << year << "/0" << month << "/" << day << endl;
		cout << "Data file: ";

		if (fileName == nullptr)
			cout << "No file" << endl;
		else
			cout << fileName << endl;
		cout << "---------------------------------" << endl;

		return m_menu.run();
	}

	AidMan::AidMan()
	{
		m_menu.setMenu("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");

		fileName = nullptr;
	}

	AidMan::~AidMan()
	{
		delete[] fileName;
		fileName = nullptr;

		int i = 0;
		for (i = 0; i < iproductItems; i++)
		{
			delete iproduct[i];
		}
		
		iproductItems = 0;
	}

	void AidMan::run() {
		int select;
		int items;
		int row = 0;
		string userDescription;
		char* decrip = nullptr;

		do {

			select = menu();
			
			if (select != 0 && select != 7 && !fileName)
			{
				select = 7;

			}

			switch (select)
			{

			case 1:

				if (iproductItems > 0)
				{
					cout << endl << "****List Items****" << endl;

					items = list();

					if (items > 1) 
					{

						cout << "Enter row number to display details or <ENTER> to continue:" << endl;

						cout << "> ";
					
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						row = cin.get();
						

						if (row == '\n')
						{
							cout << endl;
							break;

						}

						row -= 48;
						if (row > iproductItems || row == 0)
						{
							cout << "The list is emtpy!" << endl;
							break;
						}
                        
						iproduct[row - 1]->linear(false);
						cout << *iproduct[row - 1] << endl;
					}
				}
				else 
				{
					cout << "The list is emtpy!" << endl;
				}

				break;
			case 2:
				cout << endl << "****Add Item****" << endl << endl;
				add();
				break;
			case 3:

				cout << endl << "****Remove Item****" << endl;
				int index;
				cout << "Item description: ";

				cin >> userDescription;

				ut.alocpy(decrip, userDescription.c_str());

				if (list(decrip) > 0)
				{
					cout << "Enter SKU: ";
					index = search(ut.getint());

					if (index != -1)
					{
						int option;
						cout << "Following item will be removed: " << endl;
						iproduct[index]->linear(false);
						cout << *iproduct[index] << endl;
						cout << "Are you sure?\n";
						cout << "1- Yes!\n";
						cout << "0- Exit\n";

						cout << ">";
						cin >> option;
						if (option == 1)
						{
							remove(index);
							cout << "Item removed!" << endl << endl;
							delete[] decrip;
						}
						else {
							cout << "Aborted!";
							break;
						}

					}
				}
				else {
					cout << "The list is emtpy!" << endl;
				}
				break;
			case 4:
				cout << endl << "****Update Quantity****" << endl << endl;
				break;
			case 5:
				cout << endl << "****Sort****" << endl << endl;
				break;
			case 6:
				cout << endl << "****Ship Items****" << endl << endl;
				break;
			case 7:

				cout << endl << "****New/Open Aid Database****" << endl;

				cout << "Enter file name: ";

				string fName;

				cin >> fName;

				ut.alocpy(fileName, fName.c_str());
				if (load() > 0)
					cout << iproductItems << " records loaded!" << endl << endl;
				break;

			}

		} while (select != 0);


		save();
		cout << "Exiting Program!" << endl;
	}

	
	 void AidMan::save() const
	 {
		if (fileName && iproductItems > 0)
		{
			ofstream ofs;
			ofs.open(fileName, std::ios::out);

			int i;

			for (i = 0; i < iproductItems; i++)
			{
				iproduct[i]->save(ofs);
				ofs << endl;
			}
			ofs.close();
		}
	 }

	
	 bool AidMan::load()
	 {
		 int select;

		 save();

		 deallocate();

		 ifstream fstr;

		 fstr.open(fileName, ios::in);


		 if (fstr.fail())
		 {

			 Menu menuConfirmation;

			 cout << "Failed to open FN for reading!" << endl;

			 cout << "Would you like to create a new data file?" << endl;

			 menuConfirmation.menuSet("1- Yes!", 1);

			 select = menuConfirmation.run();

			 if (select == 1)
			 {
				 cout << "new data file: " << fileName;

				 save();

			 }
			 else
			 {
				 deallocate();

				 delete[] fileName;

				 fileName = nullptr;

				 return false;
			 }


		 }
		 else 
		 {

			 while (!fstr.fail()) {

				 int unitNumebr;

				 ifstream newstr;

				 unitNumebr = fstr.peek() - 48;

				 if (unitNumebr < 4 && unitNumebr > 0)
				 {
					 iproduct[iproductItems] = new Perishable;

				 }
				 else if (unitNumebr < 10 && unitNumebr > 3) 
				 {

					 iproduct[iproductItems] = new Item;

				 }
				 else
				 {
					 fstr.setstate(ios::failbit);

					 continue;
				 }
				 if (iproduct[iproductItems])
				 {
					 iproduct[iproductItems]->load(fstr);

					 iproductItems += 1;
				 }
			 }
		 }

		 if (iproductItems > 0)
		 {
			 return true;

		 }
		 return false;

	 }
	
	 void AidMan::deallocate()
	 {
		 int i;

		 for (i = 0; i < iproductItems; i++)
		 {
			 delete iproduct[i];
		 }



		 iproductItems = 0;
	 }

	
	 int AidMan::list(const char* sub_desc ) 
	 {
		 int count = 0;
		
		 cout << setw(5) << left << " ROW " << "|";
		 cout << "  SKU  ";
		 cout << "|" << left << setw(37) << setfill(' ') << " Description";
		 cout << "|" << " Have ";
		 cout << "|" << " Need ";
		 cout << "|" << "  Price  ";
		 cout << "|" << " Expiry" << endl;
		 cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		

		 if (sub_desc)
		 {
			 for (int i = 0; i < iproductItems; i++)
			 {
				 if (iproduct[i]->operator == (sub_desc))
				 {
					 iproduct[i]->linear(true);
					 cout << right << setw(4) << setfill(' ') << i + 1 << " | " << *iproduct[i] << endl;
					 count += 1;
				 }

			 }
		 }
		 else
		 {
			 for (int i = 0; i < iproductItems; i++)
			 {
				 iproduct[i]->linear(true);
				 cout << right << setw(4) << setfill(' ') << i + 1 << " | " << *iproduct[i] << endl;

			 }
			 count = iproductItems;

		 }
		 cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		 
		 
		 return iproductItems;

	 }

	 int AidMan::search(int sku)const {
		 int flg = -1;

		 for (int i = 0; i < iproductItems; i++)
		 {
			 if (*iproduct[i] == sku)
			 {
				 flg = i;
			 }
		 }
		 return flg;
	 }

	 void AidMan::add() {


		 if (iproductItems >= sdds_max_num_items) 
		 {
			 cout << "Database full!" << endl;
		 }
		 else 
		 {
			 cout << "1- Perishable" << endl;
			 cout << "2- Non-Perishable" << endl;
			 cout << "-----------------" << endl;
			 cout << "0- Exit" << endl;
			 cout << "> ";


			 int selection = ut.getint();

			 iProduct* p = {};


			 do 
			 {

				 if (selection > 2 || selection < 0)
				 {
					 cout << "Value out of range [0<=val<=2]: ";

					 cin.ignore();

					 break;
				 }

			 } while (selection > 2 || selection < 0);

			 if (selection == 0) {
				 cout << "Aborted\n";

			 }
			 else 
			 {
				 if (selection == 1) 
				 {
					 p = new Perishable();
				 }
				 if (selection == 2) 
				 {
					 p = new Item();

				 }

				 int sku;
				 sku = p->readSku(cin);

				 if (search(sku) != -1) {
					 cout << "Sku: " << sku << " is already in the system, try updating quantity instead." << endl << endl;
					 delete p;
				 }
				 else 
				 {
					 cin >> *p;
					 cout << endl;
					 if (p)
					 {
						 iproduct[iproductItems] = p;
						 iproductItems += 1;
					 }
				 }

			 }
		 }
	 }

	 void AidMan::remove(int index)
	 {
		 delete iproduct[index];

		 for (int i = index; i < iproductItems; i++)
		 {
			 iproduct[i] = iproduct[i + 1];
		 }
		 iproductItems -= 1;
		 
	 }


}
