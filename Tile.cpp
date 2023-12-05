//
// Created by xcao2 on 11/29/2023.
//

#include "Tile.h"
#include "Toolbox.h"
#include "Bomb.h"


Tile::Tile(sf::Vector2f _position) : position(_position){
    //default constructor
    Toolbox &toolbox = Toolbox::getInstance();
    sprite.setPosition(position.x, position.y);
    currentState=HIDDEN;
    sprite.setTexture(*toolbox.hidden);
}

//getters
sf::Vector2f Tile::getLocation() {
    return position;
}

Tile::State Tile::getState() {
    return currentState;
}

std::array<Tile*, 8>& Tile::getNeighbors() {
    return neighbors;
}

//used to set normal tile state and texture (not including flags); recursion: setState->revealNeighbors->setState
//given when clicked on empty tile (no bomb neighbors), sets state of surrounding tiles
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

//sets neighbors given neighbor: looping seems to work best as direct copy did not function
void Tile::setNeighbors(std::array<Tile*, 8> _neighbors) {
    for(int i = 0; i < 8; i++){
        neighbors[i]=_neighbors[i];
    }
    //if it's a mine, mine count ++
    for(Tile* t : neighbors){
        Bomb *derived=dynamic_cast<Bomb*>(t);
        if(derived != nullptr) {
            mine++;
        }
    }
}

//normal tile: when clicked Hidden, shows;
//if already revealed, shows neighbors (how certain editions of minesweeper does it)
void Tile::onClickLeft() {
    if (currentState == HIDDEN) {
        setState(REVEALED);
    }
    else if(currentState==REVEALED){
        revealNeighbors();
    }
}

//when clicked right: toggle between flagged and hidden
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

//draws on toolbox window
void Tile::draw() const {
    Toolbox& toolbox=Toolbox::getInstance();
    toolbox.window.draw(sprite);
}


//recursively reveals tile's neighbor and neighbor's neighbors (only if neighbor empty)
void Tile::revealNeighbors() {
    for(Tile* neighbor : neighbors){
        if(neighbor && neighbor->getState()==HIDDEN){
            //if bomb, unfortunately player loses; not careful enough
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
