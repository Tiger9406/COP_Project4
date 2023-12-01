//
// Created by xcao2 on 11/27/2023.
//

#ifndef COP_PROJECT4_TOOLBOX_H
#define COP_PROJECT4_TOOLBOX_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Button.h"

#include <iostream>


class Toolbox {
public:
    sf::RenderWindow window;
    GameState* gameState;

    Button* debugButton;
    Button* newGameButton;
    Button* testButton1;
    Button* testButton2;

    static Toolbox& getInstance();

    sf::Texture *hidden;
    sf::Texture *revealed;
    sf::Texture *flagged;
    sf::Texture *bombed;

    std::vector<sf::Texture*> numbers;

private:
    Toolbox(const Toolbox&);
    Toolbox& operator=(const Toolbox&);
    Toolbox();
    ~Toolbox();
};


#endif //COP_PROJECT4_TOOLBOX_H
