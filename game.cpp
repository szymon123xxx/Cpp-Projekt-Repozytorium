#include "game.h"

void Game::initWindow() {
    int width_window = 1100;
    int height_window = 900;

    sf::VideoMode window_mode(width_window, height_window);

    int frame = 60;

    this->window = new sf::RenderWindow(window_mode, "OP_GAME");
    this->window->setFramerateLimit(frame);
}

void Game::SFMLevents(){
    while ( this->window->pollEvent(this->event))
    {
        if ( this->event.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::IPlayer(){
    this->player = new Player();
}

void Game::IWall(){
    this->wall = new Wall();
}

void Game::IEnemy(){
    this->enemy = new Enemy();
}
void Game::playerMove(){
    // generowanie zakresu dla obiektu
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> dice(0, 1050);
    std::uniform_int_distribution<uint32_t> dice2(0, 850);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if (this->player->_Position.y <= 0) {
            this->player->_Position.y += 900;
        }
        else {
            this->player->moving({0.f, -5.f});
        }}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (this->player->_Position.y >= 900) {
            this->player->_Position.y -= 900;
        }
        else {
            this->player->moving({0.f, 5.f});
        }}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (this->player->_Position.x <= 0) {
            this->player->_Position.x += 1100;
        }
        else {
            this->player->moving({-5.f, 0.f});
        }}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (this->player->_Position.x >= 1050) {
            this->player->_Position.x -= 1100;
        }
        else {
            this->player->moving({5.f, 0.f});
        }}

    for (unsigned i = 0; i < this->wall->walls.size(); i++ ){
    if (this->enemy->Enemy_Sprite.getGlobalBounds().intersects(this->player->_Sprite.getGlobalBounds()) || this->enemy->Enemy_Sprite.getGlobalBounds().intersects(this->wall->walls[i].getGlobalBounds()) ) {
        this->enemy->Enemy_Sprite.setPosition(dice(generator),dice2(generator)); // kolizja postac - cel / sciany - cel
    }}

//    for (unsigned i = 0; i < this->wall->walls.size(); i++ ){
//        if (this->enemy->Enemy_Sprite.getGlobalBounds().intersects(this->wall->walls[i].getGlobalBounds()))
//            this->enemy->Enemy_Sprite.setPosition(dice(generator),dice2(generator));
//    }


}

void Game::update(){
    this->SFMLevents();
    this->playerMove();
}

void Game::render(){
    this->window->clear();
    this->window->draw(this->wall->back_Sprite);
    this->wall->walls2(this->window);
    this->window->draw(this->player->_Sprite);
    this->window->draw(this->enemy->Enemy_Sprite);
    //code
    this->window->display();
}


void Game::run(){
    while ( this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

Game::Game(){
    this->initWindow();
    this->IPlayer();
    this->IEnemy();
    this->IWall();
}

Game::~Game(){
    delete this->window;
}
