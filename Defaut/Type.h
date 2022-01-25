#ifndef DEF_TYPE
#define DEF_TYPE

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Class.h"

using namespace std;

class Type : public Class{
    public:
    //Type();
    Type(string t);
    string getType() {return m_type;};
    int getBonuspourcen() {return m_bonus_pourcentage;};

    protected:
    string m_type;
    int m_bonus_pourcentage;

};




#endif