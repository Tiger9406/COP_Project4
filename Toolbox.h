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
    static Toolbox& getInstance(){
        static Toolbox instance;
        return instance;
    }
private:
    Toolbox(){
//        gameState = nullptr;
//        debugButton = nullptr;
//        newGameButton = nullptr;
//        testButton1 = nullptr;
//        testButton2 = nullptr;

        // Initialize the SFML window
        window.create(sf::VideoMode(800, 600), "SFML Window");
    };
};


#endif //COP_PROJECT4_TOOLBOX_H
