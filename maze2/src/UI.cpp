#include "UI.hpp"

void ui::AppendBar(message msg) {
	msgs.push_back(msg);
}

void ui::AppendBar(position pos, string text) {
	message msg(text, pos);
	msgs.push_back(msg);
}

void ui::AppendBar(int x, int y, string text) {
	message msg(text, { x,y });
	msgs.push_back(msg);
}

void ui::InitCursor() {
	cursor = msgs[0].pos;
}

void ui::CursorUp() {
	cursor.y -= 30;
}

void ui::CursorDown() {
	cursor.y += 30;
}

auto ui::WhichOption() -> int {
	int index = 0;
	for (auto i : msgs) {
		if (i.pos == cursor) return index;
		index++;
	}
}

auto ui::GetTexts() -> decltype(msgs) {
	return msgs;
}

auto ui::GetCursorPos() -> decltype(cursor) {
	return cursor;
}