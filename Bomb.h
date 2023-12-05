//
// Created by xcao2 on 12/4/2023.
//

#ifndef COP_PROJECT4_BOMB_H
#define COP_PROJECT4_BOMB_H

#include "Tile.h"


class Bomb : public Tile{
public:
    //all mirror Tile
    Bomb(sf::Vector2f position);
    void setState(State _state) override;
    void draw() const override;
    void onClickLeft() override;
    void onClickRight() override;
    State getState() override;
private:
    //only needs to work with sprite and state
    sf::Sprite sprite;
    State currentState;
};


#endif //COP_PROJECT4_BOMB_H
