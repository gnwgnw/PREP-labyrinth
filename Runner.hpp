//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <stack>

#include "RunnerBase.hpp"
#include "Cell.hpp"

class Runner: public RunnerBase {
    public:
    	// Constructors
    	Runner();

        Direction step();

	private:
		std::stack<Cell> history;

		Direction lastChoice;
		bool isForwardDirection;
};


#endif //LABYRINTH_RUNNER_HPP
