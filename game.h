//
// Created by szymon on 31.10.2020.
//

#ifndef GAME_H
#define GAME_H

#include "libraries.h"

class Game {
private:
    // variables
    sf::RenderWindow *window;
    sf::Event event;
    void initWindow();

public:
    // constructor and destructor
    Game();
    ~Game();

    // initialization of methods
    void updateSFMLevents();
    void update();
    void render();
    void run();

};

#endif //GAME_H
