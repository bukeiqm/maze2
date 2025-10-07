// maze2.cpp: 定义应用程序的入口点。
//

#include <graphics.h>
#include <iostream>
#include <queue>
#include "types.hpp"
#include "cursor.hpp"
#include "player.hpp"
#include "map.hpp"
#include "trap.hpp"
#include <random>
using namespace std;

vector<vector<int>> map1(40, vector<int>(64));
int mapSelect = 0;
bool fogMode = false;

void Hello();
void SelectMode();
void SelectMap();
void Play();
void Hint();

int main()
{
	srand(time(0));
	initgraph(800, 400);

	setfillcolor(WHITE);
	fillrectangle(640, 0, 650, 400);

	BeginBatchDraw();

	Hello();

	while (!GetAsyncKeyState(VK_ESCAPE));

	Sleep(500);

	EndBatchDraw();
	exit(0);
	return 0;
}

void Hello() {
	message msg("Start Game", { 270, 150 }), msg2("Select Mode", { 270, 180 }), msg3("Select Map", { 270, 210, });

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	msgs.push_back(msg3);
	ui cur(msgs);
	cur.AddTitle(message("Maze Game", { 270, 120 }, font::TITLE));
	while (true) {
		cleardevice();
		Hint();
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
	message msg("on", { 270, 150 }), msg2("off", { 270, 180 });

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	ui cur(msgs);
	cur.AddTitle(message("Fog Mode:", { 250, 120 }, font::TITLE));
	while (true) {
		cleardevice();
		cur.Draw();
		Hint();

		if (fogMode) {
			message msg1("On", { 320,120 });
			msg1.Draw();
		}
		else {
			message msg1("Off", { 320,120 });
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

		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_BACK)) return;

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
	message msg("m1", { 270, 150 }), msg2("m2", { 270, 180 }), msg3("m3", { 270, 210 });

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	msgs.push_back(msg3);
	ui cur(msgs);
	cur.AddTitle(message("Map :", { 260, 120 }, font::TITLE));
	while (true) {
		cleardevice();
		cur.Draw();
		Hint();

		message msg("map" + to_string(mapSelect), { 300,120 });
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

		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_BACK)) return;

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

	//vector<trap> traps;

	trap trap1, trap2, trap3;

	//traps.push_back(trap1); traps.push_back(trap2); traps.push_back(trap3);

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



		cleardevice();
		/*
		* for (auto i : traps) {
			i.DoDamageTo(p1);
			i.Move(realMap, p1);
			i.Revive();
			i.Draw();
		}
		*/
		trap1.DoDamageTo(p1); trap2.DoDamageTo(p1);
		trap1.Move(realMap, p1); trap2.Move(realMap, p1);
		trap1.Revive(); trap2.Revive();
		trap1.Draw(); trap2.Draw();

		p1.Draw();
		setfillcolor(WHITE);
		fillrectangle(640, 0, 650, 400);
		outtextxy(660, 90, ("Health:" + to_string(p1.GetHealth())).c_str());
		if (p1.AtDest(realMap)) {
			message gameWin("Game Win", { 300, 150 }, font::TITLE);
			gameWin.Draw();
		}
		if (p1.GetHealth() <= 0) {
			message gameLose("Game Lost", { 240,150 }, font::ALARM);
			gameLose.Draw();
		}

		realMap.Draw(fogMode);
		FlushBatchDraw();
	}
}

void Hint() {
	setfillcolor(WHITE);
	fillrectangle(640, 0, 650, 400);
	message hint1("Up/Down to Switch", { 660,120 }), hint2("Left/Bksps Back", { 660,150 }), hint3("Spas/Retn to Confirm", { 660,180 }),
		hint4("Esc to Exit", { 660,210 });
	hint1.Draw(); hint2.Draw(), hint3.Draw(), hint4.Draw();
}