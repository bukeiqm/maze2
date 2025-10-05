#include "player.hpp"

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

bool player::AtDest(const map& M) {
	return pos == M.destination;
}