#include "types.hpp"

auto position::Offset(direction dir, int step) -> const position& {
	int xp = x, yp = y;
	switch (dir) {
	case direction::NORTH:yp -= step; break;
	case direction::EAST:xp += step; break;
	case direction::SOUTH:yp += step; break;
	case direction::WEST:xp -= step; break;
	}
	return position(xp, yp);
}

bool position::operator==(const position& other) const {
	return x == other.x && y == other.y;
}

position& position::operator=(const position& other)  {
	x = other.x;
	y = other.y;
	return *this;
}

object::object(position initPos, ::shape initShape, COLOR initColor) :pos(initPos), shape(initShape), color(initColor) {

}

void object::SetPosition(const position& newPos) {
	pos = newPos;
}

void object::SetColor(COLOR newColor) {
	color = newColor;
}

auto object::GetPosition() const -> const position& {
	return pos;
}

auto object::GetShape() const -> const ::shape& {
	return shape;
}

void object::Draw() {
	const int scaleFactor = 10;
	const int posAnchor = 5;
	const int size = 5;

	int x = pos.x;
	int y = pos.y;

	setfillcolor(color);
	switch (shape) {
	case shape::CIRCLE:
		fillcircle(posAnchor + x * scaleFactor, posAnchor + y * scaleFactor, size);
		break;
	case shape::RECT:
		fillrectangle(posAnchor + x * scaleFactor - size,
			posAnchor + y * scaleFactor - size,
			posAnchor + x * scaleFactor + size,
			posAnchor + y * scaleFactor + size);
		break;
	case shape::CURSOR:
		fillcircle(x - 20, y + 8, size);
		break;
	default:
		break;
	}
}

movable::movable(position initPos, ::shape initShape, COLOR initColor, direction initDir, int initSpd) :object(initPos, initShape, initColor), dir(initDir), speed(initSpd) {

}

void movable::Move(const direction& facing) {
	pos = pos.Offset(facing, speed);
}

void movable::SetDirection(direction newDir) {
	dir = newDir;
}

void movable::SetSpeed(int newSpeed) {
	speed = newSpeed;
}

message::message(string s, position pos, font type) :object(pos), text(s), msgType(type) {
	switch (type) {
	case font::OPTION:
		fontSize = 24; fontStyle = "Gabriola"; break;
	case font::SUBTITLE:
		fontSize = 30, fontStyle = "Corbel"; break;
	case font::TEXT:
		fontSize = 18, fontStyle = "Cambria"; break;
	case font::TITLE:
		fontSize = 45, fontStyle = "Consolas"; break;
	case font::ALARM:
		fontSize = 60, fontStyle = "Impact"; break;
	default:
		fontSize = 24, fontStyle = "Arial"; break;
	}

	if (type == font::ALARM) {
		fontColor = RED;
	}
	else {
		fontColor = LIGHTBLUE;
	}
}

void message::Draw() {
	const int x = pos.x, y = pos.y;
	const unsigned int currentColor = gettextcolor();
	LOGFONT currentFont;
	gettextstyle(&currentFont);
	settextcolor(fontColor);
	settextstyle(fontSize, 0, fontStyle.c_str());
	outtextxy(x , y , text.c_str());
	settextcolor(currentColor);
	settextstyle(&currentFont);
}

const message& message::operator=(const message& other) {
	pos = other.pos;
	text = other.text;
	return *this;
}