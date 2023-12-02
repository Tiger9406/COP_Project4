//
// Created by xcao2 on 11/28/2023.
//

#ifndef COP_PROJECT4_BUTTON_H
#define COP_PROJECT4_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>



class Button {
public:
    Button(sf::Vector2f _position, std::function<void(void)> _onClick);
    sf::Vector2f getPosition();
    sf::Sprite* getSprite();
    void setSprite(sf::Sprite* _sprite);
    void onClick();
    bool clicked(sf::Vector2f& click_pos, bool left);
private:
    sf::Vector2f position;
    sf::Sprite* sprite;
    std::function<void(void)> onClickCallback;
};


#endif //COP_PROJECT4_BUTTON_H
