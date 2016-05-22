//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"


Direction Runner::getLeft() {

    switch(currDirection) {
        case Direction::UP: {
            return Direction::LEFT;
        }
        case Direction::DOWN: {
            return Direction::RIGHT;
        }
        case Direction::LEFT: {
            return Direction::DOWN;
        }
        case Direction::RIGHT: {
            return Direction::UP;
        }
    }
}

Direction Runner::getNextDirection(const Direction direction_) {

    switch(direction_) {
        case Direction::UP: {
            return Direction::RIGHT;
        }
        case Direction::DOWN: {
            return Direction::LEFT;
        }
        case Direction::LEFT: {
            return Direction::UP;
        }
        case Direction::RIGHT: {
            return Direction::DOWN;
        }
    }
}

bool Runner::checkDirection(const Direction direction_) {
    
    switch(direction_) {
        case Direction::UP: {
            return current_status.up == BlockType::WALL;
        }
        case Direction::DOWN: {
            return current_status.down == BlockType::WALL;
        }
        case Direction::LEFT: {
            return current_status.left == BlockType::WALL;
        }
        case Direction::RIGHT: {
            return current_status.right == BlockType::WALL;
        }
    }
}


Direction Runner::step() {  
   
    //  check the end nearby
    if (current_status.up == BlockType::EXIT)
        return Direction::UP;
    if (current_status.down == BlockType::EXIT)
        return Direction::DOWN;
    if (current_status.left == BlockType::EXIT)
        return Direction::LEFT;
    if (current_status.right == BlockType::EXIT)
        return Direction::RIGHT;
        
    Direction nextDirection = getLeft();
    while(checkDirection(nextDirection)) {
        nextDirection = getNextDirection(nextDirection);
    }
    currDirection = nextDirection;
    return currDirection;
}
