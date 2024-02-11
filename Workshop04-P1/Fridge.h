/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
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
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>
namespace seneca {

   const int NAME_LEN = 20;
   const int FRIDGE_CAP = 3;

   class Food {
      char m_name[NAME_LEN]{};
      int m_weight{};
   public:
      const char* name()const;
      int weight()const;
      Food();
      Food(const char* nm, int wei);
   };

   class Fridge {
       Food m_foods[FRIDGE_CAP];
       int m_numFoods;
       char* m_model;
   public:
       Fridge();
       Fridge(Food farr[], int nf, const char* mod = "Ice Age");
       ~Fridge();

       bool addFood(const Food& f);
       void changeModel(const char* m);
       bool fullFridge() const;
       bool findFood(const char* f) const;
       std::ostream& display(std::ostream& os = std::cout) const;
   };

}

#endif
