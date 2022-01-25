#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <string>
#include <vector>
#include <map>
#include "Choix.h"

using namespace std;

class Personnage;
class Vaisseau;

class Evenement: public Choix{

    public:
    Evenement();
    Evenement(string intro);
    string getIntro() const{return m_intro;};
    std::vector <Choix> getChoix() const{return m_choix;};
    //Evenement(string l, Choix& aa, Choix& bb, Choix& cc);
    Evenement(string l, vector <Choix> choix);
    void intro(string intro);
    virtual string toSTR() const;
    void effectuer_consequences(Vaisseau* andromede, Personnage* perso, vector<int> vei);
    void application_evenement(Evenement a,Vaisseau *v, Personnage *p);
//    afficher_libelle(Evenement a);



    string m_intro;
    std::vector <Choix> m_choix;
   // Choix a;
    //Choix b;
   // Choix c;



    /*
    map<char,string>m_choix; //choix i : libellé
    vector <float> m_pourcentages();//les pourcentages de reussite de chaque choix : %a/%b...
    vector <string> m_impacts(); //les impacts reussistes/echec de chaque choix : Perso.satiete / Vaisseau.humeur ...
    vector <int> m_valeurs_impact();  //20/-30...
*/
    
};

#endif
