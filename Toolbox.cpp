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

        debugButton = new Button(sf::Vector2f(590.0f, 530.0f), [](){std::cout<<"hello";});

        newGameButton = new Button(sf::Vector2f(400.0f, 530.0f), [](){std::cout<<"newGame";});

        testButton1 = new Button(sf::Vector2f(660.0f, 530.0f), [](){std::cout<<"test1";});

        testButton2 = new Button(sf::Vector2f(730.0f, 530.0f), [](){std::cout<<"test2";});

        // Initialize the SFML window
        window.create(sf::VideoMode(800, 600), "SFML Sprite Example");

//

}
