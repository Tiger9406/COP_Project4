//
// Created by xcao2 on 11/29/2023.
//

#ifndef COP_PROJECT4_MINESWEEPER_H
#define COP_PROJECT4_MINESWEEPER_H

#include "GameState.h"
#include "Button.h"
#include "Toolbox.h"
#include <iostream>

Toolbox& toolbox = Toolbox::getInstance();

void render() {
    toolbox.window.draw(*(toolbox.debugButton->getSprite()));

    sf::Texture test_texture;
    test_texture.loadFromFile("images/face_win.png");
    sf::Sprite* test=new sf::Sprite(test_texture);
    toolbox.window.draw(*test);
}

int launch() {
    while(toolbox.window.isOpen()){
        sf::Event event;
        while(toolbox.window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                toolbox.window.close();
            }
            //other events
        }
        toolbox.window.clear();
        render();
        toolbox.window.display();
    }
    return 0;
}



void restart() {
    toolbox.gameState= new GameState(sf::Vector2i(25, 16), 50);
    render(); // Render everything
}



//void toggleDebugMode() {
//    debugMode = !debugMode;
//}
//
//bool getDebugMode() {
//    return debugMode;
//}

//int gameLoop() {
//    while (true) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                return 0;
//            }
//        }
//    }
//    return 0;
//}

int main(){ return launch(); }


#endif //COP_PROJECT4_MINESWEEPER_H
