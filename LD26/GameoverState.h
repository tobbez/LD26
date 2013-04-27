#pragma once
#include "state.h"
class GameoverState :
	public State
{
public:
	STATE_TYPE advance(SDL_Surface *screen, Uint8 *keys);
	void handle_event(SDL_Event const &ev);
	GameoverState(void);
	~GameoverState(void);

private:
	STATE_TYPE next_state;
};

