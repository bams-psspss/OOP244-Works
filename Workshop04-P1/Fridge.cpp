/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:     10 February 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca{
   const char* Food::name() const {
      return m_name;
   }
   int Food::weight() const {
      return m_weight;
   }
   Food::Food(){}

   Food::Food(const char* nm, int wei) {
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }
  
   Fridge::Fridge() {
       m_numFoods = 0;
       m_model = nullptr;
   }

   Fridge::Fridge(Food farr[], int nf, const char* mod)
   {
       int i;

       m_numFoods = 0;
       m_model = nullptr;

       if (nf > 0 && mod != nullptr && mod[0] != '\0') {
           m_numFoods = nf;
           m_model = new char[strlen(mod) + 1];
           strcpy(m_model, mod);
       }
       for (i = 0; i < nf || i < FRIDGE_CAP; i++) {
           m_foods[i] = farr[i];
       }
   }
   Fridge::~Fridge() 
   {
       delete[] m_model;
       m_model = nullptr;
   }

   bool Fridge::addFood(const Food& f)
   {
       bool answer = false;
       if (m_numFoods < FRIDGE_CAP) {
           m_foods[m_numFoods] = f;
           m_numFoods += 1;
           answer = true;
       }
       return answer;
   }

   void Fridge::changeModel(const char* m)
   {
       if (m != nullptr && m[0] != '\0') {
           delete[] m_model;
           m_model = new char[strlen(m) + 1];
           strcpy(m_model, m);
       }
   }

   bool Fridge::fullFridge() const
   {
       return m_numFoods == FRIDGE_CAP ? true: false;
   }

   bool Fridge::findFood(const char* f) const
   {
       int i;
       bool answer = false;
       for (i = 0; i < m_numFoods && !answer; i++) {
           if (strcmp(m_foods[i].name(), f) == 0) {
               answer = true;
           }
       }
       return answer;
   }

   std::ostream& Fridge::display(std::ostream& os) const
   {
       int i;
       if (m_model != nullptr) {
           os << "Fridge Model: " << m_model << endl;
           os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl;
           os << "List of Foods\n";
           if (m_numFoods > 0) {
               os.unsetf(ios::left);
               os.width(0);
               for (i = 0; i < m_numFoods; i++) {
                   os.width(20);
                   os.setf(ios::right);
                   os << m_foods[i].name();
                   os << " | " << m_foods[i].weight() << endl;
           
               }
           }
       }
       return os;
   }



}
