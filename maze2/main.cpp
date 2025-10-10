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
#include <functional>
using namespace std;

//vector<vector<int>> map1(40, vector<int>(64));
int mapSelect = 0;
bool fogMode = false;

vector<vector<int>> GenerateRandomMap(int width, int height);
void Hello();
void SelectMode();
void SelectMap();
void Play();
void Hint();

//初始地图
vector<vector<int>> maze1 = {
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 2, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
 {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
 {1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
 {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
 {1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
 {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
 {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
 {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
 {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
 {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
 {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
 {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

vector<vector<int>> maze2 = {
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
 {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
 {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
 {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
 {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
 {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
 {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct GameConfig {
	int mapSelect = 0;
	bool fogMode = false;
};
GameConfig config;

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

// 通用菜单选择函数：返回用户选择的索引（-1表示返回）
int ShowSelectionMenu(const string& title, const vector<string>& options, int which) {
	vector<message> msgs;
	for (int i = 0; i < options.size(); ++i) {
		msgs.emplace_back(options[i], position{ 300, 150 + i * 30 }, font::OPTION);
	}
	ui cur(msgs);
	cur.AddTitle(message(title, position{ 250, 120 }, font::OPTION));

	int returnValue = -1;
	// 循环显示菜单，处理用户输入

	string currentValue = msgs[which].GetText();

	int option = which;

	while (true) {
		cleardevice();
		cur.Draw();
		Hint();
		// 显示当前选中值（如"当前地图: map0"）
		if (!currentValue.empty()) {
			message currentMsg(currentValue, position{ 360, 120 }, font::OPTION);
			currentMsg.Draw();
		}
		FlushBatchDraw();

		// 确认选择
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
			option = cur.Which();
			returnValue = option;
			currentValue = msgs[option].GetText();
		}
		// 返回上一级
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_BACK)) {
			break;
		}
		// 上下键切换
		if (GetAsyncKeyState(VK_UP)) cur.CursorUp();
		if (GetAsyncKeyState(VK_DOWN)) cur.CursorDown();
		Sleep(100);
	}

	return returnValue;
}

void Hello() {
	vector<message> msgs = {
		message("Start Game", {270, 150}, font::OPTION),
		message("Settings", {270, 180}, font::OPTION),
		message("Select Map", {270, 210}, font::OPTION)
	};
	ui cur(msgs);
	cur.AddTitle(message("Maze Game", { 230, 90 }, font::TITLE));

	while (true) {
		cleardevice();
		Hint();
		cur.Draw();
		FlushBatchDraw();

		int option = cur.Which();
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
			switch (option) {
			case 0:Sleep(100); Play(); break;
			case 1:Sleep(100); SelectMode(); break;
			case 2:Sleep(100); SelectMap(); break;
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
		if (GetAsyncKeyState(VK_UP)) cur.CursorUp();
		if (GetAsyncKeyState(VK_DOWN)) cur.CursorDown();
		Sleep(100);
	}
}
	
void SelectMode() {
	vector<string> options = { "On", "Off" };
	int res = ShowSelectionMenu("Fog Mode:", options,config.fogMode == false ? 1 : 0);//, config.fogMode ? "On" : "Off"
	if (res != -1) config.fogMode = (res == 0);
}

void SelectMap() {
	vector<string> options = { "m1", "m2", "m3" };
	int res = ShowSelectionMenu("Map :", options, config.mapSelect);//, "map" + to_string(config.mapSelect)
	if (res != -1) config.mapSelect = res;
}


// 初始化陷阱
vector<trap> InitTraps() {
	vector<trap> traps;
	traps.emplace_back(100, 30);
	traps.emplace_back(120, 20);
	traps.emplace_back(50, 30);
	traps.emplace_back(80, 20);
	return traps;
}

// 处理玩家输入
void HandlePlayerInput(player& p) {
	if (GetAsyncKeyState('A')) p.SetDirection(direction::WEST);
	if (GetAsyncKeyState('D')) p.SetDirection(direction::EAST);
	if (GetAsyncKeyState('W')) p.SetDirection(direction::NORTH);
	if (GetAsyncKeyState('S')) p.SetDirection(direction::SOUTH);
}

// 检查游戏状态（胜利/失败）
bool CheckGameState(const player& p, const map& realMap, bool& gameOver) {
	if (p.GetPosition() == realMap.GetDestination()) {
		message gameWin("Game Win", { 240, 150 }, font::TITLE);
		gameWin.Draw();
		gameOver = true;
		return true;
	}
	if (p.GetHealth() <= 0) {
		message gameLose("Game Lost", { 240, 150 }, font::ALARM);
		gameLose.Draw();
		gameOver = true;
		return true;
	}
	return false;
}

void Play() {
	player p1;
	map realMap(maze1);
	// 设置地图
	switch (config.mapSelect) {
	case 0: realMap.SetMap(maze1); break;
	case 1: realMap.SetMap(maze2); break;
	case 2: realMap.SetMap(GenerateRandomMap(64, 40)); break;
	}
	p1.SetPosition(realMap.GetStartPoint());
	auto traps = InitTraps();
	int timer = 50;
	bool gameOver = false;

	while (true) {
		Sleep(100);
		if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
		if (GetAsyncKeyState(VK_BACK)) return;
		if (!gameOver) HandlePlayerInput(p1);

		// 移动逻辑（撞墙不移动）
		if (!gameOver && !realMap.IsWall(p1.GetPosition().Offset(p1.GetDirection()))) {
			p1.Move();
		}

		// 调试信息输出
		if (GetAsyncKeyState('X')) {
			cout << "Player at: " << p1.GetPosition().x << "," << p1.GetPosition().y << endl;
		}
		if (GetAsyncKeyState('B')) {
			cout << "Destination at: " << realMap.GetDestination().x << "," << realMap.GetDestination().y << endl;
		}

		realMap.UpdateCharted(p1.GetPosition());
		cleardevice();

		p1.SetDirection(direction::NONE); // 重置方向

		// 陷阱逻辑
		
		
	for (auto& t : traps) {
		if (t.GetDuration() <= 0) {
			t.SetDurationDiff(t.GetDuration() > -100 ? -1 : 200);
		}
		if (!t.IsValid()) continue;
		if (t.GetPosition() == p1.GetPosition()) {
			p1.SetHealthDiff(-t.GetDamage());
			t.SetValidity(false);
		}
		if (!gameOver && timer-- == 10) {
			timer = 50;
			// 随机位置刷新陷阱（简化逻辑）
			position mapSize = realMap.GetSize();
			int x = rand() % mapSize.x, y = rand() % mapSize.y;
			if (!realMap.IsWall({ x, y }) && !realMap.IsDestination({ x, y }) && p1.GetPosition() != position{ x, y }) {
				t.SetPosition({ x, y });
				t.SetDurationDiff(-1);
			}
		}
		t.Draw();
	}
		
		// 绘制地图和玩家
		realMap.Draw(config.fogMode);
		p1.Draw();
		fillrectangle(640, 0, 650, 400); // 分隔线
		outtextxy(660, 90, ("Health:" + to_string(p1.GetHealth())).c_str());

		// 检查游戏状态
		CheckGameState(p1, realMap, gameOver);
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

/*
	// 定义菜单配置结构体，用于传递菜单参数
struct MenuConfig {
	string title; // 菜单标题
	vector<string> options; // 选项列表
	function<void(int)> onSelect; // 选中选项后的回调函数
	position titlePos; // 标题位置
	position firstOptionPos; // 第一个选项的位置
};

// 通用菜单函数，通过配置参数实现不同菜单功能
void ShowMenu(const MenuConfig& config) {
	vector<message> msgs;
	int yOffset = 0;
	// 创建选项消息
	for (const auto& opt : config.options) {
		msgs.emplace_back(opt,
			position{ config.firstOptionPos.x, config.firstOptionPos.y + yOffset },
			font::OPTION);
		yOffset += 30; // 选项间距
	}
	ui cur(msgs);
	cur.AddTitle(message(config.title, config.titlePos, font::OPTION));

	while (true) {
		cleardevice();
		cur.Draw();
		Hint(); // 复用提示信息
		FlushBatchDraw();

		int option = cur.WhichOption();
		// 确认选中
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
			config.onSelect(option); // 调用回调处理选中逻辑
		}
		// 返回上一级
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_BACK)) return;
		// 光标移动
		if (GetAsyncKeyState(VK_UP)) cur.CursorUp();
		if (GetAsyncKeyState(VK_DOWN)) cur.CursorDown();

		Sleep(100);
	}
}
void SelectMap() {
	MenuConfig config;
	config.title = "Map :";
	config.titlePos = { 240, 120 };
	config.options = { "m1", "m2", "m3" };
	config.firstOptionPos = { 300, 150 };
	// 选中后的回调（设置mapSelect）
	config.onSelect = [&](int option) {
		mapSelect = option;
		};
	ShowMenu(config); // 复用通用菜单逻辑
}
*/