//
// Created by xcao2 on 11/29/2023.
//

#ifndef COP_PROJECT4_GAMESTATE_H
#define COP_PROJECT4_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "Tile.h"


class GameState {
public:
    enum PlayStatus { WIN, LOSS, PLAYING };

    GameState(sf::Vector2i _dimensions = sf::Vector2i(25, 16), int _numberOfMines = 50);
    GameState(const char* filepath);

    int getFlagCount();
    int getMineCount();
    Tile* getTile(int x, int y);
    PlayStatus getPlayStatus();
    void setPlayStatus(PlayStatus _status);

private:
    sf::Vector2i dimensions;
    int numberOfMines;
    int flagCount;
    PlayStatus playStatus;
    std::vector<Tile> tiles;
};


#endif //COP_PROJECT4_GAMESTATE_H
