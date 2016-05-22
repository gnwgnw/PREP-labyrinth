//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <cstdint>
#include <cstddef>

#include <fstream>
#include <stack>

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    public:
        Direction step();

private:
        Direction _history;
};


#endif //LABYRINTH_RUNNER_HPP
