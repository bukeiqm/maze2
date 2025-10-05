#include "player.hpp"

player::player(position initPos) : movable(initPos), health(100) {};

bool player::IsJammed(const map& M) {
	return !M.IsPathway(pos.Offset(dir));
}

bool player::AtDest(const map& M) {
	return pos == M.GetDestination();
}

void player::Draw() {
    // 调用父类的Draw方法或实现自己的绘制逻辑
        // 例如：绘制玩家形状
    const int scaleFactor = 10;
    const int posAnchor = 5;
    const int size = 5;
    int x = pos.x;
    int y = pos.y;
    setfillcolor(color);
    switch (shape) {
    case shape::CIRCLE:
        fillcircle(posAnchor + x * scaleFactor, posAnchor + y * scaleFactor, size);
        break;
    case shape::RECT:
        fillrectangle(pos.x - 10, pos.y - 10, pos.x + 10, pos.y + 10);
        break;
        // 可根据需要添加其他形状
    default:
        break;
    }
}