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

        newGameButton = new Button(sf::Vector2f(100.0f, 10.0f), [](){std::cout<<"newGame";});


        testButton1 = new Button(sf::Vector2f(10.0f, 100.0f), [](){std::cout<<"test1";});


        testButton2 = new Button(sf::Vector2f(100.0f, 100.0f), [](){std::cout<<"test2";});


        // Initialize the SFML window
        window.create(sf::VideoMode(800, 600), "SFML Sprite Example");

//

}

Toolbox::~Toolbox() {
    delete gameState;
    delete debugButton;
    delete newGameButton;
    delete testButton1;
    delete testButton2;
}
