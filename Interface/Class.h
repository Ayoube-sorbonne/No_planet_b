#ifndef DEF_CLASS
#define DEF_CLASS

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "Personnage.h"


class Class : public Personnage{
    public:
    Class(); 
    Class(string a, int bonus);
	string getClass() const{return m_class;};
    void changeBonus(int c){m_bonus = c;};
    int getBonus() const{return m_bonus;};

    protected:
    string m_class;
    int m_bonus;

};




#endif
