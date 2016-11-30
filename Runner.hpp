//
// Created by tsv on 09.05.16.
//
#include <iostream>
#include <vector>
#include <stack>

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
public:
    Runner(){prev_directions = Direction::RIGHT; count = 0;}
    Direction step();

private:
    Direction prev_directions ;
    int count;
};


#endif //LABYRINTH_RUNNER_HPP
