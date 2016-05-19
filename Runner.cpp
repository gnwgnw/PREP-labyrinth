//
// Created by tsv on 09.05.16.
//
#include <list>
#include <set>
#include <algorithm>
#include "Runner.hpp"

using namespace std;

bool Runner::was_went(const int a, const int b)
{
    list<pair<int, int>>::iterator p = road.begin();
    while(p != road.end())
    {
        if (*p == make_pair(a, b))
        {
            return true;
        }
        p++;
    }
    return false;
}

void Runner::find_directions()
{
    if ((current_status.right != BlockType::WALL) && (arr.find(make_pair(old_x + 1, old_y)) == arr.end()) && !was_went(old_x + 1, old_y))
    {
        if (!num_directions)
        {
            x++;
            old_x = x - 1;
            next_step = Direction::RIGHT;
        }
        num_directions++;
    }
    if ((current_status.down != BlockType::WALL) && (arr.find(make_pair(old_x, old_y - 1)) == arr.end()) && !was_went(old_x, old_y - 1))
    {
        if (!num_directions)
        {
            y--;
            old_y = y + 1;
            next_step = Direction::DOWN;
        }
        num_directions++;
    }
    if ((current_status.up != BlockType::WALL) && (arr.find(make_pair(old_x, old_y + 1)) == arr.end()) && !was_went(old_x, old_y + 1))
    {
        if (!num_directions)
        {
            y++;
            old_y = y - 1;
            next_step = Direction::UP;
        }
        num_directions++;
    }
    if ((current_status.left != BlockType::WALL) && (arr.find(make_pair(old_x - 1, old_y)) == arr.end()) && !was_went(old_x - 1, old_y))
    {
        if (!num_directions)
        {
            x--;
            old_x = x + 1;
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

    road.push_back(make_pair(x, y));
    find_directions();
    if (num_directions == 0)
    {
        arr.insert(make_pair(old_x, old_y));
        road.pop_back();
        road.pop_back();
        find_directions();
    }
    return next_step;
}

