//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <stack>
#include <list>
#include <algorithm>

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

		int oneWayStepCount = 0;

		int leftCount  = 0;
		int rightCount = 0;
		int downCount  = 0;
		int upCount    = 0;

		Direction chooseDirection(const Cell&) const;
		void handleNewDirection(const Direction&);

		std::list<Direction> dirs{
						Direction::RIGHT,
						Direction::LEFT,
						Direction::DOWN, 
						Direction::UP,
		};
};


#endif //LABYRINTH_RUNNER_HPP
