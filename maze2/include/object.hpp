#pragma once
#include "types.hpp"

class object {
protected:
	position pos;
	shape shape; 
	COLOR color;
public:
	object(position initPos = { 0,0 }, ::shape initShape = shape::CIRCLE, COLOR initColor = YELLOW);
public:
	void SetPosition(const position& newPos);
	void SetColor(COLOR color);
	auto GetPosition() const -> const position&;
	auto GetShape() const -> const ::shape&; 
public:
	virtual void Draw() = 0;
};

class movable :public object {
protected:
	direction dir;
	int speed;
public:
	movable(position initPos = { 0,0 }, ::shape initShape = shape::CIRCLE, COLOR initColor = YELLOW, direction initDir = direction::NORTH, int initSpd = 1);
public:
	void Move();
	void Move(const direction& facing);
	auto GetDirection() const -> direction;
	void SetDirection(direction newDir);
	void SetSpeed(int newSpd);
};