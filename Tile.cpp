//
// Created by xcao2 on 11/29/2023.
//

#include "Tile.h"
#include "Toolbox.h"


Tile::Tile(sf::Vector2f _position) : position(_position){
    sprite.setPosition(position.x, position.y);
    setState(HIDDEN);
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
    if(currentState==EXPLODED){
        toolbox.debug=true;
        toolbox.gameState->toggleMine();
        sprite.setTexture(*toolbox.bombed);
        toolbox.gameState->setPlayStatus(GameState::LOSS);
        toolbox.newGameButton->setSprite(toolbox.lose_sprite);
    }
    else if(currentState==HIDDEN){
        sprite.setTexture(*toolbox.hidden);
        if(toolbox.debug && mine==9){
            sprite.setTexture(*toolbox.debug_bomb);
        }
    }
    else if(mine==0){
        sprite.setTexture(*toolbox.revealed);
        toolbox.gameState->tilesLeft--;
        if(toolbox.gameState->tilesLeft==toolbox.gameState->getMineCount()){
            toolbox.gameState->setPlayStatus(GameState::WIN);
            toolbox.newGameButton->setSprite(toolbox.win_sprite);
        }
    }
    else{
        sprite.setTexture(*toolbox.numbers[mine-1]);
        toolbox.gameState->tilesLeft--;
        if(toolbox.gameState->tilesLeft==toolbox.gameState->getMineCount()){
            toolbox.gameState->setPlayStatus(GameState::WIN);
            toolbox.newGameButton->setSprite(toolbox.win_sprite);
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
        else if(mine==0){
            setState(REVEALED);
            revealNeighbors();
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
        sprite.setTexture(*toolbox.flagged);
        toolbox.gameState->incrementFlag(true);
    } else if (currentState == FLAGGED) {
        currentState = HIDDEN;
        sprite.setTexture(*toolbox.hidden);
        toolbox.gameState->incrementFlag(false);
    }
}

void Tile::draw() const {
    Toolbox& toolbox=Toolbox::getInstance();
    toolbox.window.draw(sprite);
}

void Tile::revealNeighbors() {
    for(Tile* neighbor : neighbors){
        if(neighbor && neighbor->getState()==HIDDEN){
            if(neighbor->mine==9){
                neighbor->setState(EXPLODED);
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