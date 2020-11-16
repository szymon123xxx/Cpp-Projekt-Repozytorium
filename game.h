#ifndef GAME_H
#define GAME_H


#include "libraries.h"
#include "player.h"
#include "enemy.h"
#include "wall.h"

class Game{
private:
    
    sf::RenderWindow *window;
    sf::Event event;
    Player *player;
    Enemy *enemy;
    Wall *wall;

    void initWindow();
    void IPlayer();
    void IEnemy();
    void IWall();

public:
    
    Game();
    ~Game();

    
    void SFMLevents();
    void playerMove(); //updating move
    void update();
    void render();
    void run();

};

#endif // GAME_H
