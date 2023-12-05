//
// Created by xcao2 on 11/28/2023.
//

#ifndef COP_PROJECT4_BUTTON_H
#define COP_PROJECT4_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    Button(sf::Vector2f _position, std::function<void(void)> _onClick); //constructor
    sf::Vector2f getPosition(); //get Position of Button, never used because used globalBounds for clicks
    sf::Sprite* getSprite(); //get Sprite
    void setSprite(sf::Sprite* _sprite); //set Sprite
    void onClick(); //calls onClickCallback
private:
    sf::Vector2f position; //position of button
    sf::Sprite* sprite; //sprite to draw on window
    std::function<void(void)> onClickCallback; //function called when clicked
};


#endif //COP_PROJECT4_BUTTON_H
