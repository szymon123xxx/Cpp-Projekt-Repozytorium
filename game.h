#ifndef GAME_H
#define GAME_H


#include "libraries.h"
#include "player.h"

class Game{
private:
    
    sf::RenderWindow *window;
    sf::Event event;
    Player *player;
    void initWindow();
    void IPlayer();

public:
    
    Game();
    ~Game();

    
    void SFMLevents();
    void playerMove(); //updating playing move
    void update();
    void render();
    void run();

};

#endif // GAME_H
