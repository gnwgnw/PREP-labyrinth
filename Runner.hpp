//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <cstdint>
#include <cstddef>

#include <stack>

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    public:
        Direction step();

private:
        typedef struct f {
            bool      wasUp;
            bool      wasDown;
            bool      wasLeft;
            bool      wasRight;
            Direction base;
        } Fork;

        std::stack<Direction> _history;
        std::stack<Fork>      _fork;

        bool goAhead = true;

        size_t    __countWalls() const;
        Direction __freeFork()   const;
};


#endif //LABYRINTH_RUNNER_HPP
