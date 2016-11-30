#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


void Runner::fill(int n, short x, short y) {
 
		
	++n;
	cout << x <<"," << y << " - " << n << endl;

	if ( x  < rows ) {
	++x;
	if (map[x][y] == -1)
		return;
	if (map[x][y] > n || map[x][y] == 0) {
		map[x][y] = n;
		fill(n, x, y);
	}
	--x;
	}
	
	if ( y < cols ) {
	++y;
	if (map[x][y] == -1)
		return;
	if (map[x][y] > n || map[x][y] == 0) {
		map[x][y] = n;
		fill(n, x, y);
	}
	--y;
	}

	if ( i < x ) {
	--x;
	if (map[x][y] == -1)
		return;
	if (map[x][y] > n || map[x][y] == 0) {
		map[x][y] = n;
		fill(n, x, y);
	}
	++x;
	}
	
	if (j < y) {
	--y;
	if (map[x][y] == -1)
		return;
	if (map[x][y] > n || map[x][y] == 0) {
		map[x][y] = n;
		fill(n, x, y);
	}
	++y;
	}

//	cout << "false" << endl;
	return;

}


Direction Runner::find_direction(int x, int y) {


	const short t = map[x][y] - 1;
	vector<short> dir = {map[x-1][y], map[x+1][y],
					     map[x][y-1], map[x][y+1]};

	int dist = distance(dir.begin(),
			find(dir.begin(),dir.end(), t));


		if (dist == 3) {
			++j;
			return Direction::RIGHT;
		}
		if (dist == 2) {
			--j;
			return Direction::LEFT;
		}
		if (dist == 1) {
			++i;
			return Direction::DOWN;
		}
		if (dist == 0) {
			--i;
			return Direction::UP;
		}
			
	return Direction::DOWN;
}

Direction Runner::step()
{	
	static int k = 0;
	if (k == 0) {
		fill(2, x_ex, y_ex);

	cout << "fill - end" << endl;

	if (map[i+1][j] != 1) {
		map[i][j] = map[i+1][j] + 1;
		++i;
		++k;
		return Direction::DOWN;
	}
	if (map[i][j+1] != 1) {
		map[i][j] = map[i][j+1] + 1;
		++j;
		++k;
		return Direction::RIGHT;
	}
	if (map[i][j-1] != 1) {
		map[i][j] = map[i][j-1] + 1;
		--j;
		++k;
		return Direction::LEFT;

	}
	if (map[i-1][j] != 1) {
		map[i][j] = map[i-1][j] + 1;
		--i;
		++k;
		return Direction::UP;
	}
} 
	if (map[i+1][j] == 2)
		return Direction::DOWN;
	if (map[i-1][j] == 2)
		return Direction::UP;
	if (map[i][j-1] == 2)
		return Direction::LEFT;
	if (map[i][j+1] == 2)
		return Direction::RIGHT;
		
	return find_direction(i, j);
}
