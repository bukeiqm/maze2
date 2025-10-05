#include "datatypes.hpp"

const position& position::dev(direction dir, int step) {
	int xp = x, yp = y;
	switch (dir) {
	case direction::NORTH:yp -= step; break;
	case direction::EAST:xp += step; break;
	case direction::SOUTH:yp += step; break;
	case direction::WEST:xp -= step; break;
	}
	return position(xp, yp);
}




