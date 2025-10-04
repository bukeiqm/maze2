#pragma once

#include "texture.h"

struct pos {
	int x, y;
	pos() = default;
	pos(int x, int y) : x(x), y(y) {};
	bool operator==(const pos& other) { return x == other.x && y == other.y; }
};

struct hitbox {
	int length, width, height;
	hitbox() = default;
	hitbox(int x, int y, int z) : length(x), width(y), height(z) {};
};

struct stats {
	int health, damage, speed, direction;
	stats() = default;
	stats(int x, int y, int z, int r) : health(x), damage(y), speed(z), direction(r) {};
};

class object {
protected:
	pos position;
	hitbox volume;
	stats stat;
	colors color;
public:
	object(pos position = { 0,0 }, hitbox volume = { 0,0,0 }, stats stat = { 0,0,0,0 }, colors color = colors::black) :
		position(position), volume(volume), stat(stat), color(color) { }
//public:
	//virtual void MoveDir(int direction) = 0;
	//virtual void MoveTo(const pos& position) = 0;
	//virtual bool CollideDir(int direction) = 0;
	//virtual bool CollideWith(const object& other) = 0;
	//virtual void DoDamageTo(const object& other) = 0;
public:
	const pos& GetPosition() const { return position; }
	const hitbox& GetHitbox() const { return volume; }
	const stats& GetStats() const { return stat; }
	const colors& GetColor() const { return color; }
public:
	void SetDirection(int direction) { stat.direction = direction; }
};