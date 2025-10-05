#pragma once
#include "datatypes.hpp"
#include "player.hpp"
class trap: public object {
private:
	int damage;
	int duration;
public:
	void DoDamageTo(player& player, int damage = 10);
	bool ShouldExist();
	void Draw();
};

