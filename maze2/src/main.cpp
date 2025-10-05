// maze2.cpp: 定义应用程序的入口点。
//

#include <graphics.h>
#include <iostream>
#include "datatypes.hpp"
#include "UI.hpp"
#include "player.hpp"
#include "map.hpp"
#include "trap.hpp"
using namespace std;

void DrawPlayer(const player& p1);
void DrawMap(const map& map);
void DrawUserUI();
vector<vector<int>> map1{};

int main()
{
	initgraph(800, 400);
	player p1(40, 20);
	vector<vector<int>> mat(40, vector<int>(80, 0));
	map m1(mat);
	m1.InitMap();
	m1.SetDestination(5, 10);
	BeginBatchDraw();
	DrawUserUI();
	Sleep(500);
	while (true) {
		if (GetAsyncKeyState('A')) {
			p1.SetDirection(direction::WEST);
		}
		if (GetAsyncKeyState('D')) {
			p1.SetDirection(direction::EAST);
		}
		if (GetAsyncKeyState('W')) {
			p1.SetDirection(direction::NORTH);
		}
		if (GetAsyncKeyState('S')) {
			p1.SetDirection(direction::SOUTH);
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			closegraph();
			break;
		}
		if(!p1.IsJammed(m1))	p1.Move();
		p1.SetDirection(direction::STAY);
		Sleep(100);
		cleardevice();
		DrawPlayer(p1);
		DrawMap(m1);
		if (p1.AtDest(m1)) outtextxy(400, 200, "Game Win");
		FlushBatchDraw();
	}
	EndBatchDraw();
	exit(0);
	return 0;
}

void DrawPlayer(const player& p1) {
	setfillcolor(YELLOW);
	fillcircle(p1.GetX() * 10, p1.GetY() * 10, 10);
}

void DrawMap(const map& map) {
	setfillcolor(WHITE);
	const int scaleFactor = 10;
	const int posAnchor = 5;
	const int rectSize = 5;
	for (int i = 0; i < map.n; i++) {
		for (int j = 0; j < map.m; j++) {
			if (!map.IsPathway(i, j)) {
				fillrectangle(posAnchor + i * scaleFactor - rectSize,
					posAnchor + j * scaleFactor - rectSize,
					posAnchor + i * scaleFactor + rectSize,
					posAnchor + j * scaleFactor + rectSize);
			}
		}
	}
	position dest = map.GetDestination();
	setfillcolor(RED);
	fillcircle(dest.x * 10, dest.y * 10, 10);
}

void DrawUserUI() {
	setfillcolor(WHITE);
	ui usr;
	usr.AppendBar(350, 120, "Maze Game");
	usr.AppendBar(350, 150, "Start Game");
	usr.AppendBar(350, 180, "Select Mode");
	usr.AppendBar(350, 210, "Select Map");
	usr.AppendBar(350, 240, "Exit Game");
	usr.AddOptionsFromBars(1);
	usr.AddOptionsFromBars(2);
	usr.AddOptionsFromBars(3);
	usr.AddOptionsFromBars(4);
	usr.InitCursor();
	BeginBatchDraw();
	while (true) {
		if (GetAsyncKeyState(VK_UP)) {
			usr.CursorUp();
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			usr.CursorDown();
		}

		if (usr.GetCursorIndex() == 3 && (GetAsyncKeyState(VK_SPACE)||GetAsyncKeyState(VK_RETURN))) {
			exit(0);
		}

		if (usr.GetCursorIndex() == 1 && (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN))) {
			break;
		}

		Sleep(50);

		cleardevice();
		for (auto i : usr.GetTexts()) {
			const message& msg = i;
			const position& pos = i.pos;
			const string& text = i.text;
			const int& x = pos.x, y = pos.y;
			outtextxy(x, y, text.c_str());
		}
		const position& curPos = usr.GetCursorPosition();
		const int& x = curPos.x, y = curPos.y;
		setfillcolor(GREEN);
		fillcircle(x - 20, y + 10, 5);
		FlushBatchDraw();
	}
	EndBatchDraw();
}

/*
		outtextxy(350, 120, "Maze Game");
		outtextxy(350, 150, "Start Game");
		outtextxy(350, 180, "Select Mode");
		outtextxy(350, 210, "Select Map");
*/