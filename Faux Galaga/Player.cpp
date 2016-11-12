
#include <SDL.h>
#include <iostream>
#include "Constants.h"
#include "Player.h"
#include "Projectile.h"
#include <vector>

int now, timepass;

int Player::getX() {
	return x;
}
int Player::getY() {
	return y;
}
int Player::getW() {
	return w;
}
int Player::getH() {
	return h;
}

void Player::Update(const Uint8* keys) {
	if (keys[SDL_SCANCODE_UP]) y -= DOT_VEL;
	if (keys[SDL_SCANCODE_DOWN]) y += DOT_VEL;
	if (keys[SDL_SCANCODE_LEFT]) x -= DOT_VEL;
	if (keys[SDL_SCANCODE_RIGHT]) x += DOT_VEL;
	if (keys[SDL_SCANCODE_D]) {
		now = SDL_GetTicks();
		if (now > timepass + LIMITER) {
			Projectile::createProjectile(x + w, y + (h - PROJ_H) / 2, PROJ_SPEED, 0, PROJ_W, PROJ_H);
		}
		timepass = now;
	}

	if (keys[SDL_SCANCODE_A]) {
		now = SDL_GetTicks();
		if (now > timepass + LIMITER) {
			Projectile::createProjectile(x-PROJ_W, y + (h - PROJ_H) / 2, -PROJ_SPEED,0, PROJ_W, PROJ_H);
		}
		timepass = now;
	}

	if (keys[SDL_SCANCODE_W]) {
		now = SDL_GetTicks();
		if (now > timepass + LIMITER) {
			Projectile::createProjectile(x + (w-PROJ_H)/2, y - (h + PROJ_H)/2, 0, -PROJ_SPEED, PROJ_H, PROJ_W);
		} 
		timepass = now;
	}

	if (keys[SDL_SCANCODE_S]) {
		now = SDL_GetTicks();
		if (now > timepass + LIMITER) {
			Projectile::createProjectile(x + (w - PROJ_H) / 2, y + PLAYER_HEIGHT, 0, PROJ_SPEED, PROJ_H, PROJ_W);
		}
		timepass = now;
	}
	if (x < 0) x = 0;
	if (x >(LEVEL_WIDTH - w)) x = LEVEL_WIDTH - w;
	if (y < 0) y = 0;
	if (y > LEVEL_HEIGHT - h) y = LEVEL_HEIGHT - h;
}

void Player::Draw(SDL_Renderer *ren, int cx, int cy) {
	SDL_SetRenderDrawColor(ren,255,0,0,255);
	SDL_Rect dst;
	dst.x = x - cx;
	dst.y = y - cy;
	dst.w = w;
	dst.h = h;
	SDL_RenderFillRect(ren, &dst);
}