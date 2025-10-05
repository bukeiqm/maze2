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

player::player(int x, int y) : pos({ x,y }) {
	health = 100;
	dir = direction::STAY;
	speed = 1;
}

void player::Move() {
	pos = pos.dev(dir, speed);
}

void player::SetDirection(direction dir) {
	this->dir = dir;
}

bool player::IsJammed(const map& M) {
	return !M.IsPathway(pos.dev(dir));
}

map::map(const vector<vector<int>> mat){
	this->mat = mat;
	m = mat[0].size();
	n = mat.size();
}

bool map::IsPathway(int x, int y) const {
	return mat[y][x] == 0;
}

bool map::IsPathway(position pos) const {
	return IsPathway(pos.x, pos.y);
}