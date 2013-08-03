////////////////////////////////////////////////////////////
//***********************Projet Pilko***********************
//Autheur : Mohackz (de ZEROMUS SOFTWARE TEAM)
//fichier : constantes.hpp
//fonction : regroupe les prototypes des fonctions et les includes aussi
//date de creation : ???????(à fixé)
//derniere modification : ???????(à fixé)
//terminé le : ???????(à fixé)
////////////////////////////////////////////////////////////
#ifndef CONSTANTES_HPP_INCLUDED
#define CONSTANTES_HPP_INCLUDED

#define TILESIZE 32

#include <SFML/Graphics.hpp>
#include "Animation/Animation.hpp"
#include "Animation/AnimatedSprite.hpp"
#include <iostream>

void joue(void);
void afficherMap(const char* Mapfile,sf::RenderWindow& window);

#endif // CONSTANTES_HPP_INCLUDED
