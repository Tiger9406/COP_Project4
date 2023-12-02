//
// Created by xcao2 on 11/27/2023.
//

#include "Toolbox.h"



Toolbox& Toolbox::getInstance() {
        static Toolbox instance;
        return instance;
}


Toolbox::Toolbox(){

    //make universally accessible buttons

    newGameButton = new Button(sf::Vector2f(400.0f, 530.0f), [this](){this->gameState=new GameState();});
    sf::Texture *new_game_texture=new sf::Texture;
    new_game_texture->loadFromFile("images/face_happy.png");
    sf::Sprite* new_game_sprite=new sf::Sprite(*new_game_texture);
    newGameButton->setSprite(new_game_sprite);

    debugButton = new Button(sf::Vector2f(590.0f, 530.0f), [](){std::cout<<"hello";});
    sf::Texture *debug_texture=new sf::Texture;
    debug_texture->loadFromFile("images/debug.png");
    sf::Sprite *debug_sprite=new sf::Sprite(*debug_texture);
    debugButton->setSprite(debug_sprite);

    testButton1 = new Button(sf::Vector2f(660.0f, 530.0f), [this](){this->gameState=new GameState();});
    sf::Texture *test1_texture= new sf::Texture;
    test1_texture->loadFromFile("images/test_1.png");
    sf::Sprite* test1_sprite=new sf::Sprite(*test1_texture);
    testButton1->setSprite(test1_sprite);

    testButton2 = new Button(sf::Vector2f(730.0f, 530.0f), [this](){this->gameState=new GameState();});
    sf::Texture *test2_texture=new sf::Texture;
    test2_texture->loadFromFile("images/test_2.png");
    sf::Sprite* test2_sprite=new sf::Sprite(*test2_texture);
    testButton2->setSprite(test2_sprite);

    // Initialize the SFML window
    window.create(sf::VideoMode(800, 600), "SFML Sprite Example");

    gameState = nullptr;

    //make universally accessible textures
    hidden= new sf::Texture;
    hidden->loadFromFile("images/tile_hidden.png");
    revealed= new sf::Texture;
    revealed->loadFromFile("images/tile_revealed.png");

    sf::RenderTexture flagRender;
    flagRender.create(32,32);
    sf::Texture flag;
    flag.loadFromFile("images/flag.png");
    flagRender.draw(sf::Sprite(*hidden));
    flagRender.draw(sf::Sprite(flag));
    flagRender.display();
    flagged= new sf::Texture(flagRender.getTexture());

    sf::RenderTexture bombRender;
    bombRender.create(32,32);
    sf::Texture bomb;
    bomb.loadFromFile("images/mine.png");
    bombRender.draw(sf::Sprite(*revealed));
    bombRender.draw(sf::Sprite(bomb));
    bombRender.display();
    bombed=new sf::Texture(bombRender.getTexture());

    for(int i = 1; i < 9; i++){
        sf::RenderTexture numRender;
        numRender.create(32,32);
        sf::Texture num;
        num.loadFromFile("images/number_"+std::to_string(i)+".png");
        numRender.draw(sf::Sprite(*revealed));
        numRender.draw(sf::Sprite(num));
        numRender.display();
        sf::Texture *push_num=new sf::Texture(bombRender.getTexture());
        numbers.push_back(push_num);
    }

}



Toolbox::~Toolbox() {

}
