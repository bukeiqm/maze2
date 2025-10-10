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
const int rectSize = 5;

enum class direction {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	NONE
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
public:
	int x, y;
	position(int x = 0,int y = 0):x(x),y(y){}
public:
	bool operator==(const position& other) const;
	auto operator=(const position& other) -> position&;
	auto Offset(direction dir, int step = 1) const -> const position& ;
};



class message {
private:
	position pos;
	string text;
	font msgType;
	int fontSize;
	unsigned int fontColor;
	string fontStyle;
public:
	message(string s, position pos = { 0,0 }, font type = font::TEXT);
public:
	void Draw();
	auto GetText() const -> const string&;
	auto GetPosition() const -> const position&;
public:
	const message& operator=(const message& other);
};