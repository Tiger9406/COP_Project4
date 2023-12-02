//
// Created by xcao2 on 11/29/2023.
//

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Toolbox.h"
#include <iostream>

GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines) : dimensions(_dimensions), numberOfMines(_numberOfMines), flagCount(0), playStatus(PLAYING) {
    for(int i = 0; i < dimensions.y; i++){
        for(int j = 0; j < dimensions.x; j++){
            sf::Vector2f vec(static_cast<float>(j*32), static_cast<float>(i*32));
            Tile* tile= new Tile(vec);
            tiles.push_back(*tile);
            if(i==1){
                tile->mine=true;
            }
        }
    }
}

GameState::GameState(const char* filepath) : playStatus(PLAYING) {
    // given board
}

int GameState::getFlagCount() {
    return flagCount;
}
void GameState::incrementFlag(bool up){
    if(up){
        flagCount++;
    }
    else{
        flagCount--;
    }
}

int GameState::getMineCount() {
    return numberOfMines;
}

Tile* GameState::getTile(int x, int y) {
    // if exists
    if (x >= 0 && x < dimensions.x && y >= 0 && y < dimensions.y) {
        // calculate index 2D->1D
        int index = x + y * dimensions.x;
        return &tiles[index];
    }
    return nullptr;
}

GameState::PlayStatus GameState::getPlayStatus() {
    return playStatus;
}

void GameState::setPlayStatus(PlayStatus _status) {
    playStatus = _status;
}

void GameState::draw(){
    for(Tile &t : tiles){
        t.draw();
    }
}

void GameState::onClick(sf::Vector2f& click_pos, bool left){
    int x=static_cast<int>(click_pos.x/32.0f);
    int y=static_cast<int>(click_pos.y/32.0f);
    Tile* clicked_tile=getTile(x, y);
    if(clicked_tile && left){
        clicked_tile->onClickLeft();
    }
    else if(clicked_tile && !left){
        clicked_tile->onClickRight();
    }
}