//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step() {
    switch (currDirection) {
        case Direction::UP:

            if (isExitLeft()) {
                return Direction::LEFT;
            }
            else if (isExitUp()) {
                return Direction::UP;
            }

            if (isFreeRight()) {
                currDirection = Direction::RIGHT;
                return Direction::RIGHT;
            }
            else if (isFreeUp()) {
                return Direction::UP;
            }
            else if (isFreeLeft()) {
                currDirection = Direction::LEFT;
                return Direction::LEFT;
            }
            else {
                currDirection = Direction::DOWN;
                return Direction::DOWN;
            }
        case Direction::DOWN:

            if (isExitRight()) {
                return Direction::RIGHT;
            }
            else if (isExitDown()) {
                return Direction::DOWN;
            }
            else if (isExitLeft())
                return Direction::LEFT;

            if (isFreeLeft()) {
                currDirection = Direction::LEFT;
                return Direction::LEFT;
            }
            else if (isFreeDown()) {
                currDirection = Direction::DOWN;
                return Direction::DOWN;
            }
            else if (isFreeRight()) {
                currDirection = Direction::RIGHT;
                return Direction::RIGHT;
            }
            else {
                currDirection = Direction::UP;
                return Direction::UP;
            }
        case Direction::LEFT:

            if (isExitDown()) {
                currDirection = Direction::DOWN;
                return Direction::DOWN;
            }
            else if (isExitLeft())
                return Direction::LEFT;

            if (isFreeUp()) {
                currDirection = Direction::UP;
                return Direction::UP;
            }
            else if (isFreeLeft()) {
                return Direction::LEFT;
            }
            else if (isFreeDown()) {
                currDirection = Direction::DOWN;
                return Direction::DOWN;
            }
            else {
                currDirection = Direction::RIGHT;
                return Direction::RIGHT;
            }
        case Direction::RIGHT:

            if (isExitUp()) {
                currDirection = Direction::UP;
                return Direction::UP;
            }
            else if (isExitRight()) {
                currDirection = Direction::RIGHT;
                return Direction::RIGHT;
            }
            //
            if (isFreeDown()) {
                currDirection = Direction::DOWN;
                return Direction::DOWN;
            }
            else if (isFreeRight()) {
                return Direction::RIGHT;
            }
            else if (isFreeUp()) {
                currDirection = Direction::UP;
                return Direction::UP;
            }
            else {
                currDirection = Direction::LEFT;
                return Direction::LEFT;
            }
        default:
            return Direction ::RIGHT;
    }
}

bool Runner::isFreeUp() {
    return current_status.up != BlockType::WALL;
}

bool Runner::isFreeDown() {
    return current_status.down != BlockType::WALL;
}

bool Runner::isFreeLeft() {
    return current_status.left != BlockType::WALL;
}

bool Runner::isFreeRight() {
    return current_status.right != BlockType::WALL;
}

bool Runner::isExitLeft() {
    return current_status.left == BlockType::EXIT;
}

bool Runner::isExitDown() {
    return current_status.down == BlockType::EXIT;
}

bool Runner::isExitUp() {
    return current_status.up == BlockType::EXIT;
}

bool Runner::isExitRight() {
    return current_status.right == BlockType::EXIT;
}


