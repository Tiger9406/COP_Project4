//
// Created by xcao2 on 11/28/2023.
//

#include "Button.h"
#include "Toolbox.h"

#include <utility>


//tentative: just for setup
Button::Button(sf::Vector2f _position, std::function<void(void)> _onClick): position(_position), sprite(nullptr), onClickCallback(_onClick){
}

//getters
sf::Vector2f Button::getPosition() {
    return position;
}

sf::Sprite* Button::getSprite() {
    return sprite;
}

//setter
void Button::setSprite(sf::Sprite* _sprite){
    sprite=_sprite;
    sprite->setPosition(position.x, position.y);
}

//called when clicked
void Button::onClick(){
    onClickCallback();
}
