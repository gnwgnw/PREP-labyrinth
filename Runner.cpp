
//
// Created by tsv on 09.05.16.
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
    last_step = 0;

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
    int flag = 0;
    int flag1 = 0;
    if(current_status.up == BlockType::WALL)
        flag ++;
    if(current_status.right == BlockType::WALL)
        flag ++;
    if(current_status.down == BlockType::WALL)
        flag ++;
    if(current_status.left == BlockType::WALL)
        flag ++;

    if (flag == 2)
    {
        if(current_status.left == BlockType::WALL && current_status.up == BlockType::WALL && last_step == 4 && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 2;
        }
        if(current_status.left == BlockType::WALL && current_status.up == BlockType::WALL && last_step == 1 && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 1;
        }
        if(current_status.right == BlockType::WALL && current_status.up == BlockType::WALL && last_step == 2  && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 2;
        }
        if(current_status.right == BlockType::WALL && current_status.up == BlockType::WALL && last_step == 1 && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 3;
        }
        if(current_status.left == BlockType::WALL && current_status.down == BlockType::WALL && last_step == 4 && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 4;
        }
        if(current_status.left == BlockType::WALL && current_status.down == BlockType::WALL && last_step == 3 && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 1;
        }
        if(current_status.right == BlockType::WALL && current_status.down == BlockType::WALL && last_step == 3  && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 3;
        }
        if(current_status.right == BlockType::WALL && current_status.down == BlockType::WALL && last_step == 2 && flag1 == 0)
        {
            flag1 = 1;
            left_dir = 4;
        }
    }

    if (flag == 3)
    {
        if(current_status.left != BlockType::WALL)
            left_dir = 3;
        if(current_status.right != BlockType::WALL)
            left_dir = 1;
        if(current_status.up != BlockType::WALL)
            left_dir = 4;
        if(current_status.down != BlockType::WALL)
            left_dir = 2;
        last_step = 0;
    }


    if(left_dir == 4 && flag == 1 && current_status.up != BlockType::WALL && current_status.left == BlockType::WALL)
    {
       last_step = 1;
       return Direction::UP;
    }
    if(left_dir == 2 && flag == 1 && current_status.down != BlockType::WALL  && current_status.right == BlockType::WALL)
    {
       last_step = 3;
       return Direction::DOWN;
    }
    if(left_dir == 1 && flag == 1 && current_status.right != BlockType::WALL  && current_status.up == BlockType::WALL)
    {
       last_step = 2;
       return Direction::RIGHT;
    }
    if(left_dir == 3 && flag == 1 && current_status.left != BlockType::WALL  && current_status.down == BlockType::WALL)
    {
       last_step = 4;
       return Direction::LEFT;
    }

    if(left_dir == 4 && flag == 1 && current_status.left != BlockType::WALL)
    {
       last_step = 4;
       left_dir = 3;
       return Direction::LEFT;
    }
    if(left_dir == 2 && flag == 1 && current_status.right != BlockType::WALL)
    {
       left_dir = 1;
       last_step = 2;
       return Direction::RIGHT;
    }
    if(left_dir == 1 && flag == 1 && current_status.up != BlockType::WALL)
    {
       left_dir = 4;
       last_step = 1;
       return Direction::UP;
    }
    if(left_dir == 3 && flag == 1 && current_status.down != BlockType::WALL)
    {
       left_dir = 2;
       last_step = 3;
       return Direction::DOWN;
    }

    if (flag == 0)
    {
        return Direction::LEFT;
    }

    if(left_dir == 1 && last_step != 4)
    {
        last_step = 2;
        return Direction::RIGHT;
    }
    if(left_dir == 2 && last_step != 1)
    {
        last_step = 3;
        return Direction::DOWN;
    }
    if(left_dir == 3 && last_step != 2)
    {
        last_step = 4;
        return Direction::LEFT;
    }
    if(left_dir == 4 && last_step != 3)
    {
        last_step = 1;
        return Direction::UP;
    }
}
