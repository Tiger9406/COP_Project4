//
// Created by xcao2 on 11/29/2023.
//

#ifndef COP_PROJECT4_TILE_H
#define COP_PROJECT4_TILE_H

#include <SFML/Graphics.hpp>
#include <array>


class Tile {
public:
    enum State{ //four states of a tile; unused exploded in thie class as separate Bomb Class is defined
        REVEALED,
        HIDDEN,
        FLAGGED,
        EXPLODED
    };
    Tile(sf::Vector2f position); //constructor given position
    sf::Vector2f getLocation(); //gets location
    virtual State getState(); //gets state: overriden in Bomb
    std::array<Tile*, 8>& getNeighbors(); //gets Tile's neighbors; never used because calculation done within class
    virtual void setState(State _state); //sets current state and texture of sprite
    void setNeighbors(std::array<Tile*, 8> _neighbors); //sets neighbors given array of Tile pointers
    virtual void onClickLeft(); //called when clicked left
    virtual void onClickRight(); //called when clicked right
    virtual void draw() const; //draws on toolbox window

protected:
    void revealNeighbors(); //reveal Tile neighbors
private:
    sf::Sprite sprite; //sprite
    sf::Vector2f position; //position of tile
    State currentState; //current state of tile
    std::array<Tile*, 8> neighbors; //neighbors
    int mine=0; //unique private variable: texture dependent on this; edited in setNeighbors, when can calculate bomb neighbors
};


#endif //COP_PROJECT4_TILE_H
