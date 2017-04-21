//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "utils.hpp"
#include <vector>
#include <algorithm>

Direction Runner::step()
{

    status = {current_status.up, current_status.left, current_status.down, current_status.right};

    it = std::find(status.begin(), status.end(), BlockType::EXIT);
    if (it != status.end())
            return directions[std::distance(status.begin(), it)];

    int step = (last_step + 1) % 4;

    while(status[step] == BlockType::WALL){
        if(step)
            step--;
        else
            step = 3;
    }

    return directions[last_step = step];
}

