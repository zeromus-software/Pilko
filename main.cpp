////////////////////////////////////////////////////////////
//***********************Projet Pilko***********************
//Autheur : Mohackz (de ZEROMUS SOFTWARE TEAM)
//fichier : main.cpp
//fonction : affiche le menu et renvoyer dans d'autre interface
//date de creation : ???????(à fixé)
//derniere modification : ???????(à fixé)
//terminé le : ???????(à fixé)
////////////////////////////////////////////////////////////
#ifdef __cplusplus //Ce projet ne peut etre compile qu'en C++

#include "constantes.hpp"

using namespace std;

int main(int argc,char* argv[])
{
    sf::Event even;
    int choix = 0;
    sf::RenderWindow win(sf::VideoMode(800,600,32),"zGameBall");

    //chargement du fond
    sf::Texture fondTexture;
    if(!fondTexture.loadFromFile("fond.jpg"))
    {
        cout << "Erreur lors du chargement de \"fond.jpg\"" << endl;
        return 1;
    }

    sf::Sprite fond ;
    fond.setTexture(fondTexture);

   //Chargement des polices
    sf::Font alger,bauh;
   if(!alger.loadFromFile("alger.ttf"))
   {
       cerr << "Erreur de chargement du font : \"alger.tff\"" << endl;
       return 1;
   }
   if(!bauh.loadFromFile("bauh.ttf"))
   {
       cerr << "Erreur de chargement du font : \"bauh.tff\"" << endl;
       return 1;
   }
   //Declaration des contructeurs Text pour le menu et positionnement du texte
   sf::Text titre("Menu principal",alger,80);
   sf::Text jouer("Jouer",bauh,50);
   sf::Text boutique("Boutique",bauh,50);
   sf::Text aide("Aide",bauh,50);
   sf::Text quiter("Quitter",bauh,50);
   titre.setPosition(100,80);
   sf::Vector2f posText;
   posText.x = 160;
   posText.y = 200;
   jouer.setPosition(posText);
   boutique.setPosition(posText.x,posText.y+50);
   aide.setPosition(posText.x,posText.y+100);
   quiter.setPosition(posText.x,posText.y+150);

   //limite le FPS a 50 Frame per second
    win.setFramerateLimit(30);

    /**boucle principal**/

    while(win.isOpen())
{
        while(win.pollEvent(even))
        {
            switch(even.type)
            {
            case sf::Event::Closed:
                win.close();
            break;
            case sf::Event::KeyPressed:
                 switch(even.key.code)
               {
               //SI on appui sur Down, on incremente choix
               case sf::Keyboard::Down:
                 choix++;
                 //si choix depasse 4 ,choix soit egal a 4
                 if(choix > 4)
                 {
                     choix = 4;
                 }
               break;
               //si on appui sur Up ,on decrement choix
               case sf::Keyboard::Up:
                 choix--;
                //si choix est inferieur a 1 ,choix soit egal 1
                 if(choix < 1)
                 {
                     choix=1;
                 }
               break;
               //si on appui sur space ...
               case sf::Keyboard::Space:
                //..et que choix egal a 1
                if(choix == 1)
                {
                    //on ferme le menu
                    win.close();
                    /*et a la fermeture du programme, on fait appel a la fonction joue() qui declare
                     un constructeur RenderWindow ce qui entraine l'ouverture d'une autre fenetre .
                     Vous avez saisie le principe les gars ;-) .*/
                    atexit(joue);
                }
               break;
               default:
                break;
               }
            break;
            default:
            break;
            }

        }

    //On dessine le menu
    win.draw(fond);
     win.draw(titre);
     win.draw(jouer);
     win.draw(boutique);
     win.draw(aide);
     win.draw(quiter);
     //Modifier le texte en fonction du choix de l'utilisateur
     switch(choix)
    {
    /*SI choix est egal a 1 ,le text Jouer devient rouge ,les autres blanc,par contre si choix egal a 2
    Boutique devient rouge ,les autres reviennent a leur couleur initiale (c'est-a-dire blanc) et ainsi de suite..*/
    case 1:
    win.draw(fond);
     win.draw(titre);
     jouer.setColor(sf::Color::Red);
     win.draw(jouer);
     boutique.setColor(sf::Color::White);
     win.draw(boutique);
     aide.setColor(sf::Color::White);
     win.draw(aide);
     quiter.setColor(sf::Color::White);
     win.draw(quiter);
    break;
    case 2:
    win.draw(fond);
     win.draw(titre);
     jouer.setColor(sf::Color::White);
     win.draw(jouer);
     boutique.setColor(sf::Color::Red);
     win.draw(boutique);
     aide.setColor(sf::Color::White);
     win.draw(aide);
     quiter.setColor(sf::Color::White);
     win.draw(quiter);
    break;
    case 3:
    win.draw(fond);
     win.draw(titre);
     jouer.setColor(sf::Color::White);
     win.draw(jouer);
     boutique.setColor(sf::Color::White);
     win.draw(boutique);
     aide.setColor(sf::Color::Red);
     win.draw(aide);
     quiter.setColor(sf::Color::White);
     win.draw(quiter);
    break;
    case 4:
    win.draw(fond);
     win.draw(titre);
     jouer.setColor(sf::Color::White);
     win.draw(jouer);
     boutique.setColor(sf::Color::White);
     win.draw(boutique);
     aide.setColor(sf::Color::White);
     win.draw(aide);
     quiter.setColor(sf::Color::Red);
     win.draw(quiter);
    break;
    default:
    break;
    }

        win.display();//on affiche l'ecran
        win.clear(sf::Color(255,220,167,255));//on efface l'efface l'ecran precedent
}

    return EXIT_SUCCESS;//et enfin on quitte avec succes
    /*Infos :
    Ce menu devore beaucoup en ressource CPU donc je crois que vous serez capable
    de limiter ce ressource ,je compte sur vous les gars ;-) */
}
#else
"Desole ce projet ne peut etre compiler en C,car ce projet profite des fonctionnalites du c++"
#endif //__cplusplus
