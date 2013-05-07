#include "Game.h"

#include "MenuState.h"
#include "IngameState.h"
#include "GameoverState.h"
#include "ImageManager.h"

#include "Util.h"

Game::Game() 
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);

	current = new MenuState();
	previous = STATE_TYPE::MENU;

	Util::Random::init();

	SDL_WM_SetCaption("", NULL);
	SDL_ShowCursor(0);

	running = true;
}

void Game::run()
{
	while(running) {
		Uint32 time = SDL_GetTicks();

		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) {
				running = false;
			}
			current->handle_event(ev);
		}

		Uint8 *keystate = SDL_GetKeyState(NULL);

		STATE_TYPE next = current->advance(screen, keystate);
		if (next != previous) {
			switch(next) {
			case STATE_TYPE::EXIT:
				running = false;
				break;
			case STATE_TYPE::MENU:
				delete current;
				current = new MenuState();
				break;
			case STATE_TYPE::INGAME:
				delete current;
				current = new IngameState();
				break;
			case STATE_TYPE::GAMEOVER:
				delete current;
				current = new GameoverState();
				break;
			}
		}
		previous = next;

		SDL_Flip(screen);
		time = SDL_GetTicks() - time;
		if (time > 1000/60) time = 0;
		SDL_Delay(1000/60 - time);
	}
	ImageManager::unload_all();	
}