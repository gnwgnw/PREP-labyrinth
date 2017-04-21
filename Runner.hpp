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

	Runner() {
		fout.open("Dungeon/lvl_2.txt");
		if (fout.is_open()) {
  			fout << "3 5" << endl;
 			fout << "1 1 1 1 1" << endl;
 			fout << "1 2 0 3 1" << endl;
			fout << "1 1 1 1 1" << endl;
 		}
		fout.close();
		fout.open("Dungeon/lvl_3.txt");
		if (fout.is_open()) {
  			fout << "3 5" << endl;
 			fout << "1 1 1 1 1" << endl;
 			fout << "1 2 0 3 1" << endl;
			fout << "1 1 1 1 1" << endl;
 		}
		fout.clsoe();
	}
	ostream fout;
	Direction step();
};



#endif //LABYRINTH_RUNNER_HPP
