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

bool debugMode=false;


void render() {
    toolbox.window.draw(*toolbox.debugButton->getSprite());
    toolbox.window.draw(*toolbox.newGameButton->getSprite());
    toolbox.window.draw(*toolbox.testButton1->getSprite());
    toolbox.window.draw(*toolbox.testButton2->getSprite());

    toolbox.gameState->draw();
}

void restart() {
    toolbox.gameState= new GameState();
}


void toggleDebugMode() {
    debugMode = !debugMode;
}

bool getDebugMode() {
    return debugMode;
}

void handleMouseClick(sf::Event &event){
    sf::Vector2f mouse_pos=toolbox.window.mapPixelToCoords(sf::Mouse::getPosition(toolbox.window));
    bool left= event.mouseButton.button==sf::Mouse::Left;
    if(mouse_pos.y>530.0f){
        if(toolbox.newGameButton->clicked(mouse_pos, left)){
            return;
        }
        else if(toolbox.debugButton->clicked(mouse_pos, left)){
            return;
        }
        else if(toolbox.testButton1->clicked(mouse_pos, left)){
            return;
        }
        else if(toolbox.testButton2->clicked(mouse_pos, left)){
            return;
        }
    }
    else{
        toolbox.gameState->onClick(mouse_pos, left);
    }
}

int launch() {

    restart();

    while(toolbox.window.isOpen()){
        sf::Event event;
        while(toolbox.window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                toolbox.window.close();
            }
            if(event.type==sf::Event::MouseButtonPressed){
                handleMouseClick(event);
            }
        }
        toolbox.window.clear();
        render();
        toolbox.window.display();
    }
    return 0;
}


int main(){ return launch(); }


#endif //COP_PROJECT4_MINESWEEPER_H
