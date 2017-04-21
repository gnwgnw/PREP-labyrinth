//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


using namespace std;
    Direction Runner::step() {
    if (current_status.down == BlockType::EXIT)
    return Direction::DOWN;
    if (current_status.right == BlockType::EXIT)
    return Direction::RIGHT;
    if (current_status.left == BlockType::EXIT)
    return Direction::LEFT;
    if (current_status.up == BlockType::EXIT)
    return Direction::UP;
	
	++map[i][j];

    switch (prev) {

    case(Direction::UP):
    if (current_status.left != BlockType::WALL) {
        --j;
        if (map[i][j] > 2) {
            ++j;
            continue;
        }
        return (prev = Direction::LEFT);
    }
    if (current_status.up != BlockType::WALL) {
        --i;
        if (map[i][j] > 2) {
            ++i;
            continue;
        }
        return (prev = Direction::UP);
    }
    if (current_status.right != BlockType::WALL) {
        ++j;
        if (map[i][j] > 2) {
            --j;
            continue;
        }
        return (prev = Direction::RIGHT);
    }
    if (current_status.down != BlockType::WALL) {
    ++i;
        if (map[i][j] > 2) {
            --i;
            continue;
        }
    return (prev = Direction::DOWN);
    }

    case(Direction::DOWN):
    if (current_status.right != BlockType::WALL) {
    ++j;
        if (map[i][j] > 2) {
            --j;
            continue;
        }
    return (prev = Direction::RIGHT);
    }
    if (current_status.down != BlockType::WALL) {
    ++i;
        if (map[i][j] > 2) {
            --i;
            continue;
        }
    return (prev = Direction::DOWN);
    }
    if (current_status.left != BlockType::WALL) {
    --j;
        if (map[i][j] > 2) {
            ++j;
            continue;
        }
    return (prev = Direction::LEFT);
    }
    if (current_status.up != BlockType::WALL) {
    --i;
        if (map[i][j] > 2) {
            ++i;
            continue;
        }
    return (prev = Direction::UP);
    }

    case(Direction::RIGHT):
    if (current_status.up != BlockType::WALL) {
    --i;
        if (map[i][j] > 2) {
            ++i;
            continue;
        }
    return (prev = Direction::UP);
    }
    if (current_status.right != BlockType::WALL) {
    ++j;
        if (map[i][j] > 2) {
            --j;
            continue;
        }
    return (prev = Direction::RIGHT);
    }
    if (current_status.down != BlockType::WALL) {
    ++i;
        if (map[i][j] > 2) {
            --i;
            continue;
        }
    return (prev = Direction::DOWN);
    }
    if (current_status.left != BlockType::WALL) {
    --j;
        if (map[i][j] > 2) {
            ++j;
            continue;
        }
    return (prev = Direction::LEFT);
    }

    case(Direction::LEFT):
    if (current_status.down != BlockType::WALL) {
    ++i;
        if (map[i][j] > 2) {
            --i;
            continue;
        }
    return (prev = Direction::DOWN);
    }
    if (current_status.left != BlockType::WALL) {
    --j;
        if (map[i][j] > 2) {
            ++j;
            continue;
        }
    return (prev = Direction::LEFT);
    }
    if (current_status.up != BlockType::WALL) {
    --i;
        if (map[i][j] > 2) {
            ++i;
            continue;
        }
    return (prev = Direction::UP);
    }
    if (current_status.right != BlockType::WALL) {
    ++j;
        if (map[i][j] > 2) {
            --j;
            continue;
        }
    return (prev = Direction::RIGHT);
    }
    }
    return Direction::DOWN;
    }
