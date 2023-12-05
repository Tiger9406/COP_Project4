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
    virtual State getState();
    std::array<Tile*, 8>& getNeighbors();
    virtual void setState(State _state);
    void setNeighbors(std::array<Tile*, 8> _neighbors);
    virtual void onClickLeft();
    virtual void onClickRight();
    virtual void draw() const;

protected:
    void revealNeighbors();
private:
    sf::Sprite sprite;
    sf::Vector2f position;
    State currentState;
    std::array<Tile*, 8> neighbors;
    int mine=0;
};


#endif //COP_PROJECT4_TILE_H
