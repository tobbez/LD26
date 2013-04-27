#pragma once
#include "SDL.h"
#include "State.h"

class Game {
public:
	Game();

	void run();

private:
	SDL_Surface *screen;

	State *current;
	STATE_TYPE previous;

	bool running;
};