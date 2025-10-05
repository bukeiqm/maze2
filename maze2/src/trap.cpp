#include "trap.hpp"
void trap::DoDamageTo(player& player, int damage) {
	player.health -= damage;
}

bool trap::ShouldExist() {
	return duration > 0;
}

void trap::Draw() {

}