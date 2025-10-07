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

vector<vector<int>> GenerateRandomMap(int width, int height);
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
	message msg("Start Game", { 270, 150 }, font::OPTION), msg2("Settings", { 270, 180 }, font::OPTION),
		msg3("Select Map", { 270, 210, }, font::OPTION);

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	msgs.push_back(msg3);
	ui cur(msgs);
	cur.AddTitle(message("Maze Game", { 230, 90 }, font::TITLE));
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
	message msg("On", { 300, 150 }, font::OPTION), msg2("Off", { 300, 180 }, font::OPTION);

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	ui cur(msgs);
	cur.AddTitle(message("Fog Mode:", { 250, 120 }, font::OPTION));
	while (true) {
		cleardevice();
		cur.Draw();
		Hint();

		if (fogMode) {
			message msg1("On", { 360,120 },font::OPTION);
			msg1.Draw();
		}
		else {
			message msg1("Off", { 360,120 },font::OPTION);
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
	message msg("m1", { 300, 150 }, font::OPTION), msg2("m2", { 300, 180 }, font::OPTION), msg3("m3", { 300, 210 }, font::OPTION);

	vector<message> msgs;
	msgs.push_back(msg);
	msgs.push_back(msg2);
	msgs.push_back(msg3);
	ui cur(msgs);
	cur.AddTitle(message("Map :", { 240, 120 }, font::OPTION));
	while (true) {
		cleardevice();
		cur.Draw();
		Hint();

		message msg("map" + to_string(mapSelect), { 330,120 }, font::OPTION);
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

	p1.SetPosition({ 32, 20 });

	map realMap(map1);

	if(mapSelect == 2) realMap.SetMap(GenerateRandomMap(64, 40));

	realMap.SetStart({ 32,20 });

	vector<trap> traps;

	trap trap1(100, 30), trap2(120, 20), trap3(50, 30);

	traps.emplace_back(trap1); traps.emplace_back(trap2); traps.emplace_back(trap3);

	traps.emplace_back(trap(80, 20));

	p1.SetPosition(realMap.GetStart());

	while (true) {
		Sleep(100);
		if (GetAsyncKeyState('A')) {
			p1.SetDirection(direction::WEST);
			if (!p1.IsJammed(realMap))
				p1.Move(direction::WEST);
		}
		if (GetAsyncKeyState('D')) {
			p1.SetDirection(direction::EAST);
			if (!p1.IsJammed(realMap))
				p1.Move(direction::EAST);
		}
		if (GetAsyncKeyState('W')) {
			p1.SetDirection(direction::NORTH);
			if (!p1.IsJammed(realMap))
				p1.Move(direction::NORTH);
		}
		if (GetAsyncKeyState('S')) {
			p1.SetDirection(direction::SOUTH);
			if (!p1.IsJammed(realMap))
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
		for (trap& i : traps) {
			i.DoDamageTo(p1);
			i.Move(realMap, p1);
			i.Revive();
			i.Draw();
		}

		realMap.Draw(fogMode);
		p1.Draw();
		setfillcolor(WHITE);
		fillrectangle(640, 0, 650, 400);
		outtextxy(660, 90, ("Health:" + to_string(p1.GetHealth())).c_str());
		if (p1.AtDest(realMap)) {
			p1.SetSpeed(0);
			message gameWin("Game Win", { 300, 150 }, font::TITLE);
			gameWin.Draw();
		}
		if (p1.GetHealth() <= 0) {
			p1.SetSpeed(0);
			message gameLose("Game Lost", { 240,150 }, font::ALARM);
			gameLose.Draw();
		}

		
		FlushBatchDraw();
	}
}

void Hint() {
	setfillcolor(WHITE);
	fillrectangle(640, 0, 650, 400);
	message hint1("Up/Down to Switch", { 660,120 }), hint2("Left/Bksps to be Back", { 660,150 }), hint3("Spas/Retn to Confirm", { 660,180 }),
		hint4("Esc to Exit", { 660,210 });
	hint1.Draw(); hint2.Draw(), hint3.Draw(), hint4.Draw();
}


bool IsValid(int x, int y, int width, int height, const vector<vector<int>>& mat) {
	return x > 0 && x < width - 1 && y > 0 && y < height - 1 && mat[y][x] == 1;
}

#include <stack>

vector<vector<int>> GenerateRandomMap(int width, int height) {
	// 确保宽高为奇数（便于墙壁和通路排列）
	if (width % 2 == 0) width++;
	if (height % 2 == 0) height++;
	if (width < 5) width = 5; // 最小宽度
	if (height < 5) height = 5; // 最小高度

	// 初始化地图：全部为墙壁（1）
	vector<vector<int>> mat(height, vector<int>(width, 1));
	// 方向数组：上下左右
	vector<position> dirs = { {0, -2}, {0, 2}, {-2, 0}, {2, 0} };

	// 随机数生成器
	random_device rd;
	mt19937 g(rd());

	// 起点位置（左上角附近，确保是奇数坐标）
	int startX = 1, startY = 1;
	mat[startY][startX] = 0; // 起点先设为通路
	stack<position> s;
	s.push({ startX, startY });

	// DFS挖路
	while (!s.empty()) {
		position current = s.top();
		s.pop();

		// 随机打乱方向
		vector<position> shuffledDirs = dirs;
		shuffle(shuffledDirs.begin(), shuffledDirs.end(), g);

		for (auto& dir : shuffledDirs) {
			int nx = current.x + dir.x; // 新位置（间隔一个墙壁）
			int ny = current.y + dir.y;

			if (IsValid(nx, ny, width, height, mat)) {
				// 挖通当前位置到新位置的墙壁（中间的单元格）
				mat[ny][nx] = 0; // 新位置设为通路
				mat[current.y + dir.y / 2][current.x + dir.x / 2] = 0; // 中间墙壁设为通路
				s.push({ nx, ny }); // 继续处理新位置
			}
		}
	}

	// 设置起点（2）和终点（3）
	mat[startY][startX] = 2; // 起点

	// 找离起点最远的通路作为终点
	position farthest = { startX, startY };
	int maxDist = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (mat[y][x] == 0) { // 只考虑通路
				int dist = abs(x - startX) + abs(y - startY); // 曼哈顿距离
				if (dist > maxDist) {
					maxDist = dist;
					farthest = { x, y };
				}
			}
		}
	}
	mat[farthest.y][farthest.x] = 3; // 终点

	return mat;
}