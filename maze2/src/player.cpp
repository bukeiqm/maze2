#include "player.hpp"

player::player(position initPos) {};

bool player::IsJammed(const map& M) {
	return !M.IsPathway(pos.Offset(dir));
}

bool player::AtDest(const map& M) {
	return pos == M.destination;
}

void player::Draw() {
    // ���ø����Draw������ʵ���Լ��Ļ����߼�
        // ���磺���������״
    setfillcolor(color);
    switch (shape) {
    case shape::CIRCLE:
        fillcircle(pos.x, pos.y, 10);
        break;
    case shape::RECT:
        fillrectangle(pos.x - 10, pos.y - 10, pos.x + 10, pos.y + 10);
        break;
        // �ɸ�����Ҫ���������״
    default:
        break;
    }
}