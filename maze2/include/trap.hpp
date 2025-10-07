#pragma once
#include "types.hpp"
#include "map.hpp"
#include "player.hpp"
class trap: public object {
private:
	int damage;
	int duration;
	bool triggered;
public:
	trap(position initPos, int duration = 100, int damage = 50);
	trap(int duration = 100, int damage = 50);
public:
	void DoDamageTo(player& player);
	void Mute();
	void Move(map m1,player p1);
	void Draw();
	void Revive();
};

