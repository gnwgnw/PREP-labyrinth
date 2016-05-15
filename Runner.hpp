//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <stack>
#include <vector>
#include <algorithm>

#include "RunnerBase.hpp"
#include "Cell.hpp"

class Runner: public RunnerBase {
    public:
    	// Constructors
    	Runner();

        Direction step();

	private:
		std::stack<Cell> history;
		std::vector<std::pair<int, int>> deadlocks;

		Direction lastChoice;
		bool isForwardDirection;

		int x;
		int y;

		bool checkForDeadlock(int x, int y) const;
		bool checkForDeadlock(const Direction&);

		void addDeadlock(int x, int y);
};


#endif //LABYRINTH_RUNNER_HPP
