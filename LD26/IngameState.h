#pragma once
#include "State.h"
#include "Sprite.h"
class IngameState :
	public State
{
public:
	virtual STATE_TYPE advance(SDL_Surface *screen, Uint8 *keys);
	virtual void handle_event(SDL_Event const &ev);
	IngameState(void);
	~IngameState(void);

private:
	void new_round();

	STATE_TYPE next_state;

	Sprite *player;
	Sprite *potato;

	Uint64 timeleft;

	Uint64 ticks;
};

