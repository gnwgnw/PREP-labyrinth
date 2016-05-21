//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <stack>
#include <time.h>

#include "RunnerBase.hpp"
#include "Cell.hpp"

class Runner: public RunnerBase {
    public:
    	// Constructors
    	Runner();

        Direction step();

	private:
		std::stack<Cell> history;

		Direction lastChoice    = Direction::DOWN;
		bool isForwardDirection = true;
};


#endif //LABYRINTH_RUNNER_HPP
