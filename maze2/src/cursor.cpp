#include "cursor.hpp" 

cursor::cursor(const vector<message>& initMsg, int index) : object({0,0},shape::CURSOR), options(initMsg), index(index) {
	SetColor(GREEN);

}

ui::ui(const vector<message>& initMsgs) : cursor(initMsgs), msgs(initMsgs), title("Untitled", { 350, 180 }) {
	// 已将 title 初始化移至初始化列表，避免默认构造 message
}

void cursor::SetCursorPos(position pos) {
	this->pos = pos;
}

void cursor::SetCursorPos(int x, int y) {
	position temp(x, y);
	pos = temp;
}

void cursor::CursorUp(int step) {
	if (index - step < 0) return;
	index -= step;
	pos = options[index].GetPosition();
}

void cursor::CursorDown(int step) {
	if (index + step >= options.size()) return;
	index += step;
	pos = options[index].GetPosition();
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
void ui::CursorUp() {
	cursor::CursorUp();
}
void ui::CursorDown() {
	cursor::CursorDown();
}
auto ui::WhichOption() -> int {
	return Which();
}

void ui::Draw() {
	cursor::Draw();
	title.Draw();
}

void cursor::Draw() {
	for (auto i : options) {
		i.Draw();
	}
	pos = options[index].GetPosition();
	object::Draw();
}

void ui::AddTitle(const message& title) {
	this->title = title;
}