/*************************************************
Name:			Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:		130618234
Date Completed: Wednesday February 21 2024
**************************************************/
#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"

namespace seneca {
    class Hero {
        char m_name[MAX_NAME_LENGTH + 1];
        Power* m_power;
        int m_numOfPower;
        int m_powerLvl;

    public:
        Hero();
        Hero(const char* name, const Power* power, int countPow);
        ~Hero();

        std::ostream& display(std::ostream& ostr = std::cout)const;

        Hero& operator+=(Power power);
        Hero& operator-=(int powerLvl);


        bool operator>(Hero& heroRHS);
        bool operator<(Hero& heroRHS);

        Hero& operator<<(Power& power);
       

    };

    //Global function helper
    void operator>>(Power& power, Hero& hero);
}



#endif /* SENECA_HERO_H*/