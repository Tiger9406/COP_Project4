#include <iostream>
#include <SFML/Graphics.hpp>
#include "Toolbox.h"

int main() {
    Toolbox& toolbox=Toolbox::getInstance();
    toolbox.window.setTitle("P4 - Minesweeper, Tiger Cao");

    while (toolbox.window.isOpen()) {
        // Handle events
        sf::Event event;
        while (toolbox.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                toolbox.window.close();
            }
        }
    }

    return 0;
}
