#include "trap.hpp"
void trap::DoDamageTo(player& player) {
	if (triggered) return;
	if (duration < 0) return;
    if (!(pos == player.GetPosition())) return;
	player.health -= damage;
    triggered = true;
}

void trap::Mute() {
	duration = -1;
}

trap::trap(position initPos, int duration,int damage) :object(initPos, shape::CIRCLE, CYAN), duration(duration), damage(damage) {
	triggered = false;
}

void trap::Move(map m1, player p1) {
    if (triggered) return;    // 已触发的陷阱不移动
    if (duration < 0) return; // 失效的陷阱不移动

    if (--duration % 11 != 0) return;

    int n = m1.GetSize().x, m = m1.GetSize().y;
    int x = p1.GetPosition().x, y = p1.GetPosition().y;

    // 1. 收集玩家周围5x5范围内的所有通路位置
    vector<position> validPositions;
    for (int i = x - 5; i <= x + 5; ++i) {  // x方向范围：[x-2, x+2]
        for (int j = y - 5; j <= y + 5; ++j) {  // y方向范围：[y-2, y+2]
            if (i > x - 2 && i <= x + 2) continue;
            if (j > y - 2 && j <= y + 2) continue;
            // 检查坐标是否在地图范围内且是通路
            if (i >= 0 && i < n && j >= 0 && j < m && m1.IsPathway(i, j)) {
                if (p1.GetPosition().x == i && p1.GetPosition().y == j) continue;
                validPositions.emplace_back(i, j);  // 加入有效位置列表
            }
        }
    }

    // 2. 从有效位置中随机选一个移动
    if (!validPositions.empty()) {
        // 生成随机索引
        int randomIdx = rand() % validPositions.size();
        SetPosition(validPositions[randomIdx]);  // 移动到随机选中的通路位置
    }
}

void trap::Draw() {
	if (triggered) return;
	if (duration < 0) return;
	object::Draw();
}

void trap::Revive() {
	if (triggered) return;
	if (duration < 0) {
		duration -= 1;
	}
	if (duration < -100) {
		duration = 100;
	}
}