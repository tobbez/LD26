#pragma once
#include "State.h"
class MenuState :
	public State
{
public:
	virtual STATE_TYPE advance(SDL_Surface *screen, Uint8 *keys);
	virtual void handle_event(SDL_Event const &ev);
	MenuState(void);
	~MenuState(void);

private:
	STATE_TYPE next_state;
};
