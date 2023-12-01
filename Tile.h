//
// Created by xcao2 on 11/29/2023.
//

#ifndef COP_PROJECT4_TILE_H
#define COP_PROJECT4_TILE_H

#include <SFML/Graphics.hpp>
#include <array>


class Tile {
public:
    enum State{
        REVEALED,
        HIDDEN,
        FLAGGED,
        EXPLODED
    };
    Tile(sf::Vector2f position);
    sf::Vector2f getLocation();
    State getState();
    std::array<Tile*, 8>& getNeighbors();
    void setState(State _state);
    void setNeighbors(std::array<Tile*, 8> _neighbors);
    void onClickLeft();
    void onClickRight();
    void draw();
    sf::Texture state;
    sf::Sprite sprite;
protected:
    void revealNeighbors();
private:
    sf::Vector2f position;
    State currentState;
    std::array<Tile*, 8> neighbors;
};


#endif //COP_PROJECT4_TILE_H
