#pragma once
#include "Constants.h"
#include "Player.h"
#include <SDL.h>
#include <vector>

class Projectile {
public:
	int x, y, w, h, vx, vy, now, timepass;
	static std::vector<Projectile> Bullets;
	Projectile(int x, int y, int vx, int vy, int w = PROJ_W, int h = PROJ_H) {
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		this->w = w;
		this->h = h;
	}
	static void createProjectile(int, int, int, int, int, int);
	static void Draw(SDL_Renderer* ren, int, int);
	static void Update();

};