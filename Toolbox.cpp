//
// Created by xcao2 on 11/27/2023.
//

#include "Toolbox.h"

Toolbox& Toolbox::getInstance() {
        static Toolbox instance;
        return instance;
}

Toolbox::Toolbox(){
        gameState = nullptr;

        debugButton = new Button(sf::Vector2f(10.0f, 10.0f), [](){std::cout<<"hello";});
        sf::Texture debug_texture;
        debug_texture.loadFromFile("images/debug.png");
        sf::Sprite* debug_sprite=new sf::Sprite(debug_texture);
        debugButton->setSprite(debug_sprite);


        newGameButton = new Button(sf::Vector2f(80.0f, 10.0f), [](){std::cout<<"newGame";});
        sf::Texture new_game_texture;
        new_game_texture.loadFromFile("images/face_happy.png");
//        sf::Sprite new_game_sprite;
//        new_game_sprite.setTexture(new_game_texture);
        sf::Sprite* new_game_sprite=new sf::Sprite(new_game_texture);
        newGameButton->setSprite(new_game_sprite);

        testButton1 = new Button(sf::Vector2f(10.0f, 60.0f), [](){std::cout<<"test1";});
        sf::Texture test1_texture;
        test1_texture.loadFromFile("images/test_1.png");
        sf::Sprite test1_sprite;
        test1_sprite.setTexture(test1_texture);
        testButton1->setSprite(&test1_sprite);

        testButton2 = new Button(sf::Vector2f(80.0f, 60.0f), [](){std::cout<<"test2";});
        sf::Texture test2_texture;
        test2_texture.loadFromFile("images/test_2.png");
        sf::Sprite test2_sprite;
        test2_sprite.setTexture(test2_texture);
        testButton2->setSprite(&test2_sprite);

        // Initialize the SFML window
        window.create(sf::VideoMode(800, 600), "SFML Sprite Example");
}

Toolbox::~Toolbox() {
    delete gameState;
    delete debugButton;
    delete newGameButton;
    delete testButton1;
    delete testButton2;
}