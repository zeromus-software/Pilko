////////////////////////////////////////////////////////////
//***********************Projet Pilko***********************
//Autheur : Mohackz (de ZEROMUS SOFTWARE TEAM)
//fichier : jeu.cpp
//fonction : affiche l'interface jeu
//date de creation : ???????(à fixé)
//derniere modification : ???????(à fixé)
//terminé le : ???????(à fixé)
////////////////////////////////////////////////////////////
#include "constantes.hpp"

using namespace std;

void joue(void)
{
    sf::Event even;
    sf::RenderWindow win(sf::VideoMode(320,320,32),"zGameBall");
    sf::Texture spriteSheet;
    spriteSheet.loadFromFile("mouvement.png");
    Animation mouvement;
    mouvement.setSpriteSheet(spriteSheet);
    mouvement.addFrame(sf::IntRect(0,0,100,100));
    mouvement.addFrame(sf::IntRect(1*100,0,100,100));
    mouvement.addFrame(sf::IntRect(2*100,0,100,100));
    mouvement.addFrame(sf::IntRect(3*100,0,100,100));
    mouvement.addFrame(sf::IntRect(4*100,0,100,100));
    mouvement.addFrame(sf::IntRect(5*100,0,100,100));
    mouvement.addFrame(sf::IntRect(6*100,0,100,100));

    AnimatedSprite pilko(sf::seconds(0.1));
    pilko.setAnimation(mouvement);
    pilko.setPosition(0,0);
    pilko.pause();

    win.setFramerateLimit(60);

    sf::Clock frameClock;
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
                case sf::Keyboard::Left:
                    pilko.play();
                    pilko.move(-4,0);
                break;
                case sf::Keyboard::Right:
                    pilko.play();
                    pilko.move(4,0);
                break;
                default:
                break;
                }
            break;
            case sf::Event::KeyReleased:
                 switch(even.key.code)
                {
                    case sf::Keyboard::Left:
                        pilko.pause();
                    break;
                    case sf::Keyboard::Right:
                        pilko.pause();
                    break;
                    default:
                    break;

           }
          break;
        }

    pilko.update(frameClock.restart());
    afficherMap("map.txt",win);
    win.draw(pilko);
    win.display();
    win.clear(sf::Color(178,148,120,255));

}
}

}
