//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <cstdint>
#include <cstddef>

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    public:
        Direction step();

private:
        Direction _prevDir = Direction::NONE;

        Direction __find(const BlockType &bt);
        size_t    __countWalls() const;
};


#endif //LABYRINTH_RUNNER_HPP
