#include "Vaisseau.h"

using namespace std;

std::string Vaisseau::toSTR() const
{
    string s;
    s += "Integrite : " + to_string(m_integrite_vaisseau) + ", ";
    s += "Effectif de l'equipage : " + to_string(m_nbr_equipage) + ", ";
    s += "Nourriture : " + to_string(m_nourriture) + ", ";
    s += "Humeur : " + to_string(m_humeur) ;

    return s;

}

void operator+(Vaisseau* a, vector <int> b){
    //std::cout << "ope called" << a.getHumeur() << std::endl;
    a->changeNb(b[nbr_equipage]);
    a->changeNourriture(b[nourriture]);
    a->changeHumeur(b[humeur]);
    a->changeInteg(b[integrite_vaisseau]);
}



/*
main(){
    Vaisseau Andromede;

   string  s = Andromede.toSTR();

    cout << s;

    return 0;
}
*/
