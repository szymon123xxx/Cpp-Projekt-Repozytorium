#include "game.h"
#include "menu.h"

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
// musza byc 2 eventy bo inaczej dla menu i gierki robia sie jednoczesnie
void Game::SFMLeventsMenu(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menu->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menu->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu->GetPressedItem()){
                            case 0:
                                this->scoreAndGraph->score_int = 0;
                                menuLevelRun();
                                break;
                            case 1:
                                std::cout << "muzyka" << std::endl ;
                                break;
                            case 2:
                                this->window->close();
                        }
                }
        }
        if (this->event.type == sf::Event::Closed)
            this->window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->window->close();
        }
    }
}

void Game::SFMLeventsLevelMenu(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menuLevels->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menuLevels->MoveDown();
                        break;

                    case sf::Keyboard::Escape:
                        menuRun();

                    case sf::Keyboard::Return:
                        switch (menuLevels->GetPressedItem()){
                            case 0:
                                run();
                                break;
                            case 1:
                                run();
                                break;
                            case 2:
                                run();
                                break;
                            case 3:
                                menuRun();
                        }

                }
        }
        if (this->event.type == sf::Event::Closed)
            this->window->close();
// Czemu to nei działa ? ? ?
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
//            menuRun();
//        }
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

void Game::IMenu() {
    this->menu = new Menu(this->window->getSize().x, this->window->getSize().y);

}

void Game::IscoreAndGraph(){
    this->scoreAndGraph = new ScoreAndGraph();
}

void Game::IMenuLevels() {
    this->menuLevels = new MenuLevels(this->window->getSize().x, this->window->getSize().y);
}

void Game::playerMove(){
    // generowanie zakresu dla obiektu
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> dice(0, 1050);
    std::uniform_int_distribution<uint32_t> dice2(0, 850);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        menuRun();
    }

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
    if (this->enemy->Enemy_Sprite.getGlobalBounds().intersects(this->player->_Sprite.getGlobalBounds()) ) {
        this->enemy->Enemy_Sprite.setPosition(dice(generator),dice2(generator)); // kolizja postac - cel
        this->scoreAndGraph->score_int += 1; // zwiekszanie punktow
    }}

    for (unsigned i = 0; i < this->wall->walls.size(); i++ ){
        if (this->enemy->Enemy_Sprite.getGlobalBounds().intersects(this->wall->walls[i].getGlobalBounds()) ) {
            this->enemy->Enemy_Sprite.setPosition(dice(generator),dice2(generator)); // kolizja sciany - cel
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

    if (this->menuLevels->selectedItemIndex == 0)
        this->wall->walls2(this->window);

    else if (this->menuLevels->selectedItemIndex == 1)
        this->wall->LevelMedium(this->window);

    else if (this->menuLevels->selectedItemIndex == 2)
        this->wall->LevelHard(this->window);

    this->window->draw(this->player->_Sprite);
    this->window->draw(this->enemy->Enemy_Sprite);

    std::string score_text = "Score: " + std::to_string(this->scoreAndGraph->score_int);
    this->scoreAndGraph->score.setString(score_text);
    this->window->draw(this->scoreAndGraph->score);

    this->window->display();
}

void Game::renderMenu() {
    this->window->clear();
    this->window->draw(this->menu->Menu_Sprite);
    this->menu->menu_draw(this->window);
    this->window->display();
}

void Game::renderLevelMenu() {
    this->window->clear();
    this->window->draw(this->menuLevels->Menu_Sprite);
    this->menuLevels->menu_level_draw(this->window);
    this->window->display();
}

void Game::menuRun(){
    while ( this->window->isOpen())
    {
        this->SFMLeventsMenu();
        this->renderMenu();
    }
}

void Game::menuLevelRun(){
    while ( this->window->isOpen())
    {
        this->SFMLeventsLevelMenu();
        this->renderLevelMenu();
    }
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
    this->IMenu();
    this->IscoreAndGraph();
    this->IMenuLevels();
}

Game::~Game(){
    delete this->window;

}
