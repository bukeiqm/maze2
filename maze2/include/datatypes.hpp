#pragma once
#include<vector>
#include<string>
using std::vector;
using std::string;

class player;
class map;
class trap;
enum class direction;
enum class font;

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
	OPTION
};

struct position {
	int x, y;
	position(int x = 0,int y = 0):x(x),y(y){}
	bool operator==(const position& other)const { return x == other.x && y == other.y; }
	const position& dev(direction dir, int step = 1);
};

struct message {
	position pos;
	string text;
	font msgType;
	message(string s, position pos = { 0,0 }, font type = font::TEXT) :text(s), pos(pos), msgType(type) {};
};






/*

	*/