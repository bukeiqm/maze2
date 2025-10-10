#pragma once
#include "object.hpp"
class trap: public object {
private:
	int damage;
	int duration;
	bool triggered;
public:
	trap(position initPos, int duration = 100, int damage = 50);
	trap(int duration = 100, int damage = 50);
public:
	int GetDamage() const;
	int GetDuration() const;
	void SetValidity(bool valid);
	void SetDuration(int duration);
	void SetDurationDiff(int diff);
	bool IsValid() const;
	void Draw() override;
};

