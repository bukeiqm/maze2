// maze2.cpp: 定义应用程序的入口点。
//

#include <graphics.h>
#include <iostream>
#include "datatypes.hpp"
#include "UI.hpp"
#include "player.hpp"
#include "map.hpp"
#include "trap.hpp"
#include "drawingfunc.hpp"
using namespace std;

vector<vector<int>> map1{};

int main()
{
	initgraph(800, 400);

	BeginBatchDraw();

	DrawUserUI();

	Sleep(500);

	while (true) {
		
	}
	EndBatchDraw();
	exit(0);
	return 0;
}

/*
	if (GetAsyncKeyState(VK_UP)) {
			usr.CursorUp();
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			usr.CursorDown();
		}

		if (usr.GetCursorIndex() == 3 && (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN))) {
			exit(0);
		}

		if (usr.GetCursorIndex() == 1 && (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN))) {
			break;
		}
*/

/*
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
*/

/*
	player p1(40, 20);

	vector<vector<int>> mat(40, vector<int>(80, 0));

	map m1(mat);
	m1.InitMap();
	m1.SetDestination(5, 10);
*/