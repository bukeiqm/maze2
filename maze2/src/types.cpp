#include "types.hpp"

auto position::Offset(direction dir, int step) const -> const position& {
	switch (dir) {
	case direction::NORTH:return position(x, y - step);
	case direction::EAST:return position(x + step, y);
	case direction::SOUTH:return position(x, y + step);
	case direction::WEST:return position(x - step, y);
	default:return position(x, y);
	}
}

bool position::operator==(const position& other) const {
	return x == other.x && y == other.y;
}

auto position::operator=(const position& other) -> position& {
	x = other.x;y = other.y;
	return *this;
}

const position& message::GetPosition() const {
	return pos;
}

message::message(string s, position pos, font type) :pos(pos), text(s), msgType(type) {
	switch (type) {
	case font::OPTION:
		fontSize = 24; fontStyle = "Candara"; break;
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

auto message::GetText() const -> const string& {
	return text;
}

const message& message::operator=(const message& other) {
	pos = other.pos;
	text = other.text;
	msgType = other.msgType;
	fontColor = other.fontColor;
	fontSize = other.fontSize;
	fontColor = other.fontColor;
	return *this;
}