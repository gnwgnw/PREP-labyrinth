#include "Runner.hpp"
#include "utils.hpp"

#define ENTER BlockType::ENTER
#define EXIT BlockType::EXIT
#define WALL BlockType::WALL
#define FREE BlockType::FREE
#define LEFT Direction::LEFT
#define UP Direction::UP
#define DOWN Direction::DOWN
#define RIGHT Direction::RIGHT

Direction prev_step = LEFT;

Direction left_hand(Status &current_status) {
    switch (prev_step) {
        case UP:{

            if (current_status.left == FREE)
                return prev_step = LEFT;
            else if (current_status.up == FREE)
                return UP;
            else if (current_status.right == FREE)
                return prev_step = RIGHT;
            else
                return prev_step = DOWN;

        }
        case LEFT:{

            if (current_status.down == FREE)
                return prev_step = DOWN;
            else if (current_status.left == FREE)
                return LEFT;
            else if (current_status.up == FREE)
                return prev_step = UP;
            else
                return prev_step = RIGHT;

        }
        case DOWN:{

            if (current_status.right == FREE)
                return prev_step = RIGHT;
            else if (current_status.down == FREE)
                return DOWN;
            else if (current_status.left == FREE)
                return prev_step = LEFT;
            else
                return prev_step = UP;

        }
        default:{

            if (current_status.up == FREE)
                return prev_step = UP;
            else if (current_status.right == FREE)
                return RIGHT;
            else if (current_status.down == FREE)
                return prev_step = DOWN;
            else
                return prev_step = LEFT;
        }
    }
}

Direction Runner::step(){

    if (current_status.left == EXIT)
        return LEFT;
    if (current_status.right == EXIT)
        return RIGHT;
    if (current_status.up == EXIT)
        return UP;
    if (current_status.down == EXIT)
        return DOWN;

    return left_hand(current_status);
}
