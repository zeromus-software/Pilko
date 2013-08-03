////////////////////////////////////////////////////////////
//***********************Projet Pilko***********************
//Autheur : Mohackz (de ZEROMUS SOFTWARE TEAM)
//fichier : map.cpp
//fonction : charger le map
//date de creation : ???????(à fixé)
//derniere modification : ???????(à fixé)
//terminé le : ???????(à fixé)
////////////////////////////////////////////////////////////
#include "constantes.hpp"
#include <fstream>

using namespace std;

void afficherMap(const char* Mapfile,sf::RenderWindow& window)
{
    sf::Texture tileTexture;
    sf::Sprite tileSprite;
    ifstream fileMap(Mapfile);
    if(fileMap.is_open())
    {
        int nb_block_x,nb_block_y,i,j;
        fileMap >> nb_block_x >> nb_block_y;
        string locationTile;
        fileMap >> locationTile;
        tileTexture.loadFromFile(locationTile);
        tileSprite.setTexture(tileTexture);
        while(!fileMap.eof())
        {
        for(i=0;i<nb_block_x;i++)
        {
            for(j=0;j<nb_block_y;j++)
            {
            string str;
            fileMap >> str;
            char x = str[i];
            if(x == 0){  tileSprite.setTextureRect(sf::IntRect(0,0,TILESIZE,TILESIZE));  }
            if(x == 1){  tileSprite.setTextureRect(sf::IntRect(1*TILESIZE,0,TILESIZE,TILESIZE)); }
            if(x == 2){ tileSprite.setTextureRect(sf::IntRect(2*TILESIZE,0,TILESIZE,TILESIZE)); }
            tileSprite.setPosition(i*TILESIZE,j*TILESIZE);
            window.draw(tileSprite);
            }
        }
        }
    }
}
