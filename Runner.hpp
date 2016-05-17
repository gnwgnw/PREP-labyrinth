//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP
#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    private:
        int** map_lab;
        int x;
        int y;
        int height_map;
        int width_map;
        int height_map_max;
        int width_map_max;
        int move_deadlock;

    public:
        Runner();
        void create_map_lab();
        Direction step();
        Direction check_move();
        void draw_map();
        void print_map();
};

#endif //LABYRINTH_RUNNER_HPP
