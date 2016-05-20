
#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP
#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    private:
        int f_check;
        int left_dir;

    public:
        Runner();
        Direction step();
        Direction check_move();
        void set_dir();

};

#endif //LABYRINTH_RUNNER_HPP
