#include "Choix.h"

using namespace std;

Choix::Choix()
{
    m_libelle = "Choix a";
    m_pourcentage_reussite = 0.25;

   // m_impact_reussite.insert(make_pair("Personnage",30));
   // m_impact_reussite.insert(make_pair("Humeur",20));
   // m_impact_echec.insert(make_pair("Nourriture",30));

    m_libelle_reussite = "Yes nice";
    m_libelle_echec = "Haha loser";

}

Choix::Choix(string s, float p, vector<int> ir, vector<int> ie, string lr, string le)
{
    m_libelle = s;
    m_pourcentage_reussite = p;
    m_impact_reussite = ir;
    m_impact_echec = ie;
    m_libelle_reussite = lr;
    m_libelle_echec = le;
}

string Choix::toSTR() const
{
    string s;
    s += "Libelle : " + m_libelle + ", ";
    s += "pourcentage : " + to_string(m_pourcentage_reussite) + ", ";
    s += "Libelle reussite : " + m_libelle_reussite + ", ";
  //  for (const auto & m : m_impact_reussite){
    //    s += "Impact : " + m.first + ", ";
  //      s += "Nombre : " + to_string(m.second) + ", ";
  //  }
    s += "Libelle echec : " + m_libelle_echec + ", ";
  //  for (const auto & m : m_impact_echec){
  //      s += "Impact : " + m.first + ", ";
  //      s += "Nombre : " + to_string(m.second) + ", ";
  //  }

    return s;

}
/*
int main(){

    string l = "Choix a";
    float pr = 0.25;

    map<string,int>imr;
    map<string,int>ime;

    imr.insert(make_pair("Pou",30));
    imr.insert(make_pair("Pi",20));
    ime.insert(make_pair("Nourriture",30));

    string lr = "Yes nice";
    string le = "Haha loser";

    Choix A(l, pr, imr, ime, lr, le);

    string s = A.toSTR();

    cout << s;
}
*/



