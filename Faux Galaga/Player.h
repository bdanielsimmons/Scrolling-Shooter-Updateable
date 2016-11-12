#pragma once
#include <SDL.h>
#include "Constants.h"
#include <vector>
class Player {
private:
	int x, y, w, h;
public:
	Player(int x, int y, int w = PLAYER_WIDTH, int h = PLAYER_HEIGHT) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	void Update(const Uint8* keys);
	void Draw(SDL_Renderer*, int, int);
	int getX();
	int getY();
	int getW();
	int getH();
};
