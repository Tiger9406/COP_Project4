//
// Created by xcao2 on 12/4/2023.
//

#include "Bomb.h"
#include "Toolbox.h"


Bomb::Bomb(sf::Vector2f _position):Tile(_position){
    Toolbox &toolbox = Toolbox::getInstance();
    sprite.setTexture(*toolbox.hidden);
    sprite.setPosition(_position);
    currentState=HIDDEN;
}

void Bomb::setState(Tile::State _state) {
    Toolbox& toolbox=Toolbox::getInstance();
    currentState = _state;
    if(currentState==EXPLODED){
        toolbox.gameState->setPlayStatus(GameState::LOSS);
        sprite.setTexture(*toolbox.bombed);
        toolbox.newGameButton->setSprite(toolbox.lose_sprite);
    }
    else if(currentState==HIDDEN){
        sprite.setTexture(*toolbox.hidden);
        if(toolbox.debug){
            sprite.setTexture(*toolbox.debug_bomb);
        }
    }
}

Bomb::State Bomb::getState(){
    return currentState;
}

void Bomb::draw() const{
    Toolbox& toolbox=Toolbox::getInstance();
    toolbox.window.draw(this->sprite);
}

void Bomb::onClickLeft() {
    Toolbox &toolbox = Toolbox::getInstance();
    if(currentState!=FLAGGED){
        setState(EXPLODED);

    }
}

void Bomb::onClickRight() {
    Toolbox& toolbox=Toolbox::getInstance();
    if (currentState == HIDDEN) {
        currentState = FLAGGED;
        sprite.setTexture(*toolbox.flagged);
    } else if (currentState == FLAGGED) {
        if(toolbox.debug){
            sprite.setTexture(*toolbox.debug_bomb);
        }
        else{
            sprite.setTexture(*toolbox.hidden);
        }
        currentState = HIDDEN;
    }
}