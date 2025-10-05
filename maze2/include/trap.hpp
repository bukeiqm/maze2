#pragma once
#include "datatypes.hpp"
#include "player.hpp"
class trap {
private:
	position pos;
	int damage;
	int duration;
public:
	void DoDamageTo(player& player, int damage = 10) { player.health -= damage; }
	bool ShouldExist() { return duration > 0; }
};

