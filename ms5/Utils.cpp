/***********************************************************************
// OOP244 Project
//
// File  Utils.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
    // start provided code
    bool debug = false;
    Utils U;
    int Utils::getTime() {
        int mins = -1;
        if (debug) {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    void Utils::setDebugTime(int hour, int min) {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }

    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    // end provided code
    //Prof Fardad's Utils

    size_t Utils::strlen(const char* str) {
        size_t len{};
        while (str[len]) {
            len++;
        }
        return len;
    }

    char* Utils::strcpy(char* des, const char* src, size_t len) {
        size_t i;
        for (i = 0; src[i] && i < len; i++) {
            des[i] = src[i];
        }
        des[i] = 0;
        return des;
    }

    char* Utils::strcpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = 0;
        return des;
    }


    int Utils::getInt()const {
        int val{};
        char newline{};
        bool done = false;
        while (!done) {
            cin >> val;
            newline = cin.get();
            if (cin.fail()) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else if (newline != '\n') {
                cout << "Only enter an integer, try again: ";
                cin.ignore(10000, '\n');
            }
            else {
                done = true;
            }
        }
        return val;
    }
    int Utils::getInt(int min, int max)const {
        int val{};
        do {
            val = getInt();
        } while ((val < min || val > max)
            && cout << "Invalid value enterd, retry[" << min << " <= value <= " << max << "]: ");
        return val;
    }

    void Utils::aloCopy(char*& des, const char* src, size_t len) {
        delete[] des;
        des = nullptr;
        if (src) {
            size_t l = strlen(src);
            des = new char[(l > len ? len : l) + 1];
            strcpy(des, src, len);
        }
    }
}