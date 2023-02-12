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
#include "Utils.h"
using namespace std;
namespace sdds {
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;

    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;
        destination = nullptr;

        if (source != nullptr)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    int Utils::getint(const char* prompt)
    {
        if (prompt != nullptr)
            cout << prompt;

        int number = 0;
        do
        {
            cin >> number;
            if (number != (int)number)
                cout << "Invalid Integer, retry: ";

        } while (number != (int)number);

        return number;
    }

    /*int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int number = getint(prompt);

        do
        {
            if (number < min || number > max)
                if (errMes != nullptr)
                    cout << ", retry: " << errMes;
                else
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";

        } while (number < min || number > max);

        return number;
    } */
}