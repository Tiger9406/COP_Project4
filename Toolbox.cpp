//
// Created by xcao2 on 11/27/2023.
//

#include "Toolbox.h"

Toolbox& Toolbox::getInstance() {
        static Toolbox instance;
        return instance;
}

Toolbox::Toolbox(){
        gameState = new GameState();
        debugButton = new Button(sf::Vector2f(10.0f, 10.0f), [](){std::cout<<"hello";});
        newGameButton = nullptr;
        testButton1 = nullptr;
        testButton2 = nullptr;

        // Initialize the SFML window
        window.create(sf::VideoMode(800, 600), "“P4 – Minesweeper, Tiger Cao");
}