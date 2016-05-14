//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>

#include "RunnerBase.hpp"

struct Cell{
	bool leftDone;
	bool rightDone;
	bool upDone;
	bool downDone;

	Status state;

	Direction prevStep;
};

class Runner: public RunnerBase {
	private:
		std::vector<Cell> history;

		Direction prevDirection;
		bool isForwardDirection;

    public:
    	// Constructors & Destructors
    	Runner();

        Direction step();
};


#endif //LABYRINTH_RUNNER_HPP
