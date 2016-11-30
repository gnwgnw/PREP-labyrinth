//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>
#include <fstream>
#include <algorithm>
#include "RunnerBase.hpp"
#include "iostream"

using namespace std;

class Runner: public RunnerBase {
    public:
	Runner(): prev(Direction::UP) {
			fin.open("./Dungeon/lvl_1.txt");
//			fin.open("./test_labs/test_lvl_3.txt");
//			fout.open("lag.txt");
			fin >> cols >> rows;
			cols = cols;
			rows = rows;

			map.resize(rows);
			short t1 = 0;
			for (auto& row: map) {
				row.resize(cols);
				short t2 = 0;
				for (auto& col: row) {
					fin >> col;
					if (col == 2) {
						col = -1;
						i = t1;
						j = t2;
					}
					if (col == 3) {
						col = 2;
						x_ex = t1;
						y_ex = t2;
					}
					++t2;
				}
				++t1;
			}
		 }
//	ofstream fout;
	ifstream fin;
	short cols;
	short rows;
	vector<vector<short>> map;
	Direction prev;
	short i;
	short j;
	short x_ex;
	short y_ex;
	Direction step();
	void fill(int n, short x, short y);
	Direction find_direction(int x, int y);
	~Runner() {   
//			for (auto& row: map) {
//				for (auto& col: row) {
//					cout << col << "\t";
//					fout << col << "\t";
//				}
//				fout << endl;
//				cout << endl;
//			}
//			fout.close();
			fin.close();
	}
};

#endif //LABYRINTH_RUNNER_HPP
