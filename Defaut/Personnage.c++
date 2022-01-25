#include "Personnage.h"

using namespace std;

Personnage::Personnage() : m_sante(100), m_faim(100), m_nom("Leouwu")
{
}


std::string Personnage::toSTR() const
{
    string s;
    s += "Nome : " + m_nom + ", ";
    s += "Sante : " + to_string(m_sante) + ", ";
    s += "Faim : " + to_string(m_faim) + ", ";

    return s;

}

void operator+(Personnage* a, vector <int> b){
    a->changeSante(b[sante]);
    a->changeFaim(b[faim]);
}