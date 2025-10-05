#include "player.hpp"

player::player(position initPos) {};

bool player::IsJammed(const map& M) {
	return !M.IsPathway(pos.Offset(dir));
}

bool player::AtDest(const map& M) {
	return pos == M.destination;
}

void player::Draw() {
    // 调用父类的Draw方法或实现自己的绘制逻辑
        // 例如：绘制玩家形状
    setfillcolor(color);
    switch (shape) {
    case shape::CIRCLE:
        fillcircle(pos.x, pos.y, 10);
        break;
    case shape::RECT:
        fillrectangle(pos.x - 10, pos.y - 10, pos.x + 10, pos.y + 10);
        break;
        // 可根据需要添加其他形状
    default:
        break;
    }
}