#include "player.hpp"

player::player(position initPos) : movable(initPos), health(100) {};

void player::Draw() {
	object::Draw();
}

int player::GetHealth() const {
	return health;
}

void player::SetHealthDiff(int diff) {
	health += diff;
}