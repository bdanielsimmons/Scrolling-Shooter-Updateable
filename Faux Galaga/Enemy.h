#pragma once
#include "Constants.h"
#include "Player.h"
#include <SDL.h>
#include <vector>

class Enemy {
private:
	int x, y, vx, vy, w, h;
public:
	static std::vector<Enemy> Enemies;
	Enemy(int x, int y, int vx, int vy, int w = ENEMY_W, int h = ENEMY_H) {
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		this->w = w;
		this->h = h;
	}
	static void createEnemy(int, int, int, int, int, int);
	static void Draw(SDL_Renderer*, int, int);
	static void Update(int, int, int, int);
	static void calcAngle(Enemy& ,int,int);
};