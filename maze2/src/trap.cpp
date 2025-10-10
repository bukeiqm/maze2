#include "trap.hpp"

trap::trap(position initPos, int duration,int damage) :object(initPos, shape::CIRCLE, CYAN), duration(duration), damage(damage) {
	triggered = false;
}

trap::trap(int duration, int damage) :trap({ -1,-1 }, duration, damage) {
	triggered = false;
}

bool trap::IsValid() const {
	return triggered == false && duration >= 0;
}

void trap::Draw() {
	object::Draw();
}

void trap::SetValidity(bool valid) {
	triggered = !valid;
}

void trap::SetDuration(int newDuration) {
	duration = newDuration;
}

void trap::SetDurationDiff(int diff) {
	duration += diff;
}

int trap::GetDamage() const {
	return damage;
}

int trap::GetDuration() const {
	return duration;
}