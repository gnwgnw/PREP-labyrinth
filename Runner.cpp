//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"


Direction Runner::step() {
    switch (currDirection) {
        case Direction::UP:
            if (isFreeLeft()) {
                currDirection = Direction::LEFT;

                return Direction::LEFT;
            } else if (isFreeUp()) {
                return Direction::UP;
            } else if (isFreeRight()) {
                currDirection = Direction::RIGHT;

                return Direction::RIGHT;
            } else {
                currDirection = Direction::DOWN;

                return Direction::DOWN;
            }
        case Direction::DOWN:
            if (isFreeRight()) {
                currDirection = Direction::RIGHT;

                return Direction::RIGHT;
            } else if (isFreeDown()) {
                return Direction::DOWN;
            } else if (isFreeLeft()) {
                currDirection = Direction::LEFT;

                return Direction::LEFT;
            } else {
                currDirection = Direction::UP;

                return Direction::UP;
            }

        case Direction::LEFT:
            if (isFreeDown()) {
                currDirection = Direction::DOWN;

                return Direction::DOWN;
            } else if (isFreeLeft()) {
                return Direction::LEFT;
            } else if (isFreeUp()) {
                currDirection = Direction::UP;

                return Direction::UP;
            } else {
                currDirection = Direction::RIGHT;

                return Direction::RIGHT;
            }
        case Direction::RIGHT:
            if (isFreeUp()) {
                currDirection = Direction::UP;

                return Direction::UP;
            } else if (isFreeRight()) {
                return Direction::RIGHT;
            } else if (isFreeDown()) {
                currDirection = Direction::DOWN;

                return Direction::DOWN;
            } else {
                currDirection = Direction::LEFT;

                return Direction::LEFT;
            }
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










