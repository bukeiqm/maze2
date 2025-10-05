#include "drawingfunc.hpp"

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
	ui usr = InitUIp();
	BeginBatchDraw();
	while (true) {

		Sleep(50);

		cleardevice();
		DrawUI(usr);
		FlushBatchDraw();
	}
	EndBatchDraw();
}

ui InitUIp() {
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
	return usr;
}

void DrawUI(const ui& usr) {
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
}