// maze2.cpp: 定义应用程序的入口点。
//

#include <graphics.h>
#include <iostream>
#include "datatypes.hpp"
#include "UI.hpp"
#include "player.hpp"
#include "map.hpp"
#include "trap.hpp"
#include <random>
//#include "drawingfunc.hpp"
using namespace std;

vector<vector<int>> map1(40, vector<int>(80));

void RandomMap() {
	for (int i = 0; i < 100; i++) {
		int column = rand() % 80;
		int row = rand() % 40;
		map1[row][column] = true;
	}
}

int main()
{
	initgraph(800, 400);

	RandomMap();

	BeginBatchDraw();

	player p1;

	p1.SetPosition({ 40,20 });

	message msg("test", { 400,200 });

	map realMap(map1);

	setbkcolor(LIGHTGRAY);

	while (true) {

		if (GetAsyncKeyState('A')) {
			p1.SetDirection(direction::WEST);
			if(!p1.IsJammed(map1))
			p1.Move(direction::WEST);
		}
		if (GetAsyncKeyState('D')) {
			p1.SetDirection(direction::EAST);
			if (!p1.IsJammed(map1))
			p1.Move(direction::EAST);
		}
		if (GetAsyncKeyState('W')) {
			p1.SetDirection(direction::NORTH);
			if (!p1.IsJammed(map1))
			p1.Move(direction::NORTH);
		}
		if (GetAsyncKeyState('S')) {
			p1.SetDirection(direction::SOUTH);
			if (!p1.IsJammed(map1))
			p1.Move(direction::SOUTH);;
		}

		realMap.UpdateCharted(p1.GetPosition());

		cleardevice();
		p1.Draw();
		realMap.Draw(true);
		msg.Draw();

		FlushBatchDraw();
	}

	while (!GetAsyncKeyState(VK_ESCAPE));

	Sleep(500);

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