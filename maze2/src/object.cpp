#include "object.hpp"

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
	
	int x = pos.x;
	int y = pos.y;

	setfillcolor(color);
	switch (shape) {
	case shape::CIRCLE:
		fillcircle(posAnchor + x * scaleFactor, posAnchor + y * scaleFactor, rectSize);
		break;
	case shape::RECT:
		fillrectangle(posAnchor + x * scaleFactor - rectSize,
			posAnchor + y * scaleFactor - rectSize,
			posAnchor + x * scaleFactor + rectSize,
			posAnchor + y * scaleFactor + rectSize);
		break;
	case shape::CURSOR:
		fillcircle(x - blockSize * 2, y + 12, rectSize);
		break;
	default:
		break;
	}
}

object::object(position initPos, ::shape initShape, COLOR initColor) :pos(initPos), shape(initShape), color(initColor) {

}



movable::movable(position initPos, ::shape initShape, COLOR initColor, direction initDir, int initSpd) :object(initPos, initShape, initColor), dir(initDir), speed(initSpd) {

}

void movable::Move() {
	Move(dir);
}

void movable::Move(const direction& facing) {
	pos = pos.Offset(facing, speed);
}

auto movable::GetDirection() const -> direction {
	return dir;
}

void movable::SetDirection(direction newDir) {
	dir = newDir;
}

void movable::SetSpeed(int newSpeed) {
	speed = newSpeed;
}