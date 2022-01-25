#ifndef CHOIX_H
#define CHOIX_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include "enumeration.h"

using namespace std;

class Choix{
    public:
    Choix();
    Choix(string s, float p, vector<int> ir, vector<int> ie, string lr, string le);
    virtual string toSTR() const;
    string getLibelle() const {return m_libelle;};
    string getLibReussite() const {return m_libelle_reussite;};
    string getLibEchec() const {return m_libelle_echec;};
    float getPourcen() const {return m_pourcentage_reussite;};
    vector <int> getImpactR() const {return m_impact_reussite;};
    vector <int> getImpactE() const {return m_impact_echec;};

    private:
    string m_libelle;
    float m_pourcentage_reussite;
    
    vector <int> m_impact_reussite; //parametre car on fait une enumeration
    vector <int> m_impact_echec;
    /*
    map<int*,int> m_impact_reussite;
    map<int*,int> m_impact_echec;
    */
    string m_libelle_reussite;
    string m_libelle_echec;
};

#endif