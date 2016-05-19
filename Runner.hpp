//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP
#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    private:
        int f_check;
        int left_dir;
        int last_step;
    public:
        Runner();
        Direction step();
        Direction check_move();
        void set_dir();

};

#endif //LABYRINTH_RUNNER_HPP
