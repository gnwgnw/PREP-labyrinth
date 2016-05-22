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
        Direction step();

	private:
		std::stack<Cell> history;

		Direction lastChoice    = Direction::DOWN;
		bool isForwardDirection = true;

		int stepCount = 0;

		int x = 0;
		int y = 0;

		Direction chooseDirection(const Cell&) const;
		// void handleNewDirection(const Direction&);
};


#endif //LABYRINTH_RUNNER_HPP
