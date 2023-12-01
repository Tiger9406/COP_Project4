//
// Created by xcao2 on 11/29/2023.
//

#include "minesweeper.h"
#include <iostream>

//namespace {
//    bool debugMode = false;
//}
//
//int launch() {
//    while(toolbox.window.isOpen()){
//        sf::Event event;
//        while(toolbox.window.pollEvent(event)){
//            if(event.type==sf::Event::Closed){
//                toolbox.window.close();
//            }
//            //other events
//        }
//        window.draw(toolbox.debugButton->getSprite());
//    }
//    restart();
//    return 0;
//}
//
//void restart() {
//    toolbox.gameState= new GameState(sf::Vector2i(25, 16), 50);
//    render(); // Render everything
//}
//
//void render() {
//    toolbox.window->draw(toolbox.debugButton->getPosition(), toolbox.debugButton->getSprite());
//}
//
//void toggleDebugMode() {
//    debugMode = !debugMode;
//}
//
//bool getDebugMode() {
//    return debugMode;
//}
//
////int gameLoop() {
////    while (true) {
////        sf::Event event;
////        while (window.pollEvent(event)) {
////            if (event.type == sf::Event::Closed) {
////                return 0;
////            }
////        }
////    }
////    return 0;
////}
//
//int main(){ return launch(); }