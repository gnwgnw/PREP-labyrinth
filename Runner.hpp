//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "iostream"
#include "vector"
#include "RunnerBase.hpp"
struct Coord {
    int x;
    int y;

    bool right = false;
    bool down = false;
    bool left = false;
    bool up = false;

    Direction direction;
};

class Runner: public RunnerBase {
    public:
    std::vector<Direction >* where() ;
    bool include(Direction d);

   // Direction where(int x, int y);

    bool is_free(Direction d);

    bool deadlock();

    std::vector<Coord> history;



    Direction step();
};


#endif //LABYRINTH_RUNNER_HPP
