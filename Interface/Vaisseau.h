#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include"enumeration.h"
using namespace std;

class Vaisseau{

    public:
    Vaisseau(int i): m_integrite_vaisseau(i), m_nbr_equipage(i), m_nourriture(i), m_humeur(i){};
   // void changeNbr(int modif){m_nbr_equipage += modif;};
   // void changeHumeur(int modif){m_humeur += modif;};
   // void changeNourriture(int modif){m_nourriture += modif;};
   // void changeIntegrite(int modif){m_integrite_vaisseau += modif;};
    
    int getIntegrite() const{return m_integrite_vaisseau;};
    int getNbr() const{return m_nbr_equipage;};
    int getHumeur() const{return m_humeur;};
    int getNourriture() const{return m_nourriture;};
    void changeNb(int b) { m_nbr_equipage+= b;};
    void changeNourriture(int b) { m_nourriture+= b;};
    void changeHumeur(int b) { m_humeur+= b;};
    void changeInteg(int b) { m_integrite_vaisseau+= b;};


    /*
    int* getAdNour() {return &m_nourriture;};
    int* getAdNbequipage() {return &m_nbr_equipage;};
    int* getAdHumeur() {return &m_humeur;};
    int* getAdIntegrite() {return &m_integrite_vaisseau;};
    */

    virtual string toSTR() const;

    private:

    int m_nbr_equipage;
    int m_humeur;
    int m_nourriture;
    int m_integrite_vaisseau; 
};

void operator+(Vaisseau* a, vector <int> b);

#endif
