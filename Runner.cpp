//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include "utils.hpp"

std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::UP};
int i = -1;

Direction Runner::step()
{
    // TODO: you need to replace the code below with your implementation of labyrinth solver.
    // Now here is the stupid implementation with random choicing of direction.
    if(i == 2) {
        i = -1;
        directions = {Direction::LEFT, Direction::RIGHT, Direction::LEFT};
    }
    i++;
    return directions[i];
}
