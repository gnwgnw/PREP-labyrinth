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
        right_dir = 3;
    if(current_status.down == BlockType::WALL && current_status.left != BlockType::WALL)
        right_dir = 1;
    if(current_status.left == BlockType::WALL && current_status.up != BlockType::WALL)
        right_dir = 2;
    if(current_status.right == BlockType::WALL && current_status.down != BlockType::WALL)
        right_dir = 4;
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
    if(right_dir == 1 && current_status.up != BlockType::WALL)							
    {														
        right_dir = 2;												
        return Direction::UP;
    }
    if(right_dir == 2 && current_status.right != BlockType::WALL)
    {
        right_dir = 3;
        return Direction::RIGHT;
    }
    if(right_dir == 3 && current_status.down != BlockType::WALL)
    {
        right_dir = 4;
        return Direction::DOWN;
    }
    if(right_dir == 4 && current_status.left != BlockType::WALL)
    {
        right_dir = 1;
        return Direction::LEFT;
    }

    if(right_dir == 1 && current_status.left != BlockType::WALL)
        return Direction::LEFT;
    if(right_dir == 2 && current_status.up != BlockType::WALL)
        return Direction::UP;
    if(right_dir == 3 && current_status.right != BlockType::WALL)
        return Direction::RIGHT;
    if(right_dir == 4 && current_status.down != BlockType::WALL)
        return Direction::DOWN;

    right_dir++;
    if (right_dir == 5)
        right_dir = 1;

    if(right_dir == 1 && current_status.left != BlockType::WALL)
        return Direction::LEFT;
    if(right_dir == 2 && current_status.up != BlockType::WALL)
        return Direction::UP;
    if(right_dir == 3 && current_status.right != BlockType::WALL)
        return Direction::RIGHT;
    if(right_dir == 4 && current_status.down != BlockType::WALL)
        return Direction::DOWN;

    if(right_dir == 1)
    {
        right_dir = 3;                  
        return Direction::LEFT;
    }
    if(right_dir == 2)
    {
        right_dir = 4;
        return Direction::UP;
    }
    if(right_dir == 3)
    {
        right_dir = 1;
        return Direction::RIGHT;
    }
    if(right_dir == 4)
    {
        right_dir = 2;
        return Direction::DOWN;
    }

}

