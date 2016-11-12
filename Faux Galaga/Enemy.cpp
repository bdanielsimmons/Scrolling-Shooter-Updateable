#pragma once
#define PI 3.14
#include "Constants.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include <cmath>
#include <SDL.h>
#include <vector>

void Enemy::calcAngle(Enemy &a, int px, int py) {
	float dx = px - a.x;
	float dy = py - a.y;
	float angle = atan(dy / dx) * 180 / PI;
	a.vx = (cos(angle) * ENEMY_SPEED);
	a.vy = (sin(angle) * ENEMY_SPEED);
}

std::vector<Enemy> Enemy::Enemies;

void Enemy::createEnemy(int x, int y, int vx = 2, int vy = 2, int w = ENEMY_W, int h = ENEMY_H) {
	Enemies.push_back(Enemy(x, y, vx, vy, w, h));
}

void Enemy::Draw(SDL_Renderer* ren, int cx, int cy) {
	SDL_SetRenderDrawColor(ren, 0,0,0, 255);
	for (Enemy &p : Enemies) {
		SDL_Rect recta;
		recta.x = p.x - cx;
		recta.y = p.y - cy;
		recta.w = p.w;
		recta.h = p.h;
		SDL_RenderFillRect(ren, &recta);
	}
}

void Enemy::Update(int px, int py, int pw, int ph) {
	std::vector<Enemy>present;
	for (Enemy &a : Enemies) {
		calcAngle(a, px, py);
		a.x += a.vx;
		a.y += a.vy;
		bool c = false;
		bool d = false;
		//bool e = false;
		for (Projectile &p : Projectile::Bullets) {
			c = c || (CheckCollision(a.x, a.y, a.w, a.h, p.x, p.y, p.w, p.h));
			if (c) {
				Projectile::Bullets.pop_back();
				break;
			}
		}
		//for (Enemy &b : present) {
		//	e = e || (CheckCollision(a.x, a.y, a.w, a.h, b.x, b.y, b.w, b.h));
		//}
		d = d || (CheckCollision(a.x, a.y, a.w, a.h, px, py, pw , ph));
		if (a.x + a.w > 0 && !c && a.x + a.w > 0 && !d /*&&  !e */) {
			present.push_back(a);
		}
	}
	Enemies = present;
}