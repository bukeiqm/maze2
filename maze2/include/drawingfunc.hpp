#pragma once
#include "datatypes.hpp"
#include <graphics.h>
#include "player.hpp"
#include "UI.hpp"
#include "map.hpp"

void DrawPlayer(const player& p1);

void DrawMap(const map& map);

void DrawUserUI();

ui InitUIp();

void DrawUI(const ui& usr);