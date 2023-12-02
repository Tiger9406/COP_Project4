//
// Created by xcao2 on 11/29/2023.
//

#include "Tile.h"
#include "Toolbox.h"


Tile::Tile(sf::Vector2f _position) : position(_position), currentState(HIDDEN){
    sprite.setPosition(position.x, position.y);
}

sf::Vector2f Tile::getLocation() {
    return position;
}

Tile::State Tile::getState() {
    return currentState;
}

std::array<Tile*, 8>& Tile::getNeighbors() {
    return neighbors;
}


void Tile::setState(State _state) {
    Toolbox& toolbox=Toolbox::getInstance();
    // maybe more actions later
    if(currentState==EXPLODED && _state==EXPLODED){
        //debug mode:: explode alr explode again: lose game revealed mine
    }
    else{
        currentState = _state;
        if(mine==0){
            sprite.setTexture(*toolbox.revealed);
        }
        else{
            sprite.setTexture(*toolbox.numbers[mine-1]);
        }
    }
}

void Tile::setNeighbors(std::array<Tile*, 8> _neighbors) {
    neighbors = _neighbors;
}

void Tile::onClickLeft() {
    Toolbox& toolbox=Toolbox::getInstance();
    if (currentState == HIDDEN) {
        if(mine==9){
            setState(EXPLODED);
        }
        else{
            setState(REVEALED);
        }
    }
    else if(currentState==REVEALED){
        revealNeighbors();
    }
}

void Tile::onClickRight() {
    Toolbox& toolbox=Toolbox::getInstance();
    if (currentState == HIDDEN) {
        currentState = FLAGGED;
        toolbox.gameState->incrementFlag(true);
    } else if (currentState == FLAGGED) {
        currentState = HIDDEN;
        toolbox.gameState->incrementFlag(false);
    }
    // lower flag count
}

void Tile::draw() {
    Toolbox& toolbox=Toolbox::getInstance();
    if(currentState==HIDDEN){
        sprite.setTexture(*toolbox.hidden);
    }
    else if(currentState==FLAGGED){
        sprite.setTexture(*toolbox.flagged);
    }
    else if(currentState==EXPLODED){
        sprite.setTexture(*toolbox.bombed);
    }
    toolbox.window.draw(sprite);
}

void Tile::revealNeighbors() {
    for(Tile* neighbor : neighbors){
        if(neighbor && neighbor->getState()==HIDDEN){
            if(neighbor->mine==9){
                neighbor->setState(EXPLODED);
            }
            else{
                neighbor->setState(REVEALED);
            }
        }
    }
}