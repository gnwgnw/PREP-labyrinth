//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    private:
        Direction currDirection = Direction::UP;

        Direction getLeft();
        Direction getNextDirection(const Direction); // check is left available
        bool checkDirection(const Direction); // check direction 1 -- if wall 0 -- if not wall
    public:
        Direction step(); 
};


#endif //LABYRINTH_RUNNER_HPP
