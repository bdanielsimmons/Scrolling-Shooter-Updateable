#pragma once
#include <SDL.h>

// Size of the background image
const int LEVEL_WIDTH = 1920;
const int LEVEL_HEIGHT = 1080;

// Constant window size
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int PLAYER_WIDTH = 20;
const int PLAYER_HEIGHT = 20;

// Sets size of projectiles, relative speed
const int PROJ_W = 20;
const int PROJ_H = 10;
const int PROJ_SPEED = 10;
const int LIMITER = 18;

// Sets enemy size
const int ENEMY_W = 20;
const int ENEMY_H = 20;
const int ENEMY_SPEED = 2;

const int DOT_VEL = 3;

static bool CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{

	if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && h1 + y1 > y2) {
		return true;
	}
	return false;
}