//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <vector>

class Runner: public RunnerBase {
    public:

        Runner(){
            last_step = 0;
        }

        Direction step();

    private:

        int last_step;
        const std::vector<Direction> directions = {Direction::UP, Direction::LEFT, Direction::DOWN, Direction::RIGHT};
        std::vector<BlockType> status;
        std::vector<BlockType>::iterator it;
};


#endif //LABYRINTH_RUNNER_HPP
