//
// Created by xcao2 on 11/28/2023.
//

#include "Button.h"
#include "Toolbox.h"

#include <utility>


//tentative: just for setup
Button::Button(sf::Vector2f _position, std::function<void(void)> _onClick): position(_position), sprite(nullptr), onClickCallback(_onClick){
}

sf::Vector2f Button::getPosition() {
    return position;
}

sf::Sprite* Button::getSprite() {
    return sprite;
}

void Button::setSprite(sf::Sprite* _sprite){
    sprite=_sprite;
    sprite->setPosition(position.x, position.y);
}


void Button::onClick(){
    onClickCallback();
}


bool Button::clicked(sf::Vector2f& click_pos, bool left){
    if(sprite->getGlobalBounds().contains(click_pos) && left){
        onClickCallback();
        return true;
    }
    return false;
}