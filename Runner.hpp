//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <stack>
#include <deque>

class Runner: public RunnerBase {
    public:
        Runner();
        Direction step();
        //Runner():deadlock(false){}:
    private:
        struct forkMemory
        {
          Direction inFork;
          Direction outFork;
        };
        bool mode = false;
        Direction prevStep;
        Direction BlindStep();
        Direction TrueStep();
        Direction endStep(Direction nextStep);
        Direction inverse(Direction d);
        std::stack<forkMemory> forkMem;
        std::deque<Direction> trueMem;
        int sizeFork();
        bool deadlock = false;
        Direction justGo();
        Direction goRight(Direction d);
        Direction goLeft(Direction d);
        bool canGo(Direction d);
};


#endif //LABYRINTH_RUNNER_HPP
