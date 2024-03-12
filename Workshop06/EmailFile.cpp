/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
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
Date Completed:     Tuesday 12 March 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

   Email::~Email() {
      delete[] m_name;
      delete[] m_email;
   }

    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    void EmailFile::loadEmails()
    {
        char buffer[BUFFER_SIZE]{};
        bool valid = true;
        int i;

        if (m_filename)
        {
            delete[] m_emailLines;

            //Open the file!!!
            ifstream file(m_filename);
            if (!file.is_open())
            {
                //Have file name, but fail to open it.
            }
            else
            {
               setNoOfEmails();

                m_emailLines = new Email[m_noOfEmails];

                for (i = 0; i < m_noOfEmails && valid; i++) {
                    if (!m_emailLines[i].load(file))
                    {
                        valid = false;
                    }
                }

                file.close();

            }
        }
        else
        {
            //Null Nothing happen
        }
    }

    EmailFile::EmailFile()
    {
        setEmpty();
    }

    EmailFile::EmailFile(const char* filename)
    {
        if (filename == nullptr)
        {
            setEmpty();
        }
        else
        {
            setFilename(filename);
            setNoOfEmails();
            loadEmails();
        }
    }

  EmailFile::EmailFile(const EmailFile& emailFile)
    {
      *this = emailFile;
    }





    EmailFile::~EmailFile()
    {
        delete[] m_emailLines;
        delete[] m_filename;
    }

    EmailFile::operator bool() const
    {
        return m_filename != nullptr ? true : false;
    }

    bool EmailFile::saveToFile(const char* filename) const
    {
        bool answer = false;
        ofstream file(filename);

        int i;
        if (!file.is_open())
        {
            cout << "Error: Could not open file: " << filename << endl;
        }
        else
        {
            for (i = 0; i < m_noOfEmails; i++)
            {
                
                file << m_emailLines[i].m_email << "," << m_emailLines[i].m_name << "," << m_emailLines[i].m_year;
                if (i < m_noOfEmails - 1)
                {
                    file << endl;
                }

            }
            file.close();
            answer = true;
        }
     
        return answer;
    }


    void EmailFile::fileCat(const EmailFile& obj, const char* name)
    {

        EmailFile tmpEmailF;
        int i, j;

        if (m_filename != nullptr && obj.m_filename != nullptr && tmpEmailF.m_filename == nullptr)
        {

            tmpEmailF.m_noOfEmails = m_noOfEmails + obj.m_noOfEmails;

            tmpEmailF.m_filename = new char[strlen(m_filename) + 1];
            strcpy(tmpEmailF.m_filename, m_filename);

            tmpEmailF.m_emailLines = new Email[tmpEmailF.m_noOfEmails];

            for (i = 0; i < m_noOfEmails; i++)
            {
                tmpEmailF.m_emailLines[i] = m_emailLines[i];
            }
            for (j = 0; j < obj.m_noOfEmails; j++)
            {
                tmpEmailF.m_emailLines[i] = obj.m_emailLines[j];
                i++;
            }
            delete[] m_emailLines;
            m_emailLines = new Email[m_noOfEmails];
            *this = tmpEmailF;

            if (name != nullptr)
            {
                saveToFile(name);
            }

        }
        else
        {
            //exit silently;
        }

     }

    EmailFile& EmailFile::operator=(const EmailFile& emailFile)
    {
        int i;
        setEmpty();
        m_emailLines = new Email[emailFile.m_noOfEmails];
        m_filename = new char[strlen(emailFile.m_filename) + 1];

        for (i = 0; i < emailFile.m_noOfEmails; i++)
        {
            m_emailLines[i] = emailFile.m_emailLines[i];
        }

        strcpy(m_filename, emailFile.m_filename);
        m_noOfEmails = emailFile.m_noOfEmails;

        return *this;
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

            return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

}