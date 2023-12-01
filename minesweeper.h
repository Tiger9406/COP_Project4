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

    toolbox.debugButton->draw(toolbox.window);
    toolbox.newGameButton->draw(toolbox.window);
    toolbox.testButton1->draw(toolbox.window);
    toolbox.testButton2->draw(toolbox.window);
}

int launch() {
    sf::Texture debug_texture;
    debug_texture.loadFromFile("images/debug.png");
    sf::Sprite* debug_sprite=new sf::Sprite(debug_texture);
    toolbox.debugButton->setSprite(debug_sprite);

    sf::Texture new_game_texture;
    new_game_texture.loadFromFile("images/face_happy.png");
    sf::Sprite* new_game_sprite=new sf::Sprite(new_game_texture);
    toolbox.newGameButton->setSprite(new_game_sprite);

    sf::Texture test1_texture;
    test1_texture.loadFromFile("images/test_1.png");
    sf::Sprite* test1_sprite=new sf::Sprite(test1_texture);
    toolbox.testButton1->setSprite(test1_sprite);

    sf::Texture test2_texture;
    test2_texture.loadFromFile("images/test_2.png");
    sf::Sprite* test2_sprite=new sf::Sprite(test2_texture);
    toolbox.testButton2->setSprite(test2_sprite);

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
