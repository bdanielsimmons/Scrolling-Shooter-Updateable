#include <iostream>
#include "Projectile.h"

std::vector<Projectile> Projectile::Bullets;


void Projectile::createProjectile(int x, int y, int vx, int vy, int w = PROJ_W, int h = PROJ_H) {
	Bullets.push_back(Projectile(x, y, vx, vy, w, h));
}

void Projectile::Draw(SDL_Renderer* ren, int cx, int cy) {
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	for (Projectile &p : Bullets) {
		SDL_Rect rect;
		rect.x = p.x-cx;
		rect.y = p.y-cy;
		rect.w = p.w;
		rect.h = p.h;
		SDL_RenderFillRect(ren, &rect);
	}
}

void Projectile::Update() {
	std::vector<Projectile>present;
	for (Projectile &p : Bullets) {
		p.x += p.vx;
		p.y += p.vy;
		if (p.x < LEVEL_WIDTH) {
			present.push_back(p);
		}
	}
	Bullets = present;
}