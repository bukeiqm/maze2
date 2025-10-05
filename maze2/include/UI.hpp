#include "datatypes.hpp"
class cursor {
private:
	position pos;
	vector<position> options;
	int index;
	friend class ui;
public:
	cursor(position pos = { 0,0 }, int index = 0);
public:
	void SetCursorPos(int x, int y);
	void SetCursorPos(position pos);
	void AddOptions(position pos);
	void CursorUp(int step = 1);
	void CursorDown(int step = 1);
	auto Which() -> int;
};



class ui {
private:
	vector<message> msgs;
	cursor cursor;
public:
	void AppendBar(message msg);
	void AppendBar(position pos, string text);
	void AppendBar(int x, int y, string text);
	void AppendBar(string text, font txtType);
	void AddOptionsFromBars(int index);
	void InitCursor();
	void CursorUp();
	void CursorDown();
	auto WhichOption() -> int;
	auto GetTexts() const -> decltype(msgs);
	auto GetCursor() -> decltype(cursor);
	auto GetCursorPosition() const -> position;
	auto GetCursorIndex() -> int;
};

//游标类维护一个指针，用于指向选项，当绘图函数，或者游戏机制需要时返回这个指针
//选项和普通文本以及标题同样作为消息储存在表中，但有额外的表维护其在消息表中的位置以及选项的编号
//于是游标只要指向这个表，就能指向选项，通过表，选项能够被正确引用
//选项的显示机制与消息相同，何不算一种技术债呢
//其实无所谓选项啊，我把逻辑写在其他的地方就好了
//问题其实在于，界面文字格式不统一
//类与结构体只定义了信息的存储，将这些信息输出则是函数的工作
//事到如今居然还会被库捅刀子
//其实选项应该不在文字的概念里面
//将所有选项的坐标放在一个表里，让游标在不同坐标间移动就好了

//游标只负责指向选项，移动交给外部