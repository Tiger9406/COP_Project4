//
// Created by xcao2 on 11/29/2023.
//

#include "Tile.h"
#include "Toolbox.h"
#include "Bomb.h"


Tile::Tile(sf::Vector2f _position) : position(_position){
    Toolbox &toolbox = Toolbox::getInstance();
    sprite.setPosition(position.x, position.y);
    currentState=HIDDEN;
    sprite.setTexture(*toolbox.hidden);
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
    currentState = _state;
    if(mine==0){
        sprite.setTexture(*toolbox.revealed);
        revealNeighbors();
    }
    else{
        sprite.setTexture(*toolbox.numbers[mine-1]);
    }

}


void Tile::setNeighbors(std::array<Tile*, 8> _neighbors) {
    for(int i = 0; i < 8; i++){
        neighbors[i]=_neighbors[i];
    }
    for(Tile* t : neighbors){
        Bomb *derived=dynamic_cast<Bomb*>(t);
        if(derived != nullptr) {
            mine++;
        }
    }
}

void Tile::onClickLeft() {
    if (currentState == HIDDEN) {
        setState(REVEALED);
    }
    else if(currentState==REVEALED){
        revealNeighbors();
    }
}

void Tile::onClickRight() {
    Toolbox& toolbox=Toolbox::getInstance();
    if (currentState == HIDDEN) {
        currentState = FLAGGED;
        sprite.setTexture(*toolbox.flagged);
    } else if (currentState == FLAGGED) {
        currentState = HIDDEN;
        sprite.setTexture(*toolbox.hidden);
    }
}

void Tile::draw() const {
    Toolbox& toolbox=Toolbox::getInstance();
    toolbox.window.draw(sprite);
}

void Tile::revealNeighbors() {
    for(Tile* neighbor : neighbors){
        if(neighbor && neighbor->getState()==HIDDEN){
            Bomb *derived=dynamic_cast<Bomb*>(neighbor);
            if(derived != nullptr && derived->getState()!=FLAGGED){
                derived->setState(EXPLODED);
            }
            else{
                if(neighbor->getState()!=REVEALED){
                    neighbor->setState(REVEALED);
                    if(neighbor->mine==0){
                        neighbor->revealNeighbors();
                    }
                }
            }
        }
    }
}
