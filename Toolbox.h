//
// Created by xcao2 on 11/27/2023.
//

#ifndef COP_PROJECT4_TOOLBOX_H
#define COP_PROJECT4_TOOLBOX_H

#include <SFML/Graphics.hpp>


class Toolbox {
public:
    sf::RenderWindow window;
//    GameState* gameState;
//
//    Button* debugButton;
//    Button* newGameButton;
//    Button* testButton1;
//    Button* testButton2;
    static Toolbox& getInstance();
private:
    Toolbox(const Toolbox&) = delete;
    Toolbox& operator=(const Toolbox&) = delete;
    Toolbox();
};


#endif //COP_PROJECT4_TOOLBOX_H
