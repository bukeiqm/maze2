#include "datatypes.hpp"

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