//
// Created by szymon on 01.12.2020.
//

#ifndef CPP_PROJEKT_REPOZYTORIUM_MAIN_SCOREANDGRAPH_H
#define CPP_PROJEKT_REPOZYTORIUM_MAIN_SCOREANDGRAPH_H
#include "libraries.h"

class ScoreAndGraph {
public:
    ScoreAndGraph();
    ~ScoreAndGraph();

    sf::Font font;
    sf::Text score;

    int score_int;
    std::string score_text;
    sf::Texture Score_Texture;
    sf::Sprite Score_Sprite;

    sf::Texture HP_Red_Texture;
    sf::Sprite HP_Red_Sprite;

    sf::Texture HP_Black_Texture;
    sf::Sprite HP_Black_Sprite;

};


#endif //CPP_PROJEKT_REPOZYTORIUM_MAIN_SCOREANDGRAPH_H
