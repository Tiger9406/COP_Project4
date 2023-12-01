//
// Created by xcao2 on 11/29/2023.
//

#include "Tile.h"
#include "Toolbox.h"

Tile::Tile(sf::Vector2f _position) : position(_position), currentState(HIDDEN) {

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
    currentState = _state;
    // maybe more actions later
}

void Tile::setNeighbors(std::array<Tile*, 8> _neighbors) {
    neighbors = _neighbors;
}

void Tile::onClickLeft() {
    if (currentState == HIDDEN) {
        setState(REVEALED);
        draw();
    }
    else if(currentState==REVEALED){
        revealNeighbors();
    }
}

void Tile::onClickRight() {
    if (currentState == HIDDEN) {
        currentState = FLAGGED;
    } else if (currentState == FLAGGED) {
        currentState = HIDDEN;
    }
    // lower flag count
}

void Tile::draw() {
    Toolbox& toolbox=Toolbox::getInstance();
    if(currentState==HIDDEN){
        state.loadFromFile("images/tile_hidden.png");
        sprite.setTexture(state);
        toolbox.window.draw(sprite);
    }
}

void Tile::revealNeighbors() {
    for(Tile* neighbor : neighbors){
        if(neighbor && neighbor->getState()==HIDDEN){
            neighbor->setState(REVEALED);
            neighbor->draw();
        }
    }
}