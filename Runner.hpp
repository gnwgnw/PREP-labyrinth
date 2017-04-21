//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    public:

        Runner(){
            last_step = Direction::UP;
        }

        Direction step();

    private:
        Direction last_step;
};


#endif //LABYRINTH_RUNNER_HPP
