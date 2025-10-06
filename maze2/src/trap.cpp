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
    if (triggered) return;    // �Ѵ��������岻�ƶ�
    if (duration < 0) return; // ʧЧ�����岻�ƶ�

    if (--duration % 11 != 0) return;

    int n = m1.GetSize().x, m = m1.GetSize().y;
    int x = p1.GetPosition().x, y = p1.GetPosition().y;

    // 1. �ռ������Χ5x5��Χ�ڵ�����ͨ·λ��
    vector<position> validPositions;
    for (int i = x - 5; i <= x + 5; ++i) {  // x����Χ��[x-2, x+2]
        for (int j = y - 5; j <= y + 5; ++j) {  // y����Χ��[y-2, y+2]
            if (i > x - 2 && i <= x + 2) continue;
            if (j > y - 2 && j <= y + 2) continue;
            // ��������Ƿ��ڵ�ͼ��Χ������ͨ·
            if (i >= 0 && i < n && j >= 0 && j < m && m1.IsPathway(i, j)) {
                if (p1.GetPosition().x == i && p1.GetPosition().y == j) continue;
                validPositions.emplace_back(i, j);  // ������Чλ���б�
            }
        }
    }

    // 2. ����Чλ�������ѡһ���ƶ�
    if (!validPositions.empty()) {
        // �����������
        int randomIdx = rand() % validPositions.size();
        SetPosition(validPositions[randomIdx]);  // �ƶ������ѡ�е�ͨ·λ��
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