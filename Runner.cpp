//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

bool operator != (const Status &s1, const Status &s2) {
    return (s1.up    != s2.up   ||
            s1.down  != s2.down ||
            s1.left  != s2.left ||
            s1.right != s2.right);
}

Direction Runner::step()
{
    if (current_status.right != BlockType::WALL && _history != Direction::RIGHT) {
        _history = Direction::LEFT;
        return Direction::RIGHT;
    }
    else if (current_status.up == BlockType::WALL && current_status.down == BlockType::WALL) {
        _history = Direction::RIGHT;
        return Direction::LEFT;
    }
    else if (current_status.up == BlockType::WALL && current_status.left == BlockType::WALL) {
        _history = Direction::UP;
        return Direction::DOWN;
    }
    else if (current_status.down == BlockType::WALL && current_status.left == BlockType::WALL) {
        _history = Direction::DOWN;
        return Direction::UP;
    }
    else if ((current_status.up == BlockType::WALL || current_status.down == BlockType::WALL) &&
              _history != Direction::LEFT){
        _history = Direction::RIGHT;
        return Direction::LEFT;
    }
    else if (_history == Direction::UP) {
        if (current_status.down == BlockType::WALL) {
            _history = Direction::RIGHT;
            return Direction::LEFT;
        }
        _history = Direction::UP;
        return Direction::DOWN;
    }
    else if (_history == Direction::DOWN) {
        if (current_status.up == BlockType::WALL) {
            _history = Direction::RIGHT;
            return Direction::LEFT;
        }
        _history = Direction::DOWN;
        return Direction::UP;
    }
    else if (_history == Direction::LEFT) {
        if (current_status.down == BlockType::WALL) {
            _history = Direction::DOWN;
            return Direction::UP;
        }
        _history = Direction::UP;
        return Direction::DOWN;
    }
}
