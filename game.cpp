//
// Created by szymon on 31.10.2020.
//

#include "game.h"

void Game::initWindow() {
    int width_window = 800;
    int height_window = 800;

    sf::VideoMode window_mode(width_window, height_window);

    int frame = 60;

    this->window = new sf::RenderWindow(window_mode, "OP_GAME");
    this->window->setFramerateLimit(frame);
}

void Game::updateSFMLevents(){
    while ( this->window->pollEvent(this->event))
    {
        if ( this->event.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::update(){
    this->updateSFMLevents();
}

void Game::render(){
    this->window->clear();
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
}

Game::~Game(){
    delete this->window;
}



