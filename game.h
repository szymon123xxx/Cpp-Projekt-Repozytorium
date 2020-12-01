#ifndef GAME_H
#define GAME_H


#include "libraries.h"
#include "player.h"
#include "enemy.h"
#include "wall.h"
#include "menu.h"
#include "scoreAndGraph.h"
#include "menuLevels.h"

class Game{
private:
    
    sf::RenderWindow *window;
    sf::Event event;
    Player *player;
    Enemy *enemy;
    Wall *wall;
    Menu *menu;
    ScoreAndGraph *scoreAndGraph;
    MenuLevels *menuLevels;

    void initWindow();
    void IPlayer();
    void IEnemy();
    void IWall();
    void IMenu();
    void IscoreAndGraph();
    void IMenuLevels();

public:
    
    Game();
    ~Game();

    
    void SFMLevents();
    void SFMLeventsMenu();
    void SFMLeventsLevelMenu();
    void playerMove(); //updating move
    void update();
    void render();
    void run();
    void renderMenu();
    void menuRun();
    void menuLevelRun();
    void renderLevelMenu();

};

#endif // GAME_H
