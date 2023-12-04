//
// Created by xcao2 on 11/29/2023.
//

#ifndef COP_PROJECT4_MINESWEEPER_H
#define COP_PROJECT4_MINESWEEPER_H

#include "GameState.h"

#include "Toolbox.h"
#include <iostream>

Toolbox& toolbox = Toolbox::getInstance();

bool debugMode=false;

sf::Sprite dig1;
sf::Sprite dig2;
sf::Sprite dig3;

void drawDigits(){
    int displayNum=toolbox.gameState->getMineCount()-toolbox.gameState->getFlagCount();
    sf::IntRect textureRect1;
    if(displayNum<0){
        textureRect1=sf::IntRect(210, 0, 21, 32);
        displayNum=-(displayNum%100);
    }
    else{
        textureRect1=sf::IntRect((displayNum/100)*21, 0, 21, 32);
        displayNum=displayNum%100;
    }
    dig1.setTextureRect(textureRect1);

    sf::IntRect textureRect2((displayNum/10)*21, 0, 21, 32);
    dig2.setTextureRect(textureRect2);
    displayNum=displayNum%10;

    sf::IntRect textureRect3((displayNum)*21, 0, 21, 32);
    dig3.setTextureRect(textureRect3);

    toolbox.window.draw(dig1);
    toolbox.window.draw(dig2);
    toolbox.window.draw(dig3);
}

void render() {
    toolbox.window.draw(*toolbox.debugButton->getSprite());
    toolbox.window.draw(*toolbox.newGameButton->getSprite());
    toolbox.window.draw(*toolbox.testButton1->getSprite());
    toolbox.window.draw(*toolbox.testButton2->getSprite());

    toolbox.gameState->draw();

    drawDigits();
}

void restart() {
    toolbox.gameState= new GameState();

}


void toggleDebugMode() {
    toolbox.debug=!toolbox.debug;
    toolbox.gameState->toggleMine();
}

bool getDebugMode() {
    return toolbox.debug;
}

void handleMouseClick(sf::Event &event){
    sf::Vector2f mouse_pos=toolbox.window.mapPixelToCoords(sf::Mouse::getPosition(toolbox.window));
    bool left= event.mouseButton.button==sf::Mouse::Left;
    if(mouse_pos.y>530.0f){
        if(toolbox.newGameButton->clicked(mouse_pos, left)){
            toolbox.newGameButton->setSprite(toolbox.happy_sprite);
            toolbox.debug=false;
            return;
        }
        else if(toolbox.debugButton->clicked(mouse_pos, left)){
            toggleDebugMode();
            return;
        }
        else if(toolbox.testButton1->clicked(mouse_pos, left)){
            toolbox.newGameButton->setSprite(toolbox.happy_sprite);
            toolbox.debug=false;
            return;
        }
        else if(toolbox.testButton2->clicked(mouse_pos, left)){
            toolbox.newGameButton->setSprite(toolbox.happy_sprite);
            toolbox.debug=false;
            return;
        }
    }
    else{
        toolbox.gameState->onClick(mouse_pos, left);
    }
}

int launch() {

    restart();

    dig1.setTexture(*toolbox.digits);
    dig1.setPosition(100.0f, 530.0f);

    dig2.setTexture(*toolbox.digits);
    dig2.setPosition(121.0f, 530.0f);

    dig3.setTexture(*toolbox.digits);
    dig3.setPosition(142.0f, 530.0f);

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
