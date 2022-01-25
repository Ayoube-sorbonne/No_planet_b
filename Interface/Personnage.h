#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "enumeration.h"

using namespace std;

class Personnage;
class Vaisseau;

class Personnage{

    public:
    Personnage(); //constructeur
    
    void changer_nom(string nom){m_nom = nom;};
    int getSante() const{return m_sante;};
    int getFaim() const{return m_faim;};
    string getNom() const{return m_nom;};
    void changeSante(int b) {m_sante+=b;};
    void changeFaim(int b) {m_faim+=b;}; 

    /*
    int* getAdFaim() {return &m_faim;}
    int* getAdSante() {return &m_sante;}
    */
    virtual string toSTR() const;



    protected:

    string m_nom;
    int m_sante;
    int m_faim;
};

void operator+(Personnage *a, vector <int> b);

#endif
