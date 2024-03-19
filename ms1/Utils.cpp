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
#include <cstdlib>
#include <ctime>
#include "Utils.h"
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
         else{
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
}