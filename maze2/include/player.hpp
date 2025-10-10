#pragma once
#include "object.hpp"

class player :public movable {
private:
	int health;
	friend class trap;
public:
	player(position initPos = { 0,0 });
public:
	int GetHealth() const;
	void SetHealthDiff(int diff);
	void Draw() override;
};