/*************************************************
Name:			Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:		130618234
Date Completed: Wednesday February 21 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace seneca
{
    Hero::Hero()
    {
        m_name[0] = '\0';
        m_power = nullptr;
        m_numOfPower = 0;
        m_powerLvl = 0;
    }

    Hero::Hero(const char* name, const Power* power, int countPow)
    {
        int i;
        int raritySum = 0;

        strcpy(m_name, name);

        m_power = new Power[countPow];

        for (i = 0; i < countPow; i++)
        {
            m_power[i] = power[i];
            raritySum += power[i].checkRarity();
        }

        m_numOfPower = countPow;
        m_powerLvl = raritySum * countPow;
    }

    Hero::~Hero( )
    {
        delete[] m_power;
    }


    ostream& Hero::display(std::ostream& ostr) const
    {
        int i;

        ostr << "Name: " << m_name << endl;
        ostr << "List of available powers: " << endl;

        for (i = 0; i < m_numOfPower; i++)
        {
            ostr.width(2);
            ostr << " ";
            ostr << "Name: " << m_power[i].checkName();
            ostr << ", ";
            ostr << "Rarity: " << m_power[i].checkRarity() << endl;
        }
        ostr << "Power Level: " << m_powerLvl;

        return ostr;
    }

    Hero& Hero::operator+= (Power newPower)
    {
        int i;
        int raritySum = 0;

        Power* tempPower = nullptr;

        tempPower = new Power[m_numOfPower + 1];

        for (i = 0; i < m_numOfPower + 1; i++)
        {

            if (i == m_numOfPower)
            {
                tempPower[m_numOfPower] = newPower;
                raritySum += newPower.checkRarity();
            }
            else
            {
                tempPower[i] = m_power[i];
                raritySum += m_power[i].checkRarity();
            }

        }

        m_numOfPower += 1;
        m_powerLvl = raritySum * m_numOfPower;

        delete[] m_power;
        m_power = new Power[m_numOfPower];

        for (i = 0; i < m_numOfPower; i++)
        {
            m_power[i] = tempPower[i];
        }

        delete[] tempPower;

        return *this;
    }

   Hero& Hero::operator-= (int powerLvl)
   {
        m_powerLvl -= powerLvl;

        return *this;
   }

   //The superman is 80 power lvl but the martian man is 92 because of the +=
   //function above.
   bool Hero::operator>(Hero& heroRHS)
   {
       bool answer = false;

       if (m_powerLvl > heroRHS.m_powerLvl)
       {
           answer = true;
       }
       return answer;
   }


   bool Hero::operator<(Hero& heroRHS)
   {
       bool answer = false;
       if (m_powerLvl < heroRHS.m_powerLvl)
       {
           answer = true;
       }
       return answer;
   }


   Hero& Hero::operator<<(Power& power)
   {
       int i;
       int raritySum = 0;

       Power* tempPower = nullptr;

       tempPower = new Power[m_numOfPower + 1];

       for (i = 0; i < m_numOfPower + 1; i++)
       {

           if (i == m_numOfPower)
           {
               tempPower[m_numOfPower] = power;
               raritySum += power.checkRarity();
           }
           else
           {
               tempPower[i] = m_power[i];
               raritySum += m_power[i].checkRarity();
           }

       }

       m_numOfPower += 1;
       m_powerLvl = raritySum * m_numOfPower;

       delete[] m_power;
       m_power = new Power[m_numOfPower];

       for (i = 0; i < m_numOfPower; i++)
       {
           m_power[i] = tempPower[i];
       }

       delete[] tempPower;

       return *this;
   }

   //I use chatgpt here in this helper
   //Because I don't understand about helper function
   //And the helper function
   void operator>>(Power& power, Hero& hero) 
   {
       hero += power;
   }

}