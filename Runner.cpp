//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step()
{
    // TODO: you need to replace the code below with your implementation of labyrinth solver.
    // Now here is the stupid implementation with random choicing of direction.
    //const std::vector<Direction> directions = {Direction::UP, Direction::LEFT, Direction::DOWN, Direction::RIGHT};

    if(current_status.up == BlockType::EXIT){
        return Direction::UP;
    }
    if(current_status.down == BlockType::EXIT){
        return Direction::DOWN;
    }
    if(current_status.right == BlockType::EXIT){
        return Direction::RIGHT;
    }
    if(current_status.left == BlockType::EXIT){
        return Direction::LEFT;
    }
    if (last_step == Direction::UP){
        if(current_status.left != BlockType::WALL)
            return last_step = Direction::LEFT;

        if(current_status.up != BlockType::WALL)
            return last_step = Direction::UP;

        if(current_status.right != BlockType::WALL)
            return last_step = Direction::RIGHT;

        else
            return last_step = Direction::DOWN;
    }
    else if (last_step == Direction::LEFT){
        if(current_status.down != BlockType::WALL)
            return last_step = Direction::DOWN;

        if(current_status.left != BlockType::WALL)
            return last_step = Direction::LEFT;

        if(current_status.up != BlockType::WALL)
            return last_step = Direction::UP;

        else
            return last_step = Direction::RIGHT;

    }
    else if (last_step == Direction::DOWN){
        if(current_status.right != BlockType::WALL)
            return last_step = Direction::RIGHT;

        if(current_status.down != BlockType::WALL)
            return last_step = Direction::DOWN;

        if(current_status.left != BlockType::WALL)
            return last_step = Direction::LEFT;

        else
            return last_step = Direction::UP;

    }
    else {
        if(current_status.up != BlockType::WALL)
            return last_step = Direction::UP;

        if(current_status.right != BlockType::WALL)
            return last_step = Direction::RIGHT;

        if(current_status.down != BlockType::WALL)
            return last_step = Direction::DOWN;

        else
            return last_step = Direction::LEFT;

    }
}
