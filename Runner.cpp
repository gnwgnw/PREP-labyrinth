#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Direction Runner::step() {
  if (currDirection == 0) {
        if ((current_status.up == BlockType::EXIT))
            return Direction::UP;

        if (current_status.right == BlockType::EXIT)
            return Direction::RIGHT;

        if(current_status.left == BlockType::EXIT)
            return Direction::LEFT;

        if (current_status.left == BlockType::FREE)
            return currDirection = 1, Direction::LEFT;

        if (current_status.up == BlockType::FREE)
            return Direction::UP;

        if (current_status.right == BlockType::FREE)
            return currDirection = 3, Direction::RIGHT;

        return currDirection = 2, Direction::DOWN;
    }
        if (currDirection == 2) {
            if (current_status.down == BlockType::EXIT)
                return Direction::DOWN;
            if (current_status.right == BlockType::EXIT)
                return Direction::RIGHT;
            if(current_status.left == BlockType::EXIT)
                return Direction::LEFT;

            if (current_status.right == BlockType::FREE)
                return currDirection = 3, Direction::RIGHT;

            if (current_status.down == BlockType::FREE)
                return Direction::DOWN;

            if (current_status.left == BlockType::FREE)
                return currDirection = 1, Direction::LEFT;

                return currDirection = 0, Direction::UP;
        }
        if (currDirection == 1) {
            if (current_status.up == BlockType::EXIT)
                return Direction::UP;
            if (current_status.left == BlockType::EXIT)
                return Direction::LEFT;
            if(current_status.down == BlockType::EXIT)
                return Direction::DOWN;

            if (current_status.down == BlockType::FREE)
                return currDirection = 2, Direction::DOWN;

            if (current_status.left == BlockType::FREE)
                return Direction::LEFT;

            if (current_status.up == BlockType::FREE)
                return currDirection = 0, Direction::UP;

                return currDirection = 3, Direction::RIGHT;
        }
            if (current_status.up == BlockType::EXIT)
                return Direction::UP;
            if (current_status.right == BlockType::EXIT)
                return Direction::RIGHT;
            if (current_status.down == BlockType::EXIT)
                return Direction::DOWN;

            if (current_status.up == BlockType::FREE)
                return currDirection = 0, Direction::UP;

            if (current_status.right == BlockType::FREE)
                return Direction::RIGHT;

            if (current_status.down == BlockType::FREE)
                return currDirection = 2, Direction::DOWN;

            if (current_status.left == BlockType::FREE)
                return currDirection = 1, Direction::LEFT;

    return Direction::LEFT;
}
