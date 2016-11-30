//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>
#include <fstream>
#include "RunnerBase.hpp"
#include "iostream"

using namespace std;

class Runner: public RunnerBase {
    public:
	Runner(): prev(Direction::UP), i(1), j(1) {
			map.resize(10010);
			for (auto& row: map) {
				row.resize(10010);
				for (auto& col: row)
					col = 0;
			}
	}
	vector<vector<int>> map;
	Direction prev;
	int i;
	int j;
	Direction step();
};


#endif //LABYRINTH_RUNNER_HPP
