//
// Created by tsv on 09.05.16.
//


#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

/*
typedef BlockType;
typedef Direction;
*/

/*
struct MyDirection {
public:
    Direction right = Direction::RIGHT;
    Direction up = Direction::UP;
    Direction left = Direction::LEFT;
    Direction down = Direction::DOWN;
};

struct MyStatus {
public:
    Status right =
};


void R( MyDirection *md ) {
    md->right = Direction::UP;
    md->up = Direction::LEFT;
    md->down = Direction::RIGHT;
    md->left = Direction::DOWN;
};

void L( MyDirection *md ) {
    md->right = Direction::DOWN;
    md->up = Direction::RIGHT;
    md->down = Direction::DOWN;
    md->left = Direction::UP;
};

void D( MyDirection *md ) {
    md->right = Direction::LEFT;
    md->up = Direction::DOWN;
    md->down = Direction::UP;
    md->left = Direction::RIGHT;
};
*/

Direction PrevStep = Direction::UP;

Direction Runner::step() {
    /*   // TODO: you need to replace the code below with your implementation of labyrinth solver.
       // Now here is the stupid implementation with random choicing of direction.
       const std::vector<Direction> directions = { Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT };
       return directions[std::rand() % directions.size()];
       */

//    MyDirection md;
//    Status st;

    //проверить на тупик
    if ( current_status.left == BlockType::EXIT ) {
        return Direction::LEFT;
    }
    if ( current_status.right == BlockType::EXIT ) {
        return Direction::RIGHT;
    }
    if ( current_status.up == BlockType::EXIT ) {
        return Direction::UP;
    }
    if ( current_status.down == BlockType::EXIT ) {
        return Direction::DOWN;
    }
    //по очереди проверять свободен ли проход справа и ходил ли я в него YJ RFR 'NJ CLTKFNM&

    if ( PrevStep == Direction::UP ) {
        if ( current_status.right == BlockType::FREE ) {
            PrevStep = Direction::RIGHT;
            return Direction::RIGHT;
        } else if ( current_status.up == BlockType::FREE ) {
            PrevStep = Direction::UP;
            return Direction::UP;
        } else if ( current_status.left == BlockType::FREE ) {
            PrevStep = Direction::LEFT;
            return Direction::LEFT;
        } else {
            PrevStep = Direction::DOWN;
            return Direction::DOWN;
        }
    } else if ( PrevStep == Direction::RIGHT ) {
        if ( current_status.down == BlockType::FREE ) {
            PrevStep = Direction::DOWN;
            return Direction::DOWN;
        } else if ( current_status.right == BlockType::FREE ) {
            PrevStep = Direction::RIGHT;
            return Direction::RIGHT;
        } else if ( current_status.up == BlockType::FREE ) {
            PrevStep = Direction::UP;
            return Direction::UP;
        } else {
            PrevStep = Direction::LEFT;
            return Direction::LEFT;
        }
    } else if ( PrevStep == Direction::DOWN ) {
        if ( current_status.left == BlockType::FREE ) {
            PrevStep = Direction::LEFT;
            return Direction::LEFT;
        } else if ( current_status.down == BlockType::FREE ) {
            PrevStep = Direction::DOWN;
            return Direction::DOWN;
        } else if ( current_status.right == BlockType::FREE ) {
            PrevStep = Direction::RIGHT;
            return Direction::RIGHT;
        } else {
            PrevStep = Direction::UP;
            return Direction::UP;
        }
    } else {
        if ( current_status.up == BlockType::FREE ) {
            PrevStep = Direction::UP;
            return Direction::UP;
        } else if ( current_status.left == BlockType::FREE ) {
            PrevStep = Direction::LEFT;
            return Direction::LEFT;
        } else if ( current_status.down == BlockType::FREE ) {
            PrevStep = Direction::DOWN;
            return Direction::DOWN;
        } else {
            PrevStep = Direction::RIGHT;
            return Direction::RIGHT;
        }
    }
}
