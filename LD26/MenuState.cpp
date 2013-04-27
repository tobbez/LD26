#include "SDL.h"

#include "MenuState.h"
#include "ImageManager.h"
#include "Util.h"

STATE_TYPE MenuState::advance(SDL_Surface *screen, Uint8 *keys)
{
	if (keys[SDLK_SPACE]) {
		return STATE_TYPE::INGAME;
	}

	SDL_FillRect(screen, NULL, 0);

	SDL_Surface *menu_text = ImageManager::load_image("menu-text");
	SDL_Surface *menu_legend = ImageManager::load_image("menu-legend");
	SDL_Surface *menu_controls = ImageManager::load_image("menu-controls");
	SDL_Surface *menu_credits = ImageManager::load_image("menu-credits");
	Util::blit_at(menu_text, screen, screen->w/2 - menu_text->w/2, screen->h/3 * 2 - menu_text->h/2);
	Util::blit_at(menu_legend, screen, screen->w/2 - menu_legend->w/2, screen->h/3 - menu_legend->h/2);
	Util::blit_at(menu_controls, screen, screen->w/2 - menu_controls->w/2, screen->h/3 * 2 + menu_text->h/2 + 4);
	Util::blit_at(menu_credits, screen, screen->w - (menu_credits->w + 8), screen->h - (menu_credits->h + 4));

	return next_state;
}

void MenuState::handle_event(SDL_Event const &ev) {
	if (ev.type == SDL_KEYUP && ev.key.keysym.sym == SDLK_ESCAPE) {
		next_state = STATE_TYPE::EXIT;
	}
}

MenuState::MenuState(void)
{
	next_state = STATE_TYPE::MENU;
}


MenuState::~MenuState(void)
{
}

