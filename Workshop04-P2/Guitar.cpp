/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:     Thursday 15 February 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca {
    const char* GuitarStr::material() const {
        return m_material;
    }
    double GuitarStr::gauge() const {
        return m_gauge;
    }
    GuitarStr::GuitarStr() {};

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN);
        m_gauge = ga;
    };

    /////////////////////////////////////////////////////////////////////
    Guitar::Guitar(const char* mod) : m_strings(nullptr), m_numStrings(0)
    {
        if (mod != nullptr)
        {
            strncpy(m_model, mod, MODEL_LEN);
        }
    };


    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod)
    {
        int i;

        if (strs != nullptr && ns > 0 && mod != nullptr) {

            m_strings = new GuitarStr[ns];
            for (i = 0; i < ns; i++) {
                m_strings[i] = strs[i];
            }
            m_numStrings = ns;
            strncpy(m_model, mod, MODEL_LEN);
        }
        else
        {
            m_strings = nullptr;
            m_numStrings = 0;
            m_model[0] = '\0';
        }
       
   }
   Guitar::~Guitar() {
       delete[] m_strings;
       m_strings = nullptr;
    }

   bool Guitar::changeString(const GuitarStr& gs, int sn)
   {
       return (sn >= 0 && sn < m_numStrings) ? (m_strings[sn] = gs, true) : false;
   }

   void Guitar::reString(GuitarStr strs[], int ns)
   {
       int i;

       if (m_strings != nullptr)
       {
           delete[] m_strings;
           m_strings = nullptr;
       }

       m_strings = new GuitarStr[ns];
       for (i = 0; i < ns; i++)
       {
           m_strings[i] = strs[i];
       }
      
       m_numStrings = ns;
   }

   void Guitar::deString() 
   {
       delete[] m_strings;
       m_strings = nullptr;

       m_numStrings = 0;
   }

   bool Guitar::strung() const
   {
       return m_strings != nullptr;
   }

   bool Guitar::matchGauge(double ga) const
   {
       int i;
       bool found = false;

       for (i = 0; i < m_numStrings && !found; i++)
       {
           if (m_strings[i].gauge() == ga)
           {
                found = true;
           }
       }
       return found;
   }

   std::ostream& Guitar::display(std::ostream& os) const
   {
       int i;
       if (m_numStrings <= 0)
       {
           os << "***Empty Guitar***" << endl;
       }
       else
       {
           os << "Guitar Model: " << m_model << endl;
           os << "Strings: " << m_numStrings << endl;

           if (m_strings != nullptr) {
               for (i = 0; i < m_numStrings; i++) {
                   os << "#" << i + 1;
                   os.width(MAT_LEN);
                   os << m_strings[i].material() << " | ";
                   os.setf(ios::fixed);
                   os.precision(1);
                   os << m_strings[i].gauge() << endl;
         
               }
           }
       }

       return os;
   }



}
