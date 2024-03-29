/* Citation and Sources...
Final Project Milestone 4
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author   Pattarawan Saravaneeyawong
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"

using namespace std;

namespace seneca {

    std::ostream& operator<<(std::ostream& ostr, const IOAble& ioable)
    {
        return ioable.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& ioable)
    {
        return ioable.read(istr);
    }
}
