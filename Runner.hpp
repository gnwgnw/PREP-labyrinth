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
    unsigned int count = 0;

    std::stack<Node> stack;

    bool is_free(Direction d);

    bool deadlock();

 //   Direction to_exit();

    Direction step();

    bool free_right = false;
    bool free_left = false;
    bool free_down = false;
    bool free_up = false;

 //   bool exit();
    void clear_current_dir();
  //  std::vector<Direction > direction;



};




#endif //LABYRINTH_RUNNER_HPP
