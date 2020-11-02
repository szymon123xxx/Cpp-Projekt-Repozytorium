#include "game.h"

void Game::initWindow() {
    int width_window = 1400;
    int height_window = 800;

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

void Game::playerMove(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->moving({0.f, -5.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->moving({0.f, 5.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->moving({-5.f, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->moving({5.f, 0.f});
}

void Game::update(){
    this->SFMLevents();
    this->playerMove();
}

void Game::render(){
    this->window->clear();
    this->window->draw(this->player->_Sprite);
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
}

Game::~Game(){
    delete this->window;
}
