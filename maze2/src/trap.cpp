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

trap::trap(int duration, int damage) :object({ -1,-1 }, shape::CIRCLE, CYAN), duration(duration), damage(damage) {
	triggered = false;
}

void trap::Move(map m1, player p1) {
    if (triggered) return;    // 已触发的陷阱不移动
    if (duration < 0) return; // 失效的陷阱不移动

    if (--duration % 41 != 0) return;

    int n = m1.GetSize().x, m = m1.GetSize().y;
    int x = p1.GetPosition().x, y = p1.GetPosition().y;

	while (true) {
		int i = rand() % n, j = rand() % m;
		if (i == x && j == y) continue;
		if (m1.IsDestination({ i, j })) continue;
		if (m1.IsPathway({ i, j })) {
			SetPosition({ i, j });
			break;
		}
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