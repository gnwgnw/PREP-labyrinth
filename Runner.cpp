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
    Direction prev = _prevDir;
    Direction result = __find(BlockType::EXIT);
    _prevDir = prev;

    if (result != Direction::NONE)
        return result;
    return __find(BlockType::FREE);
}

Direction Runner::__find(const BlockType &bt)
{
    Direction result;

    if (__countWalls() == 3)
        _prevDir = Direction::NONE;

    if (current_status.up == bt &&
        _prevDir != Direction::DOWN) {
        _prevDir = Direction::UP;
        result =  Direction::UP;
    }
    else if (current_status.down  == bt &&
        _prevDir != Direction::UP) {
        _prevDir = Direction::DOWN;
        result = Direction::DOWN;
    }
    else if (current_status.left  == bt &&
        _prevDir != Direction::RIGHT) {
        _prevDir = Direction::LEFT;
        result = Direction::LEFT;
    }
    else if (current_status.right == bt &&
        _prevDir != Direction::LEFT) {
        _prevDir = Direction::RIGHT;
        result = Direction::RIGHT;
    }
    else {
        _prevDir = Direction::NONE;
        result   = Direction::NONE;
    }

    return result;
}

size_t Runner::__countWalls() const
{
    size_t nWalls = 0;
    if (current_status.up == BlockType::WALL)
        nWalls++;
    if (current_status.down == BlockType::WALL)
        nWalls++;
    if (current_status.left == BlockType::WALL)
        nWalls++;
    if (current_status.right == BlockType::WALL)
        nWalls++;

    return nWalls;
}
