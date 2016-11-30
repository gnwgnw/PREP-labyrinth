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
    int i = 0;
    const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
    return directions[std::rand() % directions.size()];
}
