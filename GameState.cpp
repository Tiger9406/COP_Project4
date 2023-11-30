//
// Created by xcao2 on 11/29/2023.
//

#include "GameState.h"
#include <SFML/Graphics.hpp>

GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines) : dimensions(_dimensions), numberOfMines(_numberOfMines), flagCount(0), playStatus(PLAYING) {
    // random board
}

GameState::GameState(const char* filepath) : playStatus(PLAYING) {
    // given board
}

int GameState::getFlagCount() {
    return flagCount;
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