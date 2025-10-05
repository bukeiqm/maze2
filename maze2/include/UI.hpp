#include "datatypes.hpp"
enum class font {
	TITLE,
	SUBTITLE,
	TEXT,
	OPTION
};

struct message {
	position pos;
	string text;
	font msgType;
	message(string s, position pos = { 0,0 }, font type = font::TEXT) :text(s), pos(pos), msgType(type) {};
};

class ui {
private:
	vector<message> msgs;
	position cursor;
public:
	void AppendBar(message msg);
	void AppendBar(position pos, string text);
	void AppendBar(int x, int y, string text);
	void AppendBar(string text, font txtType);
	void InitCursor();
	void CursorUp();
	void CursorDown();
	auto WhichOption() -> int;
	auto GetTexts() -> decltype(msgs);
	auto GetCursorPos() -> decltype(cursor);
};