#pragma once
#include "SDL.h"

enum class STATE_TYPE {
	EXIT = -1,
	MENU = 0,
	INGAME = 1,
	GAMEOVER = 2
};

class State
{
public:
	virtual STATE_TYPE advance(SDL_Surface *screen, Uint8 *keys) = 0;
	virtual void handle_event(SDL_Event const &ev);

	State(void);
	virtual ~State(void);
};

