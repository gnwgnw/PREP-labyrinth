//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>
#include "RunnerBase.hpp"

using std::vector;

struct Used_Directions { //0-не ходили, 1-оттуда пришли, 2-ходили и там стена
	int up;
	int down;
	int left;
	int right;
};

class Runner: public RunnerBase {
        int square_number = 0;
        vector<Used_Directions> squares_on_field;
    public:
        Direction step();
};


#endif //LABYRINTH_RUNNER_HPP
