#pragma once
#include "types.hpp"
#include "map.hpp"
class player :public movable {
private:
	int health;
	friend class trap;
public:
	player(position initPos = { 0,0 });
public:
	bool IsJammed(const map& map);
	bool AtDest(const map& map);
	int GetHealth();
	void Draw() override;
};