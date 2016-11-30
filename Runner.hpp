//
// Created by tsv on 09.05.16.
//
#include <iostream>
#include <vector>
#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP
#define UP W
#define DOWN S
#define RIGHT D
#define LEFT A


#include "RunnerBase.hpp"

class Runner: public RunnerBase {
public:
    Runner() {angle = 0; turn_coord = current_status;}
    Direction step();
    void set_angle(short int new_angle);
    void turn();
    Direction turn_directions();
private:
    BlockType stat_ex = BlockType::EXIT;
    short int angle;
    Status turn_coord;
};


#endif //LABYRINTH_RUNNER_HPP
