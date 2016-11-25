#include "Runner.hpp"
#include "utils.hpp"

Direction direction = Direction::UP;

Direction Runner::step()
{
    if (current_status.up == BlockType::EXIT)
        return Direction::UP;

    if (current_status.down == BlockType::EXIT)
        return Direction::DOWN;

    if (current_status.left == BlockType::EXIT)
        return Direction::LEFT;

    if (current_status.right == BlockType::EXIT)
        return Direction::RIGHT;

    switch(direction) {
        case Direction::UP: {
            if (current_status.left == BlockType::FREE)
                return direction = Direction::LEFT;
            else if (current_status.up == BlockType::FREE)
                return direction = Direction::UP;
            else if (current_status.right == BlockType::FREE)
                return direction = Direction::RIGHT;
            else
                return direction = Direction::DOWN;
        }
        case Direction::DOWN: {
            if (current_status.right == BlockType::FREE)
                return direction = Direction::RIGHT;
            else if (current_status.down == BlockType::FREE)
                return direction = Direction::DOWN;
            else if (current_status.left == BlockType::FREE)
                return direction = Direction::LEFT;
            else
                return direction = Direction::UP;
        }
        case Direction::LEFT: {
            if (current_status.down == BlockType::FREE)
                return direction = Direction::DOWN;
            else if (current_status.left == BlockType::FREE)
                return direction = Direction::LEFT;
            else if (current_status.up == BlockType::FREE)
                return direction = Direction::UP;
            else
                return direction = Direction::RIGHT;
        }
        default: {
            if (current_status.up == BlockType::FREE)
                return direction = Direction::UP;
            else if (current_status.right == BlockType::FREE)
                return direction = Direction::RIGHT;
            else if (current_status.down == BlockType::FREE)
                return direction = Direction::DOWN;
            else
                return direction = Direction::LEFT;
        }
    }
}
