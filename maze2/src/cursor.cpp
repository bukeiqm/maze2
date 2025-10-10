#include "cursor.hpp" 

cursor::cursor(const vector<message>& initMsg, int index) : object({0,0},shape::CURSOR), options(initMsg), index(index) {
	SetColor(GREEN);
}

ui::ui(const vector<message>& initMsgs) : cursor(initMsgs), msgs(initMsgs), title("Untitled", { 350, 180 }) {

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