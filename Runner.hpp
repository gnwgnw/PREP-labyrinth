//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

#define while(x) while(!x)

class Runner: public RunnerBase {
    public:
        Direction step();
};


#endif //LABYRINTH_RUNNER_HPP
