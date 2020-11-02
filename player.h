#ifndef PLAYER_H
#define PLAYER_H

#include "libraries.h"

class Player{

public:
 Player();
 ~Player();

 sf::Texture _Texture;
 sf::Sprite _Sprite; //Player sprite
 sf::Vector2f _Position;

 void moving(sf::Vector2f _Position );
 
};

#endif
