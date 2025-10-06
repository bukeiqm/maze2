#include "trap.hpp"
void trap::DoDamageTo(player& player) {
	if (triggered) return;
	if (duration < 0) return;
	player.health -= damage;
}

void trap::Mute() {
	duration = -1;
}

trap::trap(position initPos, int duration,int damage) :object(initPos, shape::CIRCLE, CYAN), duration(duration), damage(damage) {
	triggered = false;
}

void trap::Move(map m1,player p1) {
	if (triggered) return;
	if (duration < 0) return;
	int n = m1.GetSize().x, m = m1.GetSize().y;
	int x = p1.GetPosition().x, y = p1.GetPosition().y;
	for (int i = x - 2; i < x + 3; i++) {
		for (int j = y - 2; j < y + 3; j++) {
			if (i < 0 || i >= n) continue;
			if (j < 0 || j >= m) continue;
			if (m1.IsPathway(i, j)){
				SetPosition({ i,j });
				return;
			}
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