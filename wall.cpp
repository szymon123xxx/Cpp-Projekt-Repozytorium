#include "wall.h"

Wall::Wall(){
    this->back_Texture.loadFromFile("tlo.png");
    if (this->back_Texture.loadFromFile("tlo.png"))
        std::cout<<"background loaded";

    this->wall_Texture_horizontal.loadFromFile("sciana4.png");
    if (this->wall_Texture_horizontal.loadFromFile("sciana4.png"))
        std::cout<<"horizontal wall loaded";

    this->wall_Texture_vertical.loadFromFile("sciana5.png");
    if (this->wall_Texture_vertical.loadFromFile("sciana5.png"))
        std::cout<<"vertical wall loaded";

    this->back_Sprite.setTexture(back_Texture);
    this->wall_Sprite_vertical.setTexture(wall_Texture_vertical);
    this->wall_Sprite_horizontal.setTexture(wall_Texture_horizontal);

    for (int i = 0; i < 3; i++) {
        this->walls.push_back(wall_Sprite_horizontal);
        this->walls.push_back(wall_Sprite_vertical);
    }
}
Wall::~Wall(){}

void Wall::walls2(sf::RenderWindow* window){

//    generator.seed(std::time(0));

//    this->walls[0].setPosition(sf::Vector2f(this->wall_x(this->generator), this->wall_y(this->generator)));
//    this->walls[1].setPosition(sf::Vector2f(this->wall_x(this->generator), this->wall_y(this->generator)));

    this->walls[0].setPosition(sf::Vector2f(100, 100 ));
    this->walls[1].setPosition(sf::Vector2f(200, 500 ));
    this->walls[2].setPosition(sf::Vector2f(600, 300 ));
    this->walls[3].setPosition(sf::Vector2f(400, 400 ));
    this->walls[4].setPosition(sf::Vector2f(500, 500 ));
    this->walls[5].setPosition(sf::Vector2f(800, 700 ));

    for (int i = 0; i < 6; i++) {
        window->draw(this->walls[i]);
    }
}

