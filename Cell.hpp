//
// Created by ed_asriyan on 14.05.16.
//

#ifndef CELL_HPP
#define CELL_HPP

#include <ostream>

#include "utils.hpp"

class Cell{
	public:
		// Constructors & Destructors
		Cell() = default;
		Cell(const Status& state, const Direction& prevStep);
		Cell(const Status& state);

		bool isDeadlock() const;
		Direction getBackDirection() const;
		Direction getPrevDirection() const;

		bool getDirectionState(const Direction&) const;
		void setDirectionState(const Direction&, bool value);

		bool isNearExit() const;

		friend std::ostream& operator<<(std::ostream&, const Cell&);
	private:
		bool leftDone;
		bool rightDone;
		bool upDone;
		bool downDone;

		Status state;

		Direction prevStep;
		Direction backDirection;
};

Direction getOppositeDirection(const Direction& direction);



#endif // CELL_HPP