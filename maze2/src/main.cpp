// maze2.cpp: 定义应用程序的入口点。
//

#include <graphics.h>
#include <iostream>
#include "datatypes.hpp"
using namespace std;

void DrawPlayer(const player& p1);
void DrawMap(const map& map);
int main()
{
	initgraph(800, 400);
	player p1(40, 20);
	vector<vector<int>> mat(40, vector<int>(80, 0));
	for (int i = 0; i < 40; i++) {
		mat[i][40] = 1;
	}
	map m1(mat);
	BeginBatchDraw();
	while (true) {
		cleardevice();
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
		Sleep(50);
		p1.SetDirection(direction::STAY);
		DrawPlayer(p1);
		DrawMap(m1);
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}

void DrawPlayer(const player& p1) {
	setfillcolor(YELLOW);
	fillcircle(p1.GetX() * 10, p1.GetY() * 10, 10);
}

void DrawMap(const map& map) {
	setfillcolor(WHITE);
	for (int i = 0; i < map.m; i++) {
		for (int j = 0; j < map.n; j++) {
			if (!map.IsPathway(i, j)) {
				fillrectangle(i * 10 - 5, j * 10 - 5, i * 10 + 5, j * 10 + 5);
			}
		}
	}
}