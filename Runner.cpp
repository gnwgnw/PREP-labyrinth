//
// Created by bsv on 20.05.16.
//

#include "Runner.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Runner::Runner()
{
   f_check = 0;
}

void Runner::set_dir()
{
    f_check = 1;

    if(current_status.up == BlockType::WALL && current_status.right != BlockType::WALL)
        left_dir = 1;
    if(current_status.down == BlockType::WALL && current_status.left != BlockType::WALL)
        left_dir = 3;
    if(current_status.left == BlockType::WALL && current_status.up != BlockType::WALL)
        left_dir = 4;
    if(current_status.right == BlockType::WALL && current_status.down != BlockType::WALL)
        left_dir = 2;
}

Direction Runner::step()
{
    if(f_check == 0)
        set_dir();
    Direction dir = check_move();
    return dir;
}

Direction Runner::check_move()
{
    if(left_dir == 1 && current_status.up != BlockType::WALL)
    {
        left_dir = 4;
        return Direction::UP;
    }
    if(left_dir == 2 && current_status.right != BlockType::WALL)
    {
        left_dir = 1;
        return Direction::RIGHT;
    }
    if(left_dir == 3 && current_status.down != BlockType::WALL)
    {
        left_dir = 2;
        return Direction::DOWN;
    }
    if(left_dir == 4 && current_status.left != BlockType::WALL)
    {
        left_dir = 3;
        return Direction::LEFT;
    }

    if(left_dir == 1 && current_status.right != BlockType::WALL)
        return Direction::RIGHT;
    if(left_dir == 2 && current_status.down != BlockType::WALL)
        return Direction::DOWN;
    if(left_dir == 3 && current_status.left != BlockType::WALL)
        return Direction::LEFT;
    if(left_dir == 4 && current_status.up != BlockType::WALL)
        return Direction::UP;

    left_dir++;
    if (left_dir == 5)
        left_dir = 1;

    if(left_dir == 1 && current_status.right != BlockType::WALL)
        return Direction::RIGHT;
    if(left_dir == 2 && current_status.down != BlockType::WALL)
        return Direction::DOWN;
    if(left_dir == 3 && current_status.left != BlockType::WALL)
        return Direction::LEFT;
    if(left_dir == 4 && current_status.up != BlockType::WALL)
        return Direction::UP;

    if(left_dir == 1)
    {
        left_dir = 3;
        return Direction::LEFT;
    }
    if(left_dir == 2)
    {
        left_dir = 4;
        return Direction::UP;
    }
    if(left_dir == 3)
    {
        left_dir = 1;
        return Direction::RIGHT;
    }
    if(left_dir == 4)
    {
        left_dir = 2;
        return Direction::DOWN;
    }

}
