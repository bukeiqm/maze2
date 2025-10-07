#pragma once
#include <graphics.h>
#include<vector>
#include<string>

using std::vector;
using std::string;

typedef unsigned int COLOR;

const int blockSize = 10;
const int scaleFactor = blockSize;
const int posAnchor = blockSize / 2;
const int size = blockSize / 2;

enum class direction {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	STAY
};

enum class font {
	TITLE,
	SUBTITLE,
	TEXT,
	OPTION,
	ALARM
};

enum class shape {
	TEXT,
	CURSOR,
	RECT,
	CIRCLE,
	SQUARE,
	ELLIPSE
};

struct position {
	int x, y;
	position(int x = 0,int y = 0):x(x),y(y){}
	bool operator==(const position& other) const;
	position& operator=(const position& other);
	auto Offset(direction dir, int step = 1) -> const position& ;
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

class message : public object {
public:
	string text;
	font msgType;
	int fontSize;
	unsigned int fontColor;
	string fontStyle;
public:
	message(string s, position pos = { 0,0 }, font type = font::TEXT);
public:
	void Draw() override;
	const message& operator=(const message& other);
};