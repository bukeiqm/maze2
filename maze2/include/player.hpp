#pragma once
#include "datatypes.hpp"
#include "map.hpp"
class player {
private:
	position pos;
	direction dir;
	int health;
	int speed;
	friend class trap;
public:
	player() = default;
	player(int xCoordinate, int yCoordinate);
	~player() = default;
public:
	void Move();
	void SetDirection(direction dir);
	bool IsJammed(const map& map);
	bool AtDest(const map& map);
	int GetX() const { return pos.x; }
	int GetY() const { return pos.y; }
};

