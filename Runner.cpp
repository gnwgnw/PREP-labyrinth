//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

Direction Runner::step() {
  
        if (current_status.left == BlockType::EXIT) {
            return Direction::LEFT;
        } else if (current_status.right == BlockType::EXIT) {
            return Direction::RIGHT;
        } else if (current_status.up == BlockType::EXIT) {
            return Direction::UP;
        } else if (current_status.down == BlockType::EXIT) {
            return Direction::DOWN;
        }
    }
   
    switch (prev_directions) {
        case Direction::LEFT: {
            if (current_status.down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else if (current_status.left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else if (current_status.up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            } else {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            }
        }
        case Direction::DOWN: {
            if (current_status.right == BlockType::FREE) {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            } else if (current_status.down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else if (current_status.left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else {
                prev_directions = Direction::UP;
                return Direction::UP;
            }
        }
        case Direction::RIGHT: {
            if (current_status.up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            } else if (current_status.right == BlockType::FREE) {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            } else if (current_status.down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            }
        }
        default: {
            if (current_status.left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else if (current_status.up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            } else if (current_status.right == BlockType::FREE) {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            } else {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            }
        }
    }
            return Direction::LEFT;
}


