#pragma once
#include <graphics.h>
#include<vector>
#include<string>
#include "enumclasses.h"

using std::vector;
using std::string;

typedef unsigned int COLOR;

struct position {
	int x, y;
	position(int x = 0,int y = 0):x(x),y(y){}
	bool operator==(const position& other) const;
	auto Offset(direction dir, int step = 1) -> const position& ;
};

struct message {
	position pos;//,别忘了消息有坐标，可以设置颜色和大小
	string text;
	font msgType;
	message(string s, position pos = { 0,0 }, font type = font::TEXT) :text(s), pos(pos), msgType(type) {};
};

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
	void Move(const direction& facing);
	void SetDirection(direction newDir);
	void SetSpeed(int newSpd);
};


/*

	*/