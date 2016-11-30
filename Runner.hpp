#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
class Runner: public RunnerBase {
public:
    Runner() : currDirection(Direction::RIGHT){};
    Direction step();
    bool isFreeUp();
    bool isFreeDown();
    bool isFreeLeft();
    bool isFreeRight();

    bool isExitLeft();
    bool isExitDown();
    bool isExitUp();
    bool isExitRight();

private:
    Direction currDirection;

};

#endif //LABYRINTH_RUNNER_HPP
