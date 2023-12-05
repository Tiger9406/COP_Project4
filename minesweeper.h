//
// Created by xcao2 on 11/29/2023.
//

#ifndef COP_PROJECT4_MINESWEEPER_H
#define COP_PROJECT4_MINESWEEPER_H

#include "GameState.h"

#include "Toolbox.h"
#include <iostream>

//used everywhere
Toolbox& toolbox = Toolbox::getInstance();

//digits display
sf::Sprite dig1;
sf::Sprite dig2;
sf::Sprite dig3;

//function to draw digits
void drawDigits(){
    int displayNum=toolbox.gameState->getMineCount()-toolbox.gameState->getFlagCount();
    sf::IntRect textureRect1;
    //sets rects to display only one digit from 0-9
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

//draws everything
void render() {
    toolbox.window.draw(*toolbox.debugButton->getSprite());
    toolbox.window.draw(*toolbox.newGameButton->getSprite());
    toolbox.window.draw(*toolbox.testButton1->getSprite());
    toolbox.window.draw(*toolbox.testButton2->getSprite());
    toolbox.window.draw(*toolbox.testButton3->getSprite());

    //draws tiles
    int y = 0;
    int x = 0;
    int total=0;
    int revealed=0;
    while(toolbox.gameState->getTile(x,y)!= nullptr){
        while(toolbox.gameState->getTile(x,y)!=nullptr){
            Tile *t=toolbox.gameState->getTile(x,y);
            t->draw();
            x++;
            total++;
            if(t->getState()==Tile::REVEALED){
                revealed++;
            }
        }
        x=0;
        y++;
    }

    //checks every refresh to see if won
    if(total-toolbox.gameState->getMineCount()==revealed){
        toolbox.gameState->setPlayStatus(GameState::WIN);
        toolbox.newGameButton->setSprite(toolbox.win_sprite);
    }
    //calls drawdigits
    drawDigits();
}


//restart game
void restart() {
    toolbox.gameState=new GameState();
}

//toggles debug mode: if tile is a bomb, sets state again to update to new debug texture
void toggleDebugMode() {
    toolbox.debug=!toolbox.debug;
    int y = 0;
    int x = 0;
    while(toolbox.gameState->getTile(x,y)!= nullptr) {
        while (toolbox.gameState->getTile(x, y) != nullptr) {
            Tile *t = toolbox.gameState->getTile(x, y);
            Bomb *derived=dynamic_cast<Bomb*>(t);
            if(derived!= nullptr){
                derived->setState(Tile::HIDDEN);
            }
            x++;
        }
        x=0;
        y++;
    }
}

//handle clicks
void handleMouseClick(sf::Event &event){
    sf::Vector2f mouse_pos=toolbox.window.mapPixelToCoords(sf::Mouse::getPosition(toolbox.window));
    bool left= event.mouseButton.button==sf::Mouse::Left;
    //if clicked below the tiles
    if(mouse_pos.y>530.0f){
        if(toolbox.newGameButton->getSprite()->getGlobalBounds().contains(mouse_pos) && left){
            toolbox.newGameButton->onClick();
            toolbox.newGameButton->setSprite(toolbox.happy_sprite);
            toolbox.debug=false;
            return;
        }
        else if(toolbox.gameState->getPlayStatus()==GameState::PLAYING && toolbox.debugButton->getSprite()->getGlobalBounds().contains(mouse_pos) && left){
            toggleDebugMode();
            return;
        }
        else if(toolbox.testButton1->getSprite()->getGlobalBounds().contains(mouse_pos) && left){
            toolbox.testButton1->onClick();
            toolbox.newGameButton->setSprite(toolbox.happy_sprite);
            toolbox.debug=false;
            return;
        }
        else if(toolbox.testButton2->getSprite()->getGlobalBounds().contains(mouse_pos) && left){
            toolbox.testButton2->onClick();
            toolbox.newGameButton->setSprite(toolbox.happy_sprite);
            toolbox.debug=false;
            return;
        }
        else if(toolbox.testButton3->getSprite()->getGlobalBounds().contains(mouse_pos) && left){
            toolbox.testButton3->onClick();
            toolbox.newGameButton->setSprite(toolbox.happy_sprite);
            toolbox.debug=false;
            return;
        }
    }
    else{ //if clicked a tile
        if(toolbox.gameState->getPlayStatus()==GameState::PLAYING){
            int x=static_cast<int>(mouse_pos.x/32.0f);
            int y=static_cast<int>(mouse_pos.y/32.0f);
            //gets the clicked tile
            Tile* clicked_tile=toolbox.gameState->getTile(x, y);
            if(clicked_tile && left){
                clicked_tile->onClickLeft();
                //checks after every click if lost
                if(toolbox.gameState->getPlayStatus()==GameState::LOSS){
                    toolbox.debug=true;
                    int y2 = 0;
                    int x2 = 0;
                    //if yes, bomb other than the exploded one reveals to bomb on hidden tile
                    while(toolbox.gameState->getTile(x2,y2)!= nullptr) {
                        while (toolbox.gameState->getTile(x2, y2) != nullptr) {
                            Tile *t = toolbox.gameState->getTile(x2, y2);
                            Bomb *derived=dynamic_cast<Bomb*>(t);
                            if(derived!= nullptr && derived->getState()!=Bomb::EXPLODED){
                                derived->setState(Tile::HIDDEN);
                            }
                            x2++;
                        }
                        x2=0;
                        y2++;
                    }
                }
            }
            else if(clicked_tile){ //if right click in tiles
                clicked_tile->onClickRight();
            }
        }
    }
}

int launch() {

    //starts new game
    restart();

    dig1.setTexture(*toolbox.digits);
    dig1.setPosition(100.0f, 530.0f);

    dig2.setTexture(*toolbox.digits);
    dig2.setPosition(121.0f, 530.0f);

    dig3.setTexture(*toolbox.digits);
    dig3.setPosition(142.0f, 530.0f);

    //loads windows
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


int main();


#endif //COP_PROJECT4_MINESWEEPER_H
