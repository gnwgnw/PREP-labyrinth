//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
enum class BlackType{
    FREE = 0,
    WALL = 1,
    ENTER = 0,
    EXIT = 0
};

struct BlackStatus {
    BlackType up;
    BlackType down;
    BlackType left;
    BlackType right;
};

#define BlockType BlackType
#define Status BlackStatus
class Runner: public RunnerBase {
    public:
        Runner(){
            last_step = Direction::UP;
        }

        Direction step();

        void set_current_status(const BlackStatus& new_status);

    private:
        Direction last_step;
        BlackStatus current_status;
};


#endif //LABYRINTH_RUNNER_HPP
