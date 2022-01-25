#include "Personnage.h"
#include "Vaisseau.h"
#include "Evenement.h"
#include "enumeration.h"
#include "Choix.h"
#include "Type.h"
#include "Class.h"
#include "Musique.h"


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Personnage;
class Vaisseau;

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

void loop_choix(Vaisseau *andro, Class *perso, vector <Evenement> eve){

    int taille = eve.size();
    int n = rand()%taille; //choix aléatoire de l'évenement


    sf::RenderWindow window( sf::VideoMode( 1600, 1000 ), "Choix", sf::Style::Titlebar);    
    sf::Texture background;
    sf::Sprite backgroundImage;

    


    sf::Texture ValidateTexture;
    sf::Sprite ValidateSprite;
    ValidateTexture.loadFromFile("./image/boutonquitter.png");
    ValidateSprite.setPosition(window.getSize().x*0.9 - ValidateTexture.getSize().x/2, window.getSize().y*0.9 - ValidateTexture.getSize().y/2 );
    ValidateSprite.setTexture(ValidateTexture);



    sf::Texture ca;
    sf::Sprite cas;
    ca.loadFromFile("./image/ca.png");
    cas.setPosition(window.getSize().x*0.1, window.getSize().y/2 + 150 );
    cas.setTexture(ca);

    sf::Texture cb;
    sf::Sprite cbs;
    cb.loadFromFile("./image/cb.png");
    cbs.setPosition(window.getSize().x*0.1, window.getSize().y/2 + 250);
    cbs.setTexture(cb);


    sf::Texture cc;
    sf::Sprite ccs;
    cc.loadFromFile("./image/cc.png");
    ccs.setPosition(window.getSize().x*0.1, window.getSize().y/2 + 350);
    ccs.setTexture(cc);


    sf::Font font;
    font.loadFromFile("./font/open-sans/OpenSans-Bold.ttf");

    sf::Text Libe;
    Libe.setString(eve[n].getIntro());
    Libe.setCharacterSize(40);
    Libe.setFillColor(sf::Color::White);
    Libe.setPosition(window.getSize().x*0.1, window.getSize().y/2 + 50 );
    Libe.setFont(font);

    sf::Text choicea;
    choicea.setString(eve[n].m_choix[0].getLibelle() + " (" + to_string(eve[n].m_choix[0].getPourcen()) + "% de reussite)");
    choicea.setCharacterSize(30);
    choicea.setFillColor(sf::Color::White);
    choicea.setPosition(cas.getPosition().x*2 + 50, window.getSize().y/2 + 150 );
    choicea.setFont(font);

    sf::Text choiceb;
    choiceb.setString(eve[n].m_choix[1].getLibelle() + " (" + to_string(eve[n].m_choix[1].getPourcen()) + "% de reussite)");
    choiceb.setCharacterSize(30);
    choiceb.setFillColor(sf::Color::White);
    choiceb.setPosition(cas.getPosition().x*2 + 50, window.getSize().y/2 + 250 );
    choiceb.setFont(font);


    sf::Text choicec;
    choicec.setString(eve[n].m_choix[2].getLibelle() + " (" + to_string(eve[n].m_choix[2].getPourcen()) + "% de reussite)");
    choicec.setCharacterSize(30);
    choicec.setFillColor(sf::Color::White);
    choicec.setPosition(ccs.getPosition().x*2 + 50, window.getSize().y/2 + 350 );
    choicec.setFont(font);

    sf::Text resultata;
    resultata.setCharacterSize(30);
    resultata.setFillColor(sf::Color::White);
    resultata.setPosition(window.getSize().x/2  - 200, window.getSize().y/2 - 200);
    resultata.setFont(font);

    sf::RectangleShape rectangle(sf::Vector2f(1600, 500));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(0,500);
    int compt = 0;

    while ( window.isOpen() )
    {
        sf::Event Event;
        while ( window.pollEvent( Event ) )
        {
            switch ( Event.type )
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                case sf::Event::MouseMoved:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                }
                break;
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                    if(ValidateSprite.getGlobalBounds().contains(mousePosF)) {
                        window.close();
                    }
                    if(cas.getGlobalBounds().contains(mousePosF)) {
                        float pourcentage = eve[n].m_choix[0].getPourcen();
                            if(pourcentage == 100){
                                resultata.setString(eve[n].m_choix[0].getLibReussite());
                                //effectuer_consequences
                                andro + eve[n].m_choix[0].getImpactR(); 
                                perso + eve[n].m_choix[0].getImpactR();

                            }
                            else{
                                srand(time(0));
                                float l = rand()%100;
                                if(l < pourcentage){
                                    resultata.setString(eve[n].m_choix[0].getLibReussite());    
                                    andro + eve[n].m_choix[0].getImpactR(); 
                                    perso + eve[n].m_choix[0].getImpactR();
                                }
                                else{
                                    resultata.setString(eve[n].m_choix[0].getLibEchec());   
                                    andro + eve[n].m_choix[0].getImpactE(); 
                                    perso + eve[n].m_choix[0].getImpactE();
                                }
                            }
                        compt = 1;    
                    }
                    if(cbs.getGlobalBounds().contains(mousePosF)) {
                        float pourcentage = eve[n].m_choix[1].getPourcen();
                            if(pourcentage == 100){
                                resultata.setString(eve[n].m_choix[0].getLibReussite());
                                //effectuer_consequences
                                andro + eve[n].m_choix[1].getImpactR(); 
                                perso + eve[n].m_choix[1].getImpactR();

                            }
                            else{
                                srand(time(0));
                                float l = rand()%100;
                                if(l < pourcentage){
                                    resultata.setString(eve[n].m_choix[1].getLibReussite());    
                                    andro + eve[n].m_choix[1].getImpactR(); 
                                    perso + eve[n].m_choix[1].getImpactR();
                                }
                                else{
                                    resultata.setString(eve[n].m_choix[0].getLibEchec());   
                                    andro + eve[n].m_choix[1].getImpactE(); 
                                    perso + eve[n].m_choix[1].getImpactE();
                                }
                        compt = 1;                       
                    }
                    if(ccs.getGlobalBounds().contains(mousePosF)) {
                        float pourcentage = eve[n].m_choix[2].getPourcen();
                            if(pourcentage == 100){
                                resultata.setString(eve[n].m_choix[2].getLibReussite());
                                //effectuer_consequences
                                andro + eve[n].m_choix[2].getImpactR(); 
                                perso + eve[n].m_choix[2].getImpactR();

                            }
                            else{
                                srand(time(0));
                                float l = rand()%100;
                                if(l < pourcentage){
                                    resultata.setString(eve[n].m_choix[1].getLibReussite());    
                                    andro + eve[n].m_choix[2].getImpactR(); 
                                    perso + eve[n].m_choix[2].getImpactR();
                                }
                                else{
                                    resultata.setString(eve[n].m_choix[0].getLibEchec());   
                                    andro + eve[n].m_choix[2].getImpactE(); 
                                    perso + eve[n].m_choix[2].getImpactE();
                                }
                            }
                        compt = 1;  
                    }
                }
                break;
            }
            }
    window.clear();
    window.draw(rectangle);
    window.draw(Libe);
    window.draw(choicea);
    window.draw(choiceb);
    window.draw(choicec);
    window.draw(cas);
    window.draw(cbs);
    window.draw(ccs);
    window.draw(ValidateSprite);
    window.draw(resultata);
    window.display();
        }
    }
}


void loop(){
    Vaisseau andromede(100);
    Class perso("Policier", 3);
    perso.changer_nom("Bobi");


    //EVENEMENT
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

    Evenement nourriture(intro, choix);
    choix.clear();
    eve.push_back(nourriture); //rajout de l'evenement dans le vect


    //CREATION FENETRE

    sf::RenderWindow windowJeu( sf::VideoMode( 1600, 1000 ), "There is no planet B", sf::Style::Titlebar);

    
    sf::Texture backgroundjeu;
    sf::Sprite backgroundImagejeu;
    


    sf::Texture textureboutonquit;
    sf::Sprite boutonquitter;
    textureboutonquit.loadFromFile("./image/boutonquitter.png");
    boutonquitter.setPosition(windowJeu.getSize().x*0.9 - textureboutonquit.getSize().x/2, windowJeu.getSize().y*0.9 - textureboutonquit.getSize().y/2 );
    boutonquitter.setTexture(textureboutonquit);

    sf::Texture textureboutonchoix;
    sf::Sprite boutonchoix;
    textureboutonchoix.loadFromFile("./image/choix.png");
    boutonchoix.setPosition(windowJeu.getSize().x/2 - textureboutonchoix.getSize().x/2, windowJeu.getSize().y*0.9 - textureboutonquit.getSize().y/2);
    boutonchoix.setTexture(textureboutonchoix);

    sf::Font font;
    font.loadFromFile("./font/open-sans/OpenSans-Bold.ttf");
    //person

    sf::Text person;
    person.setString("Personnage ");
    person.setCharacterSize(40);
    person.setFillColor(sf::Color::White);
    person.setPosition(windowJeu.getSize().x/3 - 150,530);
    person.setFont(font);

    sf::Text name;
    name.setString("Nom : " + perso.getNom());
    name.setCharacterSize(30);
    name.setFillColor(sf::Color::White);
    name.setPosition(windowJeu.getSize().x/3 - 150,610);
    name.setFont(font);


    sf::Text satiete;
    satiete.setString("Satiete :" + to_string(perso.getFaim()));
    satiete.setCharacterSize(30);
    satiete.setFillColor(sf::Color::White);
    satiete.setPosition(windowJeu.getSize().x/3 - 150,730);
    satiete.setFont(font);

    sf::Text spec;
    spec.setString("Classe :" + perso.getClass());
    spec.setCharacterSize(30);
    spec.setFillColor(sf::Color::White);
    spec.setPosition(windowJeu.getSize().x/3 - 150,670);
    spec.setFont(font);

    // boom

    sf::Text boom;
    boom.setString("Vaisseau ");
    boom.setCharacterSize(40);
    boom.setFillColor(sf::Color::White);
    boom.setPosition(windowJeu.getSize().x*(0.66) - 50,530);
    boom.setFont(font);

    sf::Text Equpage;
    Equpage.setString("Equipage :" + to_string(andromede.getNbr()));
    Equpage.setCharacterSize(30);
    Equpage.setFillColor(sf::Color::White);
    Equpage.setPosition(windowJeu.getSize().x*(0.66) - 50,610);
    Equpage.setFont(font);

    sf::Text Inte;
    Inte.setString("Integrite :" + to_string(andromede.getIntegrite()));
    Inte.setCharacterSize(30);
    Inte.setFillColor(sf::Color::White);
    Inte.setPosition(windowJeu.getSize().x*(0.66) - 50,790);
    Inte.setFont(font);

    sf::Text Bouffe;
    Bouffe.setString("Nourriture :" + to_string(andromede.getNourriture()));
    Bouffe.setCharacterSize(30);
    Bouffe.setFillColor(sf::Color::White);
    Bouffe.setPosition(windowJeu.getSize().x*(0.66) - 50,730);
    Bouffe.setFont(font);

    sf::Text Humeu;
    Humeu.setString("Humeur " + to_string(andromede.getHumeur()));
    Humeu.setCharacterSize(30);
    Humeu.setFillColor(sf::Color::White);
    Humeu.setPosition(windowJeu.getSize().x*(0.66) - 50,670);
    Humeu.setFont(font);


    sf::Text Weeks;
    Weeks.setString("Semaine " + to_string(1));
    Weeks.setCharacterSize(50);
    Weeks.setFillColor(sf::Color::White);
    Weeks.setPosition(windowJeu.getSize().x/2 - 100,10);
    Weeks.setFont(font);


    sf::RectangleShape rectangle(sf::Vector2f(1600, 500));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(0,500);

    int nbre_semaines = 3;
    int i = 1;
    int booleen = 0;
    srand(time(0));//pour l'aleatoire

    while(windowJeu.isOpen() && verif_fin_jeu(perso, andromede)!=1 && i<nbre_semaines ){
        sf::Event Event;
        while ( windowJeu.pollEvent( Event ) ){
            switch ( Event.type ){
                case sf::Event::Closed:
                {
                    windowJeu.close();
                    break;
                }
                case sf::Event::MouseMoved:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition( windowJeu );
                    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );   
                
                }
                break; 
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition( windowJeu );
                    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                    if(boutonquitter.getGlobalBounds().contains(mousePosF)) {
                        windowJeu.close();
                    }
                    else if(boutonchoix.getGlobalBounds().contains(mousePosF)) {
                        loop_choix(&andromede, &perso, eve);
                    }                   
                }
            }
            
        }
        windowJeu.clear();
        windowJeu.draw(rectangle);
        windowJeu.draw(boom);
        windowJeu.draw(person);
        windowJeu.draw(spec);
        windowJeu.draw(satiete);
        windowJeu.draw(name);
        windowJeu.draw(Inte);
        windowJeu.draw(Bouffe);
        windowJeu.draw(Humeu);
        windowJeu.draw(Equpage);
        windowJeu.draw(Weeks);
        windowJeu.draw(boutonquitter);
        windowJeu.draw(boutonchoix);
        windowJeu.display();
    }

}





int main(){

    sf::RenderWindow windowmenu( sf::VideoMode( 1024, 622 ), "Menu Principal", sf::Style::Default );
    windowmenu.setPosition(sf::Vector2i(450, 200));

    sf::Texture background;
    sf::Sprite backgroundImage;

    if ( !background.loadFromFile( "./image/back.jpg" ) ){  //load menu background
        std::cout << "Error: Could not display background image" << std::endl;
    }
    backgroundImage.setTexture( background );


    
    sf::Texture ValidateTexture2;
    sf::Sprite ValidateSprite2;
    ValidateTexture2.loadFromFile("./image/boutonnewgame.png");
    ValidateSprite2.setPosition(windowmenu.getSize().x/2 - ValidateTexture2.getSize().x/2,windowmenu.getSize().y/1.7 -  ValidateTexture2.getSize().y/2);
    ValidateSprite2.setTexture(ValidateTexture2);
    sf::Texture ValidateTexture3;
    sf::Sprite ValidateSprite3;
    ValidateTexture3.loadFromFile("./image/boutonquitter.png");
    ValidateSprite3.setPosition(windowmenu.getSize().x/2 - ValidateTexture3.getSize().x/2,windowmenu.getSize().y/1.2 -  ValidateTexture3.getSize().y/2);
    ValidateSprite3.setTexture(ValidateTexture3);


    while ( windowmenu.isOpen() )
    {
        sf::Event Event;
        while ( windowmenu.pollEvent( Event ) )
        {
            switch ( Event.type )
            {
                case sf::Event::Closed:
                {
                    windowmenu.close();
                    break;
                }
                case sf::Event::MouseMoved:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition( windowmenu );
                    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                }
                break;
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition( windowmenu );
                    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                    if(ValidateSprite2.getGlobalBounds().contains(mousePosF)) {
                        windowmenu.close();
                        loop();
                    }
                    else if(ValidateSprite3.getGlobalBounds().contains(mousePosF)) {
                        windowmenu.close();
                    }
                }
                break;
            }
    windowmenu.clear();
    windowmenu.draw(backgroundImage);
    windowmenu.draw(ValidateSprite3);
    windowmenu.draw(ValidateSprite2);
    windowmenu.display();
        }
    };



    return 0;
}