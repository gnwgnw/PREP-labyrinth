//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <stack>

class Runner: public RunnerBase {
    public:
        Direction step();
        //Runner():deadlock(false){}:
    private:
        Direction prevStep;
        Direction inverse(Direction d);
        std::stack<Direction> forkMem;
        int sizeFork();
        bool deadlock = false;
        Direction justGo();
        Direction goRight(Direction d);
        Direction goLeft(Direction d);
        bool canGo(Direction d);
};


#endif //LABYRINTH_RUNNER_HPP
