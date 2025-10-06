// maze2.cpp: 定义应用程序的入口点。
//

#include <graphics.h>
#include <iostream>
#include "types.hpp"
#include "cursor.hpp"
#include "player.hpp"
#include "map.hpp"
#include "trap.hpp"
#include <random>
using namespace std;

vector<vector<int>> map1(40, vector<int>(80));
int mapSelect = 0;
bool fogMode = false;

void Hello();
void SelectMode();
void SelectMap();
void Play();

int main()
{
	srand(time(0));
	initgraph(800, 400);

	BeginBatchDraw();

	Hello();

	while (!GetAsyncKeyState(VK_ESCAPE));

	Sleep(500);

	EndBatchDraw();
	exit(0);
	return 0;
}

void Hello() {
	message msg("Start Game", { 350, 150 }), msg2("Select Mode", { 350, 180 }), msg3("Select Map", { 350, 210, });

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	msgs.push_back(msg3);
	ui cur(msgs);
	cur.AddTitle(message("Maze Game", { 350, 120 }, font::TITLE));
	while (true) {
		cleardevice();
		cur.Draw();
		FlushBatchDraw();
		int option = cur.WhichOption();
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
			switch (option) {
			case 0:Play(); break;
			case 1:SelectMode(); break;
			case 2:SelectMap(); break;
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
		if (GetAsyncKeyState(VK_UP)) {
			cur.CursorUp();
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			cur.CursorDown();
		}
		Sleep(100);
	}
}

void SelectMode() {
	Sleep(100);
	message msg("on", { 350, 150 }), msg2("off", { 350, 180 });

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	ui cur(msgs);
	cur.AddTitle(message("Fog Mode:", { 330, 120 }, font::TITLE));
	while (true) {
		cleardevice();
		cur.Draw();

		if (fogMode) {
			message msg1("On", { 400,120 });
			msg1.Draw();
		}
		else {
			message msg1("Off", { 400,120 });
			msg1.Draw();
		}

		FlushBatchDraw();
		int option = cur.WhichOption();
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
			switch (option) {
			case 0:fogMode = true; break;
			case 1:fogMode = false; break;
			}
		}

		if (GetAsyncKeyState(VK_LEFT)) return;

		if (GetAsyncKeyState(VK_UP)) {
			cur.CursorUp();
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			cur.CursorDown();
		}
		Sleep(100);
	}
}

void SelectMap() {
	Sleep(100);
	message msg("m1", { 350, 150 }), msg2("m2", { 350, 180 }), msg3("m3", { 350, 210, });

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	msgs.push_back(msg3);
	ui cur(msgs);
	cur.AddTitle(message("Map :", { 330, 120 }, font::TITLE));
	while (true) {
		cleardevice();
		cur.Draw();

		message msg("map" + to_string(mapSelect), { 370,120 });
		msg.Draw();

		FlushBatchDraw();
		int option = cur.WhichOption();
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
			switch (option) {
			case 0:mapSelect = 0; break;
			case 1:mapSelect = 1; break;
			case 2:mapSelect = 2; break;
			}
		}

		if (GetAsyncKeyState(VK_LEFT)) return;

		if (GetAsyncKeyState(VK_UP)) {
			cur.CursorUp();
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			cur.CursorDown();
		}
		Sleep(100);
	}
}

void Play() {
	player p1;

	map1[30][20] = 3;
	map1[1][10] = 2;

	map realMap(map1);

	trap trap1;

	p1.SetPosition(realMap.GetStart());

	while (true) {
		Sleep(100);
		if (GetAsyncKeyState('A')) {
			p1.SetDirection(direction::WEST);
			if (!p1.IsJammed(map1))
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

		if (GetAsyncKeyState(VK_ESCAPE)) exit(0);

		if (GetAsyncKeyState(VK_BACK)) return;

		if (GetAsyncKeyState('X'))
		{
			cout << "Player currently at:" << p1.GetPosition().x << "," << p1.GetPosition().y << endl;
		}

		if (GetAsyncKeyState('B')) {
			cout << "Destination at:" << realMap.GetDestination().x << "," << realMap.GetDestination().y << endl;
		}

		realMap.UpdateCharted(p1.GetPosition());
		trap1.DoDamageTo(p1);
		trap1.Move(realMap, p1);
		trap1.Revive();
		cleardevice();
		p1.Draw();
		trap1.Draw();
		if (p1.AtDest(realMap)) outtextxy(400, 200, "game win");
		realMap.Draw(fogMode);
		FlushBatchDraw();
	}
}