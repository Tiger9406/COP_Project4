//
// Created by xcao2 on 11/29/2023.
//

#include "minesweeper.h"
#include <iostream>

namespace {
    bool debugMode = false;
    GameState gameState;
}

int launch() {
    restart();
    gameLoop();
    return 0;
}

void restart() {
    gameState = GameState(sf::Vector2i(25, 16), 50);
    debugMode = false;
    render(); // Render everything
}

void render() {
    // draw all elements
}

void toggleDebugMode() {
    debugMode = !debugMode;
}

bool getDebugMode() {
    return debugMode;
}

int gameLoop() {
    // game loop
    return 0;
}
int main(){ return launch(); }