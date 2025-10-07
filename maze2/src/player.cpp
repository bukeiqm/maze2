#include "player.hpp"

player::player(position initPos) : movable(initPos), health(100) {};

bool player::IsJammed(const map& M) {
	return !M.IsPathway(pos.Offset(dir));
}

bool player::AtDest(const map& M) {
	return pos == M.GetDestination();
}

void player::Draw() {
	object::Draw();
}

int player::GetHealth() {
	return health;
}