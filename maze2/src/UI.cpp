#include "UI.hpp" 

void cursor::SetCursorPos(position pos) {
	this->pos = pos;
}

void cursor::SetCursorPos(int x, int y) {
	position temp(x, y);
	pos = temp;
}

void cursor::AddOptions(position pos) {
	options.push_back(pos);
}

void cursor::CursorUp(int step) {
	if (index - step < 0) return;
	index -= step;
}

void cursor::CursorDown(int step ) {
	if (index + step >= options.size()) return;
	index += step;
}

auto cursor::Which() -> int{
	return index;
}

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

void ui::AppendBar(string text, font type) {

}

void ui::AddOptionsFromBars(int index) {
	message msg = msgs[index];
	//cursor.AddOptions(msg.pos);
}

void ui::InitCursor() {
	if (cursor.options.empty()) return;
	cursor.index = 0;
}

void ui::CursorUp() {
	cursor.CursorUp();
	//cursor.SetCursorPos(cursor.pos.dev(direction::NORTH, 30));
}

void ui::CursorDown() {
	cursor.CursorDown();
	//cursor.SetCursorPos(cursor.pos.dev(direction::SOUTH, 30));
}

auto ui::WhichOption() -> int {
	return cursor.Which();
}

auto ui::GetTexts() const -> decltype(msgs) {
	return msgs;
}

auto ui::GetCursor() -> decltype(cursor) {
	return cursor;
}

auto ui::GetCursorPosition() const -> position {
	return cursor.options[cursor.index];
}

auto ui::GetCursorIndex() -> int {
	return cursor.Which();
}

cursor::cursor(position pos, int index):pos(pos),index(index) {}