
#include "scoreAndGraph.h"
ScoreAndGraph::ScoreAndGraph() {
    if ((!font.loadFromFile("Cherry Caramel.ttf")) && (!font.loadFromFile("ostatnie.png")) && (!font.loadFromFile("zycko3.png")))
    {
        std::cout << "scoreAndGraph error" << std::endl;
    }
    this->Score_Texture.loadFromFile("Cherry Caramel.ttf");
    this->Score_Sprite.setTexture(Score_Texture);

    this->HP_Black_Texture.loadFromFile("ostatnie.png");
    this->HP_Black_Sprite.setTexture(HP_Black_Texture);

    this->HP_Red_Texture.loadFromFile("zycko3.png");
    this->HP_Red_Sprite.setTexture(HP_Red_Texture);

    score.setFont(font);
    score.setFillColor(sf::Color::Cyan);
    score.setCharacterSize(80);
    score.setPosition(sf::Vector2f(450, 5));

    score_int = 0;



}

