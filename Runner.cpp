//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

Direction Runner::step() {

if (current_status.up == BlockType::EXIT) {
        return Direction::UP;
    }else if (current_status.left == BlockType::EXIT) {
        return Direction::LEFT;
    }else if (current_status.right == BlockType::EXIT) {
        return Direction::RIGHT;
    }else if (current_status.down == BlockType::EXIT) {
        return Direction::DOWN;
    }

    if (course == Direction::UP){
        if ( current_status.left == BlockType::FREE ) {
            course = Direction::LEFT;
            return Direction::LEFT;
        } else if ( current_status.up == BlockType::FREE ) {
            course = Direction::UP;
            return Direction::UP;
        } else if ( current_status.right == BlockType::FREE ) {
            course = Direction::RIGHT;
            return Direction::RIGHT;
        } else {
            course = Direction::DOWN;
            return Direction::DOWN;
        }
    }else  if (course == Direction::LEFT){
        if ( current_status.down == BlockType::FREE ) {
            course = Direction::DOWN;
            return Direction::DOWN;
        } else if ( current_status.left == BlockType::FREE ) {
            course = Direction::LEFT;
            return Direction::LEFT;
        } else if ( current_status.up == BlockType::FREE ) {
            course = Direction::UP;
            return  Direction::UP;
        } else {
            course = Direction::RIGHT;
            return Direction::RIGHT;

        }
    }else if (course == Direction::DOWN){
        if ( current_status.right == BlockType::FREE ) {
            course = Direction::RIGHT;
            return Direction::RIGHT;
        } else if ( current_status.down == BlockType::FREE ) {
            course = Direction::DOWN;
            return Direction::DOWN;
        } else if ( current_status.left == BlockType::FREE  ) {
            course = Direction::LEFT;
            return Direction::LEFT;
        } else {
            course = Direction::UP;
            return Direction::UP;
        }
    }else if (course == Direction::RIGHT){
        if (current_status.up == BlockType::FREE) {
            course = Direction::UP;
            return Direction::UP;
        }else if (current_status.right == BlockType::FREE) {
            course = Direction::RIGHT;
            return Direction::RIGHT;
        }else if (current_status.down == BlockType::FREE) {
            course = Direction::DOWN;
            return Direction::DOWN;
        }else {
            course = Direction::LEFT;
            return Direction::LEFT;
        }
    }
    return course;

}
