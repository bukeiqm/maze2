// maze2.cpp: 定义应用程序的入口点。
//

#include "graphics.h"
#include <iostream>
#include "type.hpp"
#ifndef TEXTURE_H
#include "texture.h"
#endif
using namespace std;

void DrawObj(const object& obj) {
	pos position = obj.GetPosition();
	hitbox vol = obj.GetHitbox();
	int left, right, top, bottom;
	int x = position.x, y = position.y;
	int width = vol.width, length = vol.length;
	left = x - width / 2, right = x + width / 2;
	top = y - length / 2, bottom = y + length / 2;
	int color = static_cast<int>(obj.GetColor());
	setfillcolor(color);
	fillrectangle(left, top, right, bottom);
}

int main()
{
	initgraph(800, 400);
	colors color = colors::white;
	pos XY = { 400,200 };
	hitbox vol = { 20,10,10 };
	stats statv = { 10,10,10,0 };
	object test(XY,vol,statv,color);
	while (true) {
		DrawObj(test);
	}
	setfillcolor(WHITE);
	getchar();
	return 0;
}
