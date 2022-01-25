#include "Personnage.h"
#include "Vaisseau.h"
#include "Evenement.h"
#include "enumeration.h"
#include "Choix.h"
#include "Type.h"
#include "Class.h"

#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>

#define NBSEM 13

using namespace std;

int verif_fin_jeu(Personnage perso, Vaisseau vroum){
    if((perso.getFaim() <= 0) || (perso.getSante() <= 0)){
        return 1;
    }
    else if(( vroum.getHumeur() <= 0) || ( vroum.getIntegrite() <=0 ) || (vroum.getNbr() <= 0) || (vroum.getNourriture() <= 0))
    {
        return 1;
    }
    return 0;
}

void clear_maps(map<int*, int>RA, map<int*, int>EA, map<int*, int>RB,map<int*, int>EB , map<int*, int>RC, map<int*, int>EC){
    RA.erase(RA.begin(), RA.end());
    EA.erase(EA.begin(), EA.end());
    RB.erase(RB.begin(), RB.end());
    EB.erase(EB.begin(), EB.end());
    RC.erase(RC.begin(), RC.end());
    EC.erase(EC.begin(), EC.end());
}


int main(){
    //creation vaisseau
    Vaisseau andromede;

    //creation personnage
    string re;
    cout << "Choix de la classe de personnage. Choix entre: "<<endl <<"cuisinier medecin policier pompier"<<endl;
    cin >> re;

    Type perso(re);
    if((re == "policier")||(re=="pompier")){
        perso.changeBonus(1);
    }
    
    //Creation des evenements
    std::vector <Evenement> eve;  // vecteur de tous les evenements
    std::vector <Choix> choix; //vecteurs des differents choix pour la création d'un evenement

    string intro ="Vous tombez par hasard sur un passage menant au garde manger.";

    //Creationdes choix A B C
    string Alibelle_choix = "Voler de la nourriture";
    string Blibelle_choix = "Prévenir le cuisinier du risque de vole dans les cuisine";
    string Clibelle_choix = "Ne rien faire";
    float Apourcentage = 50; 
    float Bpourcentage = 100;
    float Cpourcentage = 100;
    vector<int> RA_impact(6, 0); 
    vector<int> EA_impact(6, 0); 
    vector<int> RB_impact(6, 0); 
    vector<int> EB_impact(6, 0); 
    vector<int> RC_impact(6, 0); 
    vector<int> EC_impact(6, 0); 
    RA_impact[faim] = 25;  //vecteur des impacts , fonctionne grace a enum
    RA_impact[nourriture] = -5;
    EA_impact[humeur] = -15;
    RB_impact[humeur] = 15;
    string AR_lib = "Vous réussissez à voler quelques fruits dans le garde manger";
    string AE_lib=" Vous réussissez à vous introduire dans le garde manger mais un cuisinier vous repere. Vous êtes séquestré dans votre appartement pour quelques jour, l'humeur du vaisseau est impacté par votre tentive.";
    string BR_lib= "Vous prévenez la sécurité d'un trou ou pourrait passer un homme accroupis reliant un cagibit et le garde manger. Vous etes remerciés chaleureusement.";
    string BE_lib= "";
    string CR_lib = "Vous ne prenez pas cette opportunité";
    string CE_lib = "";

    Choix a(Alibelle_choix, Apourcentage, RA_impact, EA_impact, AR_lib, AE_lib);
    Choix b(Blibelle_choix, Bpourcentage, RB_impact, EB_impact, BR_lib, BE_lib);
    Choix c(Clibelle_choix, Cpourcentage, RC_impact, EC_impact, CR_lib, CE_lib); 
    choix.push_back(a);
    choix.push_back(b);
    choix.push_back(c);

    //Creation Evenement voler_nourriture
    //Evenement nourriture(intro, a, b, c);
    Evenement nourriture(intro, choix);
    choix.clear();
    eve.push_back(nourriture); //rajout de l'evenement dans le vect


    //Evenement 2
    intro ="Vous assistez à une scène de raquette dans les bas fonds du vaisseau.";

    //Creationdes choix A B C
    Alibelle_choix = "Prendre la défense de l'oprimé";
    Blibelle_choix = "Partir en courant, vous ne voulez pas etre mêlé a ca";
    Clibelle_choix = "Ne rien faire";
    Apourcentage = 30; 
    Bpourcentage = 100;
    Cpourcentage = 100; 
    RA_impact[humeur] = 25;  //vecteur des impacts , fonctionne grace a enum
    //RA_impact[nourriture] = -5;
    EA_impact[humeur] = -10;
    EA_impact[nbr_equipage] = -5;
    RB_impact[humeur] = -25;
    RB_impact[nbr_equipage] = -10;
    AR_lib="Vous êtes envolopé d'une rage guerierre et réussissez à mettre en déroute les opresseurs.";
    AE_lib="Vous essayez de vous interposez. Malheureusement vous vous êtes surestimés. Vous vous faites également raqueter";
    BR_lib= "Il faut se rendre à l'évidence, vous n'aviez aucune chance";
    BE_lib= "";
    CR_lib= "Vous ignorez et continuez votre chemin par une autre direction.";
    CE_lib= "";

  //  cout << "?? = "<< RB_impact[0]<<endl;

    Choix a2(Alibelle_choix, Apourcentage, RA_impact, EA_impact, AR_lib, AE_lib);
    Choix b2(Blibelle_choix, Bpourcentage, RB_impact, EB_impact, BR_lib, BE_lib);
    Choix c2(Clibelle_choix, Cpourcentage, RC_impact, EC_impact, CR_lib, CE_lib); 
    choix.push_back(a2);
    choix.push_back(b2);
    choix.push_back(c2);
    //Creation Evenement
    //Evenement nourriture(intro, a, b, c);
    Evenement raquette(intro, choix);
    choix.clear();
    eve.push_back(raquette); //rajout de l'evenement dans le vect


    //Evenement 3
    intro ="Le vaisseau est sensé être autosuffisant.  Mais les portions de repas sont maigres. Un homme, visiblement faible, vous demande que vous lui laissiez votre ticket repas du jour pour qu'il puisse nourrir convenablement sa famille.";

    //Creationdes choix A B C
    Alibelle_choix = "Vous acceptez sans hésiter";
    Blibelle_choix = "Vous hésitez à le croire. Vous acceptez en échange de médicaments.";
    Clibelle_choix = "Vous l'ignorez.";
    Apourcentage = 100; 
    Bpourcentage = 100;
    Cpourcentage = 100; 
    RA_impact[humeur] = 5;  //vecteur des impacts , fonctionne grace a enum
    RA_impact[faim] = -15;
    RA_impact[sante] = -15;
    RB_impact[sante] = 15;
    RB_impact[faim] = -15;
    AR_lib="Il vous remercie et promet qu'un jour il vous rendra l'appareil.";
    AE_lib="";
    BR_lib= "L'homme accepte l'échange et vous remercie.";
    BE_lib= "";
    CR_lib= "*ignore*";
    CE_lib= "";

  //  cout << "?? = "<< RB_impact[0]<<endl;

    Choix a3(Alibelle_choix, Apourcentage, RA_impact, EA_impact, AR_lib, AE_lib);
    Choix b3(Blibelle_choix, Bpourcentage, RB_impact, EB_impact, BR_lib, BE_lib);
    Choix c3(Clibelle_choix, Cpourcentage, RC_impact, EC_impact, CR_lib, CE_lib); 
    choix.push_back(a3);
    choix.push_back(b3);
    choix.push_back(c3);
    //Creation Evenement
    //Evenement nourriture(intro, a, b, c);
    Evenement demande(intro, choix);
    choix.clear();
    eve.push_back(demande); //rajout de l'evenement dans le vect

    //Evenement 4
    intro ="Vous vous réveillez en sursaut. Une forte odeur de brûlé emplie vos narine et de la fumée vous pique les yeux.";

    //Creationdes choix A B C
    Alibelle_choix = "vous sortez précipitamment de votre chambre sans rien emporter. Vous mettre en sécurité est le plus important. ";
    Blibelle_choix = "Vous rassemblez vos affaires importantes  pour partir avec. Pas question de tout abondonner";
    Clibelle_choix = "vous vous rendormez";
    Apourcentage = 100; 
    Bpourcentage = 60;
    Cpourcentage = 100; 
    RA_impact[integrite_vaisseau] = -20;  
    RA_impact[faim] = -15;
    RA_impact[sante] = -25;
    RB_impact[integrite_vaisseau] = -30;  
    RB_impact[nbr_equipage] = -5;
    RB_impact[sante] = -5;
    EB_impact[integrite_vaisseau] = -30;  
    EB_impact[nbr_equipage] = -10;
    EB_impact[sante] = -40;
    EB_impact[faim] = -15;
    RC_impact[integrite_vaisseau] = -30;  
    RC_impact[nbr_equipage] = -20;
    RC_impact[sante] = -60;
    RC_impact[faim] = -30;
    AR_lib="Les dortoirs au niveau de l'aile droite on prit fin. Raison inconnu..";
    AE_lib="";
    BR_lib= "Vous rassemblez vos affaires dans un sac. Votre gorge vous brûle et votre tête tourne mais vous réussissez à partir malgré tout ";
    BE_lib= "Vous commencez à rassembler vos affaires. Votre gorge vous brûle et votre tête tourne. Tout devient noir. Vous vous réveillez dans un lit d'hôpital où l'on vous explique que vous avez été sauvé in extremis du feu ayant ravagé les dortoirs de l'aile droite du vaisseau.";
    CR_lib= "Vous vous réveillez dans un lit d'hôpital où l'on vous explique que vous avez été sauvé in extremis du fen ayant ravagé les dortoirs de l'aile droite du vaisseau.";
    CE_lib= "";

  //  cout << "?? = "<< RB_impact[0]<<endl;

    Choix a4(Alibelle_choix, Apourcentage, RA_impact, EA_impact, AR_lib, AE_lib);
    Choix b4(Blibelle_choix, Bpourcentage, RB_impact, EB_impact, BR_lib, BE_lib);
    Choix c4(Clibelle_choix, Cpourcentage, RC_impact, EC_impact, CR_lib, CE_lib); 
    choix.push_back(a4);
    choix.push_back(b4);
    choix.push_back(c4);
    //Creation Evenement
    Evenement feu(intro, choix);
    choix.clear();
    eve.push_back(feu); //rajout de l'evenement dans le vect



    //afficher synopsis
    string pitch ="A cause de la pollution, des guerres nucléaire, des tempêtes solaires et autres maux… Notre planete n'est aujourd'hui plus habitable. Dans un dernier effort collectif, l'humanité construit le vaisseau 'Andromede' capable de transporter les derniers survivants de la terre dans l'espace en quête d'une terre promise, la planète B. Une planète aux conditions exactements similaires à la terre. Andromede decolle en l'an XX, avec vous, un survivant parmi tant d'autres, à son bord.";
    cout << pitch << endl;

    //boucle
    int nbre_semaines = 5;
    int i = 1;
    int booleen = 0;
    int n, taille;
    srand(time(0));//pour l'aleatoire
    cout<<endl;
    while(i < nbre_semaines){
        
        //affichage n°semaine + infos perssonnages et vaisseau
        cout << "Semaine " << i << endl << "Toujours pas de Planete B à l'horizon.. Mais vous gardez espoir."<<endl;


        string v = andromede.toSTR();
        string p = perso.toSTR();
        
        cout << "Etat du vaisseau:" << endl << v <<endl;
        cout << "Fiche personnage:" << endl << p <<endl;

        //verif facteurs de fin du jeu
        if(verif_fin_jeu(perso, andromede)) //si on a perdu 
        { 
            booleen = 1;
            break;
        }

        taille = eve.size();
        n = rand()%taille; //choix aléatoire de l'évenement
        eve[n].application_evenement(eve[n], &andromede, &perso);
        eve.erase(eve.begin()+n); //on enleve cet evenement du tableau pour ne pas retomber dessus

       

        //effet de la class de personnage
        cout << "effet de class: ";
        if(perso.getType()=="cuisinier"){ 
            perso.changeFaim(perso.getBonus());
            cout<<" cuisinier, vous manger a votre faim(bonus nourriture)" <<endl;
        }
        if(perso.getType()=="medecin"){ 
            perso.changeSante(perso.getBonus());
            cout<<" medecin, vous faites attention à votre santé(bonus sante)" <<endl;
        }

        if(perso.getType()=="policier"){ 
            andromede.changeHumeur(perso.getBonus());
            cout<<" policier, vous faites respecter la loi(bonus humeur)" <<endl;
        }
        if(perso.getType()=="pompier"){ 
            andromede.changeNb(perso.getBonus());
            cout<<" pompier, vous sauvez des vies(bonus securite)" <<endl;
        }
        i++;
        cout <<endl<<endl<<endl<<endl;
    }

    if(booleen ==0){
        string fin= "Apres de nombreuses années à vogué dans le vide intergallactique, à rechercher cette terre promise derrière chaque asteroide. A traverser les galaxis connus et inconnus. Vous prenez enfin conscience qu'il n'y a jamais eu de planete B.... Que votre voyage n'aura jamais de fin, excepté la votre";
        cout << endl << fin <<endl;
    }
    else{
        cout << "Vous êtes mort."<<endl;
    }

    return 0;

}

