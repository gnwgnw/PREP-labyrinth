//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

#include "vector"
#include "iostream"
#include <stack>
#include "RunnerBase.hpp"

struct Node {


    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;

    Direction direction;

};

class Runner: public RunnerBase {
public:

    std::stack<Node> stack;

    bool is_free(Direction d);

    bool deadlock();

    Direction to_exit();

    Direction step();

    bool exit();

    std::vector<Direction >* where();



};




#endif //LABYRINTH_RUNNER_HPP
