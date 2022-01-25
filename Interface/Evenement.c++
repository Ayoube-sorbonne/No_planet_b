#include "Evenement.h"
#include "Vaisseau.h"
#include "Personnage.h"
#include "enumeration.h"
#include <string>


#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Personnage;
class Vaisseau;

Evenement::Evenement(string l, vector <Choix> choix)
{
    m_intro = l;
    m_choix = choix;
}


Evenement::Evenement()
{
    //intro = "Vous avez la possibilité de voler de la nourriture en cuisine.";
    //choix.insert({"a", "voler"});

}

Evenement::Evenement(std::string intro): m_intro(intro){

}

void Evenement::intro(string intro){
    m_intro = intro;
}

string Evenement::toSTR() const //probleme de private je crois
{
    string s;
    s += "Libelle :" + m_intro + ",";
    int taille = m_choix.size();
    for(int i=0; i< taille; i++){
        s+= m_choix[i].toSTR();
    }
   // s += a.toSTR() + b.toSTR() + c.toSTR();
    return s;
}

void Evenement::effectuer_consequences(Vaisseau* andromede, Personnage* perso, vector<int> impacts){
    int i;
    andromede + impacts; //effectuer les consequences sur le vaisseau
    perso + impacts; //effectuer consequences sur personnages
}

void Evenement::application_evenement(Evenement a, Vaisseau *andromede, Personnage *perso){
    /*
    cout <<endl<<"Evenement de la semaine:"<<endl;
    string s = a.getIntro();  
    cout << s << endl;

    //affichage des choix
    int taille = a.getChoix().size();
    for(int i=0; i< taille; i++){ 
        cout << i << " : " << a.m_choix[i].getLibelle() << " ("<< a.m_choix[i].getPourcen() << "% de reussite)"<<endl;
        cout <<endl;
    }
    
    //recup la reponse du joueur
    cout << endl << "Votre choix : ";
    int n, l;
   // map<string,int> impacts;
    cin >> n;
    while((n<0) || (n>2)){
        cout<<"choix invalide, veuillez réessayer : ";
        cin >> n;
    }
    float pourcentage = a.m_choix[n].getPourcen();
    //resultat de l'action
    if(pourcentage == 100){
        cout << a.m_choix[n].getLibReussite() <<endl;
        //effectuer_consequences
        effectuer_consequences(andromede, perso, a.m_choix[n].getImpactR());   
    }
    else{
        srand(time(0));
        l = rand()%100;
        if(l < pourcentage){
            cout << a.m_choix[n].getLibReussite() <<endl;
            effectuer_consequences(andromede, perso, a.m_choix[n].getImpactR());
        }
        else{
            cout << a.m_choix[n].getLibEchec() <<endl;
            effectuer_consequences(andromede, perso, a.m_choix[n].getImpactE());
        }
    }
        */

} 
