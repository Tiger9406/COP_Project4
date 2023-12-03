//
// Created by xcao2 on 11/29/2023.
//

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <random>

GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines) : dimensions(_dimensions), numberOfMines(_numberOfMines), flagCount(0), playStatus(PLAYING) {
    for(int i = 0; i < dimensions.y; i++){
        for(int j = 0; j < dimensions.x; j++){
            sf::Vector2f vec(static_cast<float>(j*32), static_cast<float>(i*32));
            Tile tile= Tile(vec);
//            if(i==1) {
//                tile.mine = 9;
//            }
            tiles.push_back(tile);
        }
    }
    std::vector<Tile*> copied_tiles;
    copied_tiles.reserve(tiles.size());
    for(auto &t:tiles){
        copied_tiles.push_back(&t);
    }
    std::random_device rand;
    std::mt19937 g(rand());
    std::shuffle(copied_tiles.begin(), copied_tiles.end(), g);
    for(int i = 0; i < numberOfMines; i++){
        copied_tiles[i]->mine=9;
    }
    setTileMineStatus();
}



GameState::GameState(const char* filepath) : playStatus(PLAYING) {
    // given board
}

int GameState::getFlagCount() {
    return flagCount;
}
void GameState::incrementFlag(bool placed){
    if(placed){
        flagCount++;
    }
    else{
        flagCount--;
    }
}

int GameState::getMineCount() {
    return numberOfMines;
}

Tile* GameState::getTile(int x, int y) {
    // if exists
    if (x >= 0 && x < dimensions.x && y >= 0 && y < dimensions.y) {
        // calculate index 2D->1D
        int index = x + y * dimensions.x;
        return &tiles[index];
    }
    return nullptr;
}

GameState::PlayStatus GameState::getPlayStatus() {
    return playStatus;
}

void GameState::setPlayStatus(PlayStatus _status) {
    playStatus = _status;
}

void GameState::setTileMineStatus(){
    int current=0;
    for(Tile &t : tiles){
        std::array<Tile*, 8> neighbors;
        sf::Vector2f pos = t.getLocation();
        if(pos.x-1<0){
            neighbors[0]=nullptr;
            neighbors[1]=nullptr;
            neighbors[2]=nullptr;
        }
        else if(pos.x+33>dimensions.x*32){
            neighbors[5]=nullptr;
            neighbors[6]=nullptr;
            neighbors[7]=nullptr;
        }
        if(pos.y-1<0){
            neighbors[0]=nullptr;
            neighbors[3]=nullptr;
            neighbors[5]=nullptr;
        }
        else if(pos.y+33>dimensions.y*32){
            neighbors[2]=nullptr;
            neighbors[4]=nullptr;
            neighbors[7]=nullptr;
        }
        for(int i =0; i < 8; i++){
            if(neighbors[i]!=nullptr){
                if(i==0){
                    neighbors[i]=&tiles[current-dimensions.x-1];
                }
                else if(i==1){
                    neighbors[i]=&tiles[current-1];
                }
                else if(i==2){
                    neighbors[i]=&tiles[current+dimensions.x-1];
                }
                else if(i==3){
                    neighbors[i]=&tiles[current-dimensions.x];
                }
                else if(i==4){
                    neighbors[i]=&tiles[current+dimensions.x];
                }
                else if(i==5){
                    neighbors[i]=&tiles[current-dimensions.x+1];
                }
                else if(i==6){
                    neighbors[i]=&tiles[current+1];
                }
                else if(i==7){
                    neighbors[i]=&tiles[current+dimensions.x+1];
                }
            }
        }
        t.setNeighbors(neighbors);
        neighbors.fill(&t);

        if(t.mine!=9){
            int mineCount=0;
            for(Tile *n : t.getNeighbors()){
                if(n!= nullptr && n->mine==9){
                    mineCount++;
                }
            }
            t.mine=mineCount;
        }
        current++;
    }
}

void GameState::draw(){
    for(Tile &t : tiles){
        t.draw();
    }
}

void GameState::onClick(sf::Vector2f& click_pos, bool left){
    int x=static_cast<int>(click_pos.x/32.0f);
    int y=static_cast<int>(click_pos.y/32.0f);
    Tile* clicked_tile=getTile(x, y);
    if(clicked_tile && left){
        clicked_tile->onClickLeft();
    }
    else if(clicked_tile && !left){
        clicked_tile->onClickRight();
    }
}