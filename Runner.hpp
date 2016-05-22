//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    public:
        Direction step();

        void setWaves();
        void enlargeMap();

        struct Point
        {
            int x;
            int y;
            int wave;
            //bool forbidden;
        };

Point **map = nullptr;

int mapSize = 1;
int numOfWave = 1;
int minimalCoordinate = 0;
int maximalCoordinate = 0;
Point position {0, 0, 1};

};




#endif //LABYRINTH_RUNNER_HPP
