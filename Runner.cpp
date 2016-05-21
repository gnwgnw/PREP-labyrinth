
//
// Created by tsv on 09.05.16.
//
#include <list>
#include <set>
#include <iostream>
#include "Runner.hpp"

Runner::Runner() :  x(0), y(0), size(square), demen(0), next_step(Direction::UP)
    {
        arr = new bool*[size];
        for(int i = 0; i < size; ++i)
        {
            arr[i] = new bool[size];
            for(int j = 0; j < size; ++j)
            {
                arr[i][j] = false;
            }
        }
    }

void Runner::arr_del()
    {
        for (int i = 0; i < size; ++i)
        {
            delete [] arr[i];
        }
        delete [] arr;
    }

bool Runner::if_exit()
{
    if (current_status.up == BlockType::EXIT)
    {
        arr_del();
        next_step = Direction::UP;
        return true;
    }
    if (current_status.down == BlockType::EXIT)
    {
        arr_del();
        next_step = Direction::DOWN;
        return true;
    }
    if (current_status.left == BlockType::EXIT)
    {
        arr_del();
        next_step = Direction::LEFT;
        return true;
    }
    if (current_status.right == BlockType::EXIT)
    {
        arr_del();
        next_step = Direction::RIGHT;
        return true;
    }
    return false;
}

bool Runner::old_direction()
{
    if ((next_step == Direction::UP) && (current_status.up != BlockType::WALL) && !arr[old_x + demen][old_y + demen + 1])
    {
        y++;
        old_x = x;
        old_y = y - 1;
        num_directions++;
        return true;
    }
    if ((next_step == Direction::RIGHT) && (current_status.right != BlockType::WALL) && !arr[old_x + demen + 1][old_y + demen])
    {
        x++;
        old_x = x - 1;
        old_y = y;
        num_directions++;
        return true;
    }
    if ((next_step == Direction::LEFT) && (current_status.left != BlockType::WALL) && !arr[old_x + demen - 1][old_y + demen])
    {
        x--;
        old_x = x + 1;
        old_y = y;
        num_directions++;
        return true;
    }
    if ((next_step == Direction::DOWN) && (current_status.down != BlockType::WALL) && !arr[old_x + demen][old_y + demen - 1])
    {
        y--;
        old_x = x;
        old_y = y + 1;
        num_directions++;
        return true;
    }
    return false;
}

void Runner::find_directions()
{
    if ((current_status.down != BlockType::WALL) && !arr[old_x + demen][old_y + demen - 1])
    {
        if (!num_directions)
        {
            y--;
            old_x = x;
            old_y = y + 1;
            next_step = Direction::DOWN;
        }
        num_directions++;
    }
    if ((current_status.right != BlockType::WALL) && !arr[old_x + demen + 1][old_y + demen])
    {
        if (!num_directions)
        {
            x++;
            old_x = x - 1;
            old_y = y;
            next_step = Direction::RIGHT;
        }
        num_directions++;
    }
    if ((current_status.up != BlockType::WALL) && !arr[old_x + demen][old_y + demen + 1])
    {
        if (!num_directions)
        {
            y++;
            old_x = x;
            old_y = y - 1;
            next_step = Direction::UP;
        }
        num_directions++;
    }
    if ((current_status.left != BlockType::WALL) && !arr[old_x + demen - 1][old_y + demen])
    {
        if (!num_directions)
        {
            x--;
            old_x = x + 1;
            old_y = y;
            next_step = Direction::LEFT;
        }
        num_directions++;
    }
}

Direction Runner::step()
{
    num_directions = 0;
    old_x = x;
    old_y = y;

    add_memory();
    arr[x + demen][y + demen] = true;
    road.push_back(Node(x, y));
    if(if_exit())
    {
        return next_step;
    }
    if (!old_direction())
    {
        find_directions();
    }
    if (num_directions == 0)
    {
        tmp = road.back();
        arr[tmp._x + demen][tmp._y + demen] = false;
        road.pop_back();
        tmp = road.back();
        arr[tmp._x + demen][tmp._y + demen] = false;
        road.pop_back();
        find_directions();
        arr[old_x + demen][old_y + demen] = true;
    }
    return next_step;
}

void Runner::add_memory()
{
    if ((x >= size - 1 - demen) || (y >= size - 1 - demen))
    {
        size += square;
        bool **new_arr = new bool*[size];
        for(int i = 0; i < size; ++i)
        {
            new_arr[i] = new bool[size];
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if ((i < size - square) && (j < size - square))
                {
                    new_arr[i][j] = arr[i][j];
                }
                else
                {
                    new_arr[i][j] = false;
                }
            }
        }
        for (int i = 0; i < size - square; ++i)
        {
            delete [] arr[i];
        }
        delete [] arr;
        arr = new_arr;
    }
    if ((x <= 0 - demen) || (y <= 0 - demen))
    {
        demen += square;
        size += square;
        bool **new_arr = new bool*[size];
        for(int i = 0; i < size; ++i)
        {
            new_arr[i] = new bool[size];
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if ((i >= square) && (j >= square))
                {
                    new_arr[i][j] = arr[i - square][j - square];
                }
                else
                {
                    new_arr[i][j] = false;
                }
            }
        }
        for (int i = 0; i < size - square; ++i)
        {
            delete [] arr[i];
        }
        delete [] arr;
        arr = new_arr;
    }
}
